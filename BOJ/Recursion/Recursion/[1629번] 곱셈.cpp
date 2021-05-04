#include <bits/stdc++.h>
using namespace std;

long long aa, bb, cc;

long long mul(long long a, long long b) {
	if (b == 0) return 1; //a^0=1
	long long tmp = mul(a, b / 2);
	tmp = tmp * tmp % cc;

	if (b % 2) return (tmp*a) % cc; //b가 홀수일 때
	else return tmp; //짝수일 때

	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//1승을 계산할 수 있다.
	//k승을 계산했으면 2k승과 2k+1승도 O(1)에 계산할 수 있다.

	cin >> aa >> bb >> cc;
	cout << mul(aa, bb);
}