//
//  main.cpp
//  1030. 完美数列
//
//  Created by 1 on 2017/12/14.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    unsigned int N,p;
    cin>>N>>p;
    unsigned int l[N];
    for (unsigned int i=0; i<N; i++) {
        cin>>l[i];
    }
    sort(l, l+N);
    int max = 0;
    for (unsigned int i=0; i<N; i++) {
        for (unsigned int j=i+max; j<N; j++) {
            if (l[i]*p < l[j]) {
                break;
            }
            max ++;
        }
    }
    cout<<max;
    return 0;
}
