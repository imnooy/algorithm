#include <iostream>
#include <set>
using namespace std;

int d(int n) {
	if (n > 100000) return 0;

	int m, x;
	int t = n;
	int result = 0;
	if (0 < n && n < 10) m = 1;
	else if (10 <= n && n < 100) m = 10;
	else if (100 <= n && n < 1000) m = 100;
	else if (1000 <= n && n < 10000) m = 1000;
	else if (n = 10000) m = 10000;

	for (int i = m; i >= 1; i /= 10) {
		x = n / i;
		result += x;
		n -= x * i;
	}
	result += t;

	return result;
}

int main() {
	set<int> s;
	
	for (int i = 1; i <= 10000; i++) {
		s.insert(d(i));
	}

	for (int i = 1; i <= 10000; i++) {
		if (s.find(i) == s.end()) cout << i << endl;
	}

	return 0;
}