#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	int arr[26];
	int sum = 0;

	cin >> s1 >> s2;
	fill(arr, arr + 26, 0);
	for (int i = 0; i < s1.length(); i++) {
		arr[s1[i] - 'a']++;
	}

	for (int i = 0; i < s2.length(); i++) {
		arr[s2[i] - 'a']--;
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] < 0) sum += (arr[i] * (-1));
		else sum += arr[i];
	}

	cout << sum;

	return 0;
}