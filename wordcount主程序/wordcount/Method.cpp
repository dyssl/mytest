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
extern int m;			//Ĭ�ϴ��鵥����Ϊ1 
extern int n;			//Ĭ�������Ƶǰ10λ 
extern int count_char ;		//�ַ����� 
extern int count_line ;		//�������� 
extern int count_word;		//��������
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
	int length = 0;				//���ȼ�¼
	int num_ASCII = 0;			//ASCII���¼
	while (str[length] != '\0')
	{
		if (str[length] >= 'A' && str[length] <= 'Z')					//��дתСд
		{
			str[length] += 32;
		}
		if (str[length] > -1 && str[length] < 128)num_ASCII++;			//ASCII����0-127
		//printf("%c\n", str[length]);
		length++;
	}
	return num_ASCII;
}

int Get_end(char *str,int i)		//�ҵ�һ�����ʵĽ�β���õ�����str[i]��ͷ
{
	while (is_letter(str[i]) or is_number(str[i]))++i;
	//printf("end:%c %d\n",str[i-1], i-1);
	return i-1;
}

int check_head(char *str, int i)	//��str[i]��ʼ ����һ����ͷ�������� �����ָ����� �� ���ʿ�ͷλ��
{
	while (str[i] != '\0')
	{
		if (str[i] == ' ')++i;			//�������Ϊ�ո�
		else if (is_letter(str[i]))return i;	//�ҵ���ĸ�ͷ���
		else return -1;		//�����ַ��������	�ҵ�����˵�����鱻�ض���
	}
	return -1;		//\0Ҳ�������
}

char *Get_char(char * str, int start, int end)		//�½��ַ�������str ��start��end
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

char *Get_phrase(char *str, int pos, int len)		//��str���Ҵ��飬�ô�����str[pos]��ͷ������������len��
{
	int length = 0;
	int head = pos;
	int tail = 0;
	while (1)
	{
		tail = Get_end(str,head);
		//printf("start:%d tail:%d\n", head, tail);
		if (tail - head >= 3)		//����4����ĸ	0123 3-0=3 ����������3
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

void pos_word(char *str,queue <int> &pos)			//Ѱ��һ���У����е�������ĸλ��
{
	int i = 0;
	int status=0;		//1 ��һ�������У�2 �ڷָ�����
	int head = 0, tail = 0;
	int letter_start=0;
	bool stopAdd = false;	//�������� ��ĸ��Ҫֹͣ����
	while (str[i] != '\0')
	{
		if (is_letter(str[i]))
		{
			status = 1;
			head = i;			//�ҵ���һ����Ч�ַ�
			letter_start ++;
			break;
		}
		++i;
	}
	for (++i; str[i] != '\0';++i)
	{
		if (is_letter(str[i]) or is_number(str[i]))		//��ǰ����Ч����
		{
			switch (status)								
			{
				case 1:break;			//1 �ϸ�״̬����Ч����
				case 2:head = i; break;		//2 �ϸ�״̬�Ƿָ��
			}
			if (is_number(str[i]))stopAdd = true;					//���� ֹͣ��
			if (!stopAdd and is_letter(str[i]))letter_start++;		//û���ֹ����ֽ��ż�
			status = 1;
		}
		else										//��ǰ�Ƿָ��
		{
			switch (status)
			{
				case 1:if (i - head > 3 && letter_start > 3) { pos.push(head); /*printf("%c %d\n", str[head], head);*/ } break;	//1 �ϸ�״̬����Ч����
				case 2:break;								//2 �ϸ�״̬�Ƿָ��
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