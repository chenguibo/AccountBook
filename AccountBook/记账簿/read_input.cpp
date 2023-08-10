#include "common.h"

// ��ȡ����������кϷ���У��ĺ���
char readMenuSelection(int options) {
	string str;
	
	while (true) {
		getline(cin, str);

		// ���кϷ���У��
		if (str.size() != 1 || str[0] - '0' <= 0 || str[0] - '0' > options)
			cout << "�������������ѡ��";
		else
			break;
	}

	// ����Ϸ�
	return str[0];
}

// ��ȡȷ���˳���Ϣ�������кϷ���У��
char readQuitConfirm() {
	string str;

	while (true) {
		getline(cin, str);

		// ���кϷ���У��
		if (str.size() != 1 || (toupper(str[0]) != 'Y' && toupper(str[0]) != 'N'))
			cout << "�����������������(Y/N)��";
		else
			break;
	}

	// ����Ϸ�
	return toupper(str[0]);
}

// ��ȡ������Ϣ�������кϷ���У��
int readAccount() {
	int account;
	string str;

	while (true) {
		getline(cin, str);

		// ���кϷ���У��
		try {
			account = stoi(str);
			break;
		}
		catch (invalid_argument e) {
			cout << "�����������ȷ�������֣�";
		}	
	}

	// ����Ϸ�
	return account;
}