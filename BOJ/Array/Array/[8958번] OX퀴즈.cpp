#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	int sum = 0;
	int res = 0;
	cin >> n;

	string *arr = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] == 'O') {
				sum += 1;
			}
			res += sum;
			if (arr[i][j + 1] != 'O') {
				sum = 0;
			}
		}
		cout << res << endl;
		res = 0;
	}

	return 0;
}