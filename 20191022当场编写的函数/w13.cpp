#include<iostream>
#include<string.h>
using namespace std;
int main(){
	struct stu{
		string str;
		int num;
	}student[5];
//	student[0].str="student";
//	student[1].str="afagf";
//	student[2].str="adgt";
//	student[3].str="sgr";
//	student[4].str="rsygtr";
//	student[0].num=4;
//	student[1].num=9;
//	student[2].num=8;
//	student[3].num=5;
//	student[4].num=7;
	int a=0;
	string b=""; 
	for(int i=0;i<4;i++)
	{
	
		for(int j=0;j<4-i;j++){
			if(student[j].num<student[j+1].num){
				a=student[j].num;
			student[j].num=student[j+1].num;
			student[j+1].num=a;
			b=student[j].str;
			student[j].str=student[j+1].str;
			student[j+1].str=b;
			}
			
			
			
		}
	}
//	for(int i=0;i<10;i++){
//		student[i].str="student";
//		student[i].num=i;
//	}

//	student[5].str="teacher";
	for(int i=0;i<5;i++)
	{
		cout<<student[i].str<<endl;
		cout<<student[i].num<<endl;
	}
	return 0;
}
