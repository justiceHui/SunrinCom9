#include "seat.h"

typedef struct _Student{
	int i, j;
}Student;

Student hash[28] = { 0 };

int exist(int n){ //중복 확인 
	int i, j;
	for (i = 1; i <= 5; i++){
		for (j = 1; j <= 6; j++){
			if (arr[i][j] == n) return 1;
		}
	}
	return 0;
}

void printFront(){
	int rnd = 0;
	printf("----------------------------------\n");
	printf("    b     o     a     r     d\n"); //칠판 
	printf("----------------------------------\n\n");
	rnd = rand() % 2;
	printf("teacher!                        ");
	rnd == 0 ? printf(" |\n") : printf("__\n"); //문
	printf("▤▤▤▤▤\n");//선생님 책상
}
 
void printDesk(int i){ //책상 출력 
	if (i != 5) {
		printf("||▩||▩||  ||▩||▩||  ||▩||▩||\n");
 
	}
	else {
		printf("||▩||▩||  ||▩||▩||\n");
	}
}
 
int main(){
	int i, j;
	int select;
	srand(time(NULL)); //랜덤 함수 시드 변경 
	printFront();//교실 앞쪽 출력 
	for (i = 1; i <= 5; i++){
		for (j = 1; j <= 6; j++){
			if (i == 5 && j > 3) break;
			int tmp;
			do{
				tmp = rand() % 27 + 1; //자리 뽑기 
			} while (exist(tmp)); 
			hash[tmp].i = i; //학생 자리 정보 테이블 제작 
			hash[tmp].j = j;
			arr[i][j] = tmp;  //자리 배치 
		}
	}
	for (i = 1; i <= 5; i++){
		printDesk(i);
		for (j = 1; j <= 6; j++){
			if (j != 1 && j % 2 == 1) printf("    ");
			if (arr[i][j] == 0) printf("    ");
			else printf("%4d", arr[i][j]); //학생 자리를 출력합니다.
		}
		printf("\n");
	}
	do{ //옵션 
		int num;
		printf("----------------------------\n");
		printf("| 1. 원하는 번호 자리 출력 |\n");
		printf("| 2. 3D 출력               |\n");
		printf("| 3. 종료                  |\n");
		printf("----------------------------\n");
		scanf("%d", &select);
		if(select == 3){
			printf("종료");
			break;
		}
		if (select != 1 && select != 2 && select != 3){
			printf("다시 입력\n");
			continue;
		}
		
		switch(select){
			case 1: 
				printf("원하는 번호 입력 : ");
				scanf("%d", &num);
				if (num < 1 || num > 27){
					printf("번호 잘못됨.\n");
				}
				else printf("%d번은 %d줄 왼쪽에서 %d번째 자리입니다.\n\n", num, hash[num].i, hash[num].j);
				break;
				
			case 2:
				makeArr(); //3d 출력 정보 생성 
				for(i=1; i<=sizeI; i++){
					for(j=1; j<=sizeJ; j++){
						if(display[i][j]==0) printf(" ");
						else printf("%c", display[i][j]);
					}
					printf("\n");
				}
				break;
		}
		
	} while (select != 3);
}
