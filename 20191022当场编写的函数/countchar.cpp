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
	cout<<"in�ļ���ʧ�ܣ�"<<endl;
	char c;
    while (!input.eof())
    {
        c=input.get();//���ļ��ж�ȡһ���ַ� 
        if(isupper(c))//�жϸ��ַ��Ƿ�Ϊ��д��ĸ �����ǣ����ΪСд��ĸ������д���ļ��� 
        {
        	c+=32;
        	input.seekg(-1,ios::cur);   //���ļ�ָ��ָ��ǰλ����ͷ����ƫ��1��λ�� 
        	input<<c;
        }
        if(c>=0&&c<=255)//�ж��Ƿ���ASCII��ķ�Χ�� 
		count++;
    }
    input.close();
    cout<<count<<endl;
	return 0;
}

