#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <queue>
#include <map>
using namespace std;
bool flagm=false;	//默认不进行词组词频统计
int m=1;			//默认词组单词数为1 
int n=10;			//默认输出词频前10位 
FILE* fp1;			//用于读取的文件 
FILE* fp2;			//用于写入的文件 
char* InputName = NULL;
char* OutputName = NULL;
char text[10000];	//将文件中的所有字符放到这里面 
int count_char;		//字符总数 
int count_line;		//分行总数 
map<string,int>mapper;	//字典 
string temp_str="";		//定义全局变量，怕返回字符串出问题

bool is_word(string str)
{
	//这个字符串处理过，里面只包含字母与数字 
	int str_length = str.length();
	//如果长度小于4则返回假 
	if ( str_length < 4 )
	{
		return false;
	}
	int i=0;
	while (i<str_length)
	{
		if ( str[i] <='z'&& str[i] >='a')
		{
			if ( i==3 )
			{
				//前三个字符都是字母，而且当前字符也是，符合条件
				//cout<<"right "<<temp_str<<endl<<endl;
				return true;
				break; 
			}
		}
		else
		{
			//前四个字符中存在数字 
			return false;
			break;
		}
		i++;
	}
}

int find_nextmbegin(int mbegin)
{
	for( int i=mbegin+1 ; i<count_char ; i++ )
	{
		if ((!(( text[i] >= 'a' && text[i] <= 'z' ) || (text[i] >= '0' && text[i] <='9' ))) && (( text[i+1] >= 'a' && text[i+1] <= 'z' ) || (text[i+1] >= '0' && text[i+1] <='9' )))
		{
			//i这是不符合条件的位置
			//且i+1位置必须符合条件，防止多个不符合条件的位置连续 
			//cout<<"nextmbegin "<<i+1<<endl;
			return i+1;
		}
	}
	return -1;//-1代表没有下一个符合条件的位置 
}

int find_nextbegin(int begin)
{
	for( int i=begin+1 ; i<count_char ; i++ )
	{
		if ( text[i]==' ' && (( text[i+1] >= 'a' && text[i+1] <= 'z' ) || (text[i+1] >= '0' && text[i+1] <='9' )))
		{
			//i这是不符合条件的位置
			//且i+1位置必须符合条件，防止多个不符合条件的位置连续 
			//cout<<"next*begin "<<i+1<<endl;
			return i+1;
		} else if ( (!(( text[i] >= 'a' && text[i] <= 'z' ) || (text[i] >= '0' && text[i] <='9' ))) && text[i] != ' ')
		{
			cout<<"词组被打断"<<endl;
		}
	}
	return -1;//-1代表没有下一个符合条件的位置
} 

void combine_str(int begin, int end)
{
	temp_str="";
	for(int i=begin ; i<=end ; i++)
	{
		temp_str=temp_str+text[i];
	}
	//cout<<"begin "<<begin<<" end "<<end<<" temp_str "<<temp_str<<endl;
	return; 
}

void turn_lowercase_and_WordLine_count()
{
	memset(text,0,sizeof(text));
	count_char=0;
	count_line=0;
	freopen(InputName,"r",stdin);
	char c;
	c=getchar();
	int posi=0;
	while( c!=EOF){
		if(c >= 'A' && c <= 'Z')
        {
            c += 32;
        }
        if(c == '\n')
        {
            count_line++;
        }
        if(c>=0&&c<=255)//判断是否在ASCII码的范围内
			count_char++;
		text[posi]=c;
		c=getchar();
		posi++;
	}
    cout<<"characters: "<<count_char-count_line<<endl<<"words: "<<endl<<"lines: "<<count_line+1<<'\n';
    //fclose(fp1);
    fclose(stdin);
	
	fp1 = fopen(InputName, "w");
		if (fp1 == NULL)
			return;
		fprintf(fp1,text);
	fclose(fp1);
	/*fstream input;
	input.open(InputName);*/
	/*fp1 = fopen(InputName, "r");
	if (fp1 == NULL) //
		return;*/
	//if(!input.good())	cout<<"文件打开失败！"<<endl;
	
    /*while ( !feof(fp1) )
    {
        c=input.get();//从文件中读取一个字符 
        if (c=='\n'||c=='\0') continue;
        if(isupper(c))//判断该字符是否为大写字母 ；若是，则改为小写字母且重新写入文件中 
        {
        	c+=32;
        	input.seekg(-1,ios::cur);   //将文件指针指向当前位置向开头方向偏移1的位置 
        	input<<c;
        }
        if(c>=0&&c<=255)//判断是否在ASCII码的范围内 
			count++;*/
		/*c = fgetc(fp1);
        if( c != EOF )
        {
            if(c >= 'A' && c <= 'Z')
            {
                c += 32;
            }
            if(c == '\n')
            {
                count_line++;
                count--;
            }
            if(c>=0&&c<=255)//判断是否在ASCII码的范围内 
				count++;
        }
    }*/
}

