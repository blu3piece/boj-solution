#include<iostream>
#include<cstring>
using namespace std;

int dirType[2][2] = {
	{1, 0},
	{0, 1}
};

typedef struct shark {
	bool dead = false;
	int y = 0;
	int x = 0;
	int dirType = 0; // 0 : 위 아래 / 1 : 왼 오른
	int speed = 0; // 스피드가 마이너스 : 위쪽 혹은 왼쪽으로 이동.
	int size = 0;
} shark;

shark sharks[10001];

int R, C;
int map[101][101];

void move_shark(int num, int r, int c) {
	shark next_pos = sharks[num];
	r = r + dirType[next_pos.dirType][0]*next_pos.speed;
	c = c + dirType[next_pos.dirType][1]*next_pos.speed;
	
	while (0 >= r || r > R) {
		next_pos.speed *= -1;
		if (r <= 0) {
			r -= 2;
			r *= -1;
		}
		else {
			r = R - (r - R);
		}
	}
	while (0 >= c || c > C) {
		next_pos.speed *= -1;
		if (c <= 0) {
			c -= 2;
			c *= -1;
		}
		else {
			c = C - (c - C);
		}
	}

	next_pos.y = r;
	next_pos.x = c;
	sharks[num] = next_pos;

	if (map[r][c]) {
		if (sharks[num].size < sharks[map[r][c]].size) {
			sharks[num].dead = true;
			return;
		}
		sharks[map[r][c]].dead = true;
		map[r][c] = num;
	}
	else map[r][c] = num;
}

int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	int M; cin >> R >> C >> M;
	for (int i = 1; i <= M; ++i) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		sharks[i].size = z;
		sharks[i].y = r;
		sharks[i].x = c;
		map[r][c] = i;
		if (d == 1) {
			sharks[i].dirType = 0;
			sharks[i].speed = -s;
		}
		else if (d == 2) {
			sharks[i].dirType = 0;
			sharks[i].speed = s;
		}
		else if (d == 3) {
			sharks[i].dirType = 1;
			sharks[i].speed = s;
		}
		else {
			sharks[i].dirType = 1;
			sharks[i].speed = -s;
		}
	}
	int ans = 0;
	for (int i = 1; i <= C; ++i) {
		for (int j = 1; j <= R; ++j) {
			if (map[j][i]) {
				sharks[map[j][i]].dead = true;
				ans += sharks[map[j][i]].size;
				break;
			}
		}

		for (int t = 1; t <= R; ++t) {
			memset(map[t], 0, sizeof(map[t]));
		}

		for (int j = 1; j <= M; ++j) {
			if (sharks[j].dead) continue;
			move_shark(j, sharks[j].y, sharks[j].x);
		}
	}
	cout << ans;
}