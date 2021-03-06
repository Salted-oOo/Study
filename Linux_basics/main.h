/* **************************
 * The main funtion of shell
 * *************************/
#include<stdio.h>

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
