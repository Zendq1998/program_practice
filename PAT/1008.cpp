//
//  main.cpp
//  PAT
//
//  Created by 1 on 2017/12/3.
//  Copyright © 2017年 1. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int N;
    int M;
    cin>>N>>M;
    int A[N];
    for(int i=0;i<N;i++) {
        cin>>A[i];
    }
    for(int i=0;i<M;i++) {
        int temp;
        for(int j=1;j<N;j++) {
            temp = A[N-j];
            A[N-j] = A[N-j-1];
            A[N-j-1] = temp;
        }
    }
    for(int i=0;i<N;i++) {
        cout<<A[i];
        if(i!=N-1)
            cout<<" ";
    }
}
