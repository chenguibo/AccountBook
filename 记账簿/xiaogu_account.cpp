#include "common.h"
#include "account_item.h"

//我使用的是vs2017，同伴的是vs2019，他发送了他写的项目给我，因为使用的vs版本不同、工具集不同，导致项目在我的电脑上编译会有如下报错：
//warning : 无法找到 v142 的生成工具。安装 v142 可使用 v142 生成工具进行生成。
//右键项目 -> 属性 -> 常规 -> 工具集 -> 选择vs2017 -> 确定
//再次右键项目 -> 重定向
//重定向成功后，即可正常编译、运行。

int main() {
	// 1. 加载文件中的账目数据
	vector<AccountItem> items;
	loadDataFromFile(items);

	bool quit = false;
	while (!quit) {
		// 2. 显示主菜单
		showMainMenu(); // 下次看102课

		// 3. 读取键盘选择，并做合法性校验
		char key = readMenuSelection(3);
		switch (key) {
			case '1': // 1 - 记账
				showAccountingMenu();
				accounting(items);
				break;
			case '2': // 2 - 查询
				showQueryMenu();
				query(items);
				break; 
			case '3': // 3 - 退出
				cout << "\n确认退出？(Y/N): ";
				if (readQuitConfirm() == 'Y') quit = true;
				break; 
			default: break;
		}

		cout << endl;
	}

	return 0;
}