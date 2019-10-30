#include "pch.h"
#include "phrasetable.h"
#include<string.h>
using namespace std;

phrasetable::phrasetable()
{
	head = NULL;
}

void phrasetable::AddNode(char *str)
{
	if (str == NULL)return;
	if (head == NULL)
	{
		head = new phrase;
		strcpy(head->content, str);
		head->count = 1;
		head->next = NULL;
	}
	phrase *p = search(str);
	if (p == NULL)
	{
		phrase *r = head;
		while (r->next != NULL)r = r->next;
		r->next = new phrase;
		strcpy(r->next->content, str);
		r->next->count = 1;
		r->next->next = NULL;
	}
	else p->count++;
}
phrase *phrasetable::search(char *str)
{
	if (str == NULL)return NULL;
	phrase *p = head;
	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(p->content, str) == 0)
		return p;
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

phrase *phrasetable::min_str()
{
	if (head == NULL)return NULL;
	char *buff=new char[1000];
	phrase *x;
	x = head;
	strcpy(buff, x->content);
	while (x ->next!= NULL)
	{
		x = x->next;
		if (strcmp(buff, x->content) > 0)
			strcpy(x->content, buff);
	}
	return buff;
}
void phrasetable::del(phrase * p)
{
	phrase *x=head;
	if (head == p) {
		head = head->next;
		delete x;
		return;
	{
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