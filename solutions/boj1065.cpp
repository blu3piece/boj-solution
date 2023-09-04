// boj1065
// 범위가 작음 -> 완탐 생각?
// n^2 에서 1000^2 < 2초 이므로 완탐 가능.
#include<iostream>
using namespace std;

int main(){
    int N; cin>>N;
    if(N<100){
        cout<<N; // 99까지는 모든 자리수가 
        return 0;
    }
    int count = 99;
    for(int i = 100; i<=N && i<1000; i++){
        // 3자리만 체크하게 될거임
        if(((i/100)%10 - ((i%100)/10)%10) == (((i%100)/10)%10 - i%10))
            count++;
    }
    cout << count;
}
