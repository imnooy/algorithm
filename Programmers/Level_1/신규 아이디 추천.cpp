#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
	string answer = "";
	int len = new_id.length();
	int index = 0; //answer[index]�� �� ����
	for (int i = 0; i < len; i++) {
		if (new_id[i] >= 'A' && new_id[i] <= 'Z') new_id[i] += 32; //1��
	}
	for (int i = 0; i < len; i++) {
		if ((new_id[i] >= 'a' && new_id[i] <= 'z') || isdigit(new_id[i]) != 0 || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') answer += new_id[i]; //2�� 
	}
	int cnt = 0;
	new_id = "";
	for (int i = 0; i < answer.length(); i++) {
		if (answer[i] == '.') {
			cnt++;
			continue;
		}
		if (cnt > 0 && i != 0 && answer[i - 1] == '.' && answer[i] != '.') {
			new_id += '.';
			cnt = 0;
		}
		new_id += answer[i]; //3��
	}
	if (new_id[0] == '.') new_id = new_id.substr(1);
	if (new_id[new_id.length() - 1] == '.') new_id = new_id.substr(0, new_id.length() - 2); //4��
	if (new_id == "") new_id = "a"; //5��
	if (new_id.length() >= 16) {
		new_id = new_id.substr(0, 15); //6��

	}
	if (new_id.length() <= 2) { //7��
		char c = new_id[new_id.length() - 1]; //����������
		while (new_id.length() < 3) new_id += c;
	}

	return new_id;
}