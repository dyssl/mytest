#include<iostream>
#include<fstream>
#include<string.h>
using namespace std; 
int main(int argc,char* argv[])
{
	int count=0;
	fstream input;
	input.open(argv[1]);
	if(!input.good())
	cout<<"in文件打开失败！"<<endl;
	char c;
    while (!input.eof())
    {
        c=input.get();//从文件中读取一个字符 
        if(isupper(c))//判断该字符是否为大写字母 ；若是，则改为小写字母且重新写入文件中 
        {
        	c+=32;
        	input.seekg(-1,ios::cur);   //将文件指针指向当前位置向开头方向偏移1的位置 
        	input<<c;
        }
        if(c>=0&&c<=255)//判断是否在ASCII码的范围内 
		count++;
    }
    input.close();
    cout<<count<<endl;
	return 0;
}

