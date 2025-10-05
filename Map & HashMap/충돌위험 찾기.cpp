// 프로그래머스 Lv.2 충돌위험 찾기
// Map + Simulation
// 주의할 점 : 각 로봇이 각 지점을 방문한 시점을 저장하는 방식
// ㄴ 배열로 저장할 경우 최대 이동 시간(max_time)을 정확히 알 수 없음 + 임의의 큰 값으로 지정할 경우 Segmentation Fault 발생
// 따라서, 각 로봇이 이동한 경로를 {X좌표, Y좌표, 시간} 형태로 저장하고, 이를 Map 자료구조를 활용해 Key : {X좌표, Y좌표, 시간} / Value : 해당 데이터가 등장한 횟수 로 변환
// -> Value가 2 이상인 데이터 개수 count

#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> points_coord, robot_routes;

int move(int sx, int sy, int dx, int dy, int second){
    int cx = sx;
    int cy = sy;

    // 문제의 규칙에 의해 X좌표 우선 이동 => dx, dy로 사방탐색 구현 X
    while(cx < dx){
        robot_routes.push_back({++cx, cy, ++second});
    }
    
    while(cx > dx){
        robot_routes.push_back({--cx, cy, ++second});
    }
    
    while(cy < dy){
        robot_routes.push_back({cx, ++cy, ++second});
    }
    
    while(cy > dy){
        robot_routes.push_back({cx, --cy, ++second});
    }
  
    return second;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    points_coord.push_back({0, 0});
    for(int i=0; i<points.size(); i++){
        points_coord.push_back(points[i]);
    }
    
    for(int i=0; i<routes.size(); i++){
        int start_time = 0;
        
        for(int j=0; j<routes[i].size()-1; j++){
            int start_x = points_coord[routes[i][j]][0];
            int start_y = points_coord[routes[i][j]][1];
            int dest_x = points_coord[routes[i][j+1]][0];
            int dest_y = points_coord[routes[i][j+1]][1];
        
            if(start_time == 0) // move() 함수 로직에 의해 최초 출발지점은 고려되지 않으므로, 직접 추가
                robot_routes.push_back({start_x, start_y, start_time});

            // 로봇이 거쳐야 하는 운송 포인트가 여러 개인 경우, 이전까지의 진행 시간을 기록해야 함 => move 함수 결과로 리턴
            start_time = move(start_x, start_y, dest_x, dest_y, start_time);
        }
    }
    
    map<vector<int>, int> collision_count;
    for(auto &route: robot_routes){
        collision_count[route] += 1;
    }
    
    for(auto &cc: collision_count){
        if(cc.second > 1)
            answer++;
    }
    
    return answer;
}
