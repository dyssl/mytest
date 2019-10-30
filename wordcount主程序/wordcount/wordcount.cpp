// wordcount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"pch.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <queue>
#include <map>
#include "Method.h"
#include"sentence.h"
using namespace std;
bool flagm = false;	//默认不进行词组词频统计
int m = 1;			//默认词组单词数为1 
int n = 10;			//默认输出词频前10位 
FILE* fp1;			//用于读取的文件 
FILE* fp2;			//用于写入的文件 
char InputName[100];//输入文件名
char OutputName[100];//输出文件名
char text[10000];	//将文件中的所有字符放到这里面
int count_char=0;		//字符总数 
int count_line=0;		//分行总数 
int count_word = 0;		//单词总数
map<string, int>mapper;	//字典 
string temp_str = "";		//定义全局变量，怕返回字符串出问题

int main(int argc, char *argv[])
{
	if(argc>3)get_cmd(argc, argv);
	else
	{
		/*strcpy_s(InputName, "D:\\.DATA\\Desktop\\input.txt");
		strcpy_s(OutputName, "D:\\.DATA\\Desktop\\output.txt");
		m =3;
		这里是手动调试信息
		*/
		printf("命令错误\n");
			exit(1);
	}
	ifstream fin(InputName);
	phrasetable phtb;
	while (1)
	{
		fin.getline(text, 10000);
		++count_line;
		count_char += turn_lowercase_and_WordLine_count(text);
		if (!fin.eof())count_char++;			//加上换行
		sentence A(text,m);
		A.separate();
		while (!A.phrs.empty())
		{
			cout << "词组：" << A.phrs.front()->content << "  次数：" << A.phrs.front()->count << endl;
			phtb.AddNode(A.phrs.front()->content, A.phrs.front()->count);
			A.phrs.del(A.phrs.front());
		}
		count_word += A.word_count;
		if (fin.eof())break;
	}
	cout << endl;
	cout << "words:" << count_word << endl;
	cout <<"chars:"<< count_char << endl;
	cout <<"lines:"<< count_line << endl;
	Data_output(phtb);
	cout << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
