#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

deque<int> deq;
bool isReverse = false;
bool isEmpty = false;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, siz;
	string s, input, ss;
	

	cin >> t;

	for (int i = 0; i < t; i++) {
		deq.clear();
		isReverse = false;
		isEmpty = false;
		cin >> s; //�Լ� �Է�
		cin >> n;
		cin >> input;
		ss = input.substr(1, input.length() - 2);

		char *buffer = new char[500000];
		strcpy(buffer, ss.c_str());

		if (n != 0) {
			char *ptr = strtok(buffer, ",");    //ù��° strtok ���.
			while (ptr != NULL)              //ptr�� NULL�϶����� (= strtok �Լ��� NULL�� ��ȯ�Ҷ�����)
			{
				deq.push_back(atoi(ptr));       //�ڸ� ���� ���
				ptr = strtok(NULL, ",");     //�ڸ� ���� �������� ������ �� ã��
			}
		}
		for (auto c : s) {
			if (c == 'R') isReverse = !isReverse;
			else if (c == 'D') {
				if (deq.empty()) isEmpty = true;
				else {
					if (isReverse) deq.pop_back();
					else deq.pop_front();
				}
			}
		}

		if (isEmpty) cout << "error" << '\n';

		else {
			siz = deq.size();
			cout << "[";
			if (isReverse == true) {
				for (int j = 0; j < siz; j++) {
					if (!deq.empty()) {
						if (j == siz - 1) {
							cout << deq.back();
							deq.pop_back();
						}
						else {
							cout << deq.back() << ",";
							deq.pop_back();
						}
					}
				}
			}
			else {
				for (int j = 0; j < siz; j++) {
					if (!deq.empty()) {
						if (j == siz - 1) {
							cout << deq[j];
						}
						else {
							cout << deq[j] << ",";
						}
					}
				}
			}
			cout << "]" << '\n';
		}
	}
}