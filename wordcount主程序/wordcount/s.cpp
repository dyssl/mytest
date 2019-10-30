#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <queue>
#include <map>
using namespace std;
bool flagm=false;	//Ĭ�ϲ����д����Ƶͳ��
int m=1;			//Ĭ�ϴ��鵥����Ϊ1 
int n=10;			//Ĭ�������Ƶǰ10λ 
FILE* fp1;			//���ڶ�ȡ���ļ� 
FILE* fp2;			//����д����ļ� 
char* InputName = NULL;
char* OutputName = NULL;
char text[10000];	//���ļ��е������ַ��ŵ������� 
int count_char;		//�ַ����� 
int count_line;		//�������� 
map<string,int>mapper;	//�ֵ� 
string temp_str="";		//����ȫ�ֱ������·����ַ���������

bool is_word(string str)
{
	//����ַ��������������ֻ������ĸ������ 
	int str_length = str.length();
	//�������С��4�򷵻ؼ� 
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
				//ǰ�����ַ�������ĸ�����ҵ�ǰ�ַ�Ҳ�ǣ���������
				//cout<<"right "<<temp_str<<endl<<endl;
				return true;
				break; 
			}
		}
		else
		{
			//ǰ�ĸ��ַ��д������� 
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
			//i���ǲ�����������λ��
			//��i+1λ�ñ��������������ֹ���������������λ������ 
			//cout<<"nextmbegin "<<i+1<<endl;
			return i+1;
		}
	}
	return -1;//-1����û����һ������������λ�� 
}

int find_nextbegin(int begin)
{
	for( int i=begin+1 ; i<count_char ; i++ )
	{
		if ( text[i]==' ' && (( text[i+1] >= 'a' && text[i+1] <= 'z' ) || (text[i+1] >= '0' && text[i+1] <='9' )))
		{
			//i���ǲ�����������λ��
			//��i+1λ�ñ��������������ֹ���������������λ������ 
			//cout<<"next*begin "<<i+1<<endl;
			return i+1;
		} else if ( (!(( text[i] >= 'a' && text[i] <= 'z' ) || (text[i] >= '0' && text[i] <='9' ))) && text[i] != ' ')
		{
			cout<<"���鱻���"<<endl;
		}
	}
	return -1;//-1����û����һ������������λ��
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
        if(c>=0&&c<=255)//�ж��Ƿ���ASCII��ķ�Χ��
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
	//if(!input.good())	cout<<"�ļ���ʧ�ܣ�"<<endl;
	
    /*while ( !feof(fp1) )
    {
        c=input.get();//���ļ��ж�ȡһ���ַ� 
        if (c=='\n'||c=='\0') continue;
        if(isupper(c))//�жϸ��ַ��Ƿ�Ϊ��д��ĸ �����ǣ����ΪСд��ĸ������д���ļ��� 
        {
        	c+=32;
        	input.seekg(-1,ios::cur);   //���ļ�ָ��ָ��ǰλ����ͷ����ƫ��1��λ�� 
        	input<<c;
        }
        if(c>=0&&c<=255)//�ж��Ƿ���ASCII��ķ�Χ�� 
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
            if(c>=0&&c<=255)//�ж��Ƿ���ASCII��ķ�Χ�� 
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
	int space = m-1; //�������ո���
	int begin=0;
	int mbegin=0;
	int end=0;
	for(int i=0;i<=count_char;)
	{
		temp_str="";
		//����ĸ������ 
		if((text[i]>='0' && text[i]<='9') || (text[i]>='a' && text[i]<='z'))
		{
			i++;
		}
		//�ո�,��ǰ��һ��������� 
		else if(((text[i-1]>='0' && text[i-1]<='9') || (text[i-1]>='a' && text[i-1]<='z')) && text[i]==' ')
		{
			end=i-1;
			temp_str="";//����ַ����� 
			combine_str(begin,end);
			//begin-end�Ǵ���
			if(is_word(temp_str))
			{
				space--;
				if(space<0)
				{
					temp_str="";//����ַ����� 
					combine_str(mbegin,end);
					cout<<temp_str<<"��������"<<endl<<endl;
					//
					//mbegin~end�����ַ���
					//��ͷλ��mbegin����βend 
					//��ʱ�� temp_str ��һ�����飡
					//������������ temp_str ���в���
					//Ȼ��Ƶ��+1
					// 
					//begin������һ����� 
					begin=find_nextmbegin(mbegin);
					//��������ո�������׼����һ�β���
					i=begin;
					mbegin=begin;
					space=m-1;
				}
				else
				{
					//����ָ��δ������������һ��Ѱ�ҵĲ���mbegin 
					begin=find_nextbegin(begin);
					i=begin;
				}
			}
			//begin-end���Ǵ��� 
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
		//�س�����������ǰ��һ��������� 
		else if( ((text[i-1]>='0' && text[i-1]<='9') || (text[i-1]>='a' && text[i-1]<='z')) && !((text[i]>='0' && text[i]<='9') || (text[i]>='a' && text[i]<='z')))
		{
			end=i-1;
			temp_str="";//����ַ����� 
			combine_str(begin,end);
			if(is_word(temp_str))
			{
				if(space<=0)
				{
					temp_str="";//����ַ����� 
					combine_str(mbegin,end);
					cout<<temp_str<<"��������"<<endl<<endl;
					//
					//mbegin-end�����ַ���
					//��ͷλ��mbegin����βend 
					//��ʱ�� temp_str ��һ�����飡
					//������������ temp_str ���в���
					//Ȼ��Ƶ��+1
					// 
					//begin������һ����� 
					begin=find_nextmbegin(mbegin);
					i=begin;
					mbegin=begin;
					//��������ո�������׼����һ�β��� 
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
	get_cmd(argc,  argv); //��ȡ���������ļ����Ͳ��� 
	turn_lowercase_and_WordLine_count();//תСд�ͼ�¼�ַ����ͼ�¼���� 
	solve_word(m);
	return 0;
} 
