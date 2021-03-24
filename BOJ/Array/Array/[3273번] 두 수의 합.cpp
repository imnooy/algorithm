#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a;
	int cnt = 0;
	cin >> n;
	bool arr1[1000001];
	fill(arr1, arr1 + 1000001, false);

	for (int i = 0; i < n; i++) { //n개의 정수를 입력받는다.
		cin >> a;
		arr1[a] = true;
	}
	cin >> m;

	for (int i = 1; i < m; i++) {
		if (arr1[i]) {
			if (arr1[m - i]) {
				if (i != (m - i)) {
					cnt++;
					arr1[m - i] = false;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}