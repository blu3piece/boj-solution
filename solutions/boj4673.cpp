// boj4673
// 10000보다 작거나 같은 경우 이고, recursion 한 경우이기 때문에 완탐은 아예 관련이없음.
// recursion 한 경우고, 10000은 O(n^2) 100000000 이면 1초보다 작으므로, dp 를 생각해볼 수 있음.
// 1부터 차례로 시작해서 memoization 하면 가능할 것 같다.

#include<iostream>
using namespace std;

int main(){
    int selfVal[10001] = {0 ,}; // selfVal[n]에는 n의 생성자 개수가 들어감.
    for(int i = 1; i < 10000; i++){
        int value = i;
        int nextNum = 0;
        while(value){
            nextNum += value%10;
            value /= 10;
        }
        nextNum += i;
        if(nextNum <= 10000)
            selfVal[nextNum]++;
    }
    for(int i = 1; i<= 10000; i++){
        if(!selfVal[i]) cout<<i<<'\n';
    }
}
