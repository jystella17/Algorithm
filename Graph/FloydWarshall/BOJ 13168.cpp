// 백준 G3 내일로 여행
// Floyd Warshall
// 자료형(double) 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define INF 987654321
using namespace std;

unordered_map<string, int> city_info; // 전체 도시의 이름, index 저장
vector<string> travel; // 방문할 도시
double transport_cost[101][101]; // 도시 i -> j 이동 비용
double naeilo_cost[101][101]; // 내일로 티켓 구매 시 도시 i->j 이동 비용

int main(){
    int n, r, m, k;
    cin>>n>>r;
    
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        city_info[s] = i;
    }
    
    cin>>m;
    for(int i=0; i<m; i++){
        string s;
        cin>>s;
        travel.push_back(s);
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j){
                transport_cost[i][j] = INF;
                naeilo_cost[i][j] = INF;
            }
        }
    }
    
    cin>>k;
    for(int i=0; i<k; i++){
        string type, s, e;
        double cost;
        cin>>type>>s>>e>>cost;
        
        int start = city_info[s]; // 출발 도시의 index 구하기
        int end = city_info[e]; // 도착 도시의 index 구하기
        
        // 내일로 티켓을 사용하지 않을 때 주어진 구간의 최소 요금
        transport_cost[start][end] = min(transport_cost[start][end], cost);
        transport_cost[end][start] = min(transport_cost[end][start], cost);
        
        // 내일로 티켓을 사용할 때 주어진 구간의 최소 요금
        if(type == "Mugunghwa" || type == "ITX-Saemaeul" || type == "ITX-Cheongchun")
            cost = 0;
        
        else if(type == "S-Train" || type == "V-Train")
            cost /= 2;
            
        naeilo_cost[start][end] = min(naeilo_cost[start][end], (double)cost);
        naeilo_cost[end][start] = min(naeilo_cost[end][start], (double)cost);
    }
    
    // Floyd-Warshall 알고리즘을 사용해 city_info에 있는 모든 도시들 간의 최소 비용 구하기
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                transport_cost[i][j] = min(transport_cost[i][j], transport_cost[i][k] + transport_cost[k][j]);
				naeilo_cost[i][j] = min(naeilo_cost[i][j], naeilo_cost[i][k] + naeilo_cost[k][j]);
            }
        }
    }
    
    // 총 이동 비용 구하기 (내일로 티켓 구매 X / 구매 O)
    double t_cost = 0;
    double n_cost = r;
    for(int i=0; i<m-1; i++){
        int start = city_info[travel[i]];
        int end = city_info[travel[i+1]];
        
        t_cost += transport_cost[start][end];
        n_cost += naeilo_cost[start][end];
    }
    
    if(t_cost > n_cost)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
