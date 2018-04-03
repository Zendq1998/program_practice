//
//  main.cpp
//  1022. D进制的A+B
//
//  Created by 1 on 2017/12/9.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    unsigned int A;
    unsigned int B;
    int D;
    cin>>A;
    cin>>B;
    cin>>D;
    if (D == 10) {
        cout<<A + B;
        return 0;
    }
    string result = "";
    unsigned int AB = A + B;
    do {
        char a = AB % D + 48;
        result = a + result;
        AB /= D;
    } while (AB > 0);
    cout<<result;
    return 0;
}
