/*************************************************************************
	> File Name: test.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 六  9/23 17:42:34 2017
 ************************************************************************/

#include <iostream>
#include <pthread.h>
#include <queue>
#include <semaphore.h>
#include <assert.h>
#include <vector>
#include <deque>
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::vector;
using std::deque;

static queue<int> task_queue;
static sem_t *task_empty, *task_full;
static int sync_lock = 0, sync_output = 0;

sem_t * CreateSemaphore(const char * inName, const int inStartingCount);
bool DestroySemaphore(sem_t * inSemaphore);
void SignalSemaphore(sem_t * inSemaphore);
void WaitSemaphore(sem_t * inSemaphore);
bool TryWaitSemaphore(sem_t * inSemaphore);
bool ClearSemaphore(const char * inName);

void *func1(void *arg) {
    // 取任务
    while (1) {
        sem_wait(task_full);
        int num;
        while (__sync_lock_test_and_set(&sync_lock, 1)) ;
        num = task_queue.front();
        task_queue.pop();
        sync_lock = 0;
        sem_post(task_empty);
        bool flag = true;
        for (int i = 2; i * i <= num && flag; i++) {
            if (num % i == 0) {
                flag = false;
            }
        }
        while (__sync_lock_test_and_set(&sync_output, 1)) ;
        cout << num << " is " << (flag ? "prime" : "not prime") << endl;
        fflush(stdout);
        sync_output = 0;
    }
    return NULL;
}

int main() {
    task_empty = CreateSemaphore("empty_sem", 10);
    task_full = CreateSemaphore("full_sem", 0);
    pthread_t thread;
    for (int i = 0; i < 10; i++) {
        pthread_create(&thread, NULL, func1, NULL);
    }
    for (int i = 2; i <= 100; i++) {
        sem_wait(task_empty);
        cout << "task empty wait done!" << endl;
        task_queue.push(i);
        sem_post(task_full);
    }
    pthread_join(thread, NULL);
    DestroySemaphore(task_empty);
    DestroySemaphore(task_full);
    return 0;
}

sem_t * CreateSemaphore( const char * inName, const int inStartingCount )
{
    sem_t * semaphore = sem_open( inName, O_CREAT, 0644, inStartingCount );
    
    //
    if( semaphore == SEM_FAILED )
    {
        switch( errno )
        {
            case EEXIST:
                printf( "Semaphore with name '%s' already exists.\n", inName );
                break;
                
            default:
                printf( "Unhandled error: %d.\n", errno );
                break;
        }
        
        //
        assert(false);
        return SEM_FAILED;
    }
    
    //
    return semaphore;
}


//
bool DestroySemaphore( sem_t * inSemaphore )
{
    int retErr = sem_close( inSemaphore );
    
    //
    if( retErr == -1 )
    {
        //
        switch( errno )
        {
            case EINVAL:
                printf( "inSemaphore is not a valid sem_t object." );
                break;
                
            default:
                printf( "Unhandled error: %d.\n", errno );
                break;
        }
        
        //
        assert(false);
        return false;
    }
    
    //
    return true;
}

//
void SignalSemaphore( sem_t * inSemaphore )
{
    sem_post( inSemaphore );
}

//
void WaitSemaphore( sem_t * inSemaphore )
{
    sem_wait( inSemaphore );
}

//
bool TryWaitSemaphore( sem_t * inSemaphore )
{
    int retErr = sem_trywait( inSemaphore );
    
    //
    if( retErr == -1 )
    {
        //
        if( errno != EAGAIN )
        {
            printf( "Unhandled error: %d\n", errno );
            assert( false );
        }
        
        //
        return false;
    }
    
    //
    return true;
}

bool ClearSemaphore( const char * inName)
{
    int retErr = sem_unlink(inName);
    
    if (retErr == -1) {
        
        return false;
        
    }
    
    return true;
}
