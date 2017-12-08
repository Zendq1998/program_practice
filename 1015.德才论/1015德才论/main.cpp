//
//  main.cpp
//  1015德才论
//
//  Created by 1 on 2017/12/7.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Grade {
    int Sno;
    int moral;
    int talent;
};
typedef Grade TElemType;
typedef struct BiNode{
    TElemType data;
    struct BiNode *lchild;
    struct BiNode *rchild;
} BiNode,*BiTree;

bool CompareGrade (Grade a, Grade b);
void InsertBiNode (BiTree &head,TElemType e);
bool InOrderBiTree (BiTree BT,int min);
int MinBiTree(BiTree BT);


int main() {
    int N,L,H;
    cin>>N;
    cin>>L;
    cin>>H;
    BiTree A = NULL;
    BiTree B = NULL;
    BiTree C = NULL;
    BiTree D = NULL;
    int num = 0;
    for (int i = 0; i < N; i ++) {
        Grade Stu;
        cin>>Stu.Sno;
        cin>>Stu.moral;
        cin>>Stu.talent;
        if (Stu.moral < L || Stu.talent <L) {
            continue;
        }
        num ++;
        if (Stu.moral >= H && Stu.talent >= H) {
            InsertBiNode(A,Stu);
        }
        else if (Stu.moral >= H && Stu.talent <= H) {
            InsertBiNode(B,Stu);
        }
        else if (Stu.moral <= H && Stu.talent <= H
                 && Stu.moral >= Stu.talent) {
            InsertBiNode(C,Stu);
        }
        else {
            InsertBiNode(D,Stu);
        }
    }
    cout<<num;
    if (A) {
        cout<<endl;
        InOrderBiTree(A, MinBiTree(A));
    }
    if (B) {
        cout<<endl;
        InOrderBiTree(B, MinBiTree(B));
    }
    if (C) {
        cout<<endl;
        InOrderBiTree(C, MinBiTree(C));
    }
    if (D) {
        cout<<endl;
        InOrderBiTree(D, MinBiTree(D));
    }
    return 0;
}

bool CompareGrade (Grade a, Grade b) {
    if (a.moral + a.talent > b.moral + b.talent) {
        return true;
    }
    else if (a.moral + a.talent < b.moral + b.talent) {
        return false;
    }
    else {
        if (a.moral > b.moral) {
            return true;
        }
        else if (a.moral < b.moral) {
            return false;
        }
        else {
            if (a.Sno < b.Sno) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}//按照题目要求比较两个学生成绩的大小

void InsertBiNode (BiTree &head,TElemType e) {
    if (!head) {
        BiTree BT = (BiTree)malloc(sizeof(BiNode));
        BT->data = e;
        BT->rchild = NULL;
        BT->lchild = NULL;
        head = BT;
    }
    else {
        if (CompareGrade(head->data,e)) {
            InsertBiNode(head->rchild,e);
        }
        else {
            InsertBiNode(head->lchild,e);
        }
    }
}//将一个学生成绩的结点按照二叉排序树的顺序插入到head树中（分数高的放左）

bool InOrderBiTree (BiTree BT,int min) {
    if (BT) {
        InOrderBiTree(BT->lchild,min);
        cout<<BT->data.Sno<<' '<<BT->data.moral<<' '<<BT->data.talent;
        if (BT->data.Sno != min) {
            cout<<endl;
        }
        InOrderBiTree(BT->rchild,min);
        return true;
    }
    else {
        return false;
    }
}//按照中序（从大到小）遍历一棵学生成绩树,输出一行学生的成绩，若不是最后一名就换行


int MinBiTree(BiTree BT) {
    BiTree T = BT;
    while (T->rchild) {
        T = T->rchild;
    }
    return T->data.Sno;
}//找到一棵树中排名最低的那个人的学号
