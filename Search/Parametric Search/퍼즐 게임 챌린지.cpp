// PCCP 기출문제 퍼즐 게임 챌린지 (Lv.2)

#include <string>
#include <vector>
using namespace std;

vector<int> diff, time_cur;

bool can_play(int level, long long limit){
    long long duration = time_cur[0];
    int time_prev = time_cur[0];
    
    for(int i=1; i<diff.size(); i++){
        if(diff[i] <= level)
            duration += time_cur[i];
        
        else
            duration += ((diff[i] - level) * (time_cur[i] + time_prev) + time_cur[i]);
        
        time_prev = time_cur[i];
        
        if(duration > limit)
            return false;
    }
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    diff = diffs;
    time_cur = times;
    
    int low = 1, high = 100000;
    while(low <= high){
        int mid = (low + high) / 2;
        
        if(can_play(mid, limit)) high = mid-1;
        else low = mid+1;
    }
    
    return low;
}
