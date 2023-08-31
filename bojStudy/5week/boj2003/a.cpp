#include <iostream>
using namespace std;

int arr[10000];
int N, M;

int solve()
{
    /*
     * 기존방식의 풀이도 있으나, 두 포인터를 이용한 더 빠른 풀이방법도 있다. 
     * sum 값이 M보다 커질 경우, 맨 앞의 start값을 증가시켜 O(N)으로 줄일수 있다.
     * 주석처리된 부분은 기존 방법, 새로이 작성된 부분은 새로운 방법을 사용하여 문제를 풀었다.
    */

    // int ans = 0;
    // int tmp = 0;
    // for(int i=0; i<N; ++i){
    //     tmp = 0;
    //     for(int j=i; j<N; ++j){
    //         tmp += arr[j];
    //         if(tmp == M){
    //             ans++;
    //             break; // 뒷부분은 해가 될 가능성이 없으므로 가지치기한다.
    //         }
    //     }
    // }
    // return ans;
    
    int h = 0, l = 0;
    int sum = 0, cnt = 0;
    for (int i = 0; i < N; ++i)
    {
    }
    while (1)
    {
        if (sum >= M)
            sum -= arr[l++];
        else if (h == N)
            break;
        else
            sum += arr[h++];

        if (sum == M)
            cnt++;
    }
    return cnt;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    cout << solve();
}