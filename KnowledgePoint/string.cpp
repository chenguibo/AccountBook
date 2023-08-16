#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void line() {
	cout << "--------------------" << endl;
}

void test01() {
	line();
	// �������ַ�����find�����±ꡣ
	// rfind��������顣
	string s = "adcdef";
	int pos = s.find("de"); // 3
	cout << "pos = " << pos << endl;

	// �滻���ַ�������������ʼ�±꣬�����±꣬�滻���ַ�����
	string s1 = "adcdef";
	s1.replace(1,3, "111"); // a111ef
	cout << "s1 = " << s1 << endl;

	// �ַ����Ƚϡ�=:0  >:1  <:-1��
	string s2 = "abcd";
	string s3 = "abcde";
	int ret = s2.compare(s3); // -1
	cout << "ret = " << ret << endl;
	line();
}

void test02() {
	// �ַ���ȡ����ȡ�����ַ���s1[i]����s1.at(i)
	string s1 = "abc";
	string s2 = "abcd";
	cout << s1.size() << " " << s2.length() << endl; // 3 4

	// �ַ�������ɾ����
	// insert(�±꣬���ӵ��ַ���) erase(�±꣬ɾ���ַ�����)
	string s3 = "hello";
	s3.insert(1, "111"); // h111ello
	cout << "insert s3=" << s3 << endl;
	s3.erase(1, 3); // hello
	cout << "erase s3=" << s3 << endl;

	// ��ȡ�Ӵ�
	// substr(�±꣬Ҫȡ���ַ�����)
	string s4 = "hello";
	string subStr = s4.substr(0,2); // he
	cout << "subStr=" << subStr << endl;
	line();
}

void test03() {
	string email = "123456@qq.com";
	int pos = email.find("@"); // 6
	string Name = email.substr(0, pos); // 123456
	cout << "Name=" << Name << endl;
	line();
}

int main() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;

	// �´ο�189��
}