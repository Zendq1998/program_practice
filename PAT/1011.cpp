//
//  main.cpp
//  1011A+B和C
//
//  Created by 1 on 2017/12/5.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

struct ABC {
    long A;
    long B;
    long C;
    bool greater = false;
};

int main() {
    int T;
    cin>>T;
    ABC test[T];
    for(int i=0;i<T;i++) {
        cin>>test[i].A;
        cin>>test[i].B;
        cin>>test[i].C;
        if(test[i].A + test[i].B > test[i].C) {
            test[i].greater = true;
        }
    }
    for(int i=0;i<T;i++) {
        cout<<"Case #"<<i+1<<": "<<(test[i].greater?"true":"false");
        if(i != T - 1) {
            cout<<endl;
        }
    }
    return 0;
}
