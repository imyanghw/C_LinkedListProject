#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define MAXNAME 10	//ÀÌ¸§ÀÇ ÃÖ´ë±æÀÌ¸¦ 15
#define MAXBIRTHDAY 8 //»ý³â¿ùÀÏÀÇ ÃÖ´ë±æÀÌ¸¦ 8
#define MAXPHONE 13	//ÀüÈ­¹øÈ£ÀÇ ÃÖ´ë±æÀÌ¸¦ 15
#define MAXADDRRESS 50	//ÁÖ¼ÒÀÇ ÃÖ´ë±æÀÌ¸¦ 50

typedef struct Addbook {
	char name[MAXNAME]; //ÀÌ¸§
	char birthday[MAXBIRTHDAY]; //»ý³â¿ùÀÏ
	char phone[MAXPHONE]; //ÀüÈ­¹øÈ£
	char address[MAXADDRRESS]; //ÁÖ¼Ò
	struct Addbook *link; //³ëµåÀÇ link
}addbook;

addbook* createList(); //¸®½ºÆ® ÃÊ±âÈ­ ÇÔ¼ö

void inputData(addbook*); //¸®½ºÆ® ÀÔ·Â ÇÔ¼ö
void printList(addbook*); //¸®½ºÆ® Ãâ·Â ÇÔ¼ö
void findList(addbook*); //¸®½ºÆ® °Ë»ö ÇÔ¼ö
void deleteList(addbook*); //¸®½ºÆ® »èÁ¦ ÇÔ¼ö
void selectionSort(addbook*); //¸®½ºÆ® Á¤·Ä ÇÔ¼ö
int saveData(addbook *); //µî·ÏµÈ È¸¿øÁ¤º¸¸¦ ÆÄÀÏ¿¡ ÀúÀåÇÏ´Â ÇÔ¼ö
void getFile();

int count = 0;
addbook *head = NULL; //head »ý¼º

int main()
{
	int checkSave;
	int menu; //switch¹®À» À§ÇÑ ¸Þ´º¼±ÅÃ
	head = createList(); //head ³ëµå¿¡ °ø¹é¸®½ºÆ® »ý¼º ¹× ÃÊ±âÈ­

	getFile();
	while (1) {
		system("cls");
		printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
		printf("¦­   Address Book   ¦­\n");
		printf("¦Å¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ã\n");
		printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
		printf("¦­ (1) Member List  ¦­\n");
		printf("¦­ (2) Add Member   ¦­\n");
		printf("¦­ (3) Search Member¦­\n");
		printf("¦­ (4) Delete Member¦­\n");
		printf("¦­ (5) Sort         ¦­\n");
		printf("¦­ (6) Save File    ¦­\n");
		printf("¦­ (7) Exit         ¦­\n");
		printf("¦Å¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ã\n");
		printf("\nPlease enter the action you want : ");
		scanf("%d", &menu);
		
		switch (menu) {
		case 1:
			system("cls");
			printf("ÁÖ¼Ò·Ï¿¡ µî·ÏµÈ ¸ñ·ÏÀÔ´Ï´Ù.\n");
			printList(head);
			break;

		case 2:
			system("cls");
			printf("È¸¿ø µî·Ï ÀÛ¾÷ÀÔ´Ï´Ù Á¤º¸¸¦ ÀÔ·ÂÇÏ¼¼¿ä.\n");
			inputData(head);
			break;

		case 3:
			system("cls");
			printf("ÁÖ¼Ò·Ï °Ë»ö ÀÛ¾÷ÀÔ´Ï´Ù Á¤º¸¸¦ ÀÔ·ÂÇÏ¼¼¿ä.\n");
			findList(head);
			break;

		case 4:
			system("cls");
			printf("ÁÖ¼Ò·Ï »èÁ¦ ÀÛ¾÷ÀÔ´Ï´Ù. Á¤º¸¸¦ ÀÔ·ÂÇÏ¼¼¿ä\n");
			deleteList(head);
			break;

		case 5:
			system("cls");
			printf("È¸¿øÀ» ÀÌ¸§¼øÀ¸·Î Á¤·ÄÇÕ´Ï´Ù.\n");
			selectionSort(head);
			break;

		case 6:
			system("cls");
			printf("µ¥ÀÌÅÍ¸¦ ÆÄÀÏ¿¡ ÀúÀåÇÕ´Ï´Ù.\n");
			checkSave = saveData(head);
			if (checkSave == 0) {
				printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
				printf("¦­ ÀúÀåÀÌ ¿Ï·áµÇ¾ú½À´Ï´Ù¦­\n");
				printf("¦Å¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ã\n");
				getchar();
			}
			else {
				printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
				printf("¦­ÀúÀå¿¡ ½ÇÆÐÇÏ¿´½À´Ï´Ù ¦­\n");
				printf("¦Å¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ã\n");
				getchar();
			}
			break;

		case 7:
			system("cls");
			printf("ÇÁ·Î±×·¥À» Á¾·áÇÕ´Ï´Ù.\n");
			return 0;

		default:
			system("cls");
			printf("¸Þ´º¸¦ ´Ù½Ã ¼±ÅÃÇØ ÁÖ¼¼¿ä(Enter)");
			break;
		}
		printf("\nPress any key to continue.\n");
		_getch();
	}
	return 0;
}

