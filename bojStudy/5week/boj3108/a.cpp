#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef struct square {
    int x1, x2, y1, y2;
} square;

int tree[1010];
int ranks[1010];
set<int> ans;

bool isJoint(square a, square b){
    if(a.x1 > b.x2 || a.x2 < b.x1) return false;
    if(a.y1 > b.y2 || a.y2 < b.y1) return false;
    if(a.x1 < b.x1 && a.x2 > b.x2 && a.y1 < b.y1 && a.y2 > b.y2) return false;
    if(b.x1 < a.x1 && b.x2 > a.x2 && b.y1 < a.y1 && b.y2 > a.y2) return false;
    return true;
}

int find(int squareNumber){
    if(tree[squareNumber] == squareNumber) return squareNumber;
    return tree[squareNumber] = find(tree[squareNumber]);
}

void unionTree(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(ranks[a] > ranks[b]){
        int tmp = a;
        a = b;
        b = tmp;
    }
    tree[a] = b;
    if(ranks[a] == ranks[b]) ranks[b]++;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    int T = N;
    vector<square> sq;
    for(int i=0; i<N; ++i) ranks[i] = 1;
    for(int i=0; i<N+1; ++i) tree[i] = i;
    square tmp;
    tmp.x1 = tmp.x2 = tmp.y1 = tmp.y2 = 0;
    sq.push_back(tmp); // 처음에 펜을 내린 상태. 점 하나도 무수히 작은 square라고 생각하면 된다.
    int idx = 1;
    while(T--){
        cin>>tmp.x1>>tmp.y1>>tmp.x2>>tmp.y2;
        for(int i=0; i<sq.size(); ++i){
            if(isJoint(sq[i], tmp)){
                unionTree(i, idx);
                // cout<<"yeet\n";
            }
        }
        sq.push_back(tmp);
        idx++;
    }
    // cout<<"tree : \n";
    // for(int i=0; i<N + 1; ++i){
    //     cout<<tree[i]<<'\n';

    // }
    for(int i=0; i<sq.size(); ++i){
        int head = find(tree[i]);
        ans.insert(head);
    }
    // if(ans.empty()) cout<<"empty!\n";
    cout<<ans.size() - 1;
}