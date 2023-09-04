// boj 3649
/*
    이진 탐색을 할 때 start 부분을 i + 1 부터 돌리는게 핵심
    왠지는 모르겠지만 계속 연구중
    => 0부터 검색해버리면, 만약 찾고자 하는 값이 동일 한 경우 [(X/2)가 레고 리스트에 있다거나]
    자기 자신도 검색이 되버리기 때문에 오류가 나온다.
    결국 바운데리 오류가 맞았음.

    위 예시의 반례 : 1 5 1 2 3 4 5000000
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  while (1) {
    int X, N;
    if (cin >> X) {
      vector<int> v;
      cin >> N;
      for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
      }

      sort(v.begin(), v.end());

      bool found = false;
      int t1, t2;

      for (int i = 0; i < N && !found; ++i) {
        int s = 0, e = N - 1;
        t1 = v[i];
        t2 = X * 10000000 - t1;
        while (s <= e) {
          int mid = (s + e) / 2;

          if (v[mid] == t2) {
            found = true;
            break;
          } else if (v[mid] < t2)
            s = mid + 1;
          else
            e = mid - 1;
        }
      }

      if (!found)
        cout << "danger\n";
      else cout << "yes " << t1 << ' ' << t2 << '\n';

    } else break;
  }
  return 0;
}