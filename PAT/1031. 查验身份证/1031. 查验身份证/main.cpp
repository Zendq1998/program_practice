//
//  main.cpp
//  1031. 查验身份证
//
//  Created by 1 on 2017/12/14.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
using namespace std;

int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int M[11] = {'1','0','X','9','8','7','6','5','4','3','2'};

bool isTureId(string a);
int main() {
    int N;
    cin>>N;
    bool Trueid[N];
    string ID[N];
    int notpass = 0;
    for (int i=0; i<N; i++) {
        cin>>ID[i];
        if (isTureId(ID[i])) {
            Trueid[i] = true;
        }
        else {
            Trueid[i] = false;
            notpass ++;
        }
    }
    if (!notpass) {
        cout<<"All passed";
        return 0;
    }
    int n=0;
    for (int i=0; i<N; i++) {
        if (!Trueid[i]) {
            cout<<ID[i];
            n++;
            if (n < notpass) {
                cout<<endl;
            }
        }
    }
    return 0;
}

bool isTureId(string a) {
    int sum = 0;
    for (int i=0; i<17; i++) {
        if (a[i] >= '0' && a[i] <= '9') {
            sum += (a[i] - 48) * weight[i];
        }
        else {
            return false;
        }
    }
    int z = sum % 11;
    if (M[z] == a[17]) {
        return true;
    }
    return false;
}
