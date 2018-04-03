//
//  main.cpp
//  1009说反话
//
//  Created by 1 on 2017/12/4.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    string Speak;
    string Reserve;
    getline(cin,Speak);
    long n = Speak.length();
    long a = 0;
    long b = 0;
    for(int i=0;i<n;i++){
        if(Speak[i] == ' ') {
            b = i - a;
            string temp = Speak.substr(a,b);
            if(Reserve.length() == 0){
                Reserve = temp;
            }
            else{
             Reserve = temp + ' ' + Reserve;
            }
            a = i + 1;
        }
        if(i == n-1) {
            b = n - a;
            string temp = Speak.substr(a,b);
            if(Reserve.length() == 0) {
                Reserve = temp;
            }
            else {
                Reserve = temp + ' ' + Reserve;
            }
        }
    }
    cout<<Reserve;
}
