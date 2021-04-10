#include <bits/stdc++.h>
using namespace std;

int fibo(int n) {
	if (n <= 1) return n;
	else return fibo(n - 1) + fibo(n - 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	cout << fibo(n);
}