#include <bits/stdc++.h>
using namespace std;

int main() {
	int x1, y1, r1, x2, y2, r2;
	int n;
	double dd, rpr, rmr;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		dd = ((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2));
		rpr = (r1 + r2)*(r1 + r2);
		rmr = (r1 - r2)*(r1 - r2);
		if (x1 == x2 && y1 == y2 && r1 == r2) { //���ɿ�
			cout << "-1" << '\n';
		}
		else if (x1 == x2 && y1 == y2 && r1 != r2) { //�������� �ٸ�
			cout << "0" << '\n';
		}
		else if (rmr == dd) { //����
			cout << "1" << '\n';
		}
		else if (rpr < dd) { //�ܺ�, �ȸ���
			cout << "0" << '\n';
		}
		else if (rpr == dd) { //����
			cout << "1" << '\n';
		}
		else if (rmr < dd && dd < rpr) { //���� 2��
			cout << "2" << '\n';
		}
		else if (rmr > dd) { //����, �ȸ���
			cout << "0" << '\n';
		}
	}
}