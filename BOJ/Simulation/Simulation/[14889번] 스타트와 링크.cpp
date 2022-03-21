#include <bits/stdc++.h>
using namespace std;

int n; //Â¦¼ö
int arr[25][25];

vector<int> team1;
vector<int> team2;
int minimum = 1001;

int a[25];

void calcuate() {
	int sum1 = 0;
	int sum2 = 0;
	
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			sum1 += arr[team1[i]][team1[j]];
			sum2 += arr[team2[i]][team2[j]];
		}
	}
	int res = abs(sum1 - sum2);
	minimum = min(res, minimum);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = n / 2; i < n; i++) a[i] = 1;

	do {
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				team1.push_back(i);
			}
			else team2.push_back(i);
		}
		calcuate();
		team1.clear();
		team2.clear();
	} while(next_permutation(a, a + n));

	cout << minimum;
	return 0;
}