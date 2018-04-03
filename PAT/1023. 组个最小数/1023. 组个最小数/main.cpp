//
//  main.cpp
//  1023. 组个最小数
//
//  Created by 1 on 2017/12/9.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int Input[10];
    int Output[50];
    bool zero = false;
    for (int i=0; i<10; i++) {
        cin>>Input[i];
    }
    if (Input[0] > 0) {
        zero = true;
    }
    int n = 0;
    for (int i=0; i<10; i++) {
        for (int j=0; j<Input[i]; j++) {
            Output[n+j] = i;
        }
        n += Input[i];
    }
    if (!zero) {
        for (int i=0; i<n; i++) {
            cout<<Output[i];
        }
        return 0;
    }
    int i = 0;
    while (!Output[i]) {
        i ++;
    }
    int temp = Output[i];
    Output[i] = 0;
    Output[0] = temp;
    for (int i=0; i<n; i++) {
        cout<<Output[i];
    }
    return 0;
}
