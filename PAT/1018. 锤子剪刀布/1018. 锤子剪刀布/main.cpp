//
//  main.cpp
//  1018. 锤子剪刀布
//
//  Created by 1 on 2017/12/8.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
using namespace std;

struct player {
    int C = 0;
    int J = 0;
    int B = 0;
    int win = 0;
    int lose = 0;
    int tie = 0;
};

int main() {
    player X,Y;
    unsigned int N;
    cin>>N;
    for (unsigned int i=0; i<N; i++) {
        char x,y;
        cin>>x;
        cin>>y;
        if (x == 'C') {
            if (y == 'C') {
                X.tie ++;
                Y.tie ++;
            }
            if (y == 'B') {
                X.lose ++;
                Y.win ++;
                Y.B ++;
            }
            if (y == 'J') {
                X.win ++;
                Y.lose ++;
                X.C ++;
            }
        }
        if (x == 'J') {
            if (y == 'C') {
                X.lose ++;
                Y.win ++;
                Y.C ++;
            }
            if (y == 'B') {
                X.win ++;
                Y.lose ++;
                X.J ++;
            }
            if (y == 'J') {
                X.tie ++;
                Y.tie ++;
            }
        }
        if (x == 'B') {
            if (y == 'C') {
                X.win ++;
                Y.lose ++;
                X.B ++;
            }
            if (y == 'B') {
                X.tie ++;
                Y.tie ++;
            }
            if (y == 'J') {
                X.lose ++;
                Y.win ++;
                Y.J ++;
            }
        }
    }
    cout<<X.win<<' '<<X.tie<<' '<<X.lose;
    cout<<endl;
    cout<<Y.win<<' '<<Y.tie<<' '<<Y.lose;
    cout<<endl;
    char max_x = 'B';
    if (X.B < X.C) {
        max_x = 'C';
        if (X.C < X.J) {
            max_x = 'J';
        }
    }
    else if (X.B < X.J) {
        max_x = 'J';
    }
    char max_y = 'B';
    if (Y.B < Y.C) {
        max_y = 'C';
        if (Y.C < Y.J) {
            max_y = 'J';
        }
    }
    else if (Y.B < Y.J) {
        max_y = 'J';
    }
    cout<<max_x<<' '<<max_y;
    return 0;
}
