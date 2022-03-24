#include <bits/stdc++.h>
using namespace std;

/*
Counting Sort ��� 
-> �����ϰ��� �ϴ� ���Ұ� �����, ���� ũ���� �ִ� ������ ������ ���� �� ���
�񱳸� ����������, ����� ������ ������ �߰������� �ʿ�
*/
int cnt[10001]; //���� 10,000���� �۰ų� ���� �ڿ����̴�. 
//-> ������ �����������Ƿ� Counting Sort ���

int n, a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cnt[a]++; //1���� 10000������ ���� ���� ���� ����
	}

	for (int i = 1; i < 10001; i++) //�� ���ڰ�
		for (int j = 0; j < cnt[i]; j++) //���� ������ŭ
			cout << i << '\n'; //���

	return 0;
}