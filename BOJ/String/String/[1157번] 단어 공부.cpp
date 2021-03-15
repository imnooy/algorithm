#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s, rep;
	cin >> s;
	int cnt[26] = { 0 };

	transform(s.begin(), s.end(), s.begin(), ::toupper);

	for (int i = 0; i < s.size(); i++) {
		for (char j = 'A'; j <= 'Z'; j++) {
			if (s[i] == j) {
				cnt[j-65]++;
			}
		}
	}

	int max = cnt[0];
	int index=0;
	string out;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] > max) {
			max = cnt[i];
			index = i;
		}
	}
	out = char(index + 65);

	for (int i = 0; i < 26; i++) {
		if (index == i) continue;
		if (cnt[i] == max) out = "?";
	}

	cout << out;
	return 0;
}