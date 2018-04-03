#include <stdio.h>
#include <string.h>
int if_only_PAT(char *str){
	int i,p=0,t=0,a=0;
	for(i=0;i<strlen(str);i++){
		if(str[i]!='P'&&str[i]!='A'&&str[i]!='T')
			return 0;
		if(str[i]=='P'&&t==0)
			p++;
		if(str[i]=='A')
			a++;
		if(str[i]=='T')
			t++;
	}
	if(p==1&&a>0&&t==1)
		return 1;
	else
		return 0;
}

int main(){
	int n;//循环的次数n 
	int l,r,m;//左右中间的A的数量
	char str[9][100];//储存n次输入的字符串 
	int i;//循环次数的计数器 
	scanf("%d",&n);
	fflush(stdin);
	for(i=0;i<n;i++){
		gets(str[i]);
		fflush(stdin);
	}//输入n次字符串 
	for(i=0;i<n;i++){
		if(!if_only_PAT(str[i])){
			printf("NO");
			if(i!=n-1)
				printf("\n");
			continue;
		}
		l=strchr(str[i],'P')-str[i];
		r=strlen(str[i])-(strchr(str[i],'T')-str[i]+1); 
		m= strchr(str[i],'T')-strchr(str[i],'P')-1;
		if(l==0&&r==0)
			printf("YES");
		else if(r%l==0&&r/l==m)
			printf("YES");
		else printf("NO");
		if(i!=n-1)
				printf("\n");
	}
} 
