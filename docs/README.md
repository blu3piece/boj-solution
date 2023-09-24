# 랭작을 해봅시다.

## STL 기초 자료구조
> 이곳 바탕으로 만듬
> 
> https://ssinyoung.tistory.com/46
>
> *list vector 양이 많아서 도중에 이거 기초로 만듬*
>
> https://baactree.tistory.com/29
> 
> **공부를 위해 아예 전적으로 베꼈으니 윗글 참고하시는게 도움 더 됩니다.**
---

## 알고리즘 정리 문서

아래부터는 제가 직접 PS하면서 궁금했거나 몰랐거나 어려워하며 했던 생각들에 대한 내용을 적은 부분입니다.

### List

+ 양방향 연결리스트(노드 기반 메모리), 어느 위치 에서든 상수 시간 안에 추가 삭제 가능
+ 별도의 iterator 로 접근 가능하고, erase로 삭제 접근이 가능
+ remove 멤버 함수로 값으로 접근하여 삭제 가능
+ for each 문으로도 접근 가능, 이때 auto 형이 아니라 엄밀히 하기 위해선 list<int>::iterator 사용
+ 추가적으로 덧붙이자면 잘 안쓸것 같아 예제 코드는 올리지 않음.


### [Vector](/docs/stl/vector.md)

### Stack

모두가 아는 그것. LIFO(후입 선출) 을 만족하는 선형 자료구조이다.

```cpp
#include<stack>

stack<int> st;
st.push(int);
st.pop(); // 이때 원소값 출력
st.top();
st.empty();
st.size();
```
### Queue

모두가 아는 그것 2. FIFO(선입 선출) 을 만족하는 선형 자료구조이다.

```cpp
#include<queue>

queue<int> q;
q.push(4);
q.pop(); // 이때 원소값 출력
q.front();
q.back();
q.empty();
q.size();
```

### Deque

덱 이라고 부르던데 데큐라고도 부르더라. 앞 뒤 모든 곳에서 삽입 삭제가 가능한 선형 자료구조.  
사용 하는 이유는 앞뒤에서 작업할 때 속도가 O(1)을 보장하기 때문.

```cpp
#include<deque>

deque<int> dq;
dq.push_back(2);
dq.push_front(1);
dq.front();
dq.back();
```

### Set

밸런스트리, 레드블랙 트리로 만들어져있다. 따라서 검색 및 삽입 삭제 모두 O(logN) 을 보장한다.  
당연히 Set(집합) 이므로 중복을 허용하지 않는다.  
레드 블랙 트리는 구현해볼만하니 시간되면 구현해보자.

```cpp
#include<set>

set<int> s;
s.insert(5); // 원소 5 삽입
if(s.find(6) != s.end()) // 원소 검색방법
    cout<<"6이 존재합니다.\n";
s.size(); // 저장된 원소의 수 s.insert(5); 3번했다고 3이 되는게 아님
s.clear(); // 모든 원소 삭제
s.erase(++s.begin()); // 2번째 원소 삭제
```

### Map
파이썬의 딕셔너리, 자바스크립트의 객체와 비슷하다.  
set에 key와 value가 추가된 버전이라고 생각하면 된다.  
따라서 삽입 삭제 탐색 모두 O(log N)
```cpp
#include<map>

map<int, int> m; // key가 int고 value가 int 인 map
m.insert(make_pair(4, 5)); // 삽입 시 pair 자료형이 들어간다.
m[4]; // 5, 인덱싱할 때 key가 스트링이면 스트링으로도 인덱싱이 가능!
cout<<m.find(4)->second; // find 함수는 pair 포인터를 반환한다.
cout<<m.count(4); // key와 관련된 원소의 갯수를 리턴한다.
m.size();
m.clear();
```

### Pair
2개의 데이터를 쌍으로 묶어 저장할 수 있는 자료형  
비교 연산 시 first -> second 순으로 비교하게된다.  
```cpp
#include<utility>
// pair 가 아니라 utility 인거 조심
pair<int, int> pii_;
// 보통 개인 정의형 자료형으로 많이 정의시켜서 쓴다.
typedef pair<int, int> pii;
typedef pair<float, int> pfi;
typedef pair<vector<int>, int> pvi; // 등등..

pii_ = make_pair(4, 5); // pair 형으로 바로 전환해줌

```

### algorithm

자료형보단 알고리즘모음에 가깝다. sort 등의 유용한 알고리즘을 편하게쓰자~  

