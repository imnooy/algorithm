#include <bits/stdc++.h>
using namespace std;

int main() {
	char a, b;
	list<char> li;

	string s;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		li.clear();
		cin >> s;
		auto cur = li.end();
		for (auto c : s) {
			if (c == '<') {
				if (cur != li.begin()) {
					cur--;
				}
			}
			else if (c == '>') {
				if (cur != li.end()) {
					cur++;
				}
			}
			else if (c == '-') {
				if (cur != li.begin()) {
					cur--;
					cur = li.erase(cur);
				}
			}
			
			else {
				li.insert(cur, c);
			}
		}
		for (auto c : li) cout << c;
		cout << '\n';
	}
}