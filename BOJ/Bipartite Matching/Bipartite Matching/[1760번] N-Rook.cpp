#include <bits/stdc++.h>
using namespace std;

#define MAX_N 102

int arr[MAX_N][MAX_N];
int col[MAX_N][MAX_N];
int row[MAX_N][MAX_N];

bool adj[5002][5002];
vector<int> aMatch, bMatch;
bool visited[5002];
bool isVisited;
int n, m;

bool dfs(int a) {
	if (visited[a]) return false;

	visited[a] = true;

	for (int b = 1; b <= m; b++) {
		if (adj[a][b]) {
			if (bMatch[b] == -1 || dfs(bMatch[b])) {
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
		}
	}

	return false;
}

int bipartiteMatch() {
	aMatch = vector<int>(n + 1, -1);
	bMatch = vector<int>(m + 1, -1);

	int cnt = 0;

	for (int start = 1; start <= n; start++) {
		fill(visited, visited + 5002, false);
		if (dfs(start)) cnt++;
	}

	return cnt;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	int num = 1;

	//행 기준 넘버링
	bool chk;
	for (int i = 1; i <= n; i++) {
		chk = false;
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 0 || arr[i][j] == 1) {
				col[i][j] = num;
				chk = true;
			}

			else {
				if (chk) {
					num++;
					chk = false;
				}
			}
		}
		if (chk) num++;
	}


	//열 기준 넘버링
	num = 1;
	for (int j = 1; j <= m; j++) {
		chk = false;
		for (int i = 1; i <= n; i++) {
			if (arr[i][j] == 0 || arr[i][j] == 1) {
				row[i][j] = num;
				chk = true;
			}

			else {
				if (chk) {
					num++;
					chk = false;
				}
			}
		}
		if (chk) num++;
	}

	int maxR = 0, maxC = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 0) {
				adj[row[i][j]][col[i][j]] = 1;

				maxR = max(maxR, row[i][j]);
				maxC = max(maxC, col[i][j]);
			}
		}
	}

	n = maxR;
	m = maxC; //넘버링된 것까지만 고려

	int ans = bipartiteMatch();

	cout << ans;

	return 0;

}