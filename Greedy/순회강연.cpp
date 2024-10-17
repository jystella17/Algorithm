// BOJ 2109 순회강연 (G3)
// Greedy + Priority Queue

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, p, d;
    priority_queue<pair<int, int>> requests;
    // 선택 정보 저장
    priority_queue<int, vector<int>, greater<>> accepted;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>p>>d;
        // 기한 오름차순, 강연료 내림차순
        requests.push(make_pair(-d, p));
    }

    while(!requests.empty()){
        int due_date = -requests.top().first;
        int pay = requests.top().second;

        // 기한이 due_date인 케이스를 처음 고려한다면, 강연료는 내림차순으로 정렬했으므로 현재 강연을 선택
        if(accepted.size() < due_date)
            accepted.push(pay);
    
        // 기한이 due_date인 케이스가 이미 1번 이상 고려된 경우, 이번 강연을 진행하는 것이 더 많은 강연료를 받을 수 있는 경우에만 선택
        // 더 많은 강연료를 받을 수 있는 경우 = 기한이 더 짧은 강연들 중 현재 강연보다 적은 강연료를 받는 강연이 있는 경우
        // 기존에 선택한 강연을 선택 해제하고, 현재 강연을 선택
        else if(accepted.size() >= due_date && accepted.top() < pay){
            accepted.pop();
            accepted.push(pay);
        }
        // else : 현재 기한까지 고를 수 있는 강연을 최대의 강연료로 모두 골랐다면 continue

        requests.pop();
    }

    int answer = 0;
    while(!accepted.empty()){
        answer += accepted.top();
        accepted.pop();
    }

    cout<<answer<<"\n";
    return 0;
}
