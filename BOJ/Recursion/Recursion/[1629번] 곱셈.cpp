#include <bits/stdc++.h>
using namespace std;

long long aa, bb, cc;

long long mul(long long a, long long b) {
	if (b == 0) return 1; //a^0=1
	long long tmp = mul(a, b / 2);
	tmp = tmp * tmp % cc;

	if (b % 2) return (tmp*a) % cc; //b�� Ȧ���� ��
	else return tmp; //¦���� ��

	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//1���� ����� �� �ִ�.
	//k���� ��������� 2k�°� 2k+1�µ� O(1)�� ����� �� �ִ�.

	cin >> aa >> bb >> cc;
	cout << mul(aa, bb);
}