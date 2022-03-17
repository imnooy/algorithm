#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int arr[55][55];
int ch[15];

int house_cnt = 0;

vector<pair<int, int>> ch_store;

vector<pair<int, int>> house;

vector<pair<int, int>> chs;

int func() { //ch_store�� ���� m���� ġŲ�� ��ǥ ����
	int dis = 200; //ġŲ�Ÿ�
	int ch_dis = 0;

	pair<int, int> chicken;
	pair<int, int> home;
	for (int i = 0; i < house_cnt; i++) { //��
		home = house[i];

		for (int j = 0; j < m; j++) { //ġŲ��
			chicken = ch_store[j];
			dis = min(dis, abs(home.X - chicken.X) + abs(home.Y - chicken.Y));
		}

		ch_dis += dis;
		dis = 200;
	}

	return ch_dis;
}

int main() {
	cin >> n >> m;
	int ch_cnt = 0; //ch_cnt �߿� m�� �̱�

	int sum = 1000000000;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				ch_cnt++;
				chs.push_back({ i, j }); //chs�� ch_cnt��ŭ ġŲ�� ��ǥ ����
			}

			else if (arr[i][j] == 1) {
				house.push_back({ i, j }); //�� ��ǥ �ֱ�
				house_cnt++;
			}
		}
	}

	for (int i = m; i < ch_cnt; i++) {
		ch[i] = 1;
	}

	do {
		ch_store.clear();
		for (int i = 0; i < ch_cnt; i++) {
			if (ch[i] == 0) {
				ch_store.push_back(chs[i]);
			}
		}

		sum = min(sum, func());
		
	} while (next_permutation(ch, ch + ch_cnt));

	cout << sum;

	return 0;
}