void get_cmd(int argc, char *argv[])
{
	string ms = "-m", ns = "-n", cs= "-i", ds="-o";
	for (int i = 1; i < argc; i++ )
	{
		if (argv[i] == ms)
		{
			flagm=true;
			m = argv[++i][0] - '0';
		}
		else if (argv[i] == ns)
		{
			n = argv[++i][0] - '0';
		}
		else if (argv[i] == cs)
		{
			InputName = argv[++i];
		}
		else if (argv[i] == ds)
		{
			OutputName = argv[++i];
		}
	}
}

void solve_word(int m)
{
	int space = m-1; //允许词组空格数
	int begin=0;
	int mbegin=0;
	int end=0;
	for(int i=0;i<=count_char;)
	{
		temp_str="";
		//是字母或数字 
		if((text[i]>='0' && text[i]<='9') || (text[i]>='a' && text[i]<='z'))
		{
			i++;
		}
		//空格,且前面一格符合条件 
		else if(((text[i-1]>='0' && text[i-1]<='9') || (text[i-1]>='a' && text[i-1]<='z')) && text[i]==' ')
		{
			end=i-1;
			temp_str="";//清空字符数组 
			combine_str(begin,end);
			//begin-end是词语
			if(is_word(temp_str))
			{
				space--;
				if(space<0)
				{
					temp_str="";//清空字符数组 
					combine_str(mbegin,end);
					cout<<temp_str<<"符合条件"<<endl<<endl;
					//
					//mbegin~end放入字符串
					//开头位置mbegin，结尾end 
					//此时的 temp_str 是一个词组！
					//俊宇你对这里的 temp_str 进行操作
					//然后频率+1
					// 
					//begin等于下一个起点 
					begin=find_nextmbegin(mbegin);
					//重置允许空格数进入准备下一次查找
					i=begin;
					mbegin=begin;
					space=m-1;
				}
				else
				{
					//这里指还未结束，所以下一个寻找的不是mbegin 
					begin=find_nextbegin(begin);
					i=begin;
				}
			}
			//begin-end不是词语 
			else
			{
				begin=find_nextmbegin(mbegin);
				i=begin;
				mbegin=begin;
				//
				space = m-1;
				//
			}
		}
		//回车或其它，且前面一格符合条件 
		else if( ((text[i-1]>='0' && text[i-1]<='9') || (text[i-1]>='a' && text[i-1]<='z')) && !((text[i]>='0' && text[i]<='9') || (text[i]>='a' && text[i]<='z')))
		{
			end=i-1;
			temp_str="";//清空字符数组 
			combine_str(begin,end);
			if(is_word(temp_str))
			{
				if(space<=0)
				{
					temp_str="";//清空字符数组 
					combine_str(mbegin,end);
					cout<<temp_str<<"符合条件"<<endl<<endl;
					//
					//mbegin-end放入字符串
					//开头位置mbegin，结尾end 
					//此时的 temp_str 是一个词组！
					//俊宇你对这里的 temp_str 进行操作
					//然后频率+1
					// 
					//begin等于下一个起点 
					begin=find_nextmbegin(mbegin);
					i=begin;
					mbegin=begin;
					//重置允许空格数进入准备下一次查找 
					space=m-1;
				}
				else
				{
					begin=find_nextmbegin(mbegin);
					i=begin;
					mbegin=begin;
					//
					space = m-1;
					//
				}
			}
			else
			{
				begin=find_nextmbegin(mbegin);
				i=begin;
				mbegin=begin;
				//
				space = m-1;
				//
			}
		}
		//cout<<i<<endl;
		if ( i==-1 ) break;
	} 
} 

int main(int argc, char *argv[])
{
	get_cmd(argc,  argv); //获取命令行中文件名和参数 
	turn_lowercase_and_WordLine_count();//转小写和记录字符数和记录行数 
	solve_word(m);
	return 0;
} 
