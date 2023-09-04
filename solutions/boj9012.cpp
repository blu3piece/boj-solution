// boj9012
// 대놓고 스택문제
// 연구 1 . 재귀로도 풀 수 있을것같은데, 어떻게 로직을 짜야할지 생각해보자.

#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool solve(){
    stack<char> st;
    string input;
    cin >> input;
    for(int i = 0; i<input.length(); i++){
        if(input[i] == '(') st.push('0');
        else if(!st.empty()) st.pop();
        else return false;
    }
    if(st.empty()) return true;
    else return false;
}

int main(){
    int t; cin>>t;
    while (t--) {
        if(solve()) cout<<"YES"<<'\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
