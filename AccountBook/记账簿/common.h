#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define INCOME "����"
#define EXPAND "֧��"
#define FILENAME "D:\\data\\AccountBook.txt"
// Ҫ�½��ļ����С�����û��д�½��ļ��Ĵ���

using namespace std;

// ͨ�ù����Ժ���˵��
// ���Ʋ˵��ĺ���
void showMainMenu();
void showAccountingMenu();
void showQueryMenu();


// ��ȡ����������кϷ���У��ĺ���
char readMenuSelection(int options);
char readQuitConfirm();
int readAccount();