#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// STL(Standard Template Library,��׼ģ���)
void line() {
	cout << "--------------------" << endl;
}

void myPrint(int val) {
	cout << val << endl;
}

void test01(){
	line();
	cout << "test01" << endl;
	vector<int> ve;

	ve.push_back(10);
	ve.push_back(20);
	ve.push_back(30);
	ve.push_back(40);

	// ������
	vector<int>::iterator itBegin = ve.begin();
	vector<int>::iterator itEnd = ve.end();
	// ��һ�ֱ���
	while (itBegin != itEnd) {
		cout << *itBegin << endl;
		itBegin++;
	}
	// �ڶ��ֱ���
	for_each(ve.begin(), ve.end(), myPrint);

	line();
}

class Person {
public:
	Person(string Name, int age) {
		this->m_Name = Name;
		this->m_age = age;
	}

	string m_Name;
	int m_age;
};

void myPrint2(Person p) {
	cout << "������" << p.m_Name << "\t" << "���䣺" << p.m_age << endl;
}

void test02(){
	// vector�����Զ�����������
	line();
	cout << "test02" << endl;
	vector<Person> ve;

	Person p1("001", 1);
	Person p2("002", 2);
	Person p3("003", 3);
	Person p4("004", 4);

	ve.push_back(p1);
	ve.push_back(p2);
	ve.push_back(p3);
	ve.push_back(p4);

	cout << "����һ��" << endl;
	for (vector<Person>::iterator it = ve.begin(); it != ve.end();it++) {
		cout << "������" << (*it).m_Name << "\t" << "���䣺" << (*it).m_age << endl;
	}
	cout << "��������" << endl;
	for_each(ve.begin(), ve.end(), myPrint2);
	line();
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;

	// �´ο�189��
}