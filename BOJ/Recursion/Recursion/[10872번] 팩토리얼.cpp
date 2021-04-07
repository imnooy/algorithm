#include <bits/stdc++.h>
using namespace std;

int n;

int recursion(int n) {
	if (n <= 0) return 1;
	return n * recursion(n - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	cout << recursion(n);
}