//
//  main.cpp
//  1028. 人口普查
//
//  Created by 1 on 2017/12/13.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
struct Person{
    string name;
    string birth;
    int year = 0;
    int mounth = 0;
    int day = 0;
};
bool CompAge(Person a,Person b);
int main() {
    int N;
    cin>>N;
    Person old,young,temp;
    old.year = 9999;
    young.year = 0;
    int num_alive = 0;
    for (int i=0; i<N; i++) {
        cin>>temp.name;
        cin>>temp.birth;
        temp.year = stoi(temp.birth.substr(0,4));
        if (temp.year < 1814 || temp.year > 2014) {
            continue;
        }
        temp.mounth = stoi(temp.birth.substr(5,2));
        if ((temp.year == 1814 && temp.mounth < 9) || (temp.year == 2014 && temp.mounth > 9)) {
            continue;
        }
        temp.day = stoi(temp.birth.substr(8,2));
        if ((temp.year == 1814 && temp.mounth == 9 && temp.day < 6) ||
            (temp.year == 2014 && temp.mounth == 9 && temp.day > 6)) {
            continue;
        }
        num_alive ++;
        if (CompAge(temp, young)) {
            young = temp;
        }
        if (CompAge(old, temp)) {
            old = temp;
        }
    }
    cout<<num_alive;
    if (num_alive) {
        cout<<' '<<old.name<<' '<<young.name;
    }
    return 0;
}

bool CompAge(Person a,Person b) {
    if (a.year > b.year) {
        return true;
    }
    else if (a.year < b.year) {
        return false;
    }
    else {
        if (a.mounth > b.mounth) {
            return true;
        }
        else if (a.mounth > b.mounth) {
            return false;
        }
        else {
            return a.day > b.day;
        }
    }
}
