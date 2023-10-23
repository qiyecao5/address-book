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
// 1.添加联系人的函数	
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
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{	
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
		{	
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
	int ret = isExist(abs, name);
	if ( ret != -1) {
		for (int i = ret; i < abs->m_Size; i++)
		{
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

//4.查找指定联系人信息
void findPerson(Addressbooks * abs) {
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	//判断指定的联系人是否存在通讯录中
	int ret = isExist(abs, name);
	if (ret != -1) //找到联系人
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex ==1 ? "男":"女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << "\t";
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
} 

//5.修改指定联系人信息
void modifyPerson(Addressbooks* abs) {
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	//判断指定的联系人是否存在通讯录中
	int ret = isExist(abs, name);
	if (ret != -1) //找到指定联系人
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{	//	如果输入的是1或2 退出循环，因为输入正确
			// 如果输入的有误 就重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
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
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//住址
		cout << "请输入家庭地址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "修改成功" << endl;
	}
	else 
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//6.清空所有联系人
void cleanPerson(Addressbooks * abs) {
	abs->m_Size = 0; // 将当前记录联系人数量置为0，做逻辑清空操作
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}


int main() {
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0; 

	while (true)
	{
		// 菜单调用.
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:		//1、添加联系人
			addPerson(&abs);  
			break;
		case 2:		//2、显示联系人
			showPerson(&abs);
			break;
		case 3:		//3、删除联系人
			deletePerson(&abs);
			break;
		case 4:		//4、查找联系人
			findPerson(&abs);
			break;
		case 5:		//5、修改联系人
			modifyPerson(&abs);
			break;
		case 6:		//6、清空联系人
			cleanPerson(&abs);
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