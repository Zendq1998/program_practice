//
//  main.cpp
//  PAT
//
//  Created by 1 on 2017/12/3.
//  Copyright © 2017年 1. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;
bool Prime(int max,int *array);

int main() {
    int max;
    cin>>max;
    int prime[max];
    int couple = 0;
    int temp = 2;
    if(Prime(max,prime)) {
        for(int i = 2;i<=max;i++) {
            if(prime[i]>0) {
                if(prime[i] - temp == 2) {
                    couple++;
                }
                temp = prime[i];
            }
            
        }
    }
    cout<<couple;
}

bool Prime(int max,int *array) {
    if(max<2)
        return false;
    for(int i = 0;i<=max;i++) {
        array[i] = i;
    }
    int prime = 2;
    while(prime*prime<=max) {
        for(int index = prime*2;index<=max;index+=prime) {
            array[index] = 0;
        }
        for(prime++;prime*prime<=max;prime++) {
            if(array[prime]>0)
                break;
        }
    }
    return true;
}
