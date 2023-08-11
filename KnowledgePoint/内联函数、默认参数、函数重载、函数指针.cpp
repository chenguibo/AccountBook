#include <iostream>
#include <string>

using namespace std;

// 函数调用需要执行一系列额外操作，会降低程序运行效率。
// 内联函数则用于提高程序运行速度，直接用函数代码代替函数调用。
// 添加inline，函数就变成内联函数。
// 内联函数是C++新增的。C语言则需要通过预处理语句#define定义“宏”来实现，比较麻烦。
inline const string& longerStr(const string& str1, const string& str2) {
	return str1.size() > str2.size() ? str1 : str2;
}

// 默认参数。
// int转string：to_string(int)
string stuInfo(string Name = "cgb", int age = 18) {
	return "姓名：" + Name + "\t年龄：" + to_string(age);
}

// 函数重载
// void add(int x)和void add(const int x)是一样的，不能实现函数重载。
// void add(int* p)和void add(int* const p)是一样的，不能实现函数重载。
// void add(int &x)和void add(const int &x)是不一样的，可以实现函数重载。
// void add(int* p)和void add(const int* p)是不一样的，可以实现函数重载。
void add(int* p) {
	(*p)++;
}
void add(int& x) {
	x++;
}

// 定义返回类型是函数指针的函数：Funcp fun()
typedef const string& (*Funcp)(const string&, const int&);
typedef decltype(stuInfo) *Funcp2;
auto Fun(int)->Funcp; // 函数返回类型写在后面

int main() {
	cout << longerStr("1234", "569") << endl;
	cout << stuInfo() << endl;
	int a = 1;
	int *p = &a;
	add(*p);
	cout << "add(*p)执行完了\t" << a << endl; // 2
	add(a);
	cout << "add(a)执行完了\t" << a << endl; // 3

	string(*fp)(string, int) = nullptr; // 函数指针
	fp = stuInfo; // fp = stuInfo和fp = &stuInfo完全一样
	cout << "函数指针fp执行了\t" << (*fp)("lcf", 18) << endl; // (*fp)("lcf", 18)和fp("lcf", 18)完全一样
}