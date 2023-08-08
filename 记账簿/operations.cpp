#include "common.h"
#include "account_item.h"

// ������Ŀ����
void loadDataFromFile(vector<AccountItem>& items) {
	ifstream input(FILENAME);

	// ���ж�ȡÿһ����Ŀ����װ��AccountItem
	AccountItem item;
	while (input >> item.itemType >> item.account >> item.detail) {
		items.push_back(item);
	}

	input.close();
}

// ����
void accounting(vector<AccountItem>& items) {
	// ��ȡ����ѡ�񣬲����Ϸ���У��
	char key = readMenuSelection(3);

	switch (key) {
		case '1': // 1 - ����
			income(items);
			break;
		case '2': // 2 - ֧��
			expand(items);
			break;
		case '3': // 3 - �������˵�
			
			break;
		default: break;
	}
}

// ��¼һ������
void income(vector<AccountItem>& items) {
	AccountItem item;

	item.itemType = INCOME;

	cout << "\n���������";
	item.account = readAccount();

	cout << "\n��ע��";
	getline(cin, item.detail);

	items.push_back(item);
	insertIntoFile(item);

	// ��ʾ�ɹ���Ϣ
	cout << "\n ------------------------���˳ɹ���--------------------------\n" << endl;
	cout << "\n �밴�س��������˵�..." << endl;

	string line;
	getline(cin, line);
}

// ��һ����Ŀд���ļ���
void insertIntoFile(const AccountItem& item) {
	// ����һ��ofstream������׷�ӵķ�ʽд��
	ofstream output(FILENAME, ios::out | ios::app);

	output << item.itemType << "\t" << item.account << "\t" << item.detail << endl;

	output.close();	
}

// ��¼һ��֧��
void expand(vector<AccountItem>& items) {
	AccountItem item;

	item.itemType = EXPAND;

	cout << "\n����֧����";
	item.account = -readAccount();

	cout << "\n��ע��";
	getline(cin, item.detail);

	items.push_back(item);
	insertIntoFile(item);

	// ��ʾ�ɹ���Ϣ
	cout << "\n ------------------------���˳ɹ���--------------------------\n" << endl;
	cout << "\n �밴�س��������˵�..." << endl;

	string line;
	getline(cin, line);
}

// ��ѯ
void query(const vector<AccountItem>& items) {
	// ��ȡ����ѡ�񣬲����Ϸ���У��
	char key = readMenuSelection(4);

	switch (key) {
		case '1': // 1 - ��ѯ������Ŀ����ͳ������֧
			queryItems(items);
			break;
		case '2': // 2 - ��ѯ���룬ͳ��������
			queryItems(items, INCOME);
			break;
		case '3': // 3 - ��ѯ֧����ͳ����֧��
			queryItems(items, EXPAND);
			break;
		default: break;
	}
}
// ��ѯ������Ŀ����ͳ������֧
void queryItems(const vector<AccountItem>& items) {
	cout << "-------------------��ѯ���-------------------" << endl;
	cout << "\n ����\t\t���\t\t��ע\n" << endl;

	// ����������Ŀ��ͳ������֧
	int total = 0;
	for (auto item : items) {
		printItem(item);
		total += item.account;
	}

	// �����Ϣ
	cout << "===================================\n" << endl;
	cout << "����֧��" << total << endl;

	// ��ʾ�ɹ���Ϣ
	cout << "\n �밴�س��������˵�..." << endl;

	string line;
	getline(cin, line);
}

// �������ء���ѯ������Ŀ����ͳ�����������֧��
void queryItems(const vector<AccountItem>& items, const string itemType) {
	cout << "-------------------��ѯ���-------------------" << endl;
	cout << "\n ����\t\t���\t\t��ע\n" << endl;

	// ����������Ŀ��ͳ�����������֧��
	int total = 0;
	for (auto item : items) {
		if (item.itemType == itemType) {
			printItem(item);
			total += item.account;
		}
	}

	// �����Ϣ
	string str = itemType == INCOME ? "�����룺" : "��֧����";
	cout << "===================================\n" << endl;
	cout << str << total << endl;

	// ��ʾ�ɹ���Ϣ
	cout << "\n �밴�س��������˵�..." << endl;

	string line;
	getline(cin, line);
}

// ��ӡ��һ����Ŀ��Ϣ
void printItem(AccountItem& item) {
	cout << item.itemType << "\t\t" << item.account << "\t\t" << item.detail << endl;
}