#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	bool is100 = false;
	int sum = 0;
	int m;

	for (int i = 0; i < 9; i++) {
		cin >> m;
		v.push_back(m);
		sum += m;
	}

	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 9; j++) {
			if (sum - (v[i] + v[j]) == 100) {
				v.erase(v.begin()+(i));
				v.erase(v.begin()+(j-1));
				is100 = true;
				break;
			}
		}
		if (is100) break;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < 7; i++) {
		cout << v[i] << '\n';
	}

	return 0;
}