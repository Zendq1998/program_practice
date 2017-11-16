#include <stdio.h>
#include <stdlib.h>
# define LIST_INIT_SIZE  100              // 顺序表(默认的)的初始分配最大容量
# define LISTINCREMENT  10                // (默认的)增补空间量
typedef struct {
    int  *elem;                      // 存储数据元素的一维数组
    int length;                           // 线性表的当前长度
    int listsize;                         // 当前分配的数组容量（以int为单位）
    int incrementsize;                   // 增补空间量（以int为单位）
} SqList; 
void InitList_Sq( SqList &L, int maxsize=LIST_INIT_SIZE,
                                 int incresize=LISTINCREMENT ) 
{      // 构造一个最大容量为maxsize的顺序表 L
     L.elem=(int *)malloc(maxsize*sizeof(int));
                         // 为顺序表分配一个最大容量为 maxsize 的数组空间
     if(!L.elem)  exit(1);           // 存储分配失败
      L.length=0;                    // 顺序表中当前所含元素个数为 0
      L.listsize=maxsize;            // 该顺序表可以容纳maxsize个数据元素
      L.incrementsize=incresize;     // 需要时可扩容incresize个元素空间
}// InitList_Sq

int ListLength_Sq(SqList L)
 { 
      return L.length;
}// ListLength_Sq

int LocateElem_Sq( SqList L, int e) 
{  
   for(int i=0;i<L. length;i++)
    if(L.elem[i]==e)  return i;   // 找到满足判定的数据元素为第 i 个元素
   return -1;                     // 该线性表中不存在满足判定的数据元素
 }//LocateElem_Sq

bool ListInsert_Sq(SqList &L, int i, int e)
{   // 在顺序表L的第i个元素之前插入新的元素e，
// 若表中当前容量不足，则按预定义的增量扩容
int j;
      if(i<0||i>L.length)  return false;            // i值不合法
      if(L.length>=L.listsize)  {                   // 当前存储空间已满，增补空间
    L.elem=(int *)realloc(L.elem,(L.listsize+L.incrementsize)*sizeof(int));
         if(!L.elem) exit(1);                   // 存储分配失败
         L.listsize+=L.incrementsize;           // 当前存储容量增加
        }
         for(j=L.length;j>i;j--)                // 被插入元素之后的元素左移
L.elem[j]=L.elem[j-1];
         L.elem[i]=e;                           // 插入元素e
         L.length++;                            // 表长增1
        return true;   
}// ListInsert_Sq

int main(){
	int n,i,j=0;
	scanf("%d",&n);
	int num[n];
	SqList l;
	InitList_Sq(l);	           //初始化一个顺序表 
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);	//输入第i+1个数
		while(num[i]!=2){
			if(num[i]%2==0)
				num[i]/=2;
			else
				num[i]=(3*num[i]+1)/2;
			if(LocateElem_Sq(L, num[i])!=-1)
				 ListInsert_Sq(L, j++, num[i]);
		} 
	}
	
	for(i=0;i<sizeof(fugai(num[0]));i++){
		printf("%3d",*(fugai(num[0])+i));
	}
}
