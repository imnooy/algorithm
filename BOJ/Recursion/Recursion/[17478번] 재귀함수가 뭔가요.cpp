#include <bits/stdc++.h>
using namespace std;

int k;

void func(int n) {
	for (int i = 0; i < k - n; i++) cout << "____";
	cout << "\"����Լ��� ������?\"" << '\n';
	if (n == 0) {
		for (int i = 0; i < k - n; i++) cout << "____";
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << '\n';
		for (int i = 0; i < k - n; i++) cout << "____";
		cout << "��� �亯�Ͽ���." << '\n';
		return;
	}
	for (int i = 0; i < k - n; i++) cout << "____";
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << '\n';
	for (int i = 0; i < k - n; i++) cout << "____";
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << '\n';
	for (int i = 0; i < k - n; i++) cout << "____";
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << '\n';

	func(n - 1);

	for (int i = 0; i < k - n; i++) cout << "____";
	cout << "��� �亯�Ͽ���." << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';
	func(k);
}