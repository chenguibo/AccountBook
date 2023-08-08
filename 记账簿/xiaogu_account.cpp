#include "common.h"
#include "account_item.h"

//��ʹ�õ���vs2017��ͬ�����vs2019������������д����Ŀ���ң���Ϊʹ�õ�vs�汾��ͬ�����߼���ͬ��������Ŀ���ҵĵ����ϱ���������±���
//warning : �޷��ҵ� v142 �����ɹ��ߡ���װ v142 ��ʹ�� v142 ���ɹ��߽������ɡ�
//�Ҽ���Ŀ -> ���� -> ���� -> ���߼� -> ѡ��vs2017 -> ȷ��
//�ٴ��Ҽ���Ŀ -> �ض���
//�ض���ɹ��󣬼����������롢���С�

int main() {
	// 1. �����ļ��е���Ŀ����
	vector<AccountItem> items;
	loadDataFromFile(items);

	bool quit = false;
	while (!quit) {
		// 2. ��ʾ���˵�
		showMainMenu(); // �´ο�102��

		// 3. ��ȡ����ѡ�񣬲����Ϸ���У��
		char key = readMenuSelection(3);
		switch (key) {
			case '1': // 1 - ����
				showAccountingMenu();
				accounting(items);
				break;
			case '2': // 2 - ��ѯ
				showQueryMenu();
				query(items);
				break; 
			case '3': // 3 - �˳�
				cout << "\nȷ���˳���(Y/N): ";
				if (readQuitConfirm() == 'Y') quit = true;
				break; 
			default: break;
		}

		cout << endl;
	}

	return 0;
}