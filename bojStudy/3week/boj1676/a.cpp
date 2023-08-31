#include<iostream>
using namespace std;

int main(){
    int N; cin>>N;
    int count_2 = 0, count_5 = 0;
    while(N){
        int tmp = N--;
        int cnt = 2;
        while(tmp > 1){
            if(!(tmp%cnt)){
                if(cnt == 2) count_2++;
                if(cnt == 5) count_5++;
                tmp /= cnt;
            }
            else{
                cnt++;
            }
        }
    }
    int count_10 = 0;
    while(count_2-- && count_5--){
        count_10++;
    }
    cout<<count_10;
}