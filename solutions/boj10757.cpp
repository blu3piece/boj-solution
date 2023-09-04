#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    string a, b, sum;
    cin>>a>>b;
    int c = 0;
    stack<char> sta, stb, stsum;

    for(int i = 0; i<a.length(); ++i){
        sta.push(a[i]);
    }
    for(int j = 0; j<b.length(); ++j){
        stb.push(b[j]);
    }

    while(!sta.empty() && !stb.empty()){
        c = (sta.top() - 48) + (stb.top() - 48) + c;
        stsum.push(c%10);
        c /= 10;
        sta.pop(); stb.pop();
    }
    while(!sta.empty()){
        c = (sta.top() - 48) + c;
        stsum.push(c%10);
        c /= 10;
        sta.pop();
    }
    while(!stb.empty()){
        c = (stb.top() - 48) + c;
        stsum.push(c%10);
        c /= 10;
        stb.pop();
    }
    if(c) stsum.push(c);
    for(int i = 0; !stsum.empty(); ++i){
        sum += stsum.top() + 48;
        stsum.pop();
    }
    cout<<sum;
    return 0;
}