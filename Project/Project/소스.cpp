#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define MAXNAME 10	//�̸��� �ִ���̸� 15
#define MAXBIRTHDAY 8 //��������� �ִ���̸� 8
#define MAXPHONE 13	//��ȭ��ȣ�� �ִ���̸� 15
#define MAXADDRRESS 50	//�ּ��� �ִ���̸� 50

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
void getFile();

int count = 0;
addbook *head = NULL; //head ����

int main()
{
	int checkSave;
	int menu; //switch���� ���� �޴�����
	head = createList(); //head ��忡 ���鸮��Ʈ ���� �� �ʱ�ȭ

	getFile();
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
			checkSave = saveData(head);
			if (checkSave == 0) {
				printf("������������������������������������������������\n");
				printf("�� ������ �Ϸ�Ǿ����ϴ٦�\n");
				printf("�Ŧ���������������������������������������������\n");
				getchar();
			}
			else {
				printf("������������������������������������������������\n");
				printf("�����忡 �����Ͽ����ϴ� ��\n");
				printf("�Ŧ���������������������������������������������\n");
				getchar();
			}
			break;

		case 7:
			system("cls");
			printf("���α׷��� �����մϴ�.\n");
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

		printf("\nPress <quit> or <exit> or <end> to Menu!!\n");
		
		printf("�� ��: ");
		scanf("%s", _name);
		getchar();

		if (strcmp(_name, "quit") == 0 || strcmp(_name, "exit") == 0 || strcmp(_name, "end") == 0)
		{
			break; //�ش�Ǵ� �ܾ �����Ͽ� �Է��� �����Ŵ
		}

		printf("�� �� �� ��: ");
		scanf("%s", _birthday);
		getchar();

		printf("�� ȭ �� ȣ [-]������ �����ϰ� �Է� : ");
		scanf("%s", _phone);
		getchar();

		printf("�� ��: ");
		gets_s(_address, MAXADDRRESS);

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
		printf("����������������������������������������������������������������������������������������������������������\n");
		printf("�� ���� ��ϵ� ������ �����ϴ�. (Press enter to menu)��\n");
		printf("�Ŧ�������������������������������������������������������������������������������������������������������\n");
		_getch();
	}

	while (tempNode != NULL)
	{
		printf("����������������������������������������������������������������������������������������������������������\n");
		printf("��<%d>��° ȸ��\n", num++);
		printf("���� ��: %s\n", tempNode->name);
		printf("���� �� �� ��: %s\n", tempNode->birthday);
		printf("���� ȭ �� ȣ : %s\n", tempNode->phone);
		printf("���� ��: %s\n", tempNode->address);
		printf("�Ŧ�������������������������������������������������������������������������������������������������������\n");

		tempNode = tempNode->link; //���� ���� �̵�
		if (tempNode == NULL) {
			printf("������������������������������������������������������������������������������������\n");
			printf("�� ������ ȸ���Դϴ�(Press enter to menu) ��\n");
			printf("�Ŧ���������������������������������������������������������������������������������\n");
		}
		else {
			printf("������������������������������������������������������������\n");
			printf("�� ���� ȸ�� ����(Enter)      ��\n");
			printf("�Ŧ���������������������������������������������������������\n");
		}
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
	scanf("%s", member);

	while (tempNode != NULL)
	{
		if (strcmp(tempNode->name, member) == 0)
		{
			printf("����������������������������������������������������������������������������������������������������������\n");
			printf("��ȸ���� ã�ҽ��ϴ�.\n");
			printf("���� ��: %s\n", tempNode->name);
			printf("���� �� �� ��: %s\n", tempNode->birthday);
			printf("���� ȭ �� ȣ : %s\n", tempNode->phone);
			printf("���� ��: %s\n", tempNode->address);
			printf("�Ŧ�������������������������������������������������������������������������������������������������������\n");
			printf("(Press enter to menu)\n");

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
		printf("\nã���ô� ȸ�������� �������� �ʽ��ϴ�. (Press enter to menu)\n");
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
	scanf("%s", delName);
	
	prevNode = head; //������带 ������� ����
	currNode = head->link; //���� ��带 ù��° �����ͳ��� ����

	while (currNode != NULL)
	{
		if (strcmp(currNode->name, delName) == 0)
		{
			printf("<%s> ȸ���� �����մϴ�.", delName);
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
		printf("\n�����Ϸ��� ȸ�������� �������� �ʽ��ϴ�. (Press enter to menu)\n");
		_getch();
	}
}

void selectionSort(addbook *head) //�̸��� ������������ ����
{
	addbook *compNode; //������ġ�� ����Ű�� ���
	addbook *nextNode; //�񱳴�� ���
	char temp[50];

	if (head->link != NULL)
	{
		compNode = head->link;
		nextNode = compNode->link;
		
		for (; compNode != NULL; compNode = compNode->link)
			//������ġ ��带 link�� �����ذ��� �ݺ����� ������
		{
			nextNode = compNode->link; //�񱳴�� ����� ������ �׻� ������ġ ��������
			for (; nextNode != NULL; nextNode = nextNode->link)
				//�񱳴�� ��带 link�� �����ذ��� ������ ������ �ݺ��� ����
			{
				if (strcmp(compNode->name, nextNode->name) > 0) //������ġ ��� �̸��� �񱳴�� ��� �̸��� ���Ͽ� ������ġ�� �� ũ�ٸ� ������
				{
					strcpy(temp, compNode->name);
					strcpy(compNode->name, nextNode->name);
					strcpy(nextNode->name, temp);

					strcpy(temp, compNode->birthday);
					strcpy(compNode->birthday, nextNode->birthday);
					strcpy(nextNode->birthday, temp);

					strcpy(temp, compNode->phone);
					strcpy(compNode->phone, nextNode->phone);
					strcpy(nextNode->phone, temp);

					strcpy(temp, compNode->address);
					strcpy(compNode->address, nextNode->address);
					strcpy(nextNode->address, temp);
				}
			}
		}
		printf("\n������ �Ϸ��߽��ϴ�. (Press enter to menu)\n");
		_getch();
	}
	else
	{
		printf("\n������ �����Ͱ� �����ϴ�. (Press enter to menu)\n");
		_getch();
	}
}

int saveData(addbook *head) //����� ȸ���� ������ ���Ͽ� ������
{
	FILE *fp;
	addbook *list;

	list = head->link;

	if ((fp = fopen("address_list.txt", "a")) == NULL)
	{
		return 1;
	}

	while (list != NULL)
	{
		fprintf(fp, "%s %s %s %s\n", list->name, list->birthday, list->phone, list->address);
		list = list->link;
	}
	fclose(fp);
	return 0;
}

void getFile()
{
	FILE *fp;
	char buffer[30] = {0, };
	addbook *tmp, *newNode;

	fp = fopen("address_list.txt", "r");

	if (fp == NULL)
	{
		printf("�о�� ������ �����Ͱ� �����ϴ�.\n");
		return;
	}
	else
	{
		while (!feof(fp))
		{
			newNode = (addbook *)malloc(sizeof(addbook));
			fgets(buffer, 30, fp);

			if (strlen(buffer) == 0)
			{
				break;
			}
			buffer[strlen(buffer) - 1] = '\0';
			fscanf(fp, "%s", newNode->name);

			fgets(buffer, 30, fp);
			buffer[strlen(buffer) - 1] = '\0';
			fscanf(fp, "%s", newNode->birthday);

			fgets(buffer, 30, fp);
			buffer[strlen(buffer) - 1] = '\0';
			fscanf(fp, "%s", newNode->phone);

			fgets(buffer, 30, fp);
			if (buffer[strlen(buffer) - 1] == '\n') 
			{
				buffer[strlen(buffer) - 1] = '\0';
			}
			fscanf(fp, "%s", newNode->address);

			if (head == NULL)
			{
				head = newNode;
				newNode->link = NULL;
				tmp = head;
			}
			else
			{
				tmp->link = newNode;
				newNode->link = NULL;
				tmp = newNode;
			}
			count = count + 1;
		}
	}
	fclose(fp);
}
