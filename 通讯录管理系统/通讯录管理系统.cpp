#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>
#define MAX 1000



// ��ϵ�˽ṹ��
struct Person {
	string m_Name;  //����
	int m_Sex; //�Ա�1�� 2Ů
	int m_Age; // ����
	string m_Phone;  //�绰
	string m_Addr;  //סַ
};


// ͨѶ¼�ṹ��
struct Addressbooks {
	struct Person personArray[MAX]; //ͨѶ¼�б������ϵ������
	int m_Size; //ͨѶ¼����Ա����
};


// �˵�����
void showMenu() {
	cout << "****************************" << endl;
	cout << "*****	1�������ϵ��	*****" << endl;
	cout << "*****	2����ʾ��ϵ��	*****" << endl;
	cout << "*****	3��ɾ����ϵ��	*****" << endl;
	cout << "*****	4��������ϵ��	*****" << endl;
	cout << "*****	5���޸���ϵ��	*****" << endl;
	cout << "*****	6�������ϵ��	*****" << endl;
	cout << "*****	0���˳�ͨѶ¼	*****" << endl;
	cout << "****************************" << endl;
}
// 1.�����ϵ�˵ĺ���	
void addPerson(Addressbooks* abs) {
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;  // �㲻�ܷ��ض���
	}
	else
	{
		//��Ӿ�����ϵ��

		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
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
				cout << "������Ĳ���ȷ" << endl;
			}
		}
		//����
		cout << "���������䣺" << endl;
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
				cout << "�����������̫���ˣ�����������" << endl;
			}
		}
		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause"); //�밴���������
		system("cls"); //��������


	}

}
// 2.��ʾ������ϵ��
void showPerson(Addressbooks * abs) {
	if (abs->m_Size == 0)
	{
		cout<< "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		//ȫ������������ӡ
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			// ��Ŀ�����
			cout << "�Ա�" << (abs->personArray[i].m_Sex ==1 ?"��":"Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "��ͥ��ַ��" << abs->personArray[i].m_Addr << endl;

		}
	}
	system("pause"); //�밴���������
	system("cls"); //��������

}
// 3.1ɾ����ϵ��
int isExist(Addressbooks* abs, string name) {
	//����1��ͨѶ¼��ַ  ����2 �Աȵ�����
	for (int i = 0; i < abs->m_Size; i++)
	{
		//�ҵ��û������������
		if (abs->personArray[i].m_Name == name)
		{
			return i;//�ҵ������ش����������е��±�
		}
	}
	return -1; //�������������û���ҵ�������-1
}
//3.2ɾ��ָ����ϵ��
void deletePerson(Addressbooks* abs) {
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if ( ret != -1) {
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;  // ����ͨѶ¼�е���Ա��
		cout<< "ɾ���ɹ�" << endl;
	}
	else
	{  
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//4.����ָ����ϵ����Ϣ
void findPerson(Addressbooks * abs) {
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ж�ָ������ϵ���Ƿ����ͨѶ¼��
	int ret = isExist(abs, name);
	if (ret != -1) //�ҵ���ϵ��
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex ==1 ? "��":"Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << "\t";
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
} 

//5.�޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ж�ָ������ϵ���Ƿ����ͨѶ¼��
	int ret = isExist(abs, name);
	if (ret != -1) //�ҵ�ָ����ϵ��
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true)
		{	//	����������1��2 �˳�ѭ������Ϊ������ȷ
			// ������������ ����������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "������Ĳ���ȷ" << endl;
			}
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//סַ
		cout << "�������ͥ��ַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "�޸ĳɹ�" << endl;
	}
	else 
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//6.���������ϵ��
void cleanPerson(Addressbooks * abs) {
	abs->m_Size = 0; // ����ǰ��¼��ϵ��������Ϊ0�����߼���ղ���
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}


int main() {
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0; 

	while (true)
	{
		// �˵�����.
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:		//1�������ϵ��
			addPerson(&abs);  
			break;
		case 2:		//2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:		//3��ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4:		//4��������ϵ��
			findPerson(&abs);
			break;
		case 5:		//5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6:		//6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0:		//0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
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