#pragma once
struct phrase
{
	char content[1000];
	int count;
	phrase *next;
};
class phrasetable
{
public:
	phrasetable();
	~phrasetable();
	phrase * head;				//ͷ�ڵ�ָ��
	void AddNode(char *, int count = 1);	//��Ӵ�Ƶ�ڵ㣬Ĭ�ϼ�1
	bool empty();				//�Ƿ�Ϊ��
	phrase *search(char *);		//Ѱ��ָ���ַ������ݵĽڵ�
	phrase* front();			//����ͷ�ڵ�
	void pop();					//ɾ��ͷ�ڵ�
	phrase *max_count();		//���ش�Ƶ����ֵ�����С�Ľṹ��
	void del(phrase*);			//ɾ��һ���ṹ��
};