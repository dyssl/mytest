#pragma once
#include<queue>
#include"phrasetable.h"
class sentence		//һ�е��� 
{
public:
	char content[10000];//����
	int word_count;//��������
	int length; //����
	//int num_word;//����ͳ��
	int phrase_length;
	sentence(char *,int m);//��ʼ�� ��Ҫ-m 
	~sentence();
	void separate();//������� 
	phrasetable phrs;//����or ���� 
};
