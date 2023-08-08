#pragma once
#include "common.h"

// ����ṹ������
struct AccountItem {
	string itemType;
	int account;
	string detail;
};

// �����Ŀ���ݽ��еĺ�������

// ������Ŀ����
void loadDataFromFile(vector<AccountItem>& items);

// ����
void accounting(vector<AccountItem>& items);
void insertIntoFile(const AccountItem& items);
void income(vector<AccountItem>& items);
void expand(vector<AccountItem>& items);

// ��ѯ
void query(const vector<AccountItem>& items);
void queryItems(const vector<AccountItem>& items);
void queryItems(const vector<AccountItem>& items, const string itemType);
void printItem(AccountItem& item);