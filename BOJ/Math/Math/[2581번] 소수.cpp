#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, n;
	int sum = 0;
	cin >> m >> n;
	
	bool isPrime = true;

	vector<int> v;

	for (int i = m; i <= n; i++) {
		isPrime = true;
		if (i == 1) isPrime = false;
		if (i > 2) {
			for (int j = 2; j <= i - 1; j++) {
				if (i % j == 0) {
					isPrime = false;
				}
			}
		}
		if (isPrime == true) v.push_back(i);
	}

	int min;

	if (v.size() != 0) {
		min = v[0];
		for (int i = 0; i < v.size(); i++) {
			if (min > v[i]) min = v[i];
			sum += v[i];
		}
	}

	if (v.size() == 0) cout << "-1";
	else cout << sum << endl << min << endl;


	return 0;
}