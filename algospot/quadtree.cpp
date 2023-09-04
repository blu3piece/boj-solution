#include<iostream>
#include<string>
using namespace std;

typedef struct node{
    struct node** QuadChild = NULL; // QuadChild[4]
    char data = '\0';
    bool isFull = false;
} Node;

void insert(Node* root, char data){
    if(root->data == '\0'){
        root->data = data;
        return;
    }
    if(root->data == 'x' && root->QuadChild == NULL){
        root->QuadChild = new Node*[4];
        for(int i = 0; i<4; ++i) root->QuadChild[i] = new Node;
    }
    for(int i = 0; i<4; ++i){
        if(root->QuadChild[i]->data == 'x' && !(root->QuadChild[i]->isFull)){
            insert(root->QuadChild[i], data);
            return;
        }
        else if(root->QuadChild[i]->data == '\0'){
            insert(root->QuadChild[i], data);
            if(i == 3) root->isFull = true;
            return;
        }
    }
}

void inverse(Node* root){
    if(root->data == 'x'){
        Node* temp = root->QuadChild[0];
        root->QuadChild[0] = root->QuadChild[2];
        root->QuadChild[2] = temp;

        temp = root->QuadChild[1];
        root->QuadChild[1] = root->QuadChild[3];
        root->QuadChild[3] = temp;
        
        for(int i = 0; i<4; ++i){
            if(root->QuadChild[i]->data == 'x'){
                inverse(root->QuadChild[i]);
            }
        }
    }
}

void preorder(Node* root){
    cout<<root->data;
    for(int i = 0; i<4 && root->QuadChild; ++i){
        preorder(root->QuadChild[i]);
    }
}

int main(){
    string input;
    int t; cin>>t;
    while(t--){
        Node* QuadTree = NULL;
        cin>>input;
        for(int i = 0; i<input.length(); ++i){
            if(QuadTree == NULL){
                QuadTree = new Node();
            }
            insert(QuadTree, input[i]);
        }
        inverse(QuadTree);
        preorder(QuadTree);
        cout<<'\n';
    }
    return 0;
}
