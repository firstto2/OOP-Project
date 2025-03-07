#include <iostream>
#include <cstring>
using namespace std;


typedef struct Account
{
	int Account_Id;
	char* name;
	int deposit;
} Account;

int Account_count = 0;
Account member[100];

int main(void)
{
	int choice, ID, deposit, withdraw;
	char name[10];
	do
	{
		cout << " -----Menu------" << "\n";
		cout << " 1. ���°���" << "\n";
		cout << " 2. �� ��" << "\n";
		cout << " 3. �� ��" << "\n";
		cout << " 4. �������� ��ü ���" << "\n";
		cout << " 5. ���α׷� ����" << "\n";
		cout << "����: "; cin >> choice; cout << "\n";

		switch (choice)
		{
		case 1:
			{
				cout << "[���°���]" << "\n";
				cout << "����ID: "; cin >> ID;
				cout << "�� ��: "; cin >> name;
				cout << "�Աݾ�: "; cin >> deposit; cout << "\n";

				member[Account_count].Account_Id = ID;
				member[Account_count].deposit += deposit;

				size_t len = strlen(name) + 1;
				member[Account_count].name = new char[len];
				strcpy_s(member[Account_count].name, len, name);

				Account_count++;
				break;
			}

		case 2:
		{
			bool found = false;

			cout << "[��    ��]" << "\n";
			cout << "����ID: "; cin >> ID;
			cout << "�Աݾ�: "; cin >> deposit;

			for (int i = 0; i <= Account_count; i++)
			{
				if (member[i].Account_Id == ID)
				{
					member[i].deposit += deposit;
					cout << "�ԱݿϷ�" << "\n\n";
					found = true;
					break;
				}
			}
			
			if (!found)
			{
				cout << "��ȿ���� ���� ID�Դϴ�." << "\n\n";
			}

			break;
		}
		case 3:
		{
			cout << "[��    ��]" << "\n";
			cout << "����ID: "; cin >> ID;
			cout << "��ݾ�: "; cin >> withdraw;

			for (int i = 0; i < Account_count; i++)
			{
				if (member[i].Account_Id == ID)
				{
					if (member[i].deposit < withdraw)
					{
						cout << "�ܾ׺���" << "\n\n";
					}
					else
					{
						member[i].deposit -= withdraw;
						cout << "��ݿϷ�" << "\n\n";
					}
				}
				else cout << "��ȿ���� ���� ID �Դϴ�. " << "\n\n";
			}
			break;
		}
		case 4:
		{
			for (int i = 0; i < Account_count; i++)
			{
				cout << "����ID: " << member[i].Account_Id << "\n";
				cout << "�� ��: " << member[i].name << "\n";
				cout << "�� ��: " << member[i].deposit << "\n\n";
			}
			break;

		}
		}
	
	} while (choice != 5);


	cout << "���� �߰�" << "\n";

	return 0;
}