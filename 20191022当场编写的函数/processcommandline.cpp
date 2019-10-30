#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

bool flagm=false;//默认不进行词组词频统计
int m=1;//默认词组单词数为1 
int n=10;//默认输出词频前10位 
char inputpath[100];
char outputpath[100];

/*命令行处理*/ 
void processcommandline(int argc,char **argv)
{
	/*参数判断*/ 
	for(int i=1;i<argc;i++)
	{
		/*输入文件*/ 
		if(strcmp(argv[i],"-i")==0)
		{
			i++;
			strcpy(inputpath,argv[i]);
		}
		/*输出文件*/ 
		else if(strcmp(argv[i],"-o")==0)
		{
			i++;
			strcpy(outputpath,argv[i]);
		}
		/*词组*/ 
		else if(strcmp(argv[i],"-m")==0)
		{
			flagm=true;//开启词组词频统计功能 
			i++;
			m = argv[i][0] - '0';
		}
		/*词频排序数*/ 
		else if(strcmp(argv[i],"-n")==0)
		{
			i++;
			n = argv[i][0] - '0';
		}
	}
}
