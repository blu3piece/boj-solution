#include<iostream>
using namespace std;

// naive : brute force 로 255부터 땅고르기하면서 든 비용 계산.
// 계산 이전에 총 땅 칸의 개수가 배치 + 인벤토리 내 블럭 개수보다 많다면 스킵한다.

int arr[500][500];
int n, m, b;
int total; // total : 블럭의 총 개수.

int best_h = -1, best_op;

int main () {
  cin.tie(0)->sync_with_stdio(0);
  cin>>n>>m>>b;
  total = b;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      cin>>arr[i][j];
      total += arr[i][j];
    }
  }
  for(long long h=256; h>=0; --h) {
    if(h*m*n > total) continue;
    int cand = 0;
    for(int i=0; i<n; ++i) {
      for(int j=0; j<m; ++j) {
        if(arr[i][j] < h) {
          cand += (h - arr[i][j]);
        }
        else if(arr[i][j] > h) {
          cand += 2*(arr[i][j] - h);
        }
      }
    }
    if(best_h == -1 || best_op > cand) {
      best_h = h;
      best_op = cand;
    }
  }
  cout<<best_op<<' '<<best_h;
}