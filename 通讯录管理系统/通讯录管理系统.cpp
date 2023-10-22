#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


// 菜单界面
void showMenu() {
	cout << "****************************" << endl;
	cout << "*****	1、添加联系人	*****" << endl;
	cout << "*****	2、显示联系人	*****" << endl;
	cout << "*****	3、删除联系人	*****" << endl;
	cout << "*****	4、查找联系人	*****" << endl;
	cout << "*****	5、修改联系人	*****" << endl;
	cout << "*****	6、清空联系人	*****" << endl;
	cout << "*****	0、退出通讯录	*****" << endl;
	cout << "****************************" << endl;
}
 

int main() {
	// 菜单调用
	showMenu();

	system("pause");
	return 0;
}