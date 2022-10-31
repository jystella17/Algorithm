#include <iostream>
#include <algorithm>
using namespace std;
 
const int MAX = 10000 + 1;
const int INF = 987654321;

int N, nodeIdx;
int node[MAX]; 
int low[MAX];
int high[MAX];

pair<int, int> tree[MAX];

void dfs(int nodeNum, int cnt){ //중위순회
    if (tree[nodeNum].first > 0)
        dfs(tree[nodeNum].first, cnt + 1);
    
    low[cnt] = min(low[cnt], nodeIdx);
    high[cnt] = max(high[cnt], nodeIdx++);
    
    if (tree[nodeNum].second > 0)
        dfs(tree[nodeNum].second, cnt + 1);
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for (int i = 0; i < MAX; i++)
        low[i] = INF;
    
    for (int i = 0; i < N; i++){
        int parent, child1, child2;
        cin>>parent>>child1>>child2;
        
        node[parent]++;        
        if (child1 != -1)
            node[child1]++;
        
        tree[parent].first = child1;
        if (child2 != -1)
            node[child2]++;
        
        tree[parent].second = child2;
    }
    
    int root;
    for (int i = 1; i <= N; i++)
        if (node[i] == 1)
            root = i;

    nodeIdx = 1;
    dfs(root, 1);
    
    int result = high[1] - low[1] + 1;
    int level = 1;
    
    for (int i = 2; i <= N; i++){
        int temp = high[i] - low[i] + 1;
        if (temp > result){
            result = temp;
            level = i;
        }
    }
    
    cout<<level<<" "<<result<<"\n";
    
    return 0;
}
