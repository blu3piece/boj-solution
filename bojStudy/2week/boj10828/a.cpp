#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    stack<int> st;
    while(t--){
        string cmd; cin>>cmd;
        if(cmd == "push"){
            int tmp; cin>>tmp;
            st.push(tmp);
        }
        else if(cmd == "top"){
            if(st.empty()){
                cout<<-1<<'\n';
            }
            else cout<<st.top()<<'\n';
        }
        else if(cmd == "size"){
            cout<<st.size()<<'\n';
        }
        else if(cmd == "empty"){
            cout<<st.empty()<<'\n';
        }
        else if(cmd == "pop"){
            if(st.empty()){
                cout<<-1<<'\n';
            }
            else{
                cout<<st.top()<<'\n';
                st.pop();
            }
        }
    }
}