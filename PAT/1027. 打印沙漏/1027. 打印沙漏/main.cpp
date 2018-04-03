//
//  main.cpp
//  1027. 打印沙漏
//
//  Created by 1 on 2017/12/13.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int N;
    cin>>N;
    char C;
    cin>>C;
    int I = 1;
    int i=1;    //最外层的的个数
    while (I+2*(i+2)<=N) {
        i += 2;
        I += 2*i;
    }
    int Y = N - I;  //余数
    for(int j=i;j>1;j-=2){
        for (int k=0; k<(i-j)/2; k++) {
            cout<<' ';
        }//空格
        for (int k=0; k<j; k++) {
            cout<<C;
        }//*
        cout<<endl;
    }
    for (int k=0; k<i/2; k++) {
        cout<<' ';
    }//空格
    cout<<C;
    for(int j=3;j<=i;j+=2){
        cout<<endl;
        for (int k=0; k<(i-j)/2; k++) {
            cout<<' ';
        }//空格
        for (int k=0; k<j; k++) {
            cout<<C;
        }//*
    }
    cout<<endl<<Y;
    return 0;
}
