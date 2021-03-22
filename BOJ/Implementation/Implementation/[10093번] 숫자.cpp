#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	long long int a, b, c, d;
	long long int cnt = 0;
	cin >> a >> b;
	vector<long long int> v;

	if (a >= b) {
		c = a;
		d = b;
	}
	else {
		c = b; 
		d = a;
	}

	for (long long int i = d+1; i < c; i++) {
		v.push_back(i);
		cnt++;
	}

	cout << cnt << '\n';
	for (long long int i = 0; i < cnt; i++) {
		cout << v[i] << " ";
	}
	return 0;
}