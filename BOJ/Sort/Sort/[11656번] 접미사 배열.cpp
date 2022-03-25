#include <bits/stdc++.h>
using namespace std;

string s;
string arr[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		arr[i] = s.substr(i, s.length());
	}

	sort(arr, arr + s.length());

	for (int i = 0; i < s.length(); i++) cout << arr[i] << '\n';

	return 0;
}