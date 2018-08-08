//
//  main.cpp
//  1033.旧键盘打字
//
//  Created by 1 on 2018/8/7.
//  Copyright © 2018年 zendq1998. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

// 判断字符c是否为大写字母
bool isUpper(char c) {
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    else {
        return false;
    }
}

// 判断str中有没有‘+’
bool hasCaps(string str) {
    unsigned long index = str.find("+");
    if (index < str.length()) {
        return true;
    }
    else {
        return false;
    }
}

// 判断字符a是否可以被打印（str是坏掉的）
bool canPrint(string str, char a) {
    unsigned long index = str.find(a);
    if (index < str.length()) {
        return false;
    }
    else {
        if (a >= 'a' && a <= 'z') {
            if (str.find(a - 32) < str.length()) {
                return false;
            }
        }
        return true;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string str1, str2;
    cin>>str1;
    cin>>str2;
//    能大写（无“+”）
    if (!hasCaps(str1)) {
        for (unsigned int i = 0; i < str2.length();) {
            if (!canPrint(str1, str2[i])) {
                str2.erase(i, 1);
            }
            else {
                i ++;
            }
        }
    }
//    不能大写
    else {
        for (unsigned int i = 0; i < str2.length();) {
            if (isUpper(str2[i])) {
                str2.erase(i, 1);
                continue;
            }
            if (!canPrint(str1, str2[i])) {
                str2.erase(i, 1);
            }
            else {
                i ++;
            }
        }
    }
    if (str2.length()) {
        cout<<str2;
    }
    else {
        cout<<endl;
    }
    return 0;
}
