#include <bits/stdc++.h>
using namespace std;

int main() {
	char a, b;
	list<char> li;

	string s;
	cin >> s;
	for (auto c : s) {
		li.push_back(c);
	}
	auto cur = li.end();

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (a == 'L') {
			if (cur != li.begin()) cur--;
		}
		else if (a == 'D') {
			if (cur != li.end()) cur++;
		}
		else if (a == 'B') {
			if (cur != li.begin()) {
				cur--;
				cur = li.erase(cur);
			}
		}
		else if (a == 'P') {
			cin >> b;
			li.insert(cur, b);
		}
	}

	for (auto c : li) cout << c;
}