#include <bits/stdc++.h>
using namespace std;

int n, m;

int num[10];
int arr[10];
bool isused[10];

void func(int k) { //arr의 k번째 자리에 들어갈 것 구하기
	if (k == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!isused[i]) {
			arr[k] = num[i];
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	sort(num, num + n);

	func(0);
}