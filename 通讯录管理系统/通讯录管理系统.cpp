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
// 1.�����ϵ�˵ĺ���	// ����Ĳ���Addressbooks* abs    ���abs���Ǹ����������������ʲô��ĸ����
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
		//�����ṹ������д�� �ʹ���.����personArray[0]  ����������ṹ��ĵ�1������
		// �����m_Size ��������ӵ�ʱ���++��
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		cout << "3 --- ����" << endl;
		int sex = 0;
		while (true)
		{	//	����������1��2 �˳�ѭ������Ϊ������ȷ
			// ������������ ����������
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
		{	//	����������1��2 �˳�ѭ������Ϊ������ȷ
			// ������������ ����������
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

int main() {
	//����ͨѶ¼�ṹ����� 16.56
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;

	int select = 0;  //�����û�ѡ������ı���

	while (true)
	{
		// �˵�����.
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:		//1�������ϵ��
			addPerson(&abs);  //ֵ���ݲ����޸�ʵ�Σ��������Ǵ���ַ
			break;
		case 2:		//2����ʾ��ϵ��
			break;
		case 3:		//3��ɾ����ϵ��
			break;
		case 4:		//4��������ϵ��
			break;
		case 5:		//5���޸���ϵ��
			break;
		case 6:		//6�������ϵ��
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