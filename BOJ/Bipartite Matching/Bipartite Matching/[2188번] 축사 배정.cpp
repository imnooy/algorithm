#include <bits/stdc++.h>
using namespace std;

int n, m; //�ҿ� ����� ��
bool arr[201][201]; //�ʱ� ���� ����
vector<int> amatch, bmatch;
vector<bool> visited; //dfs�湮����

bool dfs(int a) { //a ��Ī
	if (visited[a]) return false;

	visited[a] = true;
	for (int b = 0; b < m; b++) {
		if (arr[a][b]) {
			if (bmatch[b] == -1 || dfs(bmatch[b])) {
				amatch[a] = b;
				bmatch[b] = a;

				return true;
			}
		}
	}

	return false;
}

int bipartitematch() {
	amatch = vector<int>(n, -1);
	bmatch = vector<int>(m, -1);

	int size = 0;

	for (int st = 0; st < n; st++) {
		visited = vector<bool>(n, false);

		if (dfs(st)) size++;
	}

	return size;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b;

	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			arr[i][b - 1] = 1;
		}
	}

	cout << bipartitematch();
}