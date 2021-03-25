#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	list<int> li;
	vector<int> output;

	for (int i = 1; i <= n; i++) li.push_back(i);
	auto cur = li.begin();

	while (li.empty()==false) {
		for (int i = 0; i < k - 1; i++) {
			cur++;
			if (cur == li.end()) cur = li.begin();
		}
		output.push_back(*cur);
		cur=li.erase(cur);
		if (cur == li.end()) cur = li.begin();
	}
	cout << "<";
	for (int i = 0; i < n; i++) {
		if (i == n - 1) cout << output[i];
		else cout << output[i] << ", ";
	}
	cout << ">";
	
}