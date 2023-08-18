#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

// map/multimap：所有元素都是pair。插入则根据键值自动排序。底层红黑树实现。
// map不允许键值，multiset允许。
// unordered_map，底层哈希表实现。内部排序是无序的。

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
	printMap(mp); // 自动按键（key）排序

	cout << "mp的大小：" << mp.size() << endl; // 3
	cout << "mp是否为空：" << mp.empty() << endl; // 0

	if (mp.find(3) != mp.end()) {
		cout << "找到键3了！" << endl;
	}
	cout << "键3的个数：" << mp.count(3) << endl; // 只有0或1

	mp.erase(3); // 删除键为3
	printMap(mp);
	mp.clear();
	printMap(mp);
	cout << endl;

	map<int, int, MyCompare> mp2;
	mp2.insert(pair<int, int>(3, 11));
	mp2.insert(pair<int, int>(2, 9));
	mp2.insert(pair<int, int>(1, 10));
	printMap2(mp2); // 自动按键（key）倒序

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
}
