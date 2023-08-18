#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

// map/multimap������Ԫ�ض���pair����������ݼ�ֵ�Զ����򡣵ײ�����ʵ�֡�
// map�������ֵ��multiset����
// unordered_map���ײ��ϣ��ʵ�֡��ڲ�����������ġ�

class MyCompare{
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

void line() {
	cout << "--------------------" << endl;
}

void printMap(map<int, int> &mp) {
	for (map<int, int>::iterator it = mp.begin(); it != mp.end();it++) {
		cout << "key=" << (*it).first << " value=" << it->second << endl;
	}
}

void printMap2(map<int, int, MyCompare> &mp) {
	for (map<int, int, MyCompare>::iterator it = mp.begin(); it != mp.end(); it++) {
		cout << "key=" << (*it).first << " value=" << it->second << endl;
	}
}


void test01() {
	line();
	map<int, int> mp;
	mp.insert(pair<int, int>(3, 11));
	mp.insert(pair<int, int>(2, 9));
	mp.insert(pair<int, int>(1, 10));
	printMap(mp); // �Զ�������key������

	cout << "mp�Ĵ�С��" << mp.size() << endl; // 3
	cout << "mp�Ƿ�Ϊ�գ�" << mp.empty() << endl; // 0

	if (mp.find(3) != mp.end()) {
		cout << "�ҵ���3�ˣ�" << endl;
	}
	cout << "��3�ĸ�����" << mp.count(3) << endl; // ֻ��0��1

	mp.erase(3); // ɾ����Ϊ3
	printMap(mp);
	mp.clear();
	printMap(mp);
	cout << endl;

	map<int, int, MyCompare> mp2;
	mp2.insert(pair<int, int>(3, 11));
	mp2.insert(pair<int, int>(2, 9));
	mp2.insert(pair<int, int>(1, 10));
	printMap2(mp2); // �Զ�������key������

	line();
}

void test02() {


	line();
}


int main() {
	test01();
	test02();
	system("pause");
	return 0;

	// �´ο�201�� set map������
}