// 복기를 위한 단순 완탐문제
#include<iostream>
using namespace std;

int info[50][2];
int N;

int solve(int num){
    int weight = info[num][0];
    int height = info[num][1];
    int ans = 1;
    for(int i = 0; i<N; ++i)
        if(i != num && info[i][0] > weight && info[i][1] > height) ++ans;
    return ans;
}

int main(){
    cin>>N;
    for(int i = 0; i<N; ++i) cin>>info[i][0]>>info[i][1];
    for(int i = 0; i<N; ++i) cout<<solve(i)<<' ';
    return 0;
}
