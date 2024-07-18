// 알고리즘 문제해결 전략 예제
// ID: ARCTIC 난이도: 하
// 자료형, 소수점에 주의

#include <stdio.h>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

double distances[100][100];

double calc(double x1, double y1, double x2, double y2){
    double tmp = pow(x2 - x1, 2) + pow(y2 - y1, 2);
    return sqrt(tmp);
}

bool isConnected(int n, double radius){
    vector<bool> visited(n, false);
    queue<int> queue;

    queue.push(0);
    visited[0] = true;
    
    int count = 0;
    while(!queue.empty()){
        int current = queue.front();
        queue.pop();
        count++;

        for(int next=0; next<n; next++){
            if(!visited[next] && distances[current][next] <= radius) {
                visited[next] = true;
                queue.push(next);
            }
        }
    }
    return count == n;
}

int main(){
    int tc; scanf("%d", &tc);
    
    for(int t=0; t<tc; t++){
        vector<pair<double, double>> bases;
        int n; scanf("%d", &n);
        
        for(int i=0; i<n; i++){
            double x, y; 
            scanf("%lf %lf", &x, &y);
            bases.push_back(make_pair(x, y));
        }
        
        for(int i=0; i<n; i++){
            distances[i][i] = 0;
            
            for(int j=i+1; j<n; j++){
                double x1 = bases[i].first, y1 = bases[i].second;
                double x2 = bases[j].first, y2 = bases[j].second;

                double dist = calc(x1, y1, x2, y2);
                distances[i][j] = dist;
                distances[j][i] = dist;
            }
        }

        double low = 0, high = 1416.00;
        for(int i=0; i<100; i++){
            double mid = (low + high) / 2.0;
            
            if(isConnected(n, mid)) high = mid;
            else low = mid;
        }
        printf("%.2lf\n", high);
    }
    return 0;
}
