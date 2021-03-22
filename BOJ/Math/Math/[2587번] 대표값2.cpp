#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	int sum = 0;
	int a;

	for (int i = 0; i < 5; i++) {
		cin >> a;
		sum += a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	cout << sum / 5 << '\n' << v[2];


	return 0;
}