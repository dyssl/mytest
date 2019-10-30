#include "sentence.h"
#include<string.h>

using namespace std;
queue <int> pos_word(char *str);//得到每个单词的首字母位置
char *Get_phrase(char *str, int pos, int len);//是否能找到这么一个词组（pos开头，单词数为len），能则返回

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
	queue <int> pos=pos_word(content);//得到每个单词的首字母位置
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
