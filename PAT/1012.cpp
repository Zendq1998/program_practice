//
//  main.cpp
//  1012数字分类
//
//  Created by 1 on 2017/12/5.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct A1{
    int sum = 0;
    bool exist = false;
};

struct A2{
    int stagger = 0;
    bool plus = true;
    bool exist = false;
};

struct A3{
    int num = 0;
    bool exist = false;
};

struct A4{
    int sum = 0;
    int num = 0;
    float ave;
    bool exist = false;
};

struct A5 {
    int max;
    bool exist = false;
};

int main() {
    int N;
    cin>>N;
    int test[N];
    A1 a1;
    A2 a2;
    A3 a3;
    A4 a4;
    A5 a5;
    for(int i=0;i<N;i++) {
        cin>>test[i];
        switch (test[i]%5) {
            case 0: {
                if(test[i] % 2 == 0) {
                    if(!a1.exist) {
                        a1.exist = true;
                    }
                    a1.sum += test[i];
                }
                break;
            }
            case 1: {
                if (!a2.exist) {
                    a2.exist = true;
                }
                a2.plus? a2.stagger += test[i] : a2.stagger -=test[i];
                a2.plus = !a2.plus;
                break;
            }
            case 2: {
                if (!a3.exist) {
                    a3.exist = true;
                }
                a3.num ++;
                break;
            }
            case 3: {
                if(!a4.exist) {
                    a4.exist = true;
                }
                a4.sum += test[i];
                a4.num ++;
                break;
            }
            case 4: {
                if(!a5.exist) {
                    a5.exist = true;
                    a5.max = test[i];
                }
                if(test[i]>a5.max) {
                    a5.max = test[i];
                }
                break;
            }
            default:
                break;
        }
        a4.ave = (float)a4.sum/a4.num;
    }
    a1.exist? cout<<a1.sum : cout<<'N';
    cout<<' ';
    a2.exist? cout<<a2.stagger : cout<<'N';
    cout<<' ';
    a3.exist? cout<<a3.num : cout<<'N';
    cout<<' ';
    a4.exist? cout<<fixed<<setprecision(1)<<a4.ave : cout<< 'N';
    cout<<' ';
    a5.exist? cout<<a5.max : cout<<'N';
    return 0;
}
