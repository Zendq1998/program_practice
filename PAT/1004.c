#include <stdio.h>
struct Stu{
	char name[11];
	char num[11];
	int	grade;
};
int main(){
	int n,max=0,min=0,i;
	scanf("%d",&n);
	struct Stu stu[n];
	for(i=0;i<n;i++){
		scanf("%s%s%d",stu[i].name,stu[i].num,&stu[i].grade);
		if(stu[i].grade>stu[max].grade)
			max=i;
		if(stu[i].grade<stu[min].grade)
			min=i;
	}
	printf("%s %s\n",stu[max].name,stu[max].num);
	printf("%s %s",stu[min].name,stu[min].num);

}
