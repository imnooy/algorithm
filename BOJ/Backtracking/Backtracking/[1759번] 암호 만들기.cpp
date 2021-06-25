#include <bits/stdc++.h>
using namespace std;

int m, n;
char arr[20];
char num[20];
bool isused[20];

void func(int k) { //k번째 자리 숫자 결정
	if (k == m) {
		bool aeiou = false;
		int notaeiou = 0;
		for (int i = 0; i < k; i++) {
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') aeiou = true;
			else notaeiou++;
		}
		if (aeiou && notaeiou >= 2) {
			for (int i = 0; i < k; i++) cout << arr[i];
			cout << '\n';
			return;
		}
		else return;
	}

	for (int i = 0; i < n; i++) {
		if ((k == 0 && !isused[i]) || (k > 0 && !isused[i] && arr[k - 1] < num[i])) {
			arr[k] = num[i];
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	func(0);
}