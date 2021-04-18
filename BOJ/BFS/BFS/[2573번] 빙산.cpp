#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int arr[303][303];
int arr1[303][303];
bool vis[303][303];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool isarr1;
bool allmelt = false;

int n, m;


void melt() {
	int xx, yy;
	int count = 0;

	if (isarr1 == 0) { //현재 arr에 값이 있을 때
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] > 0) {
					allmelt = false;
					count = 0;
					for (int w = 0; w < 4; w++) {
						xx = i + dx[w];
						yy = j + dy[w];

						if (arr[xx][yy] == 0) count++;
					}
					arr1[i][j] = arr[i][j] - count;
					if (arr1[i][j] < 0) arr1[i][j] = 0;
				}
			}
		}
		fill(&arr[0][0], &arr[302][303], 0);
		isarr1 = 1;
	}


	else if (isarr1 == 1) { //현재 arr1에 값이 있을 때
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr1[i][j] > 0) {
					allmelt = false;
					count = 0;
					for (int w = 0; w < 4; w++) {
						xx = i + dx[w];
						yy = j + dy[w];

						if (arr1[xx][yy] == 0) count++;
					}
					arr[i][j] = arr1[i][j] - count;
					if (arr[i][j] < 0) arr[i][j] = 0;
				}
			}
		}
		fill(&arr1[0][0], &arr1[302][303], 0);
		isarr1 = 0;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	bool isZero = true;
	int a;
	int res = 0;
	int year = 0;
	int cnt = 0;
	int xx, yy;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			if (a != 0) isZero = false;
			arr[i][j] = a;
		}
	}

	isarr1 = false;

	if (isZero) {
		cout << 0;
		return 0;
	}

	while(1) {
		queue<pair<int, int>> q;
		pair<int, int> p;
		fill(&vis[0][0], &vis[302][303], 0);
		res = 0;

		if (allmelt) {
			cout << 0;
			return 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (isarr1 == 0) {
					if (arr[i][j] == 0) continue;
				}
				else if (isarr1 == 1) {
					if (arr1[i][j] == 0) continue;
				}
							
				if (vis[i][j]) continue;

				q.push({ i, j });
				vis[i][j] = 1;
				res++;

				while (!q.empty()) {
					p = q.front();
					q.pop();

					for (int w = 0; w < 4; w++) {
						xx = p.x + dx[w];
						yy = p.y + dy[w];

						if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
						if (vis[xx][yy]) continue;

						if (isarr1 == 0) {
							if (arr[xx][yy] == 0) continue;
						}
						else if (isarr1 == 1) {
							if (arr1[xx][yy] == 0) continue;
						}

						q.push({ xx, yy });
						vis[xx][yy] = 1;
					}
				}
			}
		}

		if (res >= 2) break;

		allmelt = true;
		melt();
		year++;
	}

	cout << year;
}