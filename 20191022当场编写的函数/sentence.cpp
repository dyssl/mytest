#include "sentence.h"
#include<string.h>

using namespace std;
queue <int> pos_word(char *str);//�õ�ÿ�����ʵ�����ĸλ��
char *Get_phrase(char *str, int pos, int len);//�Ƿ����ҵ���ôһ�����飨pos��ͷ��������Ϊlen�������򷵻�

sentence::sentence(char *str,int m)
{
	length = strlen(str) + 1;
	content = new char(length);
	strcpy(content, str);
	phrase_length = m;
}


sentence::~sentence()
{
	if (content == NULL)delete content;
	content = NULL;
}

void sentence::separate()
{
	queue <int> pos=pos_word(content);//�õ�ÿ�����ʵ�����ĸλ��
	char *str = NULL;
	while (!pos.empty())
	{
		str = Get_phrase(content, pos.front(), phrase_length);
		if (str != NULL)
		{
			phrase_head.AddNode(str);
		}
		pos.pop();
	}
}
