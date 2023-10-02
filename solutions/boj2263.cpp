#include<iostream>
#include<utility>
using namespace std;

typedef pair<int, int> pii;

int idx[100001]; // inorder idx
int postorder[100001];
int inorder[100001]; 
int n;
pii tree[100001];

void preorder(int now) {
	cout << now << ' ';
	if (tree[now].first) preorder(tree[now].first);
	if (tree[now].second) preorder(tree[now].second);
}

int getTree(int instart, int inend, int poststart, int postend) {
	// start, end : post order 에서의 범위
	// return : 현재 start/end 범위를 트리로 하는 서브 트리의 root 노드.
	int root_idx = idx[postorder[postend]];
	int leftSize = root_idx - instart;
	int rightSize = inend - root_idx;

	if(leftSize > 0) tree[postorder[postend]].first = getTree(instart, root_idx - 1, poststart, poststart + leftSize - 1);
	if(rightSize > 0) tree[postorder[postend]].second = getTree(root_idx + 1, inend, poststart + leftSize, postend - 1);

	return postorder[postend]; // 사실 끝이 root임
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> inorder[i];
		idx[inorder[i]] = i;
	}
	for (int i = 0; i < n; ++i) cin >> postorder[i];
	preorder(getTree(0, n - 1, 0, n - 1));
}