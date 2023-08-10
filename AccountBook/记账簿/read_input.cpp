#include "common.h"

// 读取键盘输入进行合法性校验的函数
char readMenuSelection(int options) {
	string str;
	
	while (true) {
		getline(cin, str);

		// 进行合法性校验
		if (str.size() != 1 || str[0] - '0' <= 0 || str[0] - '0' > options)
			cout << "输入错误，请重新选择：";
		else
			break;
	}

	// 输入合法
	return str[0];
}

// 读取确认退出信息，并进行合法性校验
char readQuitConfirm() {
	string str;

	while (true) {
		getline(cin, str);

		// 进行合法性校验
		if (str.size() != 1 || (toupper(str[0]) != 'Y' && toupper(str[0]) != 'N'))
			cout << "输入错误，请重新输入(Y/N)：";
		else
			break;
	}

	// 输入合法
	return toupper(str[0]);
}

// 读取收入信息，并进行合法性校验
int readAccount() {
	int account;
	string str;

	while (true) {
		getline(cin, str);

		// 进行合法性校验
		try {
			account = stoi(str);
			break;
		}
		catch (invalid_argument e) {
			cout << "输入错误，请正确输入数字：";
		}	
	}

	// 输入合法
	return account;
}