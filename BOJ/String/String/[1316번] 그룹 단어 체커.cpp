#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	set<char> s;
	bool isgroup, isnot;
	int n, j;
	int cnt = 0;
	cin >> n;

	bool *arr=new bool[n];
	string *sarr = new string[n];

	for (int i = 0; i < n; i++) {
		s.clear();
		cin >> sarr[i];
		for (int k = 0; k < sarr[i].size(); k++) {
			s.insert(sarr[i].at(k));
		}
		if (s.size() == sarr[i].size()) arr[i] = true;
		else {
			isnot = false;
			while (1) {
				j = 0;
				if (sarr[i].size() > 1) {
					if ((sarr[i].at(j) == sarr[i].at(j + 1)) && (s.find(sarr[i].at(j)) != s.end())) { //���ӵǴ� ���ڰ� �ְ� set�� ���� ��
						sarr[i] = sarr[i].substr(j + 1, sarr[i].size() - 1); //set���� ������ �ʰ� �ѱ��� �߶�
					}
					else if ((sarr[i].at(j) != sarr[i].at(j + 1)) && (s.find(sarr[i].at(j)) != s.end())) { //���ӵǴ� ���� ���� set�� ���� ��
						s.erase(s.find(sarr[i].at(j)));
						sarr[i] = sarr[i].substr(j + 1, sarr[i].size() - 1);
					}

					else {
						isnot = true;
						break;
					}
				}
				else if (sarr[i].size() == 1 && (s.find(sarr[i].at(j)) != s.end())) { //���̰� 1�̰� set�� ���� ��
					isnot = false;
					break;
				}
				else if (sarr[i].size() == 1 && (s.find(sarr[i].at(j)) == s.end())) { //���̰� 1�̰� set�� ���� ��
					isnot = true;
					break;
				}
			}
			if(isnot==false) arr[i] = true;
			else arr[i] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == true) cnt++;
	}

	cout << cnt;

	delete[] arr;
	delete[] sarr;

	return 0;
}