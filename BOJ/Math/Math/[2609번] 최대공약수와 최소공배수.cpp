#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	int min;
	if (a < b) min = a;
	else min = b;
	int res = 0;

	for (int i = min; i >= 1; i--) {
		if (a%i == 0 && b%i == 0) {
			res = i;
			break;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;

	cin >> a >> b;
	int g = gcd(a, b);

	cout << g << '\n' << (a * b) / g;
}