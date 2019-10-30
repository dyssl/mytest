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
	phrase * head;
	void AddNode(char *);
	bool empty();
	phrase *search(char *);
	phrase* front();
	void pop();
	phrase *min_str();
	void del(phrase*);
};