```cpp
#include<algorithm>

bool cmp (const int a, const int b) {
    return a>b; // 역순으로 정렬할 수 있도록 하는 개인 정렬함수를 정의하여 sorting 가능
}

int main(){
    vector<int> arr(1000);
    int narr[1000];
    
    sort(narr, narr + n); // arr의 N-1번째 원소(arr[n-1]까지 정렬
    sort(arr.begin(), arr.end()); // vector는 편하게 정렬가능
    sort(narr, narr+n, cmp);

    stable_sort(narr, narr+n); // 사용법은 같으나 안정적으로 sort한다. 
    // 둘의 차이점은 우선순위가 같은 여러 원소들 사이의 기존 위치가 바뀌지 않는다는 점.
    // 예 ) (3, d), (2, c), (2, d), (1, f)
    // 정렬 후 (2,c) 와 (2, d)의 순서는 바뀌지 않는다.

    // max, min 값 반환, 원소의 "주소"를 반환하니 주의할것
    *max_element(narr, narr+n);
    *min_element(narr, narr+n);
    
}
```

# 알고리즘

기초적인 알고리즘들을 정리해놓았습니다.  
알고리즘들의 아이디어들은 plzrun 님의 강의글을 참고하였습니다.  


## 정렬

정렬하기 전에 이진 탐색을 먼저 공부해두면 좋다. 이분법적 사고가 상당히 중요하다.

### 버블정렬/선택정렬/삽입정렬
응애 수준 정렬들이고 O(N^2) 라서 엄청 비효율적이지만,  
알고의 기초가 된다고 생각되어 넣어봤습니다.
```cpp
```
### [병합정렬](/docs/sort/merge_sort.md)

### [퀵 정렬](/docs/sort/quick_sort.md)

### [위상정렬](/docs/sort/topology_sort.md)

위상 정렬의 경우, 그래프 개념이 쓰이므로 주의

## 기초 구현 팁

내가 자주 실수하고 비효율적으로 하는 자료 구성에 대해 조금 잊어버리지 않기 위해 기록을 한다.

### 1. 미로 문제 (격자 자료구조의 구현)

미로 문제의 경우 칸을 더 넉넉하게 잡음으로써 경계 구분을 확인하는 코드 구현을 훨씬 쉽게 할 수 있다.

예를들어 단순한 4방향으로 움직이는 격자 모양 형태의 2차원 미로를 만들어서 움직이게 한다고 하자.

```cpp
#include<iostream>
using namespace std;
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

int maze[MAX_HEIGHT+2][MAX_WIDTH+2];

int main(){
    // ...
}
```

자료 크기를 걱정하지 않고 위와 같이 넉넉하게 배열을 잡아주자.  
이렇게 했을 경우, 실제 미로의 구현은 0~N-1 인덱스에 하는게 아니라,  
1 ~ N 에 구현을 하고, 0번 행/열, N+1째 행/열은 벽으로 설정하면 굳이 귀찮게 아래와 같은 불상사를 막을수가 있다.

```cpp
#include<iostream>
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

int main(){
    // 경계 설정
    if(0 < i && i <= N - 1 && /* 대충 엄청난 조건들*/) {

    }
    /* 위와 같은 개같은 구현을 윗 코드 블럭에서는 
    간단히 벽인지 아닌지만 확인하게 하면 간단히 
    해결 가능하다. */
}
```

### 2. 방향 프리셋 설정

나는 자료를 최대한 간단히 설정해야한다는 집착 때문에 매번 프리셋을 아래와 같이 설정해왔고,  
실제로 많은 사람들이 아직도 이렇게 구현을 한다.

```cpp
int dir[][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

// ... 프리셋 체크 시
for(int i=0; i<4; ++i) {
    int next_x = x + dir[i][0]; // 상당히 보기 껄끄러움..
}
```

위와 같은 부분은 그냥 자료를 나누어 저장하면된다.  
변수를 너어어무 많이 설정하는 것도 그렇지만, **그렇다고 쓸데없이 변수를 줄이는 것도 비효율적일 때가 많다.**

위와 같이 구현하지말고 아래처럼 구현하도록 하자.

```cpp
int dx = {-1, 0, 0, 1};
int dy = {0, 1, -1, 0};

for(int i=0; i<4; ++i) {
    int next_x = x + dx[i];
    int next_y = y + dy[i];
}
```

`그외에 더 좋은 구현 아이디어 없을까 ..?`

`코드가 가로로 길어지는 현상이 있으면 개선된 방식이 있다면, 메모하도록 하자`

## [Dynamic Programing](/docs/dp.md)

다이나믹 프로그래밍에 대한 문서

## Graph 이론

트리의 상위 개념인 그래프를 배워본다.  
개인적으로 트리보다 그래프가 더 쉬운거 같아 그래프부터 적는다.  

### DFS, BFS

