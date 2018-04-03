#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
int main() {
	int numout=0; //定义输出的结果（整型）
	char str[100],strout[3];//定义输入的10的10次方一下自然数（字符串）和输出的结果（字符串） 
	int i;
	gets(str);//键盘接收字符串直到换行键 
	for(i=0;i<strlen(str);i++){
		int a = str[i]-48;//ASCII码转换 
		numout += a;
	}//累加每一位数字 
	sprintf(strout, "%ld", numout);//把累加后的结果化为字符串strout 
//	printf("%s\n",strout);
	for(i=0;i<strlen(strout);i++){ //根据字符串的结果打印出对应的拼音 
		int a=strout[i]-48;
		switch(a)	
		{
			case 0:
				printf("ling");
				break;
			case 1:
				printf("yi");
				break;
			case 2:
				printf("er");
				break; 
			case 3:
				printf("san");
				break; 
			case 4:
				printf("si");
				break; 
			case 5:
				printf("wu");
				break;
			case 6:
				printf("liu");
				break; 
			case 7:
				printf("qi");
				break; 
			case 8:
				printf("ba");
				break; 
			case 9:
				printf("jiu");
				break; 
		}
		if(i!=strlen(strout)-1)
			printf(" ");//非最后一个数字多打印一个空格 
	}	
} 
