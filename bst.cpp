// SET, MAP 이용하면 된다.
// 단순히 노드 연결하는 방법에 대해 알려주고 적었다.
// C Struct 방식말고 Class 방식으로도 해보자.


#include<iostream>
using namespace std;
#define endl '\n'

typedef struct _Node {
    struct _Node* right;
    struct _Node* left;
    int data;
} Node;

void postorder(Node* node){
    if(node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<endl;
    }
}

Node* insertNode(Node* node, int data) {
    if(node == nullptr){
        Node* new_node = new Node();
        new_node->data = data;
        return new_node;
    }
    if(node->data < data) node->right = insertNode(node->right, data);
    else if(node->data > data) node->left = insertNode(node->left, data);
    else return nullptr;
    return node;
}

int main(){
    Node* root = nullptr;
    int data;
    while(1) {
        cin>>data;
        if(cin.eof()) break;
        root = insertNode(root, data);
    }
    postorder(root);
}