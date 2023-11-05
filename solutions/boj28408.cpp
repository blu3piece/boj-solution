/**
 * @file boj28408.cpp
 * @author johannblue
 * 
 * 나무 늘보
 * 
 * 단순히 전위 순회와 후위 순회를 통해 트리를 구성하는 문제입니다.
 * 
 * 전위순회의 순서가 노드 -> 왼쪽 자식 -> 왼쪽 자식 ... 임을 알아야합니다.
 * 단, 여기서 끝이 아니라, 후위 순회의 순서도 마지막 왼쪽 자식 -> 해당 자식의 부모임을 알아야합니다.
 * 
 * 이것 두개를 통해서 유추할 수 있는 사실은 이겁니다.
 * 
 * 전위 순회의 순서대로 방문한 노드로 깊이가 결정되고, 이때 후위순회의 순서대로 방문한 점이 일치할 때,
 * 
 * 해당 노드는 자식 노드이고, 위로 올라갈 수 있다는 점
 * 
 * 또한, 그 다음 후위 순회의 순서가 이미 방문한 점이라면, 다음 전위 순회의 방문 노드는,
 * 현재 지점 보다 위의 지점의 자식일 것이라는 점입니다.
 * 
 * 설명하기가 어려우니 좀 더 공부해서 블로그에 올려야겠습니다.
 * 
 */

#include<iostream>
#include<vector>
using namespace std;

typedef struct Node {
	int child_count = 0;
	int num = 0;
	struct Node* parent;
} Node;

Node mem[500001];
int n;

int post[500001]; // 후위 순회
int pre[500001]; // 전위 순회
int visit[500001];

int post_cursor;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> pre[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> post[i];
	}

	if (pre[0] != post[n - 1]) {
		cout << 0;
		return 0;
	}
	int idx = 0;
	bool valid = true;
	Node* now_node = nullptr;

	for (int i = 0; i < n; ++i) {
		visit[pre[i]] = true;

		if (!valid) break;

		Node* tmp = &mem[idx++];
		tmp->parent = now_node;
		tmp->num = pre[i];
		now_node = tmp;
		if (tmp->parent) {
			tmp->parent->child_count++;
			if (tmp->parent->child_count > 2) {
				valid = false;
				break;
			}
		}

		while (visit[post[post_cursor]]) {
			
			// 트리가 완성된 상태에서는 post order가 정확해야할 거임
			if (i == n - 1 && now_node->num != post[post_cursor]) {
				valid = false;
				break;
			}

			// 모를때까지 post_cursor를 올려준다.
			now_node = now_node->parent;
			if (now_node == nullptr) {
				if(i != n-1) valid = false;
				break;
			}
			
			post_cursor++;
		}
		
	}
	int ans = 1;
	const int MOD = 998244353;
	if (!valid) {
		cout << 0;
		return 0;
	}
	// cout << post_cursor << '\n';
	for (int i = 0; i < idx; ++i) {
		// cout << mem[i].child_count << ' ';
		if (mem[i].child_count == 1) {
			ans *= 2;
			ans %= MOD;
		}
	}
	// cout << '\n';
	cout << ans;
}