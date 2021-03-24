#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a = 1;
	int b = 1; 
	int c = 1;
	vector<int> v;

	while (a != 0 && b != 0 && c != 0) {
		v.clear();
		cin >> a >> b >> c;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);

		sort(v.begin(), v.end());

		if (v[0] != 0 && v[1] != 0 && v[2] != 0) {
			if (((v[0] * v[0]) + (v[1] * v[1])) == (v[2] * v[2])) cout << "right" << '\n';
			else cout << "wrong" << '\n';
		}
	}
}