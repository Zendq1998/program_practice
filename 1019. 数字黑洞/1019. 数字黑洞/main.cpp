//
//  main.cpp
//  1019. 数字黑洞
//
//  Created by 1 on 2017/12/8.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int decreaseNum (int num,bool decrease);

int main() {
    int N;
    cin>>N;
    if (decreaseNum (N, 0) == decreaseNum (N, 1)) {
        cout<<N<<" - "<<N<<" = 0000";
        return 0;
    }
    while (1) {
        int IN = decreaseNum (N, 0);
        int DE = decreaseNum (N, 1);
        N = DE - IN;
        cout<<DE<<" - ";
        for (int n=1000; IN<n && n>=10; n=n/10) {
            cout<<0;
        }
        cout<<IN<<" = ";
        for (int n=1000; N<n && n>=10; n=n/10) {
            cout<<0;
        }
        cout<<N;
        if (N == 6174) {
            return 0;
        }
        cout<<endl;
    }
    return 0;
}


int decreaseNum (int num,bool decrease) {
    int result = 0;
    int t[4];
    int numt = num;
    for (int i=0; i<4; i++) {
        t[i] = numt % 10;
        numt = numt / 10;
    }
    if (decrease) {
        sort(t, t+4, greater<int>());
    }
    else {
        sort(t, t+4, less<int>());
    }
    for (int i = 0; i<4; i++) {
        result = result * 10 + t[i];
    }
    return  result;
}
