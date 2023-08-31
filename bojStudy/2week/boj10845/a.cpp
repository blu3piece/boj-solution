#include<queue>
#include<iostream>
using namespace std;

queue<int> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t; string input;
    while(t--){
        cin>>input;
        if(input == "push"){
            int tmp; cin>>tmp;
            q.push(tmp);
        }
        else if(input == "pop"){
            if(q.empty()) cout<<-1<<'\n';
            else {
                cout<<q.front()<<'\n';
                q.pop();
            }
        }
        else if(input == "size") cout<<q.size()<<'\n';
        else if(input == "empty") cout<<q.empty()<<'\n';
        else if(input == "front"){
            if(q.empty()) cout<<-1<<'\n';
            else cout<<q.front()<<'\n';
        }
        else if(input == "back"){
            if(q.empty()) cout<<-1<<'\n';
            else cout<<q.back()<<'\n';
        }
    }
}