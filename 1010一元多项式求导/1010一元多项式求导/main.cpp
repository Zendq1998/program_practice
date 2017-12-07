//
//  main.cpp
//  1010一元多项式求导
//
//  Created by 1 on 2017/12/4.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Node{
    int coef; //单项式的系数coefficient
    int index; //x的指数index
    struct Node *next;
} formula,*pony;
//单项式formula ，多项式指针poly


void Initformula(pony &p); //初始化
void derivation (pony &p); //求导

int main() {
    pony head;
    Initformula(head);
    pony q = head;
    while(1) {
        pony p;
        Initformula(p);
        cin>>p->coef;
        cin>>p->index;
        if(p->index * p->coef == 0 && p->index + p->coef != 0 && p->index != 1) {
            free(p);
        }
        else {
            q->next = p;
            q = p;
        }
        if(getchar() == '\n') {
            break;
        }//遇到回车结束
    }
    derivation(head->next);
    pony p = head->next;
    while(p) {
        cout<<p->coef;
        cout<<' ';
        cout<<p->index;
        if(p->next) {
            cout<<' ';
        }
        p = p->next;
    }
    return 0;
}

void Initformula(pony &p) {
    p = (formula *)malloc(sizeof(formula));
    if(!p) exit(1);
    p->next = NULL;
}

void derivation (pony &p) {
    pony q = p;
    while(q) {
        q->coef = q->coef * q->index;
        if (q->index != 0) {
            q->index--;
        }
        q = q->next;
    }
    
}


