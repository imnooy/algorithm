#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin.tie(0);

	int n;
	int arr[26];
	bool isdiff;
	string s1, s2;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2;
		isdiff = false;
		fill(arr, arr + 26, 0);
		for (int i = 0; i < s1.length(); i++) {
			arr[s1[i] - 'a']++;
			arr[s2[i] - 'a']--;
		}
		for (int j = 0; j < 26; j++) {
			if (arr[j] != 0) {
				isdiff = true;
				break;
			}
		}
		if (isdiff==false) cout << "Possible\n";
		else cout << "Impossible\n";
	}

	return 0;
}