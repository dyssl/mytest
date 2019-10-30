#include"pch.h"
#include "phrasetable.h"
void Data_output(phrasetable phtb)
{
	int n_count = n;
	phrase *p;
	cout<<"characters: "<<count_char<<endl;
	cout<<"words: "<<count_words<<endl;
	cout<<"lines: "<<count_lines<<endl;
	while(n_count>0 && !phtb.empty())
	{
		p = phtb.max_count();
		cout<<"<"<< p->content<<">: "<< p->count<<endl;
		phtb.del(p);
		n_count--;
	}
}