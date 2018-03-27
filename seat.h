#include "monitor.h"

int bun = 0;
int jul = 5;

void makeArr(){
	int i;
	do{
		printf("몇번째 줄에서 보실건가요? (1~5)\n");
		scanf("%d", &jul);
	}while(jul<1 || jul>5);
	
	do{
		printf("몇 분단을 보실건가요? (1~3분단 / 모든 분단은 0)\n");
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
			printf("1분단 입니다.\n");
			printComputer(i*5, -16-i*2, i+jul, 1);
			printComputer(i*5, 16-i*2, i+jul, 2);
		}
		else if(bun==2){
			printf("2분단 입니다.\n");
			printComputer(i*5, -16-i*2, i+jul, 3);
			printComputer(i*5, 16-i*2, i+jul, 4);
		}
		else if(bun==3){
			printf("3분단 입니다.\n");
			printComputer(i*5, -16-i*2, i+jul, 5);
			printComputer(i*5, 16-i*2, i+jul, 6);
		}
	}
}
