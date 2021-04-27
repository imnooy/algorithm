#include <bits/stdc++.h>
using namespace std;

bool vis[2][500001]; //홀수는 1, 짝수는 0에 

int main() {
	int n, k;
	int time = 0;
	queue<pair <int, int>> q;
	pair<int, int> p;
	int t = 0;

	cin >> n >> k;

	q.push({ 0, n }); //홀수or짝수 시간, 위치 push
	vis[0][n] = 1;
	int sistime;


	while (!q.empty()) {
		p = q.front();
		q.pop();

		sistime = k + ((p.first*(p.first + 1)) / 2);

		if (sistime > 500000) break;

		if (vis[p.first % 2][sistime] || p.second == sistime) { //동생 위치에 이미 방문했거나, 언니 위치가 동생 위치일 때
			cout << p.first;
			return 0;
		}

		int dx[3] = { -1, 1, p.second };

		for (int i = 0; i < 3; i++) {
			if (p.second + dx[i] < 0 || p.second + dx[i] > 500000) continue;
			if (vis[(p.first + 1) % 2][p.second + dx[i]]) continue;
			q.push({ p.first + 1, p.second + dx[i] });
			vis[(p.first + 1) % 2][p.second + dx[i]] = 1;
		}
	}

	cout << -1;
	return 0;
}