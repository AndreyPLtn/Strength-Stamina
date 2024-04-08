#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int num1, num2;
	char ch;
	cout << "Enter two int's: " << endl;
	cin >> num1 >> num2;
	cout << endl;
	cout << "Enter operator: + (add), - (subt)," << " * (multiplication), / (division), %" << endl;
	cin >> ch;
	cout << endl;
	cout << num1 << " " << ch << " " << num2 << " = ";
	switch (ch) {
	case '+':
		cout << num1 + num2 << endl;
		break;
	case '-':
		cout << num1 - num2 << endl;
		break;
	case '*':
		cout << num1 * num2 << endl;
		break;
	case '/':
		if (num2 != 0) {
			cout << num1 / num2 << endl;
		}
		else {
			cout << "Error NA NOL DELIT NELZYA" << endl;
		}
		break;
	case '%':
		cout << num1 % num2 << endl;
		break;
	default:
		cout << "illegal operation" << endl;
	}
	return 0;
}
