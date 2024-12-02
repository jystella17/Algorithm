// BOJ 2213 트리의 독립집합 (G1)
// Tree DP = DFS & 방문 여부 기반으로 트리 탐색 + DP 수행

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> tree[100001], graph[100001];
int weights[100001];
// i번 노드를 루트로 하는 subtree에 대해
// i번째 노드를 독립 집합에 포함하는 경우 / 포함하지 않는 경우의 최대값
int dp[100001][2];
bool is_selected[100001];

// 트리 재구성 => index가 작은 노드일수록 root에 가깝게, 큰 노드일수록 leaf에 가깝게
// 이 때, 처음에 입력된 트리와 비교해 부모/자식 관계가 서로 바뀌어도 상관없음
// 이유: 연결된 두 노드에 대해 하나를 선택하면 다른 하나는 선택하지 않는 원칙 유지 + 
// 전체 노드 간의 연결 관계 역시 유지되므로 답을 구하는 데에는 영향 X
void make_tree(int start, int prev){
    for(int i=0; i<graph[start].size(); i++){
        int next = graph[start][i];
            
        // graph는 무향 그래프 => next == prev인 경우 이미 방문했던 노드 재방문
        // 따라서 현재 지점에 도달할 때까지 방문된 적 없는 지점만 자식 노드로 저장
        if(next != prev){
            tree[start].push_back(next);
            make_tree(next, start);
        }
    }
}

int find_independent(int current, int select){
    // dfs로 트리 탐색을 구현하기 위한 조건 => 각 노드를 1번씩만 방문 (리턴 제외)
    if(dp[current][select] > -1) 
        return dp[current][select];
    
    int set_size = 0;
    
    // 현재 노드가 independent set에 포함되어 있는 경우
    if(select){
        // 다이렉트로 연결된 자식 노드들을 1번씩 탐색하면서 부분 문제 해결
        for(int i=0; i<tree[current].size(); i++){
            // 다음번 자식 노드는 포함하지 않고, 
            // 이후의 자식 노드들은 포함하거나 포함하지 않는 경우의 최대값
            set_size += find_independent(tree[current][i], 0);
        }
        
        return set_size + weights[current];
    }
    
    // 포함되지 않은 경우
    else{
        for(int i=0; i<tree[current].size(); i++){
            // 다음 자식 노드를 포함하는 경우의 최대값
            int with = find_independent(tree[current][i], 1);
            // 다음 자식 노드를 포함하지 않는 경우의 최대값
            int without = find_independent(tree[current][i], 0);
            
            // 다음 자식 노드를 포함해야 최적해를 구할 수 있다면
            if(with > without)
                is_selected[tree[current][i]] = true; // 독립 집합 후보에 추가
            
            set_size += max(with, without);
        }
        
        return set_size;
    }
}

void post_process(int current, bool selected){
    for(int i=0; i<tree[current].size(); i++){
        int next = tree[current][i];
        
        if(selected){
            is_selected[next] = false;
            post_process(next, false);
        }
        
        else post_process(next, is_selected[next]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>weights[i];
        
    for(int i=1; i<=n; i++)
        dp[i][0] = dp[i][1] = -1;
        
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    make_tree(1, 1);
    
    // root 노드를 포함하는 쪽이 최적해가 될 수도 있고, 
    // 포함하지 않는 쪽이 최적해가 될 수도 있으므로
    // 두 케이스를 모두 계산
    int with_root = find_independent(1, 1);
    int without_root = find_independent(1, 0);
    
    if(with_root > without_root){
        is_selected[1] = true;
        cout<<with_root<<"\n";
    }
    else cout<<without_root<<"\n";
    
    // 탐색 과정에서 거쳐간 노드들이 모두 선택된 상태로 배열에 남아있는 문제
    // => root 노드에서 시작해서, 현재 노드가 선택되었으면 다음 자식 노드는 모두 선택 해제
    // 현재 노드가 선택되지 않았으면 다음 자식 노드는 기존 상태 유지
    post_process(1, is_selected[1]);

    for(int i=1; i<=n; i++){
        if(is_selected[i]) 
            cout<<i<<" ";
    }
    
    return 0;
}
