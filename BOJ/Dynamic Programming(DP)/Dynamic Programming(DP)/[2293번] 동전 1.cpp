#include <bits/stdc++.h>
using namespace std;

int arr[101];
int d[10001]; //i원 만들 수 있는 방법 수

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	d[0] = 1; //0원 만들 수 있는 방법 수 1 (아무 동전 안 쓸 때)

	for (int i = 1; i <= n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			//만약 i=2, j=3이라고 하면, 
			//2동전의 가치는 3원 (arr[2]=3이라 가정)
			//3원의 가치로(2동전으로) j원의 가치들 만드려면
			//1. j=3, d[3]+=d[0] -> 0원에서 3원만드려면 
			//0원의 가치를 만드는 방법이 있으면 됨 -> 3 더하면 되니까

			//2. j=4, d[4]+=d[1] -> 1원에서 4원만드려면
			//1원의 가치를 만드는 방법 있으면 됨 -> 2동전(3원) 더하면 되니까
			//... k가치까지 계속
			d[j] += d[j - arr[i]];
		}
	}

	cout << d[k];

	return 0;
}