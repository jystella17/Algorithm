// 백준 G2 수열과 쿼리 15
// Segment Tree 공부

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[100001];
vector<int> segment_tree(400001); // 자식 노드 2개 중 더 작은 값을 갖는 노드의 인덱스 저장
// root(=1)에 가까울수록 더 작은 값의 인덱스가 저장, leaf에 가까울수록 더 큰 값의 인덱스가 저장

int min_index(int x, int y){
    if(A[x] == A[y])
        return x < y ? x : y;
    
    else
        return A[x] < A[y] ? x : y;
}

int init(int start, int end, int node){ // node = 현재 노드 번호
    if(start == end) // leaf 노드인 경우 (더이상 left/right로 분할하여 탐색할 인덱스가 없는 경우)
        return segment_tree[node] = start; // 현재 인덱스를 그대로 저장
        
    int mid = (start+end) / 2;
    int smaller = min_index(init(start, mid, node*2), init(mid+1, end, node*2+1));
    return segment_tree[node] = smaller;
}

int update_tree(int start, int end, int node, int target){
    // 현재 노드가 leaf 노드인 경우 or 현재 범위 내에 변경하려는 인덱스가 포함되지 않은 경우
    if(start == end || target < start || target > end)
        return segment_tree[node]; // 현재 노드에 저장된 인덱스 리턴
        
    int mid = (start+end) / 2;
    int smaller = min_index(update_tree(start, mid, node*2, target), update_tree(mid+1, end, node*2+1, target));
    return segment_tree[node] = smaller;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>A[i];
        
    init(1, n, 1);   
        
    cin>>m;
    for(int i=0; i<m; i++){
        int query, index, value;
        cin>>query;
        
        if(query == 1){
            cin>>index>>value;
            A[index] = value;
            update_tree(1, n, 1, index);
        }
        
        else if(query == 2){
            // 세그먼트 트리의 1번 인덱스 = 수열의 최소값의 인덱스
            cout<<segment_tree[1]<<"\n";
        }
    }

    return 0;
}
