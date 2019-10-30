#pragma once
#include<queue>
#include"phrasetable.h"
class sentence		//一行单词 
{
public:
	char *content;//内容
	int length; //长度
	//int num_word;//调用统计
	int phrase_length;
	sentence(char *,int m);//初始化 需要-m 
	~sentence();
	void separate();//分离词组 
	phrasetable phrase_head;//单词or 词组 
};
