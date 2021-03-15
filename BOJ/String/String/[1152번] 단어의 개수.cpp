#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int cnt = 0;

	istringstream str(s);
	string buffer;
	vector<string> x;

	while (getline(str, buffer, ' ')) {
		if (buffer != "") {
			x.push_back(buffer);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}