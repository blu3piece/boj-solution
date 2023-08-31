#include<iostream>
#include<set>
#include<queue>
using namespace std;
typedef pair<int, pair<int, int>> piii;

int A, B, C; //full bucket

set<int> ans;
bool visit[200][200][200];

void addQueue(queue<piii>& q, int a, int b, int c){
    if(!visit[a][b][c]) q.push(make_pair(a, make_pair(b, c)));
    visit[a][b][c] = true;
}

void simulate(){
    queue<piii> q;

    q.push(make_pair(0, make_pair(0, C)));

    visit[0][0][C] =  true;

    ans.insert(C);
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        if(!a){
            ans.insert(c);
        }
        
        //A -> B
        if(a + b > B) addQueue(q, a - (B - b), B, c);
        else addQueue(q, 0, a + b, c);
        //A -> C
        if(a + c > C) addQueue(q, a - (C - c), b, C);
        else addQueue(q, 0, b, a+c);
        //B -> A
        if(a + b > A) addQueue(q, A, b - (A - a), c);
        else addQueue(q, a + b, 0, c);
        //B -> C
        if(c + b > C) addQueue(q, a, b - (C - c), C);
        else addQueue(q, a, 0, b + c);
        //C -> A
        if(a + c > A) addQueue(q, A, b, c - (A - a));
        else addQueue(q, a + c, b, 0);
        //C -> B
        if(c + b > B) addQueue(q, a, B, c - (B - b));
        else addQueue(q, a, b + c, 0);

    }
    return;
}

int main(){
    cin>>A>>B>>C;
    simulate();
    for(int i : ans){
        cout<<i<<' ';
    }
}