#include<iostream>
#include<deque>
using namespace std;

deque<int> dq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t; string input;
    while(t--){
        cin>>input;
        if(input == "push_front"){
            int tmp; cin>>tmp;
            dq.push_front(tmp);
        }
        if(input == "push_back"){
            int tmp; cin>>tmp;
            dq.push_back(tmp);
        }
        if(input == "pop_front"){
            if(dq.empty()) cout<<-1<<'\n';
            else{
                cout<<dq.front()<<'\n';
                dq.pop_front();
            }
        }
        if(input == "pop_back"){
            if(dq.empty()) cout<<-1<<'\n';
            else{
                cout<<dq.back()<<'\n';
                dq.pop_back();
            }
        }
        if(input == "size") cout<<dq.size()<<'\n';
        if(input == "empty") cout<<dq.empty()<<'\n';
        if(input == "front"){
            if(dq.empty()) cout<<-1<<'\n';
            else cout<<dq.front()<<'\n';
        }
        if(input == "back"){
            if(dq.empty()) cout << -1 << '\n';
            else cout<<dq.back() << '\n';
        }
    }
}