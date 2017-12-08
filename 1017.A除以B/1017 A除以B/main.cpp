//
//  main.cpp
//  1017 A除以B
//
//  Created by 1 on 2017/12/8.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    string A;
    int B;
    cin>>A;
    cin>>B;
    string Q = "";
    int R;
    int Aint[A.length()];
    for (int i=0; i<A.length(); i++) {
        Aint[i] = A[i] - 48;
    }
    for (int i=0; i<A.length()-1; i++) {
        if (Aint[i] >= B) {
            char q = Aint[i] / B + 48;
            Q += q;
        }
        else if (i > 0) {
            Q += '0';
        }
        Aint[i+1] += (Aint[i] % B) * 10;
    }
    char q = Aint[A.length()-1] / B + 48;
    Q += q;
    R = Aint[A.length()-1] % B;
    cout<<Q<<' '<<R;
    
    return 0;
}
