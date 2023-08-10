#include "common.h"
#include "account_item.h"

// 加载账目数据
void loadDataFromFile(vector<AccountItem>& items) {
	ifstream input(FILENAME);

	// 逐行读取每一条账目，包装成AccountItem
	AccountItem item;
	while (input >> item.itemType >> item.account >> item.detail) {
		items.push_back(item);
	}

	input.close();
}

// 记账
void accounting(vector<AccountItem>& items) {
	// 读取键盘选择，并做合法性校验
	char key = readMenuSelection(3);

	switch (key) {
		case '1': // 1 - 收入
			income(items);
			break;
		case '2': // 2 - 支出
			expand(items);
			break;
		case '3': // 3 - 返回主菜单
			
			break;
		default: break;
	}
}

// 记录一笔收入
void income(vector<AccountItem>& items) {
	AccountItem item;

	item.itemType = INCOME;

	cout << "\n本次收入金额：";
	item.account = readAccount();

	cout << "\n备注：";
	getline(cin, item.detail);

	items.push_back(item);
	insertIntoFile(item);

	// 显示成功信息
	cout << "\n ------------------------记账成功！--------------------------\n" << endl;
	cout << "\n 请按回车返回主菜单..." << endl;

	string line;
	getline(cin, line);
}

// 将一条账目写入文件中
void insertIntoFile(const AccountItem& item) {
	// 创建一个ofstream对象，以追加的方式写入
	ofstream output(FILENAME, ios::out | ios::app);

	output << item.itemType << "\t" << item.account << "\t" << item.detail << endl;

	output.close();	
}

// 记录一笔支出
void expand(vector<AccountItem>& items) {
	AccountItem item;

	item.itemType = EXPAND;

	cout << "\n本次支出金额：";
	item.account = -readAccount();

	cout << "\n备注：";
	getline(cin, item.detail);

	items.push_back(item);
	insertIntoFile(item);

	// 显示成功信息
	cout << "\n ------------------------记账成功！--------------------------\n" << endl;
	cout << "\n 请按回车返回主菜单..." << endl;

	string line;
	getline(cin, line);
}

// 查询
void query(const vector<AccountItem>& items) {
	// 读取键盘选择，并做合法性校验
	char key = readMenuSelection(4);

	switch (key) {
		case '1': // 1 - 查询所有账目，并统计总收支
			queryItems(items);
			break;
		case '2': // 2 - 查询收入，统计总收入
			queryItems(items, INCOME);
			break;
		case '3': // 3 - 查询支出，统计总支出
			queryItems(items, EXPAND);
			break;
		default: break;
	}
}
// 查询所有账目，并统计总收支
void queryItems(const vector<AccountItem>& items) {
	cout << "-------------------查询结果-------------------" << endl;
	cout << "\n 类型\t\t金额\t\t备注\n" << endl;

	// 遍历所有账目，统计总收支
	int total = 0;
	for (auto item : items) {
		printItem(item);
		total += item.account;
	}

	// 输出信息
	cout << "===================================\n" << endl;
	cout << "总收支：" << total << endl;

	// 显示成功信息
	cout << "\n 请按回车返回主菜单..." << endl;

	string line;
	getline(cin, line);
}

// 函数重载。查询所有账目，并统计总收入或总支出
void queryItems(const vector<AccountItem>& items, const string itemType) {
	cout << "-------------------查询结果-------------------" << endl;
	cout << "\n 类型\t\t金额\t\t备注\n" << endl;

	// 遍历所有账目，统计总收入或总支出
	int total = 0;
	for (auto item : items) {
		if (item.itemType == itemType) {
			printItem(item);
			total += item.account;
		}
	}

	// 输出信息
	string str = itemType == INCOME ? "总收入：" : "总支出：";
	cout << "===================================\n" << endl;
	cout << str << total << endl;

	// 显示成功信息
	cout << "\n 请按回车返回主菜单..." << endl;

	string line;
	getline(cin, line);
}

// 打印出一条账目信息
void printItem(AccountItem& item) {
	cout << item.itemType << "\t\t" << item.account << "\t\t" << item.detail << endl;
}