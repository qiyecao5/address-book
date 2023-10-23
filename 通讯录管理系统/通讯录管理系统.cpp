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
// 1.添加联系人的函数	// 这里的参数Addressbooks* abs    这个abs就是个参数，理论上随便什么字母都行
void addPerson(Addressbooks* abs) {
	//判断通讯录是否已满，如果满了就不在添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;  // 你不能返回东西
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		//创建结构体数组写几 就代表.例如personArray[0]  代表是这个结构体的第1个数组
		// 这里的m_Size 在外面添加的时候会++，
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		cout << "3 --- 保密" << endl;
		int sex = 0;
		while (true)
		{	//	如果输入的是1或2 退出循环，因为输入正确
			// 如果输入的有误 就重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "你输入的不正确" << endl;
			}
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true)
		{	//	如果输入的是1或2 退出循环，因为输入正确
			// 如果输入的有误 就重新输入
			cin >> age;
			if (age < 100)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			else
			{
				cout << "你输入的年龄太大了，请重新输入" << endl;
			}
		}
		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause"); //请按任意键继续
		system("cls"); //清屏操作


	}

}
// 2.显示所有联系人
void showPerson(Addressbooks * abs) {
	//判断通讯录中人数是否为0，如果为0，提示记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->m_Size == 0)
	{
		cout<< "当前记录为空" << endl;
	}
	else
	{
		//全部遍历出来打印
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			// 三目运算符
			cout << "性别：" << (abs->personArray[i].m_Sex ==1 ?"男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "家庭地址：" << abs->personArray[i].m_Addr << endl;

		}
	}
	system("pause"); //请按任意键继续
	system("cls"); //清屏操作

}
// 3.1删除联系人
// 检查联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
int isExist(Addressbooks* abs, string name) {
	//参数1：通讯录地址  参数2 对比的姓名
	for (int i = 0; i < abs->m_Size; i++)
	{
		//找到用户输入的姓名了
		if (abs->personArray[i].m_Name == name)
		{
			return i;//找到，返回此人在数组中的下标
		}
	}
	return -1; //如果遍历结束都没有找到，返回-1
}
//3.2删除指定联系人
void deletePerson(Addressbooks* abs) {
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	// ret == -1 未查到
	// ret != -1 查到了
	int ret = isExist(abs, name);
	if ( ret != -1) {
		//cout << "zhaodao" << endl;
		//要删除李四，将李四后的数据做向前移动，并且让通讯录中记录的人员个数做-1的操作即可
		//查找到人，要进行删除操作
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据迁移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;  // 更新通讯录中的人员数
		cout<< "删除成功" << endl;
	}
	else
	{  
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}



//19.29
int main() {
	//创建通讯录结构体变量 
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;

	int select = 0;  //创建用户选择输入的变量


	while (true)
	{
		// 菜单调用.
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:		//1、添加联系人
			addPerson(&abs);  //值传递不能修改实参，所以我们传地址
			break;
		case 2:		//2、显示联系人
			showPerson(&abs);
			break;
		case 3:		//3、删除联系人
		//{//如果你用switch语句，判断中的语句很复杂，你要把这片都包起来，否则报错
		//	cout << "请输入删除联系人姓名：" << endl;
		//	string name;
		//	cin >> name;
		//	if (isExist(&abs, name) == -1) {
		//		cout << "查无此人" << endl;
		//	}
		//	else
		//	{
		//		cout << "找到此人" << endl;
		//	}
		//}
			deletePerson(&abs);
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