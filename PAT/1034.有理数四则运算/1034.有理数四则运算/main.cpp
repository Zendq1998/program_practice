//
//  main.cpp
//  1034.有理数四则运算
//
//  Created by 1 on 2018/8/8.
//  Copyright © 2018年 zendq1998. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

// 字符串转换为整数
long strToInt(string str) {
    if (str[0] == '-') {
        // 如果是个负数
        return - stol(str.substr(1, str.length() - 1));
    }
    return stol(str);
}

long division(long a, long b) {
    // 求a b最大公约数
    if (a == b) {
        return a;
    }
    else if (a > b) {
        return division(a - b, b);
    }
    else {
        return division(b - a, a);
    }
}

string posiiveFracToStr(long a, long b) {
    // 两个正数转化为对应格式分数
    if (a < 0) {
        a = 0 - a;
    }
    if (b < 0) {
        b = 0 - b;
    }
    string result = "";
    if (a / b > 0) {
        // 存在整数k部分
        result += to_string(a / b);
        if (a % b > 0) {
            // 还有余数
            long c = a % b;
            result += " " +  to_string(c / division(c, b)) + "/" + to_string(b / division(c, b));
        }
    }
    else {
        // 不存在整数k部分
        result += to_string(a / division(a, b)) + "/" + to_string(b / division(a, b));
    }
    return result;
}

string fracToStr(long a, long b) {
    // a是分子，b是分母 转化为对应格式的字符串
    if (a == 0) {
        return "0";
    }
    if (b == 0) {
        return "Inf";
    }
    if (a * b > 0) {
        //  化简后是正数
        if (a < 0 && b < 0) {
            // 都是负数
            return posiiveFracToStr(-a, -b);
        }
        return  posiiveFracToStr(a, b);
    }
    else {
        // 化简后是负数
        string result = "(-";
        if (a < 0) {
            a = 0 -a;
        }
        if (b < 0) {
            b = 0 -b;
        }
        result += posiiveFracToStr(a, b) + ")";
        return result;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    string a1, a2, b1, b2;
    string x, y;
    cin>>x;
    cin>>y;
    a1 = x.substr(0, x.find("/"));
    b1 = x.substr(x.find("/") + 1);
    a2 = y.substr(0, y.find("/"));
    b2 = y.substr(y.find("/") + 1);
    long a1_int = strToInt(a1), b1_int = strToInt(b1),
        a2_int = strToInt(a2), b2_int = strToInt(b2);
    string x_str = fracToStr(a1_int, b1_int);
    string y_str = fracToStr(a2_int, b2_int);
//    加法
    string result_plus = fracToStr(a1_int*b2_int+a2_int*b1_int, b1_int*b2_int);
//    减法
    string result_minus = fracToStr(a1_int*b2_int-a2_int*b1_int, b1_int*b2_int);
//    乘法
    string result_mult = fracToStr(a1_int*a2_int, b1_int*b2_int);
//    除法
    string result_divi = fracToStr(a1_int*b2_int, b1_int*a2_int);
    cout<<x_str<<" + "<<y_str<<" = "<<result_plus<<endl;
    cout<<x_str<<" - "<<y_str<<" = "<<result_minus<<endl;
    cout<<x_str<<" * "<<y_str<<" = "<<result_mult<<endl;
    cout<<x_str<<" / "<<y_str<<" = "<<result_divi;
    return 0;
}
