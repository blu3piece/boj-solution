#include<iostream>
#include<stack>
using namespace std;

stack<int> st;
int arr[500001];

int main() {
	cin.tie(0); cout.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		while (1) {
			if (st.empty()) {
				cout << 0 << ' ';
				st.push(i);
				break;
			}
			int top = st.top();
			if (arr[top] > arr[i]) {
				cout << top << ' ';
				st.push(i);
				break;
			}
			else {
				st.pop();
			}
		}
	}
}