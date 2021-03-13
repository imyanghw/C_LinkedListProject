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
void printList(addbook*); //����Ʈ ��� �Լ�
void findList(addbook*); //����Ʈ �˻� �Լ�
void deleteList(addbook*); //����Ʈ ���� �Լ�
void selectionSort(addbook*); //����Ʈ ���� �Լ�
int saveData(addbook *); //��ϵ� ȸ�������� ���Ͽ� �����ϴ� �Լ�


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

void inputData(addbook* head) //����Ʈ�� ��� �߰�
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

void printList(addbook* head) //����Ʈ ��� ���
{
	addbook *tempNode;
	tempNode = head->link;
	int num = 1; //�ּ������� ��ϵ� �ο��� ī������ ��

	system("cls");

	if (tempNode == NULL) //����� �����Ͱ� ����ִٸ�
	{
		printf("���� ��ϵ� ������ �����ϴ�. (Press enter to menu)\n");
		fflush(stdin);
		_getch();
	}

	while (tempNode != NULL)
	{
		printf("\n<%d>��° ȸ��\n", num++);
		printf("�� ��: %s\n", tempNode->name);
		printf("�� �� �� ��: %s\n", tempNode->birthday);
		printf("�� ȭ �� ȣ : %s\n", tempNode->phone);
		printf("�� ��: %s\n", tempNode->address);

		tempNode = tempNode->link; //���� ���� �̵�
		if (tempNode == NULL) {
			printf("����������������������������\n");
			printf("������ ȸ���Դϴ�(Press enter to menu)");
		}
		else {
			printf("���� ȸ�� ����(Enter)\n");
		}
		fflush(stdin);
		_getch();
	}
}

void findList(addbook *head) //����Ʈ�� �ִ� ������ �˻�
{
	int check = 0; //ȸ���� ã������
	addbook *tempNode;
	tempNode = head->link;
	char member[MAXNAME];

	printf("ã���� ȸ���� �̸��� �Է��ϼ��� : ");
	fflush(stdin);
	scanf("%s", member);

	while (tempNode != NULL)
	{
		if (strcmp(tempNode->name, member) == 0)
		{
			printf("����������������������������\n");
			printf("ȸ���� ã�ҽ��ϴ�.\n");
			printf("�� ��: %s\n", tempNode->name);
			printf("�� �� �� ��: %s\n", tempNode->birthday);
			printf("�� ȭ �� ȣ : %s\n", tempNode->phone);
			printf("�� ��: %s\n", tempNode->address);
			printf("����������������������������\n");
			printf("(Press enter to menu)\n");

			fflush(stdin);
			_getch();
			check = 1; //ȸ���� ã��
			tempNode = NULL; //ȸ���� ã�����Ƿ� while ������ ���������� ���� ����
		}
		else //ȸ���� �ƴҰ�� ���� ���� �̵�
		{
			tempNode = tempNode->link; //ȸ���� ã�� �������� ���� ��带 �˻�
		}
	}

	if (check == 0) //ȸ���� ���ٸ�
	{
		printf("\n ã���ô� ȸ�������� �������� �ʽ��ϴ�.\n");
		printf("(Press enter to menu)\n");
		fflush(stdin);
		_getch();
	}
}

void deleteList(addbook *head) //������ ����
{
	int check = 0; //������ �����Ͱ� �ִ��� üũ
	addbook *currNode; //�����带 ����ų ������
	addbook *prevNode; //������带 ����ų ������
	char delName[MAXNAME];

	printf("�����Ͻ� ȸ���� �̸��� �Է��ϼ��� : ");
	fflush(stdin);
	scanf("%s", delName);
	
	prevNode = head; //������带 ������� ����
	currNode = head->link; //���� ��带 ù��° �����ͳ��� ����

	while (currNode != NULL)
	{
		if (strcmp(currNode->name, delName) == 0)
		{
			printf("<%s> ȸ���� �����մϴ�.", delName);
			fflush(stdin);
			_getch();

			prevNode->link = prevNode->link->link;
			free(currNode);
			check = 1; //������ �����Ϸ�
			break; //while�ݺ��� ��������
		}
		else
		{
			prevNode = currNode; //������带 ���� ���� �ű�� �� �Ŀ�
			currNode = currNode->link; //������� ���� ��ũ ���� �̵�
		}
	}

	if (check == 0) //ȸ���� ���ٸ�
	{
		printf("\n �����Ϸ��� ȸ�������� �������� �ʽ��ϴ�.\n");
		printf("(Press enter to menu)\n");
		fflush(stdin);
		_getch();
	}
}

void selectonSort(addbook *head) //���������� �����Ͽ� �̸��� ������������ ����
{

}

int saveData(addbook *head)
{

}