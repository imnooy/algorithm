#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[502]; //연결 상태
int aMatch[502];
int bMatch[502]; //연결된 상대 번호 저장
bool visited[502];

char arr[51][51];
int col[51][51];
int row[51][51];

bool chk[502];

int num;

bool dfs(int a) {
	if (visited[a]) return false;

	visited[a] = true;

	for (int i = 0; i < adj[a].size(); i++) {
		int b = adj[a][i];
		if (bMatch[b] == -1 || dfs(bMatch[b])) {
			aMatch[a] = b;
			bMatch[b] = a;

			return true;
		}
	}
	return false;
}

int bipartiteMatch() {
	memset(aMatch, -1, sizeof(aMatch));
	memset(bMatch, -1, sizeof(bMatch));
	int cnt = 0;

	for (int start = 1; start <= num; start++) {
		memset(visited, false, sizeof(visited));
		if (dfs(start)) cnt++;
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	num = 1;
	//행 넘버링
	for (int i = 0; i < n; i++) {
		if (chk[num]) num++;

		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '*') {
				col[i][j] = num;
				chk[num] = true;
			}
			else if (arr[i][j] == '.') {
				if (chk[num]) num++;
			}
		}
	}

	int tmp = num;
	num = 1;
	memset(chk, false, sizeof(chk));

	for (int i = 0; i < m; i++) {
		if (chk[num]) num++;
		for (int j = 0; j < n; j++) {
			if (arr[j][i] == '*') {
				row[j][i] = num;
				chk[num] = true;
			}
			else if (arr[j][i] == '.') {
				if (chk[num]) num++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (col[i][j] != 0) { //행 기준 넘버링된 곳일 때
				adj[col[i][j]].push_back(row[i][j]); //행 기준 넘버링된 곳에 연결
			}
		}
	}
	
	if (tmp > num) num = tmp;

	cout << bipartiteMatch();
}