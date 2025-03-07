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
		cout << " 1. 계좌개설" << "\n";
		cout << " 2. 입 금" << "\n";
		cout << " 3. 출 금" << "\n";
		cout << " 4. 계좌정보 전체 출력" << "\n";
		cout << " 5. 프로그램 종료" << "\n";
		cout << "선택: "; cin >> choice; cout << "\n";

		switch (choice)
		{
		case 1:
			{
				cout << "[계좌개설]" << "\n";
				cout << "계좌ID: "; cin >> ID;
				cout << "이 름: "; cin >> name;
				cout << "입금액: "; cin >> deposit; cout << "\n";

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

			cout << "[입    금]" << "\n";
			cout << "계좌ID: "; cin >> ID;
			cout << "입금액: "; cin >> deposit;

			for (int i = 0; i <= Account_count; i++)
			{
				if (member[i].Account_Id == ID)
				{
					member[i].deposit += deposit;
					cout << "입금완료" << "\n\n";
					found = true;
					break;
				}
			}
			
			if (!found)
			{
				cout << "유효하지 않은 ID입니다." << "\n\n";
			}

			break;
		}
		case 3:
		{
			cout << "[출    금]" << "\n";
			cout << "계좌ID: "; cin >> ID;
			cout << "출금액: "; cin >> withdraw;

			for (int i = 0; i < Account_count; i++)
			{
				if (member[i].Account_Id == ID)
				{
					if (member[i].deposit < withdraw)
					{
						cout << "잔액부족" << "\n\n";
					}
					else
					{
						member[i].deposit -= withdraw;
						cout << "출금완료" << "\n\n";
					}
				}
				else cout << "유효하지 않은 ID 입니다. " << "\n\n";
			}
			break;
		}
		case 4:
		{
			for (int i = 0; i < Account_count; i++)
			{
				cout << "계좌ID: " << member[i].Account_Id << "\n";
				cout << "이 름: " << member[i].name << "\n";
				cout << "잔 액: " << member[i].deposit << "\n\n";
			}
			break;

		}
		}
	
	} while (choice != 5);


	cout << "내용 추가" << "\n";

	return 0;
}