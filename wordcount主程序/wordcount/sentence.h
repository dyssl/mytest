#pragma once
#include<queue>
#include"phrasetable.h"
class sentence		//一行单词 
{
public:
	char content[10000];//内容
	int word_count;//单词总数
	int length; //长度
	//int num_word;//调用统计
	int phrase_length;
	sentence(char *,int m);//初始化 需要-m 
	~sentence();
	void separate();//分离词组 
	phrasetable phrs;//单词or 词组 
};
