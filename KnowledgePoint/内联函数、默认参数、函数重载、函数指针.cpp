#include <iostream>
#include <string>

using namespace std;

// ����������Ҫִ��һϵ�ж���������ή�ͳ�������Ч�ʡ�
// ����������������߳��������ٶȣ�ֱ���ú���������溯�����á�
// ���inline�������ͱ������������
// ����������C++�����ġ�C��������Ҫͨ��Ԥ�������#define���塰�ꡱ��ʵ�֣��Ƚ��鷳��
inline const string& longerStr(const string& str1, const string& str2) {
	return str1.size() > str2.size() ? str1 : str2;
}

// Ĭ�ϲ�����
// intתstring��to_string(int)
string stuInfo(string Name = "cgb", int age = 18) {
	return "������" + Name + "\t���䣺" + to_string(age);
}

// ��������
// void add(int x)��void add(const int x)��һ���ģ�����ʵ�ֺ������ء�
// void add(int* p)��void add(int* const p)��һ���ģ�����ʵ�ֺ������ء�
// void add(int &x)��void add(const int &x)�ǲ�һ���ģ�����ʵ�ֺ������ء�
// void add(int* p)��void add(const int* p)�ǲ�һ���ģ�����ʵ�ֺ������ء�
void add(int* p) {
	(*p)++;
}
void add(int& x) {
	x++;
}

// ���巵�������Ǻ���ָ��ĺ�����Funcp fun()
typedef const string& (*Funcp)(const string&, const int&);
typedef decltype(stuInfo) *Funcp2;
auto Fun(int)->Funcp; // ������������д�ں���

int main() {
	cout << longerStr("1234", "569") << endl;
	cout << stuInfo() << endl;
	int a = 1;
	int *p = &a;
	add(*p);
	cout << "add(*p)ִ������\t" << a << endl; // 2
	add(a);
	cout << "add(a)ִ������\t" << a << endl; // 3

	string(*fp)(string, int) = nullptr; // ����ָ��
	fp = stuInfo; // fp = stuInfo��fp = &stuInfo��ȫһ��
	cout << "����ָ��fpִ����\t" << (*fp)("lcf", 18) << endl; // (*fp)("lcf", 18)��fp("lcf", 18)��ȫһ��
}