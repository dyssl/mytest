#include<iostream>
using namespace std;

struct item_node
{
	char item[100];
	int number;
};

void output_function(int n_sign,char *output_file,int *count_number,item_node *q,int q_count)
{
	cout<<"characters:"<<count_number[0]<<endl;
	cout<<"words:"<<count_number[1]<<endl;
	cout<<"lines:"<<count_number[2]<<endl;
	int cnt = min(n_sign,q_count);
	for(int i=0; i<cnt; i++)
	{
		cout<<"<"<<q[i].item<<">:"<<q[i].number<<endl;	
	}
}

