#include <bits/stdc++.h>
using namespace std;

int arr[129][129];
int res[2];

void count(int x, int y, int n) { //시작점, 길이
	int tmp = arr[x][y];
	bool isdiff = false;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (tmp != arr[i][j]) {
				isdiff = true;
				break;
			}
		}
		if (isdiff) break;
	}

	if (!isdiff) res[tmp]++;
	else {
		count(x, y, n / 2);
		count(x, y + n / 2, n / 2);
		count(x + n / 2, y, n / 2);
		count(x + n / 2, y + n / 2, n / 2);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) cin >> arr[i][j];

	count(0, 0, n);

	cout << res[0] << '\n' << res[1];

}