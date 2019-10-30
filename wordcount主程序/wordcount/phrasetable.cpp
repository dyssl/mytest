#include "pch.h"
#include "phrasetable.h"
#include<string.h>
#include<stdio.h>
using namespace std;

phrasetable::phrasetable()
{
	head = NULL;
}

void phrasetable::AddNode(char *str,int count)
{
	if (str == NULL)return;
	if (head == NULL)
	{
		head = new phrase;
		strcpy_s(head->content, str);
		head->count = count;
		head->next = NULL;
		//printf("创建：%s 次数：%d\n", head->content, head->count);
		return;
	}
	phrase *p = search(str);
	if (p == NULL)
	{
		p = new phrase;
		phrase *r = head;
		strcpy_s(p->content, str);
		p->count = count;
		p->next = NULL;
		while (r->next != NULL)r = r->next;
		r->next = p;
		//printf("创建：%s 次数：%d\n", p->content, p->count);
	}
	else
	{
		p->count += count;
		//printf("累加：%s 次数：%d\n", p->content, p->count);
	}
}
phrase *phrasetable::search(char *str)
{
	if (str == NULL)return NULL;
	phrase *p = head;
	while (p!= NULL)
	{
		if (strcmp(p->content, str) == 0)
		return p;
		p = p->next;
	}
	return NULL;
}
phrasetable::~phrasetable()
{
}
bool phrasetable::empty()
{
	if (head !=NULL)return false;
	return true;
}
phrase*phrasetable::front()
{
	return head;
}
void phrasetable::pop()
{
	if (head = NULL)return;
	phrase *r = head;
	head = head->next;
	delete r;
	r = NULL;
}

phrase *phrasetable::max_count()
{
	if (head == NULL)return NULL;
	phrase *x,*r;
	x = r = head;
	while (x ->next!= NULL)
	{
		x = x->next;
		if (r->count < x->count)r = x;
		else if (r->count == x->count)
		{
			if (strcmp(r->content, x->content) > 0)
				r = x;
		}
	}
	return r;
}
void phrasetable::del(phrase * p)
{
	if (head == NULL)return;
	phrase *x=head;
	if (head == p) {
		head = head->next;
		delete x;
		x = NULL;
		return;
	}
	while (x!= NULL)
	{
		if (x->next == p)
		{
			x->next = p->next;
			delete p;
			p = NULL;
			return;
		}
		x = x->next;
	}
}