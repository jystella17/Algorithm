#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

const int NODE_MAX = 5000;

struct Node {
    int data;
    Node* next;
    
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
    Node* head; 
    Node* tail;
    vector<Node*> nodeArr;
    int nodeCnt;

// Linked List Initialization
public:
    LinkedList() : head(nullptr), tail(nullptr), nodeCnt(0) {
        nodeArr.resize(NODE_MAX, nullptr);
    }
        
    // insert를 위해 새로운 노드 생성
    Node* getNewNode(int data){
        nodeArr[nodeCnt] = new Node(data);
        return nodeArr[nodeCnt++];
    }
        
    void insert(int idx, const vector<int>& nums){
        int sequence = 0; // nums에서의 인덱스
        // 노드의 맨 앞에 insert
        if(idx == 0){
            // 이미 다른 값이 있는 경우
            if(head != nullptr){
                Node* newNode = getNewNode(nums[0]);
                newNode->next = head;
                head = newNode;
            }
            // 빈 linked list인 경우
            else{
                head = getNewNode(nums[0]);
            }
            idx = 1;
            sequence = 1;
        }
            
        //중간 or 맨 뒤에 insert하거나, 2개 이상의 값을 insert해야 하는 경우
        Node* cur = head;
        for(int i=1; i<idx; i++){
            cur = cur->next; // insert할 위치까지 이동
        }
            
        for(int i=sequence; i<nums.size(); i++){
            Node* newNode = getNewNode(nums[i]);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = newNode;
        }
            
        // 맨 뒤에 insert하는 경우
        if(cur->next == nullptr){
            tail = cur;
        }
    }
        
    void remove(int idx, int cnt){
        Node* cur = head;
        // 맨 앞 노드부터 삭제해야 하는 경우, head값을 변경해야 하므로 따로 처리
        if(idx == 0){
            for(int i=0; i<cnt; i++){
                cur = cur->next;
            }
            head = cur;
            return;
        }
            
        for(int i=1; i<idx; i++){
            cur = cur->next;
        }
            
        Node* anchor = cur;
        for(int i=0; i<cnt; i++){
            cur = cur->next;
        }
            
        anchor->next = cur->next;
        // 마지막 노드까지 삭제한 경우 tail값 변경
        if(anchor->next == nullptr){
            tail = anchor;
        }
    }
        
    // 1개의 노드를 맨 뒤에 추가
    void add(int data){
        Node* cur = tail;
        Node* newNode = getNewNode(data);
        
        cur->next = newNode;
        tail = newNode;
    }
        
    void print(){
        int cnt = 10;
        Node* cur = head;
            
        while(cnt-- > 0){
            cout<<cur->data<<" ";
            cur = cur->next;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    for(int t=1; t<=10; t++){
        LinkedList list;
        int n; cin>>n;
        
        vector<int> cipher(n);
        for(int i=0; i<n; i++){
            cin>>cipher[i];
        }
        list.insert(0, cipher);
        
        int m; cin>>m;
        for(int i=0; i<m; i++){
            char cmd; cin>>cmd;
            
            vector<int> tmp;
            if(cmd == 'I'){
                int x, y; cin>>x>>y;
                tmp = vector<int>(y);
                
                for(int j=0; j<y; j++){
                    cin>>tmp[j];
                }
                list.insert(x, tmp);
            }
            
            else if(cmd == 'D'){
                int x, y; cin>>x>>y;
                
                list.remove(x, y);
            }
            
            else if(cmd == 'A'){
                int y; cin>>y;
                
                for(int j=0; j<y; j++){
                    int data; cin>>data;
                    
                    list.add(data);
                }
            }
        }
        cout<<"#"<<t<<" ";
        list.print();
        cout<<"\n";
    }
    return 0;
}
