#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define MAXNAME 10	//檜葷曖 譆渠望檜蒂 15
#define MAXBIRTHDAY 8 //儅喇錯橾曖 譆渠望檜蒂 8
#define MAXPHONE 13	//瞪�食醽�曖 譆渠望檜蒂 15
#define MAXADDRRESS 50	//輿模曖 譆渠望檜蒂 50

typedef struct Addbook {
	char name[MAXNAME]; //檜葷
	char birthday[MAXBIRTHDAY]; //儅喇錯橾
	char phone[MAXPHONE]; //瞪�食醽�
	char address[MAXADDRRESS]; //輿模
	struct Addbook *link; //喻萄曖 link
}addbook;

addbook* createList(); //葬蝶お 蟾晦�� л熱

void inputData(addbook*); //葬蝶お 殮溘 л熱
void printList(addbook*); //葬蝶お 轎溘 л熱
void findList(addbook*); //葬蝶お 匐儀 л熱
void deleteList(addbook*); //葬蝶お 餉薯 л熱
void selectionSort(addbook*); //葬蝶お 薑溺 л熱
int saveData(addbook *); //蛔煙脹 �蛾讔內虜� だ橾縑 盪濰ж朝 л熱
void getFile();

int count = 0;
addbook *head = NULL; //head 儅撩

int main()
{
	int checkSave;
	int menu; //switch僥擊 嬪и 詭景摹鷗
	head = createList(); //head 喻萄縑 奢寥葬蝶お 儅撩 塽 蟾晦��

	getFile();
	while (1) {
		system("cls");
		printf("旨收收收收收收收收收收收收收收收收收收旬\n");
		printf("早   Address Book   早\n");
		printf("汍收收收收收收收收收收收收收收收收收收污\n");
		printf("旨收收收收收收收收收收收收收收收收收收旬\n");
		printf("早 (1) Member List  早\n");
		printf("早 (2) Add Member   早\n");
		printf("早 (3) Search Member早\n");
		printf("早 (4) Delete Member早\n");
		printf("早 (5) Sort         早\n");
		printf("早 (6) Save File    早\n");
		printf("早 (7) Exit         早\n");
		printf("汍收收收收收收收收收收收收收收收收收收污\n");
		printf("\nPlease enter the action you want : ");
		scanf("%d", &menu);
		
		switch (menu) {
		case 1:
			system("cls");
			printf("輿模煙縑 蛔煙脹 跡煙殮棲棻.\n");
			printList(head);
			break;

		case 2:
			system("cls");
			printf("�蛾� 蛔煙 濛機殮棲棻 薑爾蒂 殮溘ж撮蹂.\n");
			inputData(head);
			break;

		case 3:
			system("cls");
			printf("輿模煙 匐儀 濛機殮棲棻 薑爾蒂 殮溘ж撮蹂.\n");
			findList(head);
			break;

		case 4:
			system("cls");
			printf("輿模煙 餉薯 濛機殮棲棻. 薑爾蒂 殮溘ж撮蹂\n");
			deleteList(head);
			break;

		case 5:
			system("cls");
			printf("�蛾衋� 檜葷牖戲煎 薑溺м棲棻.\n");
			selectionSort(head);
			break;

		case 6:
			system("cls");
			printf("等檜攪蒂 だ橾縑 盪濰м棲棻.\n");
			checkSave = saveData(head);
			if (checkSave == 0) {
				printf("旨收收收收收收收收收收收收收收收收收收收收收收旬\n");
				printf("早 盪濰檜 諫猿腎歷蝗棲棻早\n");
				printf("汍收收收收收收收收收收收收收收收收收收收收收收污\n");
				getchar();
			}
			else {
				printf("旨收收收收收收收收收收收收收收收收收收收收收收旬\n");
				printf("早盪濰縑 褒ぬж艘蝗棲棻 早\n");
				printf("汍收收收收收收收收收收收收收收收收收收收收收收污\n");
				getchar();
			}
			break;

		case 7:
			system("cls");
			printf("Щ煎斜極擊 謙猿м棲棻.\n");
			return 0;

		default:
			system("cls");
			printf("詭景蒂 棻衛 摹鷗п 輿撮蹂(Enter)");
			break;
		}
		printf("\nPress any key to continue.\n");
		_getch();
	}
	return 0;
}

