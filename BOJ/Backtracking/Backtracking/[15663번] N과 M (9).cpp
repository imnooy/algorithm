#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[10];
int arr[10];
bool isused[10];

void func(int k) { //arr의 k번째 자리에 놓을 숫자 결정
	if (k == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	int tmp = -1;
	
	for (int i = 0; i < n; i++) { //num의 index인 i -> num[i]를 k번째 자리에 놓고 ++.
		if (!isused[i] && tmp != num[i]) {
			arr[k] = num[i];
			tmp = num[i];
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
	for (int i = 0; i < n; i++) cin >> num[i];
	
	sort(num, num + n);

	func(0);
}