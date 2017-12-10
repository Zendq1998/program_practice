//
//  main.cpp
//  1024. 科学计数法
//
//  Created by 1 on 2017/12/10.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string A;
    cin>>A;
    bool positive_num = true;
    bool positive_pow = true;
    if (A[0] == '-') {
        positive_num = false;
    }
    string  Num = "";
    string Pow = "";
    bool power = false;
    for (int i=1; i<A.length(); i++) {
        if (!power) {
            if (i == 2) {
                continue;
            }
            if (A[i] == 'E') {
                power = true;
                continue;
            }
            Num += A[i];
        }
        if (power) {
            if (A[i] == '+') {
                positive_pow = true;
            }
            else if (A[i] == '-') {
                positive_pow = false;
            }
            else {
                Pow += A[i];
            }
        }
    }
    int Pow_num = stoi(Pow);
    if (Pow_num == 0) {
        string Num0 = "";
        for (int i=1; A[i] != 'E'; i++) {
            Num0 += A[i];
        }
        if (!positive_num) {
            Num0 = '-' + Num0;
        }
        cout<<Num0;
        return 0;
    }
    int dec = Num.length() - 1;
    if (positive_pow) {
        for (int i=0; i<Pow_num-dec; i++) {
            Num += '0';
        }
    }
    else {
        for(int i=0; i<Pow_num-1; i++) {
            Num = '0' + Num;
        }
        Num = "0." + Num;
    }
    if (!positive_num) {
        Num = '-' + Num;
    }
    cout<<Num;
    return 0;
}
