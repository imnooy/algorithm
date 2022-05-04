#include <bits/stdc++.h>
using namespace std;

string arr[5001];
long long d[5001]; //i번째 수까지 봤을 때 나올 수 있는 경우의 수

int main() {
	string str;
	cin >> str;

	if (str == "0") {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < str.length(); i++) {
		arr[i + 1] = str[i];
	}

	if (arr[1] != "0") d[1] = 1;
	else d[1] = 0;
	
	for (int i = 2; i <= str.length(); i++) {
		string stmp = arr[i - 1] + arr[i];
		if (stmp == "00") {
			break;
		}

		if (arr[i - 1] == "0") {
			d[i] = d[i - 1];
			continue;
		}

		int tmp = stoi(stmp);

		if (tmp >= 1 && tmp <= 26) {
			if (arr[i] == "0") {
				if (i - 2 > 0) d[i] = d[i - 2];
				else d[i] = d[i - 1];
			}
			else {
				if (i == 2) d[i] = (d[i - 1] * 2) % 1000000;
				else d[i] = (d[i - 1] + d[i - 2]) % 1000000;
			}
		}
		else {
			if (arr[i] == "0") d[i] = 0;
			else d[i] = d[i - 1];
		}
	}
	
	cout << d[str.length()] % 1000000;

	return 0;
}