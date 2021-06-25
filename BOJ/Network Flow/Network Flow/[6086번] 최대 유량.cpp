#include <bits/stdc++.h>
using namespace std;

int c[52][52];
int f[52][52];

int main() {
	int n;
	char chfrom, chto;
	int from, to;
	int fl;

	vector<int> adj[52];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> chfrom >> chto >> fl;

		if ('A' <= chfrom && chfrom <= 'Z') from = chfrom - 'A';
		else from = chfrom - 'a' + 26;

		if ('A' <= chto && chto <= 'Z') to = chto - 'A';
		else to = chto - 'a' + 26;

		c[from][to] += fl;
		c[to][from] += fl;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	int totalflow = 0, S = 0, T = 'Z' - 'A';

	while (1) {
		int prev[52];
		fill(prev, prev + 52, -1);

		queue<int> q;
		q.push(S);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			int adjsize = adj[cur].size();

			for (int i = 0; i < adjsize; i++) {
				int next = adj[cur][i];
				if (prev[next] != -1) continue;
				if (c[cur][next] - f[cur][next] > 0) {
					q.push(next);
					prev[next] = cur;
					if (next == T) break;
				}
			}
		}

		if (prev[T] == -1) break;
		
		int flow = 1001;
		for (int i = T; i != S; i = prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		for (int i = T; i != S; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		totalflow += flow;
	}

	cout << totalflow;
}