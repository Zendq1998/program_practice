//
//  main.cpp
//  1013.数素数
//
//  Created by 1 on 2017/12/5.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int M;
    int N;
    int uper;
    cin>>M;
    cin>>N;
    if (N >= 6) {
        uper = N * log(N) + N * log(log(N));
    }
    else {
        uper = 11;
    }
    int test[uper];
    for(int i=0;i<=uper;i++) {
        test[i] = i;
    }
    for(int i=2;i*i<=uper;i++) {
        if(test[i]) {
            for(int j=2*i;j<=uper;j+=i) {
                test[j] = 0;
            }
        }
    }
    int sum = 0;
    int row = 0;
    for(int i=2;i<=uper;i++) {
        if(test[i]){
            sum++;
            if(sum>=M && sum<N) {
                cout<<test[i];
                row++;
                if(row < 10) {
                    cout<<' ';
                }
                else if(row >= 10) {
                    cout<<endl;
                    row = 0;
                }
            }
            if(sum == N) {
                if(row == 10) {
                    cout<<endl;
                    row = 0;
                }
                cout<<test[i];
            }
        }
    }
    return 0;
}
