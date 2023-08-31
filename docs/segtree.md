# 세그먼트 트리

세그먼트 트리를 설명하기 이전에 이러한 자료구조가 어떻게 나오게 되었는지 알 필요성이 있어, 이부터 먼저 설명합니다.

많은 알고리즘들은 선형적 자료구조에 대한 해결책으로 $O(N)$ 방법을 제시합니다.

이에 저는 생각했습니다.
> 이를 더 최적화 시킬 순 없을까?  
> 이를 더 효율적으로 검색할 순 없을까?  
> **이 문제를 이분법적으로 접근하여 최적화 할 순 없을까?**

이는 선형적 자료구조의 대표 문제인 `정렬`에서도 나타납니다.

대부분의 일반적인 정렬은 $O(N^2)$의 시간복잡도를 제시합니다.
하지만 이는 생각보다 느리게 되어 많은 수의 배열을 정렬하기는 쉽지 않습니다.

이에 등장한 것 중 대표적인 두개가 `합병정렬`,`퀵정렬`입니다. 

두 정렬 전략에서 보이는 시간복잡도는 $O(N*log(N))$ 으로, 상당히 강력한 모습을 보여주며 실제 stl sort 에서도 부분적으로 사용되는 모습을 보여줍니다.

> 이들의 공통점이 보이십니까?

두 정렬의 공통점으로는 모두 `이분법적` 사고를 통해 접근했다라는 점입니다. 이러한 이분법적 분할정복 방식은 N의 시간복잡도를 $log_2$ $(N)$으로 줄이는 아주 강력한 방식임을 알 수 있습니다.

이에 저는 이러한 이분법적 사고를 보다 일반적으로 접근할 수 없을까 매번 고민해왔습니다. 네 그렇습니다.

**세그먼트 트리는 바로 이러한 선형적 자료구조에 대한 이분법적 접근을 보다 범용적으로 사용할 수 있도록 만들어줍니다**

비록 아직 제가 이 분야에 입문한 지 얼마 되지 않아 통찰력이 적지만, 세그먼트 트리는 **부분적인 배열에 대한 $O(log(N))$ 차원의 접근** 방법을 제시해줍니다.

## 세그먼트 트리

그래서 구체적으로 세그먼트 트리가 뭔지 모를수도, 감이 잡히셨을 수도 있습니다.

세그먼트 트리란, 특정 선형적 자료 구간에 대한 질의의 결과를 트리의 각 노드에 저장하고, 해당 노드의 왼쪽 자식을 해당 노드의 자료구간의 전반, 오른쪽 자식을 후반 구간으로 나누어 분할한 문제의 정답을 자식에 저장해놓은 트리구조라고 볼 수 있습니다.

### 예를 들어봅시다.

배열의 원소를 바꾼 후, 특정 구간의 합에 대한 결과를 우리는 $O(log N)$ 만에 구해야하는 상황이 있다고 가정합시다.

우리가 기존까지 직접 구현해온 $presum[]$ 배열로는 최악의 경우 배열의 원소를 바꿀 경우 $O(N)$ 의 시간 복잡도를 가지므로 해결할 수 없습니다.

세그먼트 트리는 위에서 설명한 트리구조라는 점을 이용하여 $ceil(log_2(N) + 1)$ (트리의 높이) 만큼의 비교를 통해 구할 수 있습니다. 네, $O(logN)$의 접근법을 제시해줍니다.

이후부터는 예시 문제로 보겠습니다.

## 예시 1 : [구간 합 구하기](https://boj.kr/2042)

위 문제에서 우리는 세그먼트 트리의 $init, update, get$ 의 3가지의 연산을 구현해보는 경험을 할 수 있습니다.

```cpp
// why not ac?
// boj : 2042

#include<bits/stdc++.h>
using namespace std;

long long segtree[4000005];
long long arr[1000001]; // 16mb

long long init(int start, int end, int index) {
  if(start == end) return segtree[index] = arr[start];
  int mid = (start + end) / 2;
  return segtree[index] = init(start, mid, index*2) + init(mid + 1, end, index*2 + 1);
}

long long getSum(int start, int end, int left, int right, int index) {
  // s, e : 검색되는 경계 / l, r : 검색하는 경계
  if(end < left || start > right) return 0;
  if(left <= start && end <= right) return segtree[index];
  int mid = (start + end)/2;
  return getSum(start, mid, left, right, index*2) + getSum(mid + 1, end, left, right, index*2+1);
}

void update(int s, int e, int idx, int node, long long d){
  if(e < idx || s > idx) return;
  segtree[node] += d;
  if(e == s) return;
  int mid = (s+e)/2;
  update(s, mid, idx, node*2, d);
  update(mid+1, e, idx, node*2 + 1, d);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,m,k; cin>>n>>m>>k;

  for(int i=1; i<=n; ++i) cin>>arr[i];

  init(1, n, 1);

  for(int i=0; i<m+k; ++i) {
    int a, b; long long c; cin>>a>>b>>c;
    if(a == 1) {
      long long dif = c - arr[b];
      arr[b] = c;
      update(1, n, b, 1, dif);
    }
    else {
      cout<<getSum(1, n, b, c, 1)<<'\n';
    }
  }
}
```