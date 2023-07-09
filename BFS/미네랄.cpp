// 백준 G1 미네랄
// Simulation + BFS => 솔루션 없이 다시 풀어보기

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

int r, c, n;
char mineral[101][101];
bool visited[101][101] = {false, };
bool cluster[101][101] = {false, }; // 클러스터의 위치 저장
vector<int> stick; // 막대를 던진 높이, 짝수 인덱스=왼->오, 홀수 인덱스=오->왼
vector<pair<int, int>> air_cluster;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// 막대기를 던질 때 파괴되는 미네랄이 있는지 체크
// 파괴되는 미네랄이 있으면 클러스터가 분리될 수 있음
bool is_destroyed(char direction, int height){
    if(direction == 'L'){
        for(int i=0; i<c; i++){
            if(mineral[height][i] == 'x'){
                mineral[height][i] = '.';
                return true;
            }
        }
    }
    
    else{
        for(int i=c-1; i>=0; i--){
            if(mineral[height][i] == 'x'){
                mineral[height][i] = '.';
                return true;
            }
        }
    }
    
    return false;
}

void bfs(int x, int y){
    queue<pair<int, int>> queue;
    queue.push(make_pair(x,y));
    visited[x][y] = true;
    
    while(!queue.empty()){
        int cx = queue.front().first;
        int cy = queue.front().second;
        queue.pop();
        
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
                
            if(mineral[nx][ny] == 'x' && visited[nx][ny] == false){
                visited[nx][ny] = true;
                queue.push(make_pair(nx,ny));
            }
        }
    }
}

// bfs로 공중에 뜨게 되는 클러스터가 있는지 확인
bool is_air_cluster(){
    // 바닥에 있는(파괴되어도 공중에 뜨지 않는) 미네랄은 우선적으로 방문 처리
    for(int i=0; i<c; i++){
        if(mineral[r-1][i] == 'x' && visited[r-1][i] == false)
            bfs(r-1, i);
    }
    
    bool is_air = false;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(mineral[i][j] == 'x' && visited[i][j] == false){
                is_air = true;
                air_cluster.push_back(make_pair(i,j));
                cluster[i][j] = true;
            }
        }
    }
    return is_air;
}

// 분리된 클러스터가 바닥에 떨어지거나 다른 클러스터와 합쳐지는 이동 거리 확인
int merge_dist(int x, int y){
    int count = 0;
    for(int i=x+1; i<r; i++){
        if(mineral[i][y] == 'x'){
            if(cluster[i][y] == true) return INF;
            else return count;
        }
        
        else if(mineral[i][y] == '.') count++;
    }
    return count;
}

// 동굴 상태 업데이트
void update_cave(){
    int moving = INF-1;
    for(int i=0; i<air_cluster.size(); i++){
        int x = air_cluster[i].first;
        int y = air_cluster[i].second;
        
        int distance = merge_dist(x, y);
        if(distance == INF) continue;
        else moving = min(distance, moving);
    }
    
    sort(air_cluster.begin(), air_cluster.end());
    for(int i=air_cluster.size()-1; i>=0; i--){
        int x = air_cluster[i].first;
        int y = air_cluster[i].second;
        
        mineral[x][y] = '.';
        mineral[x+moving][y] = 'x';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>r>>c;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin>>mineral[i][j];
            
    cin>>n;
    for(int i=0; i<n; i++){
        int tmp; cin>>tmp;
        stick.push_back(tmp);
    }
    
    for(int i=0; i<stick.size(); i++){
        air_cluster.clear();
        memset(visited, false, sizeof(visited));
        memset(cluster, false, sizeof(cluster));
        
        char direction;
        int height = stick[i];
        height = r - height;
        
        if(i%2 == 0) direction = 'L';
        else direction = 'R';
        
        if(is_destroyed(direction, height) == false) continue;
        if(is_air_cluster() == false) continue;
        
        else update_cave();
    }
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            cout<<mineral[i][j];
        cout<<"\n";
    }
    return 0;
}
