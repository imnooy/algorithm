#include <bits/stdc++.h>
using namespace std;

int n, k;
bool adj[502][502];
vector<int> aMatch, bMatch;

vector<bool> visited;

bool dfs(int a) { 
	if (visited[a]) return false;

	visited[a] = true;

	for (int b = 0; b < n; b++) {
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
	aMatch = vector<int>(n, -1);
	bMatch = vector<int>(n, -1);

	int cnt = 0;
	for (int start = 0; start < n; start++) {
		visited = vector<bool>(n, false);
		if (dfs(start)) cnt++;
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	int a, b;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		adj[a - 1][b - 1] = 1;
	}

	cout << bipartiteMatch() << '\n';
}