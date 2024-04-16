#include<iostream>
using namespace std;

// V + Bx = Ax 인데, 정상위에 오를땐, A > B 이므로 B를 세지 않음.

// V - B = (A-B)x

int main(){
    long long a, b, v;
    cin>>a>>b>>v;
    cout<<(v-b)/(a-b) + (((v-b)%(a-b)) ? 1 : 0);
}