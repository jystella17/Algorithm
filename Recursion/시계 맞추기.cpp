// 알고리즘 문제해결 전략 예제
// ID: CLOCKSYNC 난이도: 중

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int clocks[16];
vector<vector<int>> modify = {{0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, 
                              {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, 
                              {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5},
                              {3, 4, 5, 9, 13}};

void rotateClock(int switchNum){
    for(int i=0; i<modify[switchNum].size(); i++){
        int current = clocks[modify[switchNum][i]];
        clocks[modify[switchNum][i]] = (current + 3) % 12;
    }
}

int turnClock(int current, int count){
    if(current == 10) {
        for(int i=0; i<16; i++){
            if(clocks[i] != 0)
                return 987654321;
        }
        return count;
    }
    
    int result = 987654321;
    for(int i=0; i<4; i++){
        result = min(result, turnClock(current+1, count+i));
        rotateClock(current);
    }
    return result;
}

int main() {
    int tc; cin>>tc;
    for(int t=0; t<tc; t++){
        for(int i=0; i<16; i++){
            int tmp; cin>>tmp;
            clocks[i] = (tmp % 12);
        }
        
        int answer = turnClock(0, 0);
        if(answer < 987654321)
            cout<<answer<<"\n";
        else cout<<-1<<"\n";
    }
    return 0;
}
