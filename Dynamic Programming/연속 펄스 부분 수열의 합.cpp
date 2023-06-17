// 프로그래머스 Lv.3 연속 펄스 부분 수열의 합
// DP 응용 => 펄스 수열의 특성을 sequence 배열에 적용하는 방법 착안 필요
// DP를 활용한 최대 연속 부분수열 합 구하기 => https://shoark7.github.io/programming/algorithm/4-ways-to-get-subarray-consecutive-sum

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long max(long long a, long long b){
    if (a > b) return a;
    else return b;
}

long long solution(vector<int> sequence) {
    long long answer = -987654321;
    long long dp = 0;
    
    for(int i=0; i<sequence.size(); i++){
        if(i % 2 == 1) // [1, -1, 1, -1] 형태의 펄스 수열
            sequence[i] *= -1;
    }
    
    for(int i=0; i<sequence.size(); i++){
        dp = max(0, dp) + sequence[i];
        answer = max(answer, dp);
    }
    
    for(int i=0; i<sequence.size(); i++){
        sequence[i] *= -1; // [-1, 1, -1, 1] 형태의 펄스 수열
        // 이전에 [1, -1, 1, -1] 형태의 펄스 수열을 이미 곱한 값이므로
        // 모든 원소에 -1을 곱해주면 반대 형태의 펄스 수열을 적용한 것과 같은 결과
    }
    
    dp = 0;
    for(int i=0; i<sequence.size(); i++){
        dp = max(0, dp) + sequence[i];
        answer = max(answer, dp);
    }
    
    return answer;
}
