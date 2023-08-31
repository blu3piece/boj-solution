#include<iostream>
#include<utility>
#include<vector>
using namespace std;

int count;
vector<pair<int, int>> procedure;

void hanoi(int N, int from, int where){
    int remain = -1;
    bool tag[4] = {false,};
    tag[from] = true, tag[where] = true;
    for(int i=1; i<=3; ++i) if(!tag[i]) remain = i;
    if(N == 1){
        procedure.push_back(make_pair(from, where));
        return;
    } 
    hanoi(N-1, from, remain);
    procedure.push_back(make_pair(from, where));
    hanoi(N-1, remain, where);
}

int main(){
    int N; cin>>N;
    hanoi(N, 1, 3);
    cout<<procedure.size()<<'\n';
    for(pair<int, int> i : procedure){
        cout<<i.first<<" "<<i.second<<'\n';
    }
    return 0;
}