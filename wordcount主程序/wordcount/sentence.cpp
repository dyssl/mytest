#include "pch.h"
#include "sentence.h"
#include<string.h>
#include"Method.h"
using namespace std;
//queue <int> pos_word(char *str);//得到每个单词的首字母位置
//char *Get_phrase(char *str, int pos, int len);//是否能找到这么一个词组（首字母在pos开头，单词数为len），能则返回

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
	pos_word(content,pos);//得到每个单词的首字母位置
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
			//printf("起点：%c 终点 %c\n", content[pos.front()], content[Get_end(content, pos.front())]);
			phrs.AddNode(str);
			delete str;
			str=NULL;
		}
		pos.pop();
	}
}
