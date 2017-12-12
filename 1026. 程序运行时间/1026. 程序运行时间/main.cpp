//
//  main.cpp
//  1026. 程序运行时间
//
//  Created by 1 on 2017/12/12.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int cLK_TCK = 100;
    int C1;
    int C2;
    cin>>C1>>C2;
    int us = C2 - C1;
    int s;
    if (us % cLK_TCK >= 50) {
        s = us / cLK_TCK + 1;
    }
    else {
        s = us / cLK_TCK;
    }
    int hh = s / 3600;
    int mm = (s % 3600) / 60;
    int ss = (s % 3600) % 60;
    
    cout<<setw(2)<<setfill('0')<<hh<<':'<<setw(2)<<setfill('0')<<mm<<':'<<setw(2)<<setfill('0')<<ss;
    return 0;
}
