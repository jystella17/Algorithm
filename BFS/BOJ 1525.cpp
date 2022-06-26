#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> myMap;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool available(int x, int y){ return x>=0 && y>=0 && x<=2 && y<=2; }

int bfs(string s){
  queue<string> myQueue;
  myQueue.push(s);

  while(!myQueue.empty()){
    string p = myQueue.front();
    myQueue.pop();

    if(p == "123456780"){
      return myMap[p];
    }
      
    auto zpos = p.find('0');
    for (int i = 0; i < 4; i++) {
      int nx = zpos / 3 + dx[i];
      int ny = (zpos % 3) + dy[i];
      if(!available(nx, ny)) continue;
      string tmp = p;
      swap(tmp[zpos], tmp[(3*nx)+ny]);
      if(!myMap[tmp]){
        myMap[tmp] = myMap[p]+1;
        myQueue.push(tmp);
      }
    }
  }

  return -1;
}

int main(){
  int arr[3][3];
  string s = "";

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> arr[i][j];
      s += (arr[i][j]+'0');
    }
  }

  cout << bfs(s) << endl;

  return 0;
}
