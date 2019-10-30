#include <stdio.h>
#include <string.h>
 
int main(void)  
{  
        char str[] = "2015-3-22 abcd efg hij klmn opq##rst,uvw,xyz,tao";/*待分隔的原字符串*/  
        char *s=str;
        
        while(*s)
        {
        	if (*s<'0' || (*s>'9' && *s<'A') || (*s>'Z' && *s<'a') || *s>'z')
        	{
        		*s=' ';
        	}
        	s ++;
        }
        char seg[] = " "; /*分隔符这里为逗号comma，分隔符可以为你指定的，如分号，空格等*/
		char charlist[50][50]={""};/*指定分隔后子字符串存储的位置，这里定义二维字符串数组*/
        int i = 0;
        char *substr= strtok(str, seg);/*利用现成的分割函数,substr为分割出来的子字符串*/
  
        while (substr != NULL) {  
				strcpy(charlist[i],substr);/*把新分割出来的子字符串substr拷贝到要存储的charlsit中*/
				i++;
                 
                substr = strtok(NULL,seg);/*在第一次调用时，strtok()必需给予参数str字符串，
				往后的调用则将参数str设置成NULL。每次调用成功则返回被分割出片段的指针。*/
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
