#include <bits/stdc++.h>
using namespace std;

int n;
string arr[51];

bool cmp3(const string &a, const string &b) {
	return a < b; //사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
}

bool cmp2(const string &a, const string &b) {
	int sz = a.length();
	int suma = 0, sumb = 0;
	for (int i = 0; i < sz; i++) { //A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
		if (a[i] >= 48 && a[i] <= 57) suma += a[i] - '0';
		if (b[i] >= 48 && b[i] <= 57) sumb += b[i] - '0';
	}
	if (suma == sumb) return cmp3(a, b); //3. 만약 1,2번 둘 조건으로도 비교할 수 없으면,
	return suma < sumb;
}

bool cmp1(const string &a, const string &b) { 
	if (a.length() == b.length()) return cmp2(a, b);//2. 만약 서로 길이가 같다면,
	else return a.length() < b.length(); //1. A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n, cmp1);

	for (int i = 0; i < n; i++) cout << arr[i] << '\n';

	return 0;
}