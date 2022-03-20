#include <bits/stdc++.h>
using namespace std;

int arr[505][505];

vector<pair<int, int>> shape; //�� 4�� ��ǥ
vector<vector<pair<int, int>>> shapes;

int n, m;
int a[16];

bool isIn(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first && abs(p1.second - p2.second) == 1) return true;
	if (p1.second == p2.second && abs(p1.first - p2.first) == 1) return true;
	return false;
}

bool search() { //2���̻�� ������ ĭ�� 1���� �ִ���
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (isIn(shape[i], shape[j])) cnt++;
		}
		if (cnt == 0) return false;
		if (cnt >= 2) flag = true;
	}
	return flag;
}

int main() {
	cin >> n >> m;
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 4; i < 16; i++) a[i] = 1;

	do { //��Ʈ�ι̳� �����
		shape.clear();
		for (int i = 0; i < 16; i++) { //4*4���� ��Ʈ�ι̳븸��� (�ִ� �� ���� 4)
			if (a[i] == 0) {
				shape.push_back({ i / 4, i % 4 });
			}
		}
		if (search()) shapes.push_back(shape);
	} while (next_permutation(a, a + 16));
	
	for (int i = 0; i <= n - 4; i++) {
		for (int j = 0; j <= m - 4; j++) { //������ -> ���⼭���� ���� �׷�����
			for (auto shape : shapes) {
				int sum = 0;
				for (auto coor : shape) {
					sum += arr[i + coor.first][j + coor.second];
				}
				res = max(sum, res);
			}
		}
	}
	cout << res;
	return 0;
}