DFS, BFS는 그래프를 순회하는 방법 중의 하나로,  
Depth First Search 와 Breadth First Search 의 줄임말이다.   
당연히 말 그대로 깊이 우선 너비 우선 탐색이다.  
알고리즘의 경우 구현이 생각보다 다양한데,  
dfs의 경우 visit 배열을 포함한 재귀, 스택으로 구현가능하고  
bfs의 경우 분기 기반일 경우 단순 while 문을 활용할 수 있고,  
그 외의 경우 queue 와 함께 while문 기반으로 검색가능하다.

`DFS`
```cpp
#include<vector>
#define MAX_N 1000

const int N = MAX_N;

bool visit[N];
vector<int> graph[N];

void dfs(int where){
    visit[where] = true; // 방문했을 경우 다시 탐색할 이유가 없다.
    for (int t : graph[where]) {
        if(!visit[t]) {
            // 방문하지 않았고 순회할 수 있는 점이 있는 경우
            dfs(t);
        }
    }
}
```

`BFS`

```cpp
#include<vector>
#define MAX_N 1000

const int N = MAX_N;

bool visit[N];
vector<int> graph[N];

void bfs(int where) {
    visit[where] = true; // where : 방문의 시작점
    queue<int> q; q.insert(where);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int t : graph[x]) {
            if(!visit[t]) {
                q.insert(t);
                visit[t] = true; // queue에 중복삽입 방지
            }
        }
    }
}
```

### 다익스트라

### 플로이드 와샬

### 벨만-포드 알고리즘

## 두 포인터

보통 일반적으로 배열을 순회할 때는 for 문을 돌려서 변수 1개로 순회를 한다.  
하지만 이렇게 되면, 배열에서의 **특정 조건을 만족하는 가장 짧은 길이, 부분배열의 합** 등과 같은 문제를 풀 때,  
포인터가 하나밖에 없으므로 두개의 for문을 중첩하여 사용한다.  

이렇게 될 경우, O(N^2)의 시간복잡도를 가지게 되어버리는데, 이렇게 될 경우 상당히 시간적으로 비효율적이다.  

따라서 두 포인터를 활용한 순회를 알아보자.  

이번에는 for문이 아닌, while 문으로 순회를 돈다.  
변수를 start, end 두개를 선언하고, start는 부분합의 시작지점, end는 부분합의 끝지점이다.  

조건을 과만족(더 빼도 되는 경우) start를 앞으로 가게하고,  
조건을 불만족할 경우 end를 앞으로 가게 하면서,

start <= end 인 경우를 찾아서 구하면된다.  
이때의 시간 복잡도는 최대 end를 1에서 N까지 간 후 start를 1에서 N까지 가게하는   
경우이므로 O(2N)이므로 **O(N)** 이다.  

이를 더 활용한게 이분탐색에서 사용하는 start/end 순회인 것 같다.  

```cpp
// 부분합에서 부분수열의 전체합이 S보다 작은 최소 길이를 가진 수열의 길이를 반환하는 프로그램
#include<iostream>
using namespace std;

int presum[100001];

int main(){
    int N, S; cin>>N>>S;
    int len = 0;
    for(int i=1; i<=N; ++i) {
        cin>>presum[i];
        presum[i] += presum[i-1];
    }
    int start = 0, end = 1; // 조사 범위를 start +1 부터 end 0까지를 범위로 잡았다.
    while(start < end) {
        if(presum[end] - presum[start] >= S){
            if(len == 0 || end - start < len) len = end - start;
            start++;
        }
        else {
            if(end == N) break;
            end++;
        }
    }
    cout<<len;
}
```

## 최소 신장 트리 (Minimum Spanning Tree)

최소 신장 트리란, 비용이 있는 그래프에서 비용을 최소로 하는 간선만 남기고, 모든 정점을 지나는 트리를 의미한다.  
알고리즘면에서 봤을 때는 가장 적은 비용으로 모든 노드를 연결하는 방법을 찾고자 할 때 쓰일 수 있을 것이다.  
최소 신장 트리 알고리즘은 대표적으로 2가지가 있는데 모두 실제 코딩테스트에서 자주 쓰이는 개념이므로,  
바로바로 쓰일 수 있도록 하자.  

### 4-1. Kruskal Algorithm

간선의 개수가 적은 경우 크루스칼 알고리즘을 활용한다.  

간선의 비용만 최소로하면 되므로, 간선을 우선 정렬하여 비용이 적은 간선부터 선택해나가는 알고리즘이다.
생각해보면 가장 단순한 방법이지만, 트리는 사이클이 생기지 않아야 하므로 사이클이 생기지 않게 해야한다.  

사이클을 없애는 방법은 **Union-Find** 알고리즘을 활용하면 된다.  
하나의 알고리즘 안에 두개의 이론이 있어서 헷갈릴 수 있지만, Union-find는 익혀두면 좋다.

