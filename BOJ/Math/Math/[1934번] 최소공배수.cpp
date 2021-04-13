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



	int n;

	cin >> n;



	int a, b;



	for (int i = 0; i < n; i++) {

		cin >> a >> b;

		int g = gcd(a, b);



		cout << (a * b) / g << '\n';

	}

}