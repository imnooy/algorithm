#include <iostream>
using namespace std;

int main() {
	int sugar;
	cin >> sugar; //����� ����

	 //���� ��
	int three = 0;

	while (sugar % 5 != 0) {
		if (sugar < 3) {
			break;
		}
		sugar -= 3;
		three++;
	}

	if ((sugar % 3 != 0) && (sugar % 5 != 0)) cout << "-1" << endl;
	else cout << (sugar / 5) + three << endl;

	return 0;
}