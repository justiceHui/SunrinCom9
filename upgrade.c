#include "seat.h"

typedef struct _Student{
	int i, j;
}Student;

Student hash[28] = { 0 };

int exist(int n){ //�ߺ� Ȯ�� 
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
	printf("    b     o     a     r     d\n"); //ĥ�� 
	printf("----------------------------------\n\n");
	rnd = rand() % 2;
	printf("teacher!                        ");
	rnd == 0 ? printf(" |\n") : printf("__\n"); //��
	printf("�ǢǢǢǢ�\n");//������ å��
}
 
void printDesk(int i){ //å�� ��� 
	if (i != 5) {
		printf("||��||��||  ||��||��||  ||��||��||\n");
 
	}
	else {
		printf("||��||��||  ||��||��||\n");
	}
}
 
int main(){
	int i, j;
	int select;
	srand(time(NULL)); //���� �Լ� �õ� ���� 
	printFront();//���� ���� ��� 
	for (i = 1; i <= 5; i++){
		for (j = 1; j <= 6; j++){
			if (i == 5 && j > 3) break;
			int tmp;
			do{
				tmp = rand() % 27 + 1; //�ڸ� �̱� 
			} while (exist(tmp)); 
			hash[tmp].i = i; //�л� �ڸ� ���� ���̺� ���� 
			hash[tmp].j = j;
			arr[i][j] = tmp;  //�ڸ� ��ġ 
		}
	}
	for (i = 1; i <= 5; i++){
		printDesk(i);
		for (j = 1; j <= 6; j++){
			if (j != 1 && j % 2 == 1) printf("    ");
			if (arr[i][j] == 0) printf("    ");
			else printf("%4d", arr[i][j]); //�л� �ڸ��� ����մϴ�.
		}
		printf("\n");
	}
	do{ //�ɼ� 
		int num;
		printf("----------------------------\n");
		printf("| 1. ���ϴ� ��ȣ �ڸ� ��� |\n");
		printf("| 2. 3D ���               |\n");
		printf("| 3. ����                  |\n");
		printf("----------------------------\n");
		scanf("%d", &select);
		if(select == 3){
			printf("����");
			break;
		}
		if (select != 1 && select != 2 && select != 3){
			printf("�ٽ� �Է�\n");
			continue;
		}
		
		switch(select){
			case 1: 
				printf("���ϴ� ��ȣ �Է� : ");
				scanf("%d", &num);
				if (num < 1 || num > 27){
					printf("��ȣ �߸���.\n");
				}
				else printf("%d���� %d�� ���ʿ��� %d��° �ڸ��Դϴ�.\n\n", num, hash[num].i, hash[num].j);
				break;
				
			case 2:
				makeArr(); //3d ��� ���� ���� 
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
