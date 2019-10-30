#include "pch.h"
#include "Method.h"
#include <stdio.h>
#include <string>
#include<fstream>
#include "phrasetable.h"
using namespace std;
extern bool flagm;
extern char InputName[100];
extern char OutputName[100];
extern int m;			//默认词组单词数为1 
extern int n;			//默认输出词频前10位 
extern int count_char ;		//字符总数 
extern int count_line ;		//分行总数 
extern int count_word;		//单词总数
#define is_number(x)	(x>=48&&x<=57)
#define is_letter(x)	(x>=97&&x<=122)
void get_cmd(int argc, char *argv[])
{
	string ms = "-m", ns = "-n", is = "-i", os = "-o";
	for (int i = 1; i < argc; i++)
	{
		if (argv[i] == ms)
		{
			flagm = true;
			m = atoi(argv[++i]);
		}
		else if (argv[i] == ns)
		{
			n = atoi(argv[++i]);
		}
		else if (argv[i] == is)
		{
			strcpy_s(InputName, argv[++i]);
		}
		else if (argv[i] == os)
		{
			strcpy_s(OutputName, argv[++i]);
		}
	}
}
int turn_lowercase_and_WordLine_count(char *str)
{
	int length = 0;				//长度记录
	int num_ASCII = 0;			//ASCII码记录
	while (str[length] != '\0')
	{
		if (str[length] >= 'A' && str[length] <= 'Z')					//大写转小写
		{
			str[length] += 32;
		}
		if (str[length] > -1 && str[length] < 128)num_ASCII++;			//ASCII码表从0-127
		//printf("%c\n", str[length]);
		length++;
	}
	return num_ASCII;
}

int Get_end(char *str,int i)		//找到一个单词的结尾，该单词以str[i]开头
{
	while (is_letter(str[i]) or is_number(str[i]))++i;
	//printf("end:%c %d\n",str[i-1], i-1);
	return i-1;
}

int check_head(char *str, int i)	//从str[i]开始 找下一个开头，即返回 跳过分隔符后 的 单词开头位置
{
	while (str[i] != '\0')
	{
		if (str[i] == ' ')++i;			//正常情况为空格
		else if (is_letter(str[i]))return i;	//找到字母就返回
		else return -1;		//其他字符算非正常	找到数字说明词组被截断了
	}
	return -1;		//\0也算非正常
}

char *Get_char(char * str, int start, int end)		//新建字符串复制str 从start到end
{
	char *p = new char[end - start + 2];
	int i;
	for ( i= 0; i+start != end +1; i++)
	{
		p[i] = str[i + start];
	}
	p[i] = '\0';
	return p;
}

char *Get_phrase(char *str, int pos, int len)		//从str中找词组，该词组以str[pos]开头，包含单词输len个
{
	int length = 0;
	int head = pos;
	int tail = 0;
	while (1)
	{
		tail = Get_end(str,head);
		//printf("start:%d tail:%d\n", head, tail);
		if (tail - head >= 3)		//至少4个字母	0123 3-0=3 所以这里是3
		{
			if (++length == len)break;
			head = check_head(str, tail + 1);
			if (head == -1)break;
		}
		else break;
	}
	if (length == len)
	{
		return Get_char(str, pos, tail);
	}
	return NULL;
}

void pos_word(char *str,queue <int> &pos)			//寻找一行中，所有单词首字母位置
{
	int i = 0;
	int status=0;		//1 在一个单词中，2 在分隔符中
	int head = 0, tail = 0;
	int letter_start=0;
	bool stopAdd = false;	//出现数字 字母就要停止计数
	while (str[i] != '\0')
	{
		if (is_letter(str[i]))
		{
			status = 1;
			head = i;			//找到第一个有效字符
			letter_start ++;
			break;
		}
		++i;
	}
	for (++i; str[i] != '\0';++i)
	{
		if (is_letter(str[i]) or is_number(str[i]))		//当前是有效符号
		{
			switch (status)								
			{
				case 1:break;			//1 上个状态是有效符号
				case 2:head = i; break;		//2 上个状态是分割符
			}
			if (is_number(str[i]))stopAdd = true;					//数字 停止加
			if (!stopAdd and is_letter(str[i]))letter_start++;		//没出现过数字接着加
			status = 1;
		}
		else										//当前是分割符
		{
			switch (status)
			{
				case 1:if (i - head > 3 && letter_start > 3) { pos.push(head); /*printf("%c %d\n", str[head], head);*/ } break;	//1 上个状态是有效符号
				case 2:break;								//2 上个状态是分割符
			}
			letter_start = 0;
			stopAdd = false;
			status = 2;
		}
	}
	if (status == 1)
	{
		if (i - head > 3&& letter_start > 3)pos.push(head);/*printf("%c %d\n", str[head], head);*/
	}
}
void Data_output(phrasetable phtb)
{
	int n_count = n;
	phrase *p;
	ofstream fout(OutputName);
	fout << "characters: " << count_char << endl;
	fout << "words: " << count_word << endl;
	fout << "lines: " << count_line << endl;
	while (n_count > 0 && !phtb.empty())
	{
		p = phtb.max_count();
		fout << "<" << p->content << ">: " << p->count << endl;
		phtb.del(p);
		n_count--;
	}
}