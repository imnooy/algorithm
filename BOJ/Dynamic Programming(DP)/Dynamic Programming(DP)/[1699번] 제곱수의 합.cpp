#include <bits/stdc++.h>
using namespace std;

int d[100001];
int n;
vector<int> vec;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	d[0] = 0;
	for (int i = 1; i <= 100000; i++) {
		d[i] = i;
		if (sqrt(i) == (int)sqrt(i)) vec.push_back(i);
	}

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < vec.size(); j++) {
			if (vec[j] > i) continue;
			d[i] = min(d[i], d[i - vec[j]] + 1);
		}
	}
	cout << d[n];

	return 0;
}