//
//  main.cpp
//  1016部分A+B
//
//  Created by 1 on 2017/12/8.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    string A;
    string B;
    char DA;
    char DB;
    cin>>A;
    cin>>DA;
    cin>>B;
    cin>>DB;
    int a = DA - 48;
    int b = DB - 48;
    int na = 0;
    int nb = 0;
    for (int i=0; i<A.length(); i++) {
        if (A[i] == DA) {
            na ++;
        }
    }
    for (int i=0; i<B.length(); i++) {
        if (B[i] == DB) {
            nb ++;
        }
    }
    int PA = 0;
    int PB = 0;
    for (int i=0; i<na; i++) {
        PA += a * pow(10, i);
    }
    for (int i=0; i<nb; i++) {
        PB += b * pow(10, i);
    }
    cout<<PA + PB;
    return 0;
}
