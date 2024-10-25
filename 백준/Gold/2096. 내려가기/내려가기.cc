#include<iostream>
#include<algorithm>
using namespace std;

int mat[100001][3];
int max_dp[2][3];
int min_dp[2][3];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin>>N;

    for(int i=1; i<=N; ++i) {
        for(int j=0; j<3; ++j) {
            cin>>mat[i][j];
            if (i == N) min_dp[0][j] = max_dp[0][j] = mat[i][j];
        }
    }
    
    for(int i=N-1; i>=1; --i) {
        for(int i=0; i<3; ++i) {
            max_dp[1][i] = max_dp[0][i];
            min_dp[1][i] = min_dp[0][i];
        }

        int left_max = max(max_dp[1][0], max_dp[1][1]);
        int left_min = min(min_dp[1][0], min_dp[1][1]);
        int right_max = max(max_dp[1][2], max_dp[1][1]);
        int right_min = min(min_dp[1][2], min_dp[1][1]);

        max_dp[0][0] = mat[i][0] + left_max;
        max_dp[0][2] = mat[i][2] + right_max;
        max_dp[0][1] = mat[i][1] + max(left_max, right_max);

        min_dp[0][0] = mat[i][0] + left_min;
        min_dp[0][2] = mat[i][2] + right_min;
        min_dp[0][1] = mat[i][1] + min(left_min, right_min);
    }
    cout<<max(max_dp[0][0], max(max_dp[0][1], max_dp[0][2]))<<' '<< min(min_dp[0][0], min(min_dp[0][1], min_dp[0][2]));
}