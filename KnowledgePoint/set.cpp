#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

// set/multiset���������Զ����򡣵ײ������ʵ�֡�
// setԪ�ز������ظ���multiset����

class Person {
public:
	Person(string Name, int age) {
		this->m_Name = Name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

class MyCompare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

class MyComparePerson {
public:
	bool operator()(const Person& p1, const Person& p2){
		return p1.m_Age > p2.m_Age;
	}
};

void line() {
	cout << "--------------------" << endl;
}

void printSet(set<int> &st) {
	for (set<int>::iterator it = st.begin(); it != st.end();it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void printSet2(set<int, MyCompare> &st) {
	for (set<int, MyCompare>::iterator it = st.begin(); it != st.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void printSet3(set<Person, MyComparePerson> &st) {
	for (set<Person, MyComparePerson>::iterator it = st.begin(); it != st.end(); it++) {
		cout << "������" << (*it).m_Name << " " << "���䣺" << (*it).m_Age << endl;
	}
}

void test01() {
	line();
	set<int> st;

	st.insert(10);
	st.insert(20);
	st.insert(30);
	st.insert(40);

	printSet(st);
	cout << "set��С��" << st.size() << endl; // 4
	cout << "set�Ƿ�Ϊ�գ�" << st.empty() << endl; // 0

	if (st.find(40) != st.end()) {
		cout << "�ҵ�40�ˣ�" << endl;
	}
	cout << "40��set�е�������" << st.count(40) << endl; // 1

	set<int, MyCompare> st2;
	st2.insert(10);
	st2.insert(20);
	st2.insert(30);
	st2.insert(40);
	printSet2(st2); // ����


	st.erase(10); // ɾ��ָ��ֵ
	printSet(st);
	st.clear(); // ���
	printSet(st); 

	line();
}

void test02() {
	pair<string, int> p("cgb", 20);
	cout << "������" << p.first << " " << "���䣺" << p.second << endl;
	cout << endl;
	set<Person, MyComparePerson> st;
	Person p1("ccc", 30);
	Person p2("ggg", 40);
	Person p3("bbb", 50);
	st.insert(p1);
	st.insert(p2);
	st.insert(p3);
	printSet3(st); // ����Ӵ�С��

	line();
}


int main() {
	test01();
	test02();
	system("pause");
	return 0;

	// �´ο�201��
}