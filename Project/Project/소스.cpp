#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define MAXNAME 15	//이름의 최대길이를 15
#define MAXBIRTHDAY 8 //생년월일의 최대길이를 8
#define MAXPHONE 13	//전화번호의 최대길이를 15
#define MAXADDRRESS 20	//주소의 최대길이를 50

typedef struct Addbook {
	char name[MAXNAME]; //이름
	char birthday[MAXBIRTHDAY]; //생년월일
	char phone[MAXPHONE]; //전화번호
	char address[MAXADDRRESS]; //주소
	struct Addbook *link; //노드의 link
}addbook;

addbook* createList(); //리스트 초기화 함수
void inputData(addbook*); //리스트 입력 함수

int main()
{
	int checkSave;
	int menu; //switch문을 위한 메뉴선택
	addbook *head; //head 생성
	head = createList(); //head 노드에 공백리스트 생성 및 초기화

	while (1) {
		system("cls");
		printf("┏━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃   Address Book   ┃\n");
		printf("┖━━━━━━━━━━━━━━━━━━┚\n");
		printf("┏━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃ (1) Member List  ┃\n");
		printf("┃ (2) Add Member   ┃\n");
		printf("┃ (3) Search Member┃\n");
		printf("┃ (4) Delete Member┃\n");
		printf("┃ (5) Sort         ┃\n");
		printf("┃ (6) Save File    ┃\n");
		printf("┃ (7) Exit         ┃\n");
		printf("┖━━━━━━━━━━━━━━━━━━┚\n");
		printf("\nPlease enter the action you want : ");
		scanf("%d", &menu);
		
		switch (menu) {
		case 1:
			system("cls");
			printf("주소록에 등록된 목록입니다.\n");
			printList(head);
			break;

		case 2:
			system("cls");
			printf("회원 등록 작업입니다 정보를 입력하세요.\n");
			inputData(head);
			break;

		case 3:
			system("cls");
			printf("주소록 검색 작업입니다 정보를 입력하세요.\n");
			findList(head);
			break;

		case 4:
			system("cls");
			printf("주소록 삭제 작업입니다. 정보를 입력하세요\n");
			deleteList(head);
			break;

		case 5:
			system("cls");
			printf("회원을 이름순으로 정렬합니다.\n");
			selectionSort(head);
			break;

		case 6:
			system("cls");
			printf("데이터를 파일에 저장합니다.\n");
			checkSave = savaData(Head);
			if (checkSave == 0) {
				printf("\n==저장이 완료되었습니다==");
				fflush(stdin); getchar();
			}
			else {
				printf("\n==저장에 실패하였습니다==");
				fflush(stdin); getchar();
			}
			break;

		case 7:
			system("cls");
			printf("종료합니다.\n");
			return 0;

		default:
			system("cls");
			printf("메뉴를 다시 선택해 주세요(Enter)");
			break;
		}
		printf("\nPress any key to continue.\n");
		_getch();
	}
	return 0;
}

addbook* createList() //공백리스트 생성 및 초기화
{
	addbook* node; //Head에 addbook 만큼의 동적 메모리를 할당
	node = (addbook *)malloc(sizeof(addbook));
	node->link = NULL;
	return node;
}

void inputData(addbook* head) //리스트에 사용자 추가
{
	char _name[MAXNAME]; //이름
	char _birthday[MAXBIRTHDAY]; //생년월일
	char _phone[MAXPHONE]; //전화번호
	char _address[MAXADDRRESS]; //주소

	addbook *temp; //임시 노드생성

	while(1)
	{
		temp = (addbook *)malloc(sizeof(addbook));

		printf("\n Press <quit> or <exit> or <end> to Menu!!\n");
		
		fflush(stdin);
		printf("이 름:");
		scanf("%s", _name);

		if (strcmp(_name, "quit") == 0 || strcmp(_name, "exit") == 0 || strcmp(_name, "end") == 0)
		{
			break; //해당되는 단어를 유도하여 입력을 종료시킴
		}

		fflush(stdin);
		printf("생 년 월 일:");
		scanf("%s", _birthday);

		fflush(stdin);
		printf("전 화 번 호 :");
		scanf("%s", _phone);

		fflush(stdin);
		printf("주 소:");
		scanf("%s", _address);

		//입력받은 값을 임시노드에 저장시켜논다.
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