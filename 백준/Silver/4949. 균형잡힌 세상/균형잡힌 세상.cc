#include<iostream>
#include<stack>
using namespace std;
stack<char> st;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  string buf;
  while(1) {
    while(!st.empty()) st.pop();
    getline(cin, buf);
    if(buf[0] == '.') {
      break;
    }
    for(char t : buf) {
      if(t == '(') {
        st.push('(');
      }
      if(t == '[') {
        st.push('[');
      }
      if(t == ')') {
        if(st.empty() || st.top() != '(') {
          st.push('e');
          break;
        }
        else st.pop();
      }
      if(t == ']') {
        if(st.empty() || st.top() != '[') {
          st.push('e');
          break;
        }
        else st.pop();
      }
    }

    if(st.empty()) {
      cout<<"yes\n";
    }
    else cout<<"no\n";
  } 
}