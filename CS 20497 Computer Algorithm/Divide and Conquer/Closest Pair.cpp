#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct point{
    int x;
    int y;
};

bool compX(point a, point b){
    if(a.x == b.x)
        return a.y < b.y;
        
    return a.x < b.x;
}

bool compY(point a, point b){
    if(a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

float distance(vector<point> &v, int l, int r){
    float minDist = -1;
    
    for(int i=l; i<=r-1; i++){
        for(int j=i+1; j<=r; j++){
            float dist = sqrt(
                pow(v[i].x - v[j].x, 2) + 
                pow(v[i].y - v[j].y, 2));
            
            if(minDist == -1 || minDist > dist)
                minDist = dist;
        }
    }

    return minDist;
}

float closestPair(vector<point> &v, int left, int right){
    if(right-left+1 <= 3)
        return distance(v, left, right);
    
    int mid = (left + right) / 2;
    float leftMin = closestPair(v, left, mid);
    float rightMin = closestPair(v, mid+1, right);
    
    float closest;
    
    if(leftMin > rightMin)
        closest = rightMin;
    else
        closest = leftMin;
        
    vector<point> medium;
    for(int i=left; i<=right; i++){
        if(i != mid){
            float xDist = v[i].x - v[mid].x;
        
            if(sqrt(pow(xDist, 2)) < closest)
                medium.push_back(v[i]);
        }
    }
    
    int idx = medium.size();
    sort(medium.begin(), medium.end(), compY);
    // y 좌표 기준 정렬
    
    for(int i=0; i<medium.size(); i++){
        cout<<medium[i].x<<" "<<medium[i].y<<endl;
    }
    
    for(int i=0; i<idx-1; i++){
        for(int j=i+1; j<idx; j++){
            float y = medium[i].y - medium[j].y;
            
            if(sqrt(pow(y, 2)) < closest){
                float tmpDist = sqrt(
                    pow(medium[i].x - medium[j].x, 2) + 
                    pow(medium[i].y - medium[j].y, 2));
                    
                cout<<tmpDist<<endl;
                
                if(tmpDist < closest)
                    closest = tmpDist;
            }
            
            else
                break;
        }
    }
    return closest;
}

int main(){
    vector<point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    sort(points.begin(), points.end(), compX);
    
    float answer = closestPair(points, 0, points.size()-1);
    cout<<answer<<endl;
    
    return 0;
}
