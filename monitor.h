#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int sizeI = 50, sizeJ = 260;
const int displayMinI = 35, displayMaxI = 45;
const int displayMinJ = 105, displayMaxJ = 135;
const int midMinI = 46, midMaxI = 47;
const int midMinJ = 119, midMaxJ = 121;
const int underMinI = 48, underMaxI = 50;
const int underMinJ = 110, underMaxJ = 130;
const char hello[20] = "  Hello World!";
const char here[20] = " number ";

char display[51][261] = {0};
int arr[6][7] = { 0 };

void printComputer(int plusI, int plusJ, int a, int b){
	int i, j;
	for(i=displayMinI + plusI; i<=displayMaxI + plusI; i++){
		for(j=displayMinJ + plusJ; j<=displayMaxJ + plusJ; j++){
			if(i==displayMinI+plusI || i==displayMaxI+plusI || j==displayMinJ+plusJ || j==displayMaxJ+plusJ) display[i][j] = '#';
			else if(i==displayMinI+plusI+1){
				if(displayMinJ+plusJ+2<=j && j<=displayMinJ+plusJ+13) display[i][j] =  hello[j - (displayMinJ + plusJ)];
			}
			else if(i==displayMinI+plusI+2){
				if(displayMinJ+plusJ+2<=j && j<=displayMinJ+plusJ+10) display[i][j] = here[j - (displayMinJ + plusJ) - 1];
				if(displayMinJ+plusJ+12 == j) display[i][j] = (arr[a][b]/10) + '0';
				if(displayMinJ+plusJ+13 == j) display[i][j] = (arr[a][b]%10) + '0';
				
			}
			else display[i][j] = ' ';
		}
	}
	for(i=midMinI+plusI; i<=midMaxI+plusI; i++){
		for(j=midMinJ+plusJ; j<=midMaxJ+plusJ; j++){
			if(j==midMinJ+plusJ || j==midMaxJ+plusJ) display[i][j] = '|';
			else display[i][j] = ' ';
		}
	}
	for(i=underMinI+plusI; i<=underMaxI+plusI; i++){
		for(j=underMinJ+plusJ; j<=underMaxJ+plusJ; j++){
			if(i==underMinI+plusI || i==underMaxI+plusI) display[i][j] = '-';
			else if(j==underMinJ+plusJ || j==underMaxJ+plusJ) display[i][j] = '|';
			else display[i][j] = ' ';
		}
	}
}
