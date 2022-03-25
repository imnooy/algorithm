#include <bits/stdc++.h>
using namespace std;

int n;
string arr[51];

bool cmp3(const string &a, const string &b) {
	return a < b; //���������� ���Ѵ�. ���ڰ� ���ĺ����� ���������� �۴�.
}

bool cmp2(const string &a, const string &b) {
	int sz = a.length();
	int suma = 0, sumb = 0;
	for (int i = 0; i < sz; i++) { //A�� ��� �ڸ����� �հ� B�� ��� �ڸ����� ���� ���ؼ� ���� ���� ������ ���� �����´�. (������ �͸� ���Ѵ�)
		if (a[i] >= 48 && a[i] <= 57) suma += a[i] - '0';
		if (b[i] >= 48 && b[i] <= 57) sumb += b[i] - '0';
	}
	if (suma == sumb) return cmp3(a, b); //3. ���� 1,2�� �� �������ε� ���� �� ������,
	return suma < sumb;
}

bool cmp1(const string &a, const string &b) { 
	if (a.length() == b.length()) return cmp2(a, b);//2. ���� ���� ���̰� ���ٸ�,
	else return a.length() < b.length(); //1. A�� B�� ���̰� �ٸ���, ª�� ���� ���� �´�.
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