### Union - Find 알고리즘 (분리 집합)

Union - find 알고리즘은 그래프 등에서 분리집합을 찾아내는 알고리즘이다.  
모든 정점들에 대한 부모값을 나타내는 parent[] 배열을 만들고, 해당 정점의 부모노드가 누구를 바라보는지  
반영하면된다.  

> 예를 들어 그래프가 `V({1, 2, 3, 4}), E({{1, 2}, {1, 3}, {2, 3}})`으로 이루어져 있을 때,  
>
> 초기 부모노드는 자신을 가르키는 배열을 가진다.
> ```js
> parent[] = { 1:1 , 2:2 , 3:3, 4:4};
> ```
> 1부터 4까지를 순회하는 반복문 내에서, 1과 인접한 노드들 중에 부모값이 자신보다 작은 숫자가 있는지를 확인한다.
>
> - 1과 인접한 노드는 2, 3 둘다 1보다 작으므로 무시
>
> 이후 2와 인접한 노드들 중에 부모값이 자신보다 작은 숫자가 있는지를 확인한다.
>
> - 2와 인접한 노드는 1, 3 중, parent값이 자신보다 작은 1이 있으므로 parent[2] = 1로 바꿔준다.
>
> - 3도 마찬가지 과정을 통해 parent[3] = 1이고,
>
> - 4는 인접한 노드가 없으므로 parent[4] = 4이다.
>```js
>console.log(parent) // {1:1, 2:1, 3:1, 4:4}
>```
> 

이렇게 보았을 때, parent 값이 같은 정점들은 모두 연결되어 있음을 의미한다.  
구현은 배열링크로 구현한다. 조금 복잡할 수 있으므로 다음부터 구현시 유의하도록 하자.  

```cpp
int getParent(int a) {
    if(parent[a] = a) return a;
    return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b, int V){
    // union a, b and update
    a = getParent(a);
    b = getParent(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

// 모두 연결되었는지 확인
bool allSet(int V){
    bool finish = true;
    for(int i=2; i<=V; ++i) {
        if(parent[1] == getParent(parent[i])) finish = false;
    }
    return finish;
}
```

---

이를 기반으로 최소 신장 트리를 구하는 알고리즘을 나열하면,

1. 간선들을 비용이 적은 순으로 정렬한다.
2. 간선을 우선순위 큐에서 pop 한다.
3. 간선이 나타내는 두 정점이 현재 스패닝 트리에서 같은 부모를 가르키는지 확인한다.
4. 그렇지않다면 두 정점의 parent 배열값을 더 작은 값으로 통일(union) 해주고, 간선을 MST에 포함시킨다.
4-1. 이때, 스패닝트리에 있는 다른 노드들에 대한 union도 모두 진행해주어야 합집합이 새로 정의됨을 주의한다.
5. 모든 parent 배열값이 같아질때까지 반복한다.

이를 코드로 옮기면 아래와 같아진다...

```cpp
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int, int> pii;

priority_queue<pair<int, pii>> pq; // 간선 우선순위
int parent[10001];

vector<pii> graph[10001];


int getParent(int a) {
    if(parent[a] = a) return a;
    return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b, int V){
    // union a, b and update
    a = getParent(a);
    b = getParent(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

bool allSet(int V){
    bool finish = true;
    for(int i=2; i<=V; ++i) {
        if(1 == getParent(parent[i])) finish = false;
    }
    return finish;
}

int kruskal(int V){
    int cost = 0;
    while(!pq.empty()) {
        int _cost = -pq.top().first;
        pii edge = pq.top().second;

        pq.pop();
        if(parent[edge.first] == parent[edge.second]) continue;

        unionParent(edge.first, edge.second, V);
        cost += _cost;
        if(allSet(V)) break;
    }
    return cost;
}

//main 에서의 자료구조 입력 형태

int main(){
    int V,E; cin>>V>>E;
    for(int i=1; i<=V; ++i) parent[i] = i;
    for(int i=0; i<E; ++i){
        int tmp1, tmp2, cost; cin>>tmp1>>tmp2>>cost;
        graph[tmp1].push_back(make_pair(tmp2, cost));
        graph[tmp2].push_back(make_pair(tmp1, cost));
        pq.push(make_pair(-cost, make_pair(tmp1, tmp2)));
    }
    cout<<kruskal(V);
}
```


### Prim Algorithm

간선의 개수가 많을 경우 크루스칼 알고리즘보다 프림 알고리즘이 유리한 경우가 많다.  

## ~~줫같은~~ 문자열

문자열이 엿같은 이유를 한번 씩 알아보자

### [최장 공통 수열(LCS)](/docs/str/lcs)