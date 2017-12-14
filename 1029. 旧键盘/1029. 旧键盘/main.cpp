//
//  main.cpp
//  1029. 旧键盘
//
//  Created by 1 on 2017/12/14.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
using namespace std;

bool compchar(char a,char b);

int main() {
    string inp,outp;
    cin>>inp>>outp;
    for (int i=0; i<inp.length(); i++) {
        bool rept = false;
        for (int j=0; j<i; j++) {
            if (compchar(inp[j],inp[i])) {
                rept = true;
                break;
            }
        }
        if (rept) {
            continue;
        }
        for (int j=0; j<outp.length(); j++) {
            if (compchar(inp[i], outp[j])) {
                rept = true;
                break;
            }
        }
        if (!rept) {
            if (inp[i] >= 'a' && inp[i] <= 'z') {
                inp[i] -= 32;
            }
            cout<<inp[i];
        }
    }
    return 0;
}

bool compchar(char a,char b) {
    if (a == b) {
        return true;
    }
    if (a >= 'A' && a <= 'Z') {
        if (a + 32 == b) {
            return true;
        }
    }
    if (a >= 'a' && a <= 'z') {
        if (a - 32 == b) {
            return true;
        }
    }
    return false;
}
