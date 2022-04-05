#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	string res = "";
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		switch (c) {
		case 'z':
			res += "0";
			i += 3;
			break;
		case 'o':
			res += "1";
			i += 2;
			break;
		case 't':
			if (s[i + 1] == 'w') {
				res += "2";
				i += 2;
			}
			else if (s[i + 1] == 'h') {
				res += "3";
				i += 4;
			}
			break;
		case 'f':
			if (s[i + 1] == 'o') {
				res += "4";
				i += 3;
			}
			else if (s[i + 1] == 'i') {
				res += "5";
				i += 3;
			}
			break;
		case 's':
			if (s[i + 1] == 'i') {
				res += "6";
				i += 2;
			}
			else if (s[i + 1] == 'e') {
				res += "7";
				i += 4;
			}
			break;
		case 'e':
			res += "8";
			i += 4;
			break;
		case 'n':
			res += "9";
			i += 3;
			break;
		default:
			res += c;
		}
	}
	answer = stoi(res);
	return answer;
}