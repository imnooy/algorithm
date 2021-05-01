#include <bits/stdc++.h>
using namespace std;

bool cycle[100002];
bool vis[100002];
int arr[100002];
int ans = 0;

void check(int cur) {
	vis[cur] = 1;
	int next = arr[cur];

	if (!vis[next]) check(next);
	else if (!cycle[next]) {
		for (int i = next; i != cur; i = arr[i]) ans++;
		ans++;
	}
	cycle[cur] = 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a;	
	cin >> n;
	for (int i = 0; i < n; i++) {
		ans = 0;
		fill(&vis[0], &vis[0] + 100002, 0);
		fill(&cycle[0], &cycle[0] + 100002, 0);

		cin >> a;
		for (int j = 1; j <= a; j++) {
			cin >> arr[j];
		}
		for (int j = 1; j <= a; j++) {
			if (!vis[j]) check(j);
		}
		cout << a - ans << '\n';
	}
}