/* **************************
 * The cd command of shell
 * *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <sys/types.h>
#include <dirent.h>
#include <grp.h>

#define BUF_SIZE 64

typedef struct _input_type
{
	char * str; // the value of input
	int size;   // the length of value
}input_type;

input_type input[] =
{
	{"exit",4},
	{"cd",2},
	{"ls",2},
};

void cds(const char * p);
void lss(const char * p);

int main(int argc, char *argv[])
{
	char buf[BUF_SIZE];
	int res = 1;
	int flag = 1;
	int index = 0;

	while(flag)
	{
		printf("|->");
		if(NULL == fgets(buf,BUF_SIZE,stdin))
			return 0;

		index = sizeof(input)/sizeof(input_type);
		while(index-- > 0)
		{
			res = strncmp(buf,input[index].str,input[index].size);
			if(res == 0)
			{
				switch(index)
				{
				case 0: // exec exit commond
					flag = 0;
					break;
				case 1: // exec cd commond
					cds(buf);
					break;
				case 2: // exec ls commond
					lss(buf);
					break;
				default:
					printf("can 's \n");
					break;
				}

				index = -1; // if find the commond, stop finding
			}
		}

		if(index == -1)
			printf("can't find commond: %s ",buf);
	}

	return 0;
}

void cds(const char * p)
{
	printf("cd running \n");
}

void lss(const char * p)
{
	printf("ls running \n");
}





int cds(const char *p)
{
	char path[PATH_SIZE];
	char *start;
	char *end;
	int res;
	int n= 0;

	memset(path,'\0',PATH_SIZE); // must init ,ohtrway there is a wrong result with @
	
	start = strchr(p,' ');
	end = strchr(p,'\n');
	if(!start || !end)
	{
		printf("can't support this format \n");
		return 1;
	}

	strncpy(path,p+3,end-start-1); // get the path in inputting command

	res = chdir(path); //change dir

	if(res != 0)
		printf("%s is nod a path,please check again \n",path);

	return res;
}
