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
	int m_age;
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

int main() {
	showMenu(); // 显示菜单
	int select = 0;

	while (true) {
		cin >> select;
		switch (select)
		{
		case 0: // 退出通讯录
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		case 1: // 添加联系人
			break;
		case 2: // 显示联系人
			break;
		case 3: // 删除联系人
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
