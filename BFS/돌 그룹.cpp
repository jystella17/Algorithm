// BOJ 12886 돌 그룹 (G4)

#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, c, answer = 0;
    cin>>a>>b>>c;

    unordered_map<string, int> hm;
    queue<pair<int, pair<int, int>>> stones;
    stones.push(make_pair(a, make_pair(b, c)));

    if((a+b+c) % 3 == 0){
        string tmp = to_string(a) + "|" + to_string(b) + "|" + to_string(c);
        hm.insert(make_pair(tmp, 1));

        while(!stones.empty()){
            int ca = stones.front().first;
            int cb = stones.front().second.first;
            int cc = stones.front().second.second;
            stones.pop();

            if(ca == cb && cb == cc){
                answer = 1;
                break;
            }

            // 돌 a, b를 선택하는 경우 | b, c를 선택하는 경우 | c, a를 선택하는 경우를 모두 확인
            int na, nb, nc;

            if(ca != cb){
                if(ca < cb){
                    na = 2 * ca;
                    nb = cb - ca;
                    nc = cc;
                }
                else if(ca > cb){
                    na = ca - cb;
                    nb = 2 * cb;
                    nc = cc;
                }

                tmp = to_string(na) + "|" + to_string(nb) + "|" + to_string(nc);
                // 동일한 a, b, c 조합이 2번 등장했다면, 앞으로도 같은 조합이 반복적으로 등장하므로 a = b = c를 만들 수 없음
                if(hm.count(tmp) == 0){
                    hm.insert(make_pair(tmp, 1));
                    stones.push(make_pair(na, make_pair(nb, nc)));
                }
            }

            if(cb != cc){
                if(cb < cc){
                    na = ca;
                    nb = 2 * cb;
                    nc = cc - cb;
                }
                else if(cb > cc){
                    na = ca;
                    nb = cb - cc;
                    nc = 2 * cc;
                }

                tmp = to_string(na) + "|" + to_string(nb) + "|" + to_string(nc);
                if(hm.count(tmp) == 0){
                    hm.insert(make_pair(tmp, 1));
                    stones.push(make_pair(na, make_pair(nb, nc)));
                }
            }

            if(ca != cc){
                if(ca < cc){
                    na = 2 * ca;
                    nb = cb;
                    nc = cc - ca;
                }
                else if(ca > cc){
                    na = ca - cc;
                    nb = cb;
                    nc = 2 * cc;
                }

                tmp = to_string(na) + "|" + to_string(nb) + "|" + to_string(nc);
                if(hm.count(tmp) == 0){
                    hm.insert(make_pair(tmp, 1));
                    stones.push(make_pair(na, make_pair(nb, nc)));
                }
            }
        }
    }
    cout<<answer<<"\n";
    return 0;
}