addbook* createList() //°ø¹é¸®½ºÆ® »ý¼º ¹× ÃÊ±âÈ­
{
	addbook* node; //Head¿¡ addbook ¸¸Å­ÀÇ µ¿Àû ¸Þ¸ð¸®¸¦ ÇÒ´ç
	node = (addbook *)malloc(sizeof(addbook));
	node->link = NULL;
	return node;
}

void inputData(addbook* head) //¸®½ºÆ®¿¡ ³ëµå Ãß°¡
{
	char _name[MAXNAME]; //ÀÌ¸§
	char _birthday[MAXBIRTHDAY]; //»ý³â¿ùÀÏ
	char _phone[MAXPHONE]; //ÀüÈ­¹øÈ£
	char _address[MAXADDRRESS]; //ÁÖ¼Ò

	addbook *temp; //ÀÓ½Ã ³ëµå»ý¼º

	while(1)
	{
		temp = (addbook *)malloc(sizeof(addbook));

		printf("\nPress <quit> or <exit> or <end> to Menu!!\n");
		
		printf("ÀÌ ¸§: ");
		scanf("%s", _name);
		getchar();

		if (strcmp(_name, "quit") == 0 || strcmp(_name, "exit") == 0 || strcmp(_name, "end") == 0)
		{
			break; //ÇØ´çµÇ´Â ´Ü¾î¸¦ À¯µµÇÏ¿© ÀÔ·ÂÀ» Á¾·á½ÃÅ´
		}

		printf("»ý ³â ¿ù ÀÏ: ");
		scanf("%s", _birthday);
		getchar();

		printf("Àü È­ ¹ø È£ [-]ÇÏÀÌÇÂ Á¦¿ÜÇÏ°í ÀÔ·Â : ");
		scanf("%s", _phone);
		getchar();

		printf("ÁÖ ¼Ò: ");
		gets_s(_address, MAXADDRRESS);

		//ÀÔ·Â¹ÞÀº °ªÀ» ÀÓ½Ã³ëµå¿¡ ÀúÀå½ÃÄÑ³í´Ù.
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

void printList(addbook* head) //¸®½ºÆ® ³ëµå Ãâ·Â
{
	addbook *tempNode;
	tempNode = head->link;
	int num = 1; //ÁÖ¼ÒÁ¤º¸¿¡ µî·ÏµÈ ÀÎ¿øÀ» Ä«¿îÆÃÇÒ ¼ö

	system("cls");

	if (tempNode == NULL) //ÀúÀåµÈ µ¥ÀÌÅÍ°¡ ºñ¾îÀÖ´Ù¸é
	{
		printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
		printf("¦­ ÇöÀç µî·ÏµÈ Á¤º¸°¡ ¾ø½À´Ï´Ù. (Press enter to menu)¦­\n");
		printf("¦Å¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ã\n");
		_getch();
	}

	while (tempNode != NULL)
	{
		printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
		printf("¦­<%d>¹øÂ° È¸¿ø\n", num++);
		printf("¦­ÀÌ ¸§: %s\n", tempNode->name);
		printf("¦­»ý ³â ¿ù ÀÏ: %s\n", tempNode->birthday);
		printf("¦­Àü È­ ¹ø È£ : %s\n", tempNode->phone);
		printf("¦­ÁÖ ¼Ò: %s\n", tempNode->address);
		printf("¦Å¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ã\n");

		tempNode = tempNode->link; //´ÙÀ½ ³ëµå·Î ÀÌµ¿
		if (tempNode == NULL) {
			printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
			printf("¦­ ¸¶Áö¸· È¸¿øÀÔ´Ï´Ù(Press enter to menu) ¦­\n");
			printf("¦Å¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ã\n");
		}
		else {
			printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
			printf("¦­ ´ÙÀ½ È¸¿ø º¸±â(Enter)      ¦­\n");
			printf("¦Å¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ã\n");
		}
		_getch();
	}
}

void findList(addbook *head) //¸®½ºÆ®¿¡ ÀÖ´Â ³»¿ëÀ» °Ë»ö
{
	int check = 0; //È¸¿øÀ» Ã£±âÀ§ÇÔ
	addbook *tempNode;
	tempNode = head->link;
	char member[MAXNAME];

	printf("Ã£À¸½Ç È¸¿øÀÇ ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä : ");
	scanf("%s", member);

	while (tempNode != NULL)
	{
		if (strcmp(tempNode->name, member) == 0)
		{
			printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
			printf("¦­È¸¿øÀ» Ã£¾Ò½À´Ï´Ù.\n");
			printf("¦­ÀÌ ¸§: %s\n", tempNode->name);
			printf("¦­»ý ³â ¿ù ÀÏ: %s\n", tempNode->birthday);
			printf("¦­Àü È­ ¹ø È£ : %s\n", tempNode->phone);
			printf("¦­ÁÖ ¼Ò: %s\n", tempNode->address);
			printf("¦Å¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ã\n");
			printf("(Press enter to menu)\n");

			_getch();
			check = 1; //È¸¿øÀ» Ã£À½
			tempNode = NULL; //È¸¿øÀ» Ã£¾ÒÀ¸¹Ç·Î while ·çÇÁ¸¦ ºüÁ®³ª¿À±â À§ÇÑ ¼öÇà
		}
		else //È¸¿øÀÌ ¾Æ´Ò°æ¿ì ´ÙÀ½ ³ëµå·Î ÀÌµ¿
		{
			tempNode = tempNode->link; //È¸¿øÀ» Ã£Áö ¸øÇßÀ¸¸é ´ÙÀ½ ³ëµå¸¦ °Ë»ö
		}
	}

	if (check == 0) //È¸¿øÀÌ ¾ø´Ù¸é
	{
		printf("\nÃ£À¸½Ã´Â È¸¿øÁ¤º¸°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù. (Press enter to menu)\n");
		_getch();
	}
}

void deleteList(addbook *head) //µ¥ÀÌÅÍ »èÁ¦
{
	int check = 0; //»èÁ¦ÇÑ µ¥ÀÌÅÍ°¡ ÀÖ´ÂÁö Ã¼Å©
	addbook *currNode; //ÇöÀç³ëµå¸¦ °¡¸®Å³ ³ëµå»ý¼º
	addbook *prevNode; //ÀÌÀü³ëµå¸¦ °¡¸®Å³ ³ëµå»ý¼º
	char delName[MAXNAME];

	printf("»èÁ¦ÇÏ½Ç È¸¿øÀÇ ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä : ");
	scanf("%s", delName);
	
	prevNode = head; //ÀÌÀü³ëµå¸¦ Çì´õ³ëµå·Î ¼³Á¤
	currNode = head->link; //ÇöÀç ³ëµå¸¦ Ã¹¹øÂ° µ¥ÀÌÅÍ³ëµå·Î ¼³Á¤

	while (currNode != NULL)
	{
		if (strcmp(currNode->name, delName) == 0)
		{
			printf("<%s> È¸¿øÀ» »èÁ¦ÇÕ´Ï´Ù.", delName);
			_getch();

			prevNode->link = prevNode->link->link;
			free(currNode);
			check = 1; //µ¥ÀÌÅÍ »èÁ¦¿Ï·á
			break; //while¹Ýº¹¹® ºüÁ®³ª°¨
		}
		else
		{
			prevNode = currNode; //ÀÌÀü³ëµå¸¦ ÇöÀç ³ëµå·Î ¿Å±â°í ³­ ÈÄ¿¡
			currNode = currNode->link; //ÇöÀç³ëµå´Â ´ÙÀ½ ¸µÅ© ³ëµå·Î ÀÌµ¿
		}
	}

	if (check == 0) //È¸¿øÀÌ ¾ø´Ù¸é
	{
		printf("\n»èÁ¦ÇÏ·Á´Â È¸¿øÁ¤º¸°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù. (Press enter to menu)\n");
		_getch();
	}
}

void selectionSort(addbook *head) //ÀÌ¸§À» ¿À¸§Â÷¼øÀ¸·Î Á¤·Ä
{
	addbook *compNode; //±âÁØÀ§Ä¡¸¦ °¡¸£Å°´Â ³ëµå
	addbook *nextNode; //ºñ±³´ë»ó ³ëµå
	char temp[50];

	if (head->link != NULL)
	{
		compNode = head->link;
		nextNode = compNode->link;
		
		for (; compNode != NULL; compNode = compNode->link)
			//±âÁØÀ§Ä¡ ³ëµå¸¦ link·Î ¿¬°áÇØ°¡¸ç ¹Ýº¹¹®À» ¼öÇàÇÔ
		{
			nextNode = compNode->link; //ºñ±³´ë»ó ³ëµåÀÇ ½ÃÀÛÀº Ç×»ó ±âÁØÀ§Ä¡ ´ÙÀ½ºÎÅÍ
			for (; nextNode != NULL; nextNode = nextNode->link)
				//ºñ±³´ë»ó ³ëµå¸¦ link·Î ¿¬°áÇØ°¡¸ç ¸¶Áö¸· ³ëµå±îÁö ¹Ýº¹¹® ¼öÇà
			{
				if (strcmp(compNode->name, nextNode->name) > 0) //±âÁØÀ§Ä¡ ³ëµå ÀÌ¸§°ú ºñ±³´ë»ó ³ëµå ÀÌ¸§À» ºñ±³ÇÏ¿© ±âÁØÀ§Ä¡°¡ ´õ Å©´Ù¸é ¼öÇàÇÔ
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
		printf("\nÁ¤·ÄÀ» ¿Ï·áÇß½À´Ï´Ù. (Press enter to menu)\n");
		_getch();
	}
	else
	{
		printf("\nÁ¤·ÄÇÒ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù. (Press enter to menu)\n");
		_getch();
	}
}

int saveData(addbook *head) //ÀúÀåµÈ È¸¿øÀÇ Á¤º¸¸¦ ÆÄÀÏ¿¡ ÀúÀåÇÔ
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
		printf("ÀÐ¾î¿Â ÆÄÀÏÀÇ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù.\n");
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
