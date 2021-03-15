#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, r;
	string s, rep;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> r >> s;
		for (int j = 0; j < s.size(); j++) {
			rep = "";
			for (int k = 0; k < r; k++) {
				rep += s[j]; //r번 더하기
			}
			cout << rep;
		}
		cout << endl;
	}

	return 0;
}