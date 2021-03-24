#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool arr[250001];
	fill(arr, arr + 250000, true);
	int cnt;
	
	for (int i = 2; i <= 250000; i++) {
		if (arr[i] == true) {
			for (int j = i * 2; j <= 250000; j += i) {
				arr[j] = false;
			}
		}
	}
	int n = 1;
	while (n != 0) {
		cnt = 0;
		cin >> n;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i] == true)  cnt++;
		}
		if(n!=0) cout << cnt << '\n';
	}
}