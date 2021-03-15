#include <iostream>
#include <string>
using namespace std;

int main() {
	string strs[8] = { "c=", "c-", "dz=",
	"d-", "lj", "nj", "s=", "z=" };

	string s;
	int cnt = 0;
	int count;
	cin >> s;

	while (1) {
		count = 0;
		for (int j = 0; j < 8; j++) {
			if (s.find(strs[j]) != string::npos) {
				s.replace(s.find(strs[j]), strs[j].size(), " ");
				cnt++;
				break;
			}
		}

		for (int j = 0; j < 8; j++) {
			if (s.find(strs[j]) == string::npos) {
				count++;
			}
		}
		if (count==8) break;
	}

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') cnt++;
	}


	cout << cnt;

	return 0;
}