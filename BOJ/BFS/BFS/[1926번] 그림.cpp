#include <bits/stdc++.h>
using namespace std;

int arr[502][502];
bool vis[502][502];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	queue<pair<int, int>> q;
	vector<int> v; //그림들의 크기를 저장
	int size; //각 그림의 크기
	int num = 0; //그림 수
	int x, y;
	int a, b;
	bool isStart = false;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (a = 0; a < n; a++) {
		for (b = 0; b < m; b++) {			
			if (!arr[a][b] || vis[a][b]) { //1이 아니거나 방문했을 때는 start 아님
				continue;
			}
			num++;
			size = 0;
			q.push({ a, b }); //1
			vis[a][b] = 1;
			while (!q.empty()) { //4
				x = q.front().first;
				y = q.front().second;
				q.pop(); //2
				size++;
				for (int i = 0; i < 4; i++) { //2
					int xx = x + dx[i];
					int yy = y + dy[i];

					if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;

					if (!arr[xx][yy] || vis[xx][yy]) continue;

					vis[xx][yy] = 1;
					q.push({ xx, yy });
				}
				v.push_back(size);
			}
		}
	}

	int max = 0;
	if (v.size() != 0) {
		max = v[0];

		for (int i = 0; i < v.size(); i++) {
			if (v[i] > max) max = v[i];
		}
	}
	cout << num << '\n' << max;
}