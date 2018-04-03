//
//  main.cpp
//  1014.福尔摩斯的约会
//
//  Created by 1 on 2017/12/5.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string A1;
    string A2;
    string B1;
    string B2;
    cin>>A1;
    cin>>A2;
    cin>>B1;
    cin>>B2;
    
    int lena1 = A1.length();
    int lena2 = A2.length();
    int lenb1 = B1.length();
    int lenb2 = B2.length();
    
    int week = 0;
    int hour;
    int munite;
    
    for(int i=0;i<lena1&&i<lena2;i++) {
        if(!week && A1[i] == A2[i] && A1[i] >= 'A' && A1[i] <= 'G') {
            week = A1[i] - 64;
            switch (week) {
                case 1:
                    cout<<"MON ";
                    break;
                case 2:
                    cout<<"TUE ";
                    break;
                case 3:
                    cout<<"WED ";
                    break;
                case 4:
                    cout<<"THU ";
                    break;
                case 5:
                    cout<<"FRI ";
                    break;
                case 6:
                    cout<<"SAT ";
                    break;
                case 7:
                    cout<<"SUN ";
                    break;
                default:
                    break;
            }
            continue;
        }
        if(week && A1[i] == A2[i]) {
            if (A1[i] >= '0' && A1[i] <= '9') {
                hour = A1[i] - 48;
                cout<<setw(2)<<setfill('0')<<hour<<':';
                break;
            }
            if(A1[i] >= 'A' && A1[i] <= 'N') {
                hour = A1[i] - 55;
                cout<<setw(2)<<setfill('0')<<hour<<":";
                break;
            }
        }
    }
    
    for(int i=0;i<lenb1&&i<lenb2;i++) {
        if(B1[i] == B2[i] && ((B1[i] >= 'A' && B1[i] <= 'Z') || (B1[i] >= 'a' && B1[i] <= 'z'))) {
            cout<<setw(2)<<setfill('0')<<i;
            break;
        }
    }
    return 0;
}
