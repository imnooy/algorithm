#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void change(string s) {
	int tmp = 0;
	string ss = "";
	if (s.length() == 1) { //±âÀú
		cout << cnt << '\n';
		if ((s[0] - '0') % 3 == 0) {
			cout << "YES";
		}
		else cout << "NO";

		return;
	}

	for (int i = 0; i < s.length(); i++) tmp += s[i] - '0';

	cnt++;
	change(to_string(tmp));
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	change(s);
}