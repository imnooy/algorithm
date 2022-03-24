#include <bits/stdc++.h>
using namespace std;

int a[1000001], b[1000001], c[2000002];
int n, m;

int a_index = 0, b_index = 0;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false); //²À ¾²ÀÚ..
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int j = 0; j < m; j++) cin >> b[j];

	for (int i = 0; i < n + m; i++) {
		if (a_index >= n) {
			c[i] = b[b_index++];
			continue;
		}
		else if (b_index >= m) {
			c[i] = a[a_index++];
			continue;
		}

		if (a[a_index] > b[b_index]) c[i] = b[b_index++];
		else c[i] = a[a_index++];
	}

	for (int i = 0; i < n+m; i++)	
		cout << c[i] << " ";
	return 0;
}