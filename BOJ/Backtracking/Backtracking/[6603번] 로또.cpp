#include <bits/stdc++.h>
using namespace std;

int n;

int arr[6];
int num[15];
bool isused[15];

void func(int k) {
	if (k == 6) {
		for (int i = 0; i < 6; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if ((k == 0 && !isused[i]) || (k > 0 && !isused[i] && arr[k - 1] < num[i])) {
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

	while (1) {
		fill(num, num + 15, 0);
		fill(isused, isused + 15, 0);
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) cin >> num[i];
		func(0);
		cout << '\n';
	}
}