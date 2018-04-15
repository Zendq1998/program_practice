//
//  main.cpp
//  GSS-and-Version-Control
//
//  Created by 1 on 2018/4/15.
//  Copyright © 2018年 zendq1998. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    int states[N];
    int state_now = 0;
    for(int i=0;i<N;i++) {
        string check;
        int num;
        cin>>check;
        if(check=="commit") {
            cin>>num;
            states[i] += num;
        }
        if(check=="checkout") {
            cin>>num;
            states[i] = states[num-1];
        }
        state_now = states[i];
        cout<<state_now;
    }
    return 0;
}
