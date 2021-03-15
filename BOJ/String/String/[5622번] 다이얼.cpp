#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int x;
	int sum = 0;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i]>=65 && s[i]<=67) {
			x = 3;
		}
		else if (s[i] >= 68 && s[i] <= 70) {
			x = 4;
		}
		else if (s[i] >= 71 && s[i] <= 73) {
			x = 5;
		}
		else if (s[i] >= 74 && s[i] <= 76) {
			x = 6;
		}
		else if (s[i] >= 77 && s[i] <= 79) {
			x = 7;
		}
		else if (s[i] >= 80 && s[i] <= 83) {
			x = 8;
		}
		else if (s[i] >= 84 && s[i] <= 86) {
			x = 9;
		}
		else if (s[i] >= 87 && s[i] <= 90) {
			x = 10;
		}
		sum += x;
	}

	cout << sum;

	return 0;
}