#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define MAXNAME 15	//�̸��� �ִ���̸� 15
#define MAXBIRTHDAY 8 //��������� �ִ���̸� 8
#define MAXPHONE 13	//��ȭ��ȣ�� �ִ���̸� 15
#define MAXADDRRESS 20	//�ּ��� �ִ���̸� 50

typedef struct Addbook {
	char name[MAXNAME]; //�̸�
	char birthday[MAXBIRTHDAY]; //�������
	char phone[MAXPHONE]; //��ȭ��ȣ
	char address[MAXADDRRESS]; //�ּ�
	struct Addbook *link; //����� link
}addbook;

addbook* createList(); //����Ʈ �ʱ�ȭ �Լ�
void inputData(addbook*); //����Ʈ �Է� �Լ�

int main()
{
	int checkSave;
	int menu; //switch���� ���� �޴�����
	addbook *head; //head ����
	head = createList(); //head ��忡 ���鸮��Ʈ ���� �� �ʱ�ȭ

	while (1) {
		system("cls");
		printf("����������������������������������������\n");
		printf("��   Address Book   ��\n");
		printf("�Ŧ�������������������������������������\n");
		printf("����������������������������������������\n");
		printf("�� (1) Member List  ��\n");
		printf("�� (2) Add Member   ��\n");
		printf("�� (3) Search Member��\n");
		printf("�� (4) Delete Member��\n");
		printf("�� (5) Sort         ��\n");
		printf("�� (6) Save File    ��\n");
		printf("�� (7) Exit         ��\n");
		printf("�Ŧ�������������������������������������\n");
		printf("\nPlease enter the action you want : ");
		scanf("%d", &menu);
		
		switch (menu) {
		case 1:
			system("cls");
			printf("�ּҷϿ� ��ϵ� ����Դϴ�.\n");
			printList(head);
			break;

		case 2:
			system("cls");
			printf("ȸ�� ��� �۾��Դϴ� ������ �Է��ϼ���.\n");
			inputData(head);
			break;

		case 3:
			system("cls");
			printf("�ּҷ� �˻� �۾��Դϴ� ������ �Է��ϼ���.\n");
			findList(head);
			break;

		case 4:
			system("cls");
			printf("�ּҷ� ���� �۾��Դϴ�. ������ �Է��ϼ���\n");
			deleteList(head);
			break;

		case 5:
			system("cls");
			printf("ȸ���� �̸������� �����մϴ�.\n");
			selectionSort(head);
			break;

		case 6:
			system("cls");
			printf("�����͸� ���Ͽ� �����մϴ�.\n");
			checkSave = savaData(Head);
			if (checkSave == 0) {
				printf("\n==������ �Ϸ�Ǿ����ϴ�==");
				fflush(stdin); getchar();
			}
			else {
				printf("\n==���忡 �����Ͽ����ϴ�==");
				fflush(stdin); getchar();
			}
			break;

		case 7:
			system("cls");
			printf("�����մϴ�.\n");
			return 0;

		default:
			system("cls");
			printf("�޴��� �ٽ� ������ �ּ���(Enter)");
			break;
		}
		printf("\nPress any key to continue.\n");
		_getch();
	}
	return 0;
}

addbook* createList() //���鸮��Ʈ ���� �� �ʱ�ȭ
{
	addbook* node; //Head�� addbook ��ŭ�� ���� �޸𸮸� �Ҵ�
	node = (addbook *)malloc(sizeof(addbook));
	node->link = NULL;
	return node;
}

void inputData(addbook* head) //����Ʈ�� ����� �߰�
{
	char _name[MAXNAME]; //�̸�
	char _birthday[MAXBIRTHDAY]; //�������
	char _phone[MAXPHONE]; //��ȭ��ȣ
	char _address[MAXADDRRESS]; //�ּ�

	addbook *temp; //�ӽ� ������

	while(1)
	{
		temp = (addbook *)malloc(sizeof(addbook));

		printf("\n Press <quit> or <exit> or <end> to Menu!!\n");
		
		fflush(stdin);
		printf("�� ��:");
		scanf("%s", _name);

		if (strcmp(_name, "quit") == 0 || strcmp(_name, "exit") == 0 || strcmp(_name, "end") == 0)
		{
			break; //�ش�Ǵ� �ܾ �����Ͽ� �Է��� �����Ŵ
		}

		fflush(stdin);
		printf("�� �� �� ��:");
		scanf("%s", _birthday);

		fflush(stdin);
		printf("�� ȭ �� ȣ :");
		scanf("%s", _phone);

		fflush(stdin);
		printf("�� ��:");
		scanf("%s", _address);

		//�Է¹��� ���� �ӽó�忡 ������ѳ��.
		strcpy(temp->name, _name);
		strcpy(temp->birthday, _birthday);
		strcpy(temp->phone, _phone);
		strcpy(temp->address, _address);

		addbook *p;
		p = head;

		if (p->link == NULL) {  
			p->link = temp;
			temp->link = NULL;
		}
		else {
			while (p->link != NULL)
			{
				p = p->link;
			}
			p->link = temp;
			temp->link = NULL;
		}
	}
}