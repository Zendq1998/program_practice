//
//  main.cpp
//  1032.挖掘机技术哪家强
//
//  Created by 1 on 2018/8/7.
//  Copyright © 2018年 zendq1998. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin>>N;
    int Score[N + 1];
    memset(Score, 0, sizeof(Score));
//    将已经开辟内存空间的Score首arg2（size_t）个字节的值设为arg1（int）
    int index_temp;
    int score_temp;
    for (int i = 0; i < N; i ++) {
        cin>>index_temp;
        cin>>score_temp;
        Score[index_temp] += score_temp;
        if (Score[index_temp] > Score[Score[0]]) {
            Score[0] = index_temp;
        }
    }
    cout<<Score[0]<<' ';
    cout<<Score[Score[0]];
    return 0;
}
