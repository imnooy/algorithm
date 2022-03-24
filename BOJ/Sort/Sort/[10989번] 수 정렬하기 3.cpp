#include <bits/stdc++.h>
using namespace std;

/*
Counting Sort 사용 
-> 정렬하고자 하는 원소가 양수고, 원소 크기의 최대 범위가 정해져 있을 때 사용
비교를 하지않지만, 결과를 저장할 공간이 추가적으로 필요
*/
int cnt[10001]; //수는 10,000보다 작거나 같은 자연수이다. 
//-> 범위가 정해져있으므로 Counting Sort 사용

int n, a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cnt[a]++; //1부터 10000까지의 수가 나온 개수 저장
	}

	for (int i = 1; i < 10001; i++) //각 숫자가
		for (int j = 0; j < cnt[i]; j++) //나온 개수만큼
			cout << i << '\n'; //출력

	return 0;
}