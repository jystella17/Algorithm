// 백준 G2 퍼즐
// 2차원 배열이 아닌 1차원 string으로 변환하여 탐색해야 함에 유의
// string에서의 index를 기반으로 x, y 좌표 변환
// 방문 여부를 저장하기 위해 set 사용 => 특정 좌표가 아니라 숫자 위치 조합을 방문했는지 확인

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string start = "";
string organized = "123456780";
set<string> visited; // 이미 등장한 숫자 배치 저장

int bfs(){
    queue<pair<string, int>> q; // 숫자 배치와 현재까지의 이동 횟수
    q.push(make_pair(start, 0));
    visited.insert(start);
    
    while(!q.empty()){
        string cur = q.front().first;
        int count = q.front().second;
        q.pop();
        
        if(cur == organized)
            return count;
            
        int zero_pos = cur.find('0');
        int x = zero_pos / 3;
        int y = zero_pos % 3;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3){
                string next_table = cur;
                swap(next_table[x*3 + y], next_table[nx*3 + ny]);
                
                if(visited.find(next_table) == visited.end()){
                    visited.insert(next_table);
                    q.push(make_pair(next_table, count+1));
                }
            }
        }
    }
    
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int idx;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            string s;
            cin>>s;
            start += s;
        }
    }

    int answer = bfs();
    
    if(answer == -1)
        cout<<-1<<endl;
    else
        cout<<answer<<endl;

    return 0;
}
