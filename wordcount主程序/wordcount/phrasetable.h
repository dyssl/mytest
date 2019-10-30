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
	phrase * head;				//头节点指针
	void AddNode(char *, int count = 1);	//添加词频节点，默认加1
	bool empty();				//是否为空
	phrase *search(char *);		//寻找指定字符串内容的节点
	phrase* front();			//返回头节点
	void pop();					//删除头节点
	phrase *max_count();		//返回词频最高字典序最小的结构体
	void del(phrase*);			//删除一个结构体
};