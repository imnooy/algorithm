#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	for (char n = 'a'; n <= 'z'; n++) {
		if (s.find(n) != string::npos) {
			cout << s.find(n) << " ";
		}
		else cout << "-1 ";
	}
	return 0;
}