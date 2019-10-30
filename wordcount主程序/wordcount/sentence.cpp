#include "pch.h"
#include "sentence.h"
#include<string.h>
#include"Method.h"
using namespace std;
//queue <int> pos_word(char *str);//�õ�ÿ�����ʵ�����ĸλ��
//char *Get_phrase(char *str, int pos, int len);//�Ƿ����ҵ���ôһ�����飨����ĸ��pos��ͷ��������Ϊlen�������򷵻�

sentence::sentence(char *str,int m)
{
	strcpy_s(content, str);
	phrase_length = m;
	word_count = 0;
}

sentence::~sentence()
{
}

void sentence::separate()
{
	queue <int> pos;
	pos_word(content,pos);//�õ�ÿ�����ʵ�����ĸλ��
	char *str = NULL;
	while (!pos.empty())
	{
		str = Get_phrase(content, pos.front(), phrase_length);
		if (Get_end(content, pos.front()) - pos.front() >=3)
		{
			word_count++;
			//printf("word:%c %d", content[pos.front()], pos.front());
		}
		if (str != NULL)
		{
			//printf("��㣺%c �յ� %c\n", content[pos.front()], content[Get_end(content, pos.front())]);
			phrs.AddNode(str);
			delete str;
			str=NULL;
		}
		pos.pop();
	}
}
