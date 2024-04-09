#include <stdio.h>
#include "testcase.h"
#include "solution.h"
#include <Windows.h>
#include <time.h>

void printAlgoComplete();
void copy2dArr(int base2dArr[5][5], int copyed2dArr[5][5]);

int main() {
	//checkSoultion();
	for (int i = 0; i < 5; i++) {
		//printf("matchCounter = %d\n", );
		int checkArr[5][5] = { 0 };
		char checkMove[10] = { '0' };
		
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				checkArr[j][k] = caseArr[i][j][k];
			}
		}
		for (int j = 0; j < 10; j++) {
			checkMove[j] = caseMove[i][j];
		}
		if (solution(checkArr, checkMove) == answer[i]) {
			printf("\n테스트 케이스 %d 통과 !\n\n", i+1);
		}
		else {
			printf("\n테스트 케이스 %d 실패 !\n\n", i+1);
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					printf("%d ", caseArr[i][j][k]);
				}
				printf("\n");
			}
			printf("\n{ ");
			for (int k = 0; k < 10; k++) {
				printf("%c, ", caseMove[i][k]);
			}
			printf("}");
			return 0;
		}
		Sleep(500);
	}
	system("cls");
	printAlgoComplete();
	return 0;
}
void copy2dArr(int base2dArr[5][5],int copyed2dArr[5][5]) {
	for (int j = 0; j < 5; j++) {
		for (int k = 0; k < 5; k++) {
			copyed2dArr[j][k] = copyed2dArr[j][k];
		}
	}
}
void printAlgoComplete() {
	printf("  ##     ##        #####    ####    #####    ######   ######   ##  ##   ##   ##\n"); printf(" ####    ##       ##       ##  ##   ##  ##     ##       ##     ##  ##   ### ###\n");
	printf("##  ##   ##       ##       ##  ##   ##  ##     ##       ##     ######   #######\n"); printf("##  ##   ##       ## ###   ##  ##   #####      ##       ##     ##  ##   ## # ##\n");
	printf("######   ##       ##  ##   ##  ##   ## ##      ##       ##     ##  ##   ##   ##\n"); printf("##  ##   ######    #####    ####    ##  ##   ######     ##     ##  ##   ##   ##\n\n");
	printf(" ####     ####    ##   ##  #####    ##       ######   ######   ######      #\n"); printf("##  ##   ##  ##   ### ###  ##  ##   ##       ##         ##     ##          #\n");
	printf("##       ##  ##   #######  ##  ##   ##       #####      ##     #####       #\n"); printf("##       ##  ##   ## # ##  #####    ##       ##         ##     ##          #\n");
	printf("##  ##   ##  ##   ##   ##  ##       ##       ##         ##     ##           \n"); printf(" ####     ####    ##   ##  ##       ######   ######     ##     ######      #\n");
}
