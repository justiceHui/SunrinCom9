#include "monitor.h"

int bun = 0;
int jul = 5;

void makeArr(){
	int i;
	do{
		printf("���° �ٿ��� ���ǰǰ���? (1~5)\n");
		scanf("%d", &jul);
	}while(jul<1 || jul>5);
	
	do{
		printf("�� �д��� ���ǰǰ���? (1~3�д� / ��� �д��� 0)\n");
		scanf("%d", &bun);
	}while(bun<0 || bun>3);
	
	for(i=-1*jul+1; i<=0; i++){
		if(bun==0){
			printComputer(i*5, -104-i*2, i+jul, 1);
			printComputer(i*5, -72-i*2, i+jul, 2);
			printComputer(i*5, -16-i*2, i+jul, 3);
			printComputer(i*5, 16-i*2, i+jul, 4);
			printComputer(i*5, 72-i*2, i+jul, 5);
			printComputer(i*5, 104-i*2, i+jul, 6);
		}
		else if(bun==1){
			printf("1�д� �Դϴ�.\n");
			printComputer(i*5, -16-i*2, i+jul, 1);
			printComputer(i*5, 16-i*2, i+jul, 2);
		}
		else if(bun==2){
			printf("2�д� �Դϴ�.\n");
			printComputer(i*5, -16-i*2, i+jul, 3);
			printComputer(i*5, 16-i*2, i+jul, 4);
		}
		else if(bun==3){
			printf("3�д� �Դϴ�.\n");
			printComputer(i*5, -16-i*2, i+jul, 5);
			printComputer(i*5, 16-i*2, i+jul, 6);
		}
	}
}
