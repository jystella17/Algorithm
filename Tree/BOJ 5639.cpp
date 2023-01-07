// 백준 G5 이진 검색 트리

#include <iostream>
using namespace std;

struct Node{
    struct Node *left;
    struct Node *right;
    int key;
};

Node* insertNode(Node* node, int data){
    if(node == NULL){
        node = new Node();
        node->key = data;
        node->left = node->right = NULL;
    }
    
    else if(data <= node->key) // node->key = 이전 노드의 값
    // 현재 노드를 이전 노드의 왼쪽 자식으로 저장
        node->left = insertNode(node->left, data);
        
    else // data > node->key
    // 현재 노드를 이전 노드의 오른쪽 자식으로 저장
        node->right = insertNode(node->right, data);
        
    return node;
}

void postOrder(Node* node){ // 후위 순회
    if(node->left != NULL) 
        postOrder(node->left);
        
    if(node->right != NULL)
        postOrder(node->right);
        
    cout<<node->key<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    Node* root = NULL;
    
    int data;
    while(cin>>data){
        if(data == EOF)
            break;
            
        root = insertNode(root, data);
    }

    postOrder(root);
    
    return 0;
}