addbook* createList() //奢寥葬蝶お 儅撩 塽 蟾晦��
{
	addbook* node; //Head縑 addbook 虜躑曖 翕瞳 詭賅葬蒂 й渡
	node = (addbook *)malloc(sizeof(addbook));
	node->link = NULL;
	return node;
}

void inputData(addbook* head) //葬蝶お縑 喻萄 蹺陛
{
	char _name[MAXNAME]; //檜葷
	char _birthday[MAXBIRTHDAY]; //儅喇錯橾
	char _phone[MAXPHONE]; //瞪�食醽�
	char _address[MAXADDRRESS]; //輿模

	addbook *temp; //歜衛 喻萄儅撩

	while(1)
	{
		temp = (addbook *)malloc(sizeof(addbook));

		printf("\nPress <quit> or <exit> or <end> to Menu!!\n");
		
		printf("檜 葷: ");
		scanf("%s", _name);
		getchar();

		if (strcmp(_name, "quit") == 0 || strcmp(_name, "exit") == 0 || strcmp(_name, "end") == 0)
		{
			break; //п渡腎朝 欽橫蒂 嶸紫ж罹 殮溘擊 謙猿衛霽
		}

		printf("儅 喇 錯 橾: ");
		scanf("%s", _birthday);
		getchar();

		printf("瞪 �� 廓 �� [-]ж檜Ъ 薯諼ж堅 殮溘 : ");
		scanf("%s", _phone);
		getchar();

		printf("輿 模: ");
		gets_s(_address, MAXADDRRESS);

		//殮溘嫡擎 高擊 歜衛喻萄縑 盪濰衛麵喱棻.
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

void printList(addbook* head) //葬蝶お 喻萄 轎溘
{
	addbook *tempNode;
	tempNode = head->link;
	int num = 1; //輿模薑爾縑 蛔煙脹 檣錳擊 蘋遴たй 熱

	system("cls");

	if (tempNode == NULL) //盪濰脹 等檜攪陛 綠橫氈棻賊
	{
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早 ⑷營 蛔煙脹 薑爾陛 橈蝗棲棻. (Press enter to menu)早\n");
		printf("汍收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收污\n");
		_getch();
	}

	while (tempNode != NULL)
	{
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早<%d>廓簞 �蛾鱋n", num++);
		printf("早檜 葷: %s\n", tempNode->name);
		printf("早儅 喇 錯 橾: %s\n", tempNode->birthday);
		printf("早瞪 �� 廓 �� : %s\n", tempNode->phone);
		printf("早輿 模: %s\n", tempNode->address);
		printf("汍收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收污\n");

		tempNode = tempNode->link; //棻擠 喻萄煎 檜翕
		if (tempNode == NULL) {
			printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("早 葆雖虞 �蛾衋埭炴�(Press enter to menu) 早\n");
			printf("汍收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收污\n");
		}
		else {
			printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("早 棻擠 �蛾� 爾晦(Enter)      早\n");
			printf("汍收收收收收收收收收收收收收收收收收收收收收收收收收收收收污\n");
		}
		_getch();
	}
}

void findList(addbook *head) //葬蝶お縑 氈朝 頂辨擊 匐儀
{
	int check = 0; //�蛾衋� 瓊晦嬪л
	addbook *tempNode;
	tempNode = head->link;
	char member[MAXNAME];

	printf("瓊戲褒 �蛾衋� 檜葷擊 殮溘ж撮蹂 : ");
	scanf("%s", member);

	while (tempNode != NULL)
	{
		if (strcmp(tempNode->name, member) == 0)
		{
			printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("早�蛾衋� 瓊懊蝗棲棻.\n");
			printf("早檜 葷: %s\n", tempNode->name);
			printf("早儅 喇 錯 橾: %s\n", tempNode->birthday);
			printf("早瞪 �� 廓 �� : %s\n", tempNode->phone);
			printf("早輿 模: %s\n", tempNode->address);
			printf("汍收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收污\n");
			printf("(Press enter to menu)\n");

			_getch();
			check = 1; //�蛾衋� 瓊擠
			tempNode = NULL; //�蛾衋� 瓊懊戲嘎煎 while 瑞Щ蒂 緒螳釭螃晦 嬪и 熱ч
		}
		else //�蛾衋� 嬴棍唳辦 棻擠 喻萄煎 檜翕
		{
			tempNode = tempNode->link; //�蛾衋� 瓊雖 跤ц戲賊 棻擠 喻萄蒂 匐儀
		}
	}

	if (check == 0) //�蛾衋� 橈棻賊
	{
		printf("\n瓊戲衛朝 �蛾讔內萼� 襄營ж雖 彊蝗棲棻. (Press enter to menu)\n");
		_getch();
	}
}

void deleteList(addbook *head) //等檜攪 餉薯
{
	int check = 0; //餉薯и 等檜攪陛 氈朝雖 羹觼
	addbook *currNode; //⑷營喻萄蒂 陛葬鑒 喻萄儅撩
	addbook *prevNode; //檜瞪喻萄蒂 陛葬鑒 喻萄儅撩
	char delName[MAXNAME];

	printf("餉薯ж褒 �蛾衋� 檜葷擊 殮溘ж撮蹂 : ");
	scanf("%s", delName);
	
	prevNode = head; //檜瞪喻萄蒂 ④渦喻萄煎 撲薑
	currNode = head->link; //⑷營 喻萄蒂 羅廓簞 等檜攪喻萄煎 撲薑

	while (currNode != NULL)
	{
		if (strcmp(currNode->name, delName) == 0)
		{
			printf("<%s> �蛾衋� 餉薯м棲棻.", delName);
			_getch();

			prevNode->link = prevNode->link->link;
			free(currNode);
			check = 1; //等檜攪 餉薯諫猿
			break; //while奩犒僥 緒螳釭馬
		}
		else
		{
			prevNode = currNode; //檜瞪喻萄蒂 ⑷營 喻萄煎 衡晦堅 陪 �醴�
			currNode = currNode->link; //⑷營喻萄朝 棻擠 葭觼 喻萄煎 檜翕
		}
	}

	if (check == 0) //�蛾衋� 橈棻賊
	{
		printf("\n餉薯ж溥朝 �蛾讔內萼� 襄營ж雖 彊蝗棲棻. (Press enter to menu)\n");
		_getch();
	}
}

void selectionSort(addbook *head) //檜葷擊 螃葷離牖戲煎 薑溺
{
	addbook *compNode; //晦遽嬪纂蒂 陛腦酈朝 喻萄
	addbook *nextNode; //綠掖渠鼻 喻萄
	char temp[50];

	if (head->link != NULL)
	{
		compNode = head->link;
		nextNode = compNode->link;
		
		for (; compNode != NULL; compNode = compNode->link)
			//晦遽嬪纂 喻萄蒂 link煎 翱唸п陛貊 奩犒僥擊 熱чл
		{
			nextNode = compNode->link; //綠掖渠鼻 喻萄曖 衛濛擎 о鼻 晦遽嬪纂 棻擠睡攪
			for (; nextNode != NULL; nextNode = nextNode->link)
				//綠掖渠鼻 喻萄蒂 link煎 翱唸п陛貊 葆雖虞 喻萄梱雖 奩犒僥 熱ч
			{
				if (strcmp(compNode->name, nextNode->name) > 0) //晦遽嬪纂 喻萄 檜葷婁 綠掖渠鼻 喻萄 檜葷擊 綠掖ж罹 晦遽嬪纂陛 渦 觼棻賊 熱чл
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
		printf("\n薑溺擊 諫猿ц蝗棲棻. (Press enter to menu)\n");
		_getch();
	}
	else
	{
		printf("\n薑溺й 等檜攪陛 橈蝗棲棻. (Press enter to menu)\n");
		_getch();
	}
}

int saveData(addbook *head) //盪濰脹 �蛾衋� 薑爾蒂 だ橾縑 盪濰л
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
		printf("檗橫螞 だ橾曖 等檜攪陛 橈蝗棲棻.\n");
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
