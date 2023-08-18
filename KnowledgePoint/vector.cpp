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

	cout << "�Ƿ�Ϊ�գ�" << ve.empty() << endl; // 0
	cout << "�������٣�" << ve.capacity() << endl; // 10
	cout << "Ԫ�ض��٣�" << ve.size() << endl; // 10
	ve.resize(12); // ����ָ����СΪ12
	cout << "�������٣�" << ve.capacity() << endl; // 15
	cout << "Ԫ�ض��٣�" << ve.size() << endl; // 12

	// ����ɾ��
	ve.insert(ve.begin(), 1000); // ����һ��
	printVector(ve);
	ve.insert(ve.begin(), 2, 1000); // ��������
	printVector(ve);
	ve.erase(ve.begin()); // ɾ��һ��
	printVector(ve);
	//ve.erase(ve.begin(), ve.end()); // ɾ��ȫ��
	ve.clear(); // ����һ��Ч��һ��
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

	// �´ο�201��
}