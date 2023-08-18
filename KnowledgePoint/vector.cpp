#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void line() {
	cout << "--------------------" << endl;
}

void printVector(vector<int> &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end();it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	line();
	vector<int> ve(10, 0);

	cout << "是否为空：" << ve.empty() << endl; // 0
	cout << "容量多少：" << ve.capacity() << endl; // 10
	cout << "元素多少：" << ve.size() << endl; // 10
	ve.resize(12); // 重新指定大小为12
	cout << "容量多少：" << ve.capacity() << endl; // 15
	cout << "元素多少：" << ve.size() << endl; // 12

	// 插入删除
	ve.insert(ve.begin(), 1000); // 插入一个
	printVector(ve);
	ve.insert(ve.begin(), 2, 1000); // 插入两个
	printVector(ve);
	ve.erase(ve.begin()); // 删除一个
	printVector(ve);
	//ve.erase(ve.begin(), ve.end()); // 删除全部
	ve.clear(); // 和上一句效果一样
	printVector(ve);

	line();
}

void test02() {
	
	line();
}

void test03() {
	
	line();
}

int main() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;

	// 下次看201课
}