#include <iostream>
#include <string>

using namespace std;
#define MAX 1000

// 联系人
struct Person {
	// 姓名
	string m_Name;
	// 性别 1：男 2：女
	int m_Sex;
	// 年龄
	int m_Age;
	// 电话
	string m_Phone;
	// 住址
	string m_Addr;
};

struct Addressbooks {
	// 联系人数组
	struct Person personArray[MAX];
	// 联系人个数
	int m_Size;
};

void showMenu() {
	cout << "*************************" << endl;
	cout << "****  1、添加联系人  ****" << endl;
	cout << "****  2、显示联系人  ****" << endl;
	cout << "****  3、删除联系人  ****" << endl;
	cout << "****  4、查找联系人  ****" << endl;
	cout << "****  5、修改联系人  ****" << endl;
	cout << "****  6、清空联系人  ****" << endl;
	cout << "****  0、退出通讯录  ****" << endl;
	cout << "*************************" << endl;
}

// 添加联系人
void addPerson(Addressbooks *abs) {
	if (abs->m_Size == MAX) {
		cout << "通讯录人数已满！" << endl;
	}
	else {
		// 添加具体联系人
		// 姓名
		string m_Name;
		cout << "请输入姓名：" << endl;
		cin >> m_Name;
		abs->personArray[abs->m_Size].m_Name = m_Name;
		// 性别 1：男 2：女
		int m_Sex = 1;
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		while (true) {
			cin >> m_Sex;
			if (m_Sex == 1 || m_Sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = m_Sex;
				break;
			}
			else {
				cout << "输入有误，请重新输入！" << endl;
			}
		}
		
		// 年龄
		int m_Age;
		cout << "请输入年龄：" << endl;
		cin >> m_Age;
		abs->personArray[abs->m_Size].m_Age = m_Age;
		// 电话
		string m_Phone;
		cout << "请输入电话：" << endl;
		cin >> m_Phone;
		abs->personArray[abs->m_Size].m_Phone = m_Phone;
		// 住址
		string m_Addr;
		cout << "请输入住址：" << endl;
		cin >> m_Addr;
		abs->personArray[abs->m_Size].m_Addr = m_Addr;

		abs->m_Size++;
		cout << "添加成功！" << endl;

		system("pause");
		system("cls"); // 清屏
	}
}

// 显示联系人
void showPerson(Addressbooks *abs) {
	if (abs->m_Size == 0) {
		cout << "通讯录为空！" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size;i++) {
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "地址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls"); // 清屏
}

// 是否存在联系人
int isExist(Addressbooks *abs, string Name) {
	for (int i = 0; i < abs->m_Size;i++) {
		if (abs->personArray[i].m_Name == Name) {
			return i;
		}
	}
	return -1;
}

int main() {	
	int select = 0;
	Addressbooks abs;
	abs.m_Size = 0;

	while (true) {
		showMenu(); // 显示菜单
		cin >> select;
		switch (select)
		{
		case 0: // 退出通讯录
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		case 1: // 添加联系人
			addPerson(&abs);
			break;
		case 2: // 显示联系人
			showPerson(&abs);
			break;
		case 3: // 删除联系人
		{
			cout << "请输入要删除的联系人姓名：" << endl;
			string Name;
			cin >> Name;
			if (isExist(&abs, Name) > -1) {
				cout << "此人存在！" << endl;
			}
			else {
				cout << "查无此人！" << endl;
			}
		}
			break;
		case 4: // 查找联系人
			break;
		case 5: // 修改联系人
			break;
		case 6: // 清空联系人
			break;
		}
	}

	system("pause");
	return 0;
}
