#include <stdio.h>
#include <string.h>
 
int main(void)  
{  
        char str[] = "2015-3-22 abcd efg hij klmn opq##rst,uvw,xyz,tao";/*���ָ���ԭ�ַ���*/  
        char *s=str;
        
        while(*s)
        {
        	if (*s<'0' || (*s>'9' && *s<'A') || (*s>'Z' && *s<'a') || *s>'z')
        	{
        		*s=' ';
        	}
        	s ++;
        }
        char seg[] = " "; /*�ָ�������Ϊ����comma���ָ�������Ϊ��ָ���ģ���ֺţ��ո��*/
		char charlist[50][50]={""};/*ָ���ָ������ַ����洢��λ�ã����ﶨ���ά�ַ�������*/
        int i = 0;
        char *substr= strtok(str, seg);/*�����ֳɵķָ��,substrΪ�ָ���������ַ���*/
  
        while (substr != NULL) {  
				strcpy(charlist[i],substr);/*���·ָ���������ַ���substr������Ҫ�洢��charlsit��*/
				i++;
                 
                substr = strtok(NULL,seg);/*�ڵ�һ�ε���ʱ��strtok()����������str�ַ�����
				����ĵ����򽫲���str���ó�NULL��ÿ�ε��óɹ��򷵻ر��ָ��Ƭ�ε�ָ�롣*/
				//char *p = charlist;
				int j=0;
				int cou = 0;
				for(j = 0; j < i; j++)
				{
					char *p = charlist[j];
					while(*p)
					{
						if(*p<)
					}
				}
				
				
        } 
		
        return 0;  
}
