#pragma once
#include<queue>
#include"phrasetable.h"
class sentence		//һ�е��� 
{
public:
	char *content;//����
	int length; //����
	//int num_word;//����ͳ��
	int phrase_length;
	sentence(char *,int m);//��ʼ�� ��Ҫ-m 
	~sentence();
	void separate();//������� 
	phrasetable phrase_head;//����or ���� 
};
