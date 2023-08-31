#include<iostream>
#include<map>
using namespace std;

map<int, int> m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin>>N;
    for(int i=0; i<N; ++i){
        int tmp; cin>>tmp;
        auto cursor = m.find(tmp);
        if(cursor == m.end()){
            m.insert(make_pair(tmp, 1));
        }
        else cursor->second++;
    }
    cin>>M;
    for(int i=0; i<M; ++i){
        int tmp; cin>>tmp;
        auto cursor = m.find(tmp);
        if(cursor == m.end()){
            cout<<"0 ";
        }
        else cout<<cursor->second<<' ';
    }
}