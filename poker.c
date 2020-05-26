#include<stdio.h>

#define RankNum 13
#define SuitNum 4
#define Cards 5
int numrank[RankNum + 1];/*rank가 r인 카드의 개수*/
int numsuit[SuitNum];/*suit가 s인카드의 개수*/
void init(void);
void read(void);
void analyze(void);
int flush() {/*같은문양 5번*/
	for (int i = 0; i < SuitNum; i++) {
		if (numsuit[i] == 5)
			return 1;
	}
	return 0;
}
int straight() {/*숫자가 5개 연속*/

	for (int j = 1; j <= 13; j++) {
		int tmp = j;
		int count = 0;
		for (int i = 0; i < Cards; i++) {/**/
			if (numrank[tmp] == 1 && numrank[tmp + 1] == 1 && j < 13) {
				count++;
			}
			else if (j == 13 && numrank[13] == 1 && numrank[1] == 1) {
				count++;/*이때 2 a j q k 와같은 스트레이트 패를 처리하기위해서 설정한 문장이다*/
			}
			tmp++;
			if (count == 4)
				return 1;
		}
	}
	return 0;
}
int fourcards() {
	for (int i = 1; i <= RankNum; i++) {
		if (numrank[i] == 4)
			return 1;
	}
	return 0;
}
int triple() {
	for (int i = 1; i <=RankNum; i++) {
		if (numrank[i] == 3)
			return 1;
	}
	return 0;
}
int pair() {
	int count = 0;
	for (int i = 1; i <=RankNum; i++) {
		if (numrank[i] == 2)
			count++;
	}
	if (count == 2)
		return 2;
	else if (count == 1)
		return 1;
	else
		return 0;
}
int main(void) {
	while (1) {
		read();
		analyze();
		return 0;
	}
}
void read(void) {/*카드를읽는함수*/
	char ch, rank_ch, suit_ch;
	int storage_rank[5];/*이배열들은 중복을 검사하기 위해 존재한다.*/
	int storage_suit[5];
	int rank,suit;
	init();/*매시작마다 데이터를 0으로 초기화해줘야함*/
	int Num = 0;
	while (Num < Cards) {
		int tmp = 1;
		printf("Enter a card: ");
		scanf_s(" %c", &rank_ch);
		switch (rank_ch) {
		case 'a':{ rank = 1;
			storage_rank[Num] = 1;
			break;
		}
		case '2':{ rank = 2;
			storage_rank[Num] = 2;
			break;
		}
		case '3':{ rank = 3;
			storage_rank[Num] = 3;
			break;
		}
		case '4': { rank = 4;
			storage_rank[Num] = 4;
			break; }
		case '5': {rank = 5;
			storage_rank[Num] = 5;
			break; }
		case '6': { rank = 6;
			storage_rank[Num] = 6;
			break; }
		case '7': {rank = 7;
			storage_rank[Num] = 7;
			break; }
		case '8': { rank = 8;
			storage_rank[Num] = 8;
			break; }
		case '9': { rank = 9;
			storage_rank[Num] = 9;
			break; }
		case 't': {rank = 10;
			storage_rank[Num] = 10;
			break; }
		case 'j': {rank = 11;
			storage_rank[Num] = 11;
			break; }
		case 'q': {rank = 12;
			storage_rank[Num] = 12;
			break; }
		case 'k': {rank = 13;
			storage_rank[Num] = 13;
			break; }
		default: {
			tmp = 0;/*이때 필터에 걸리게되면 tmp는 0값을 가지게하여 tmp가0일때 나머지문장들을 실행되지않게한다.*/
			printf("없는 카드입니다 다시 입력하세요\n\n");
			break;
		}
		}
		scanf_s(" %c", &suit_ch);
		if (tmp != 0) {
			switch (suit_ch) {
			case 'c': { suit = 0;
				storage_suit[Num] = 0;
				break; }
			case 'd': {suit = 1;
				storage_suit[Num] = 1;
				break; }
			case 'h': {suit = 2;
				storage_suit[Num] = 2;
				break; }
			case 's': {suit = 3;
				storage_suit[Num] = 3;
				break;
			}
			default: {
				printf("중복된 문양입니다 다시 입력하세요\n");
				tmp = 0;
				break;
			}
			}
		}
		for (int i = 0; i < Num; i++) {/*중복된 카드를 검사하는 문장*/
			for (int j = i; j < Num; j++) {
				if (storage_rank[j] == storage_rank[j+1] && storage_suit[j] == storage_suit[j + 1]) {
					printf("중복된 카드입니다 다시 입력하세요\n");
					tmp = 0;
				}
			}
		}
		if (tmp != 0) {
			numrank[rank]++;
			numsuit[suit]++;
			Num++;
		}
	}

}


void analyze(void) {/*분석하여 어떤패를 가졌는지 출력하는 함수*/
	if (straight() == 1 && flush() == 1) {
		printf("straight flush!");
		return;
	}
	else if (fourcards() == 1) {
		printf("fourcards!");
		return;
	}
	else if (triple() == 1 && pair() == 1)
	{
		printf("full house");
		return;
	}
	else if (flush() == 1) {
		printf("flush");
		return;
	}
	else if (straight() == 1) {
		printf("straight");
		return;
	}
	else if (triple() == 1)
	{
		printf("triple");
		return;
	}
	else if (pair() == 2) {
		printf("two pair");
		return;
	}
	else if (pair() == 1) {
		printf("one pair");
		return;
	}
	else {
		printf("Nop..");
		return;
	}
}


	void init(void) {/*데이터값을 초기화*/

	for (int i = 0; i < RankNum;i++) {
		numrank[i] = 0;
	}
	for (int i = 0; i < SuitNum; i++) {
		numsuit[i] = 0;
	}


}
