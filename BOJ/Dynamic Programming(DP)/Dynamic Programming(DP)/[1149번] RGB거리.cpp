#include <bits/stdc++.h>
using namespace std;

int r[1003];
int g[1003];
int b[1003];
int d[1003][3]; //i번째 집의 j가 0이면 r, 1이면 g, 2이면 b색깔 

int n;

int main() {
	ios::sync_with_stdio(0);  
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> r[i] >> g[i] >> b[i];
	}

	//초기값 설정
	d[1][0] = r[1];
	d[1][1] = g[1];
	d[1][2] = b[1];

	for (int i = 2; i <= n; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + r[i];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + g[i];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + b[i];
	}

	int res = min(d[n][1], d[n][2]);
	cout << min(res, d[n][0]);
	
	return 0;
}