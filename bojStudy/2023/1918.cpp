// boj 1918
#include<bits/stdc++.h>
using namespace std;

stack<string> opend;
stack<string> oper;
string ans;

void merge() {
    string opend2 = opend.top(); opend.pop();
    string op_value(oper.top()); oper.pop();
    string opend1 = opend.top(); opend.pop();
    opend.push(opend1 + opend2 + op_value);
}

void calculate(string t) {
    if(oper.empty() || t == "("){
        oper.push(t);
        return;
    }
    if(t == ")" || t == "+" || t == "-") {
        while(!oper.empty() && oper.top() != "(")
            merge();
        if(t == ")" && oper.top() == "(") oper.pop();
        if(t == "+" || t == "-") oper.push(t);
    }
    else if(t == "*" || t == "/") {
        while(!oper.empty() && (oper.top() == "/" || oper.top() == "*"))
            merge();
        oper.push(t);
    }
}

int main(){
    string input; cin>>input;
    for(char k : input) {
        string t(1, k);
        if(t == "+" || t == "-" || t == "*" || t == "/" || t == ")" || t == "(") {
            calculate(t);
        }
        else opend.push(t);
    }
    while(!oper.empty()) merge();
    cout<<opend.top();
}