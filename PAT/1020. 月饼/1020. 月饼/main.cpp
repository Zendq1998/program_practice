//
//  main.cpp
//  1020. 月饼
//
//  Created by 1 on 2017/12/9.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct cake {
    int stock;
    int totalprice;
};

bool compCake (cake A,cake B);

int main() {
    int N;
    int D;
    cin>>N;
    cin>>D;
    cake Sale[N];
    for (int i=0; i<N; i++) {
        cin>>Sale[i].stock;
    }
    for (int i=0; i<N; i++) {
        cin>>Sale[i].totalprice;
    }
    sort(Sale, Sale+N, compCake);
    int num = D;
    float profit = 0;
    for (int i=0; i<N && num > 0; i++) {
        if (Sale[i].stock < num) {
            profit += Sale[i].totalprice;
            num -= Sale[i].stock;

        }
        else {
            profit += (float(Sale[i].totalprice) / Sale[i].stock) * num;
            num = 0;
        }
    }
    cout<<fixed << setprecision(2)<<profit;
    return 0;
}


bool compCake (cake A,cake B) {
    float a = float(A.totalprice) / A.stock;
    float b = float(B.totalprice) / B.stock;
    return (a > b);
}
