#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int arr[102][102];
bool vis[102][102];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	set<int> s;
	vector<int> v;
	vector<int> res;
	pair<int, int> p;


	int cnt = 0;
	int n, xx, yy, in;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> in;
			arr[i][j] = in;
			s.insert(in);
		}
	}
	s.insert(0);

	for (auto i = s.begin(); i != s.end(); i++) {
		v.push_back( *i );
	}
	s.clear();

	for (int a = 0; a < v.size(); a++) {
		queue<pair<int, int>> q;
		cnt = 0;
		fill(&vis[0][0], &vis[101][102], 0);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] <= v[a]) continue;
				if (vis[i][j]) continue;

				q.push({ i, j });
				vis[i][j] = 1;
				cnt++;

				while (!q.empty()) {
					p = q.front();
					q.pop();

					for (int w = 0; w < 4; w++) {
						xx = p.x + dx[w];
						yy = p.y + dy[w];
						if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
						if (vis[xx][yy]) continue;
						if (arr[xx][yy] <= v[a]) continue;

						q.push({ xx, yy });
						vis[xx][yy] = 1;
					}
				}
			}
		}
		res.push_back(cnt);
	}

	sort(res.begin(), res.end());
	cout << res[res.size() - 1];
}