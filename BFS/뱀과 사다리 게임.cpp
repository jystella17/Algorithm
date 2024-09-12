// BOJ 16928 뱀과 사다리 게임 (G5)
// 1D BFS 응용

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; cin>>n>>m;
    int ld_sn[101];
    for(int i=1; i<=100; i++){
        ld_sn[i] = 0;
    }

    for(int i=0; i<n; i++){
        int x, y; cin>>x>>y;
        ld_sn[x] = y;
    }

    for(int i=0; i<m; i++){
        int x, y; cin>>x>>y;
        ld_sn[x] = y;
    }

    queue<int> spot; spot.push(1);
    int dice_count[101];
    fill(dice_count, dice_count+101, 987654321);
    dice_count[1] = 0;

    while(!spot.empty()){
        int current = spot.front();
        spot.pop();

        for(int i=1; i<=6; i++){
            int next = current + i;

            if(next > 100) continue;
            // 체크중인 지점에 이미 최적해가 저장되어 있다면 pass
            if(dice_count[next] <= dice_count[current] + 1) continue;

            dice_count[next] = dice_count[current] + 1;
            if(ld_sn[next]) {
                // 사다리 or 뱀을 타고 도착하는 지점에 이미 최적해가 저장되어 있는 경우, 현재 케이스의 dice count로 업데이트되지 않아야 함
                // 현재 케이스의 dice count가 더 최적해에 가까운 경우, 업데이트가 되어야 함
                // 따라서 둘 중 더 작은 값 (= 최적해에 더 근접한 값)을 도착 지점에 저장
                dice_count[ld_sn[next]] = min(dice_count[next], dice_count[ld_sn[next]]);
                spot.push(ld_sn[next]);
            } else {
                spot.push(next);
            }
        }
    }
    cout<<dice_count[100]<<"\n";
    return 0;
}
