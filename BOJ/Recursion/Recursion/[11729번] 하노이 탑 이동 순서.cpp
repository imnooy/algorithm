#include <bits/stdc++.h>
using namespace std;

int N;


void func(int n, int a, int b) {
	if (n == 1) {
		cout << a << " " << b << '\n';
		return;
	}

	func(n - 1, a, 6 - b - a);
	cout << a << " " << b << '\n';
	func(n - 1, 6 - b - a, b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	cout << (1<<N) - 1 << '\n';
	func(N, 1, 3);
}