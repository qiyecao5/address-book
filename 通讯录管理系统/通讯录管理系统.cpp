#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>
#define MAX 1000



// 联系人结构体
struct Person {
	string m_Name;  //姓名
	int m_Sex; //性别：1男 2女
	int m_Age; // 年龄
	string m_Phone;  //电话
	string m_Addr;  //住址
};


// 通讯录结构体
struct Addressbooks {
	struct Person personArray[MAX]; //通讯录中保存的联系人数据
	int m_Size; //通讯录中人员个数
};



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
	int select = 0;  //创建用户选择输入的变量
	
	while (true)
	{
		// 菜单调用.
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:		//1、添加联系人
			break;
		case 2:		//2、显示联系人
			break;
		case 3:		//3、删除联系人
			break;
		case 4:		//4、查找联系人
			break;
		case 5:		//5、修改联系人
			break;
		case 6:		//6、清空联系人
			break;
		case 0:		//0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}

	}

	system("pause");
	return 0;
}