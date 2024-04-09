#include "solution.h"
/*
< 문제 설명 >
주어진 map에서 자신의 위치(2)를 기준으로 주어진 move대로 이동했을때 만나는 사람의 수를 return하는 함수 solution()을 완성하시오.
solution 함수는 매개변수로 다음과 같은 5*5 행렬 map[5][5]과 10개의 원소로 이뤄진 배열 move[10]을 받는다.

예시)
map = {
	{0,0,0,0,1},
	{0,1,0,0,0},
	{0,0,0,2,0},
	{0,1,0,0,1},
	{0,0,0,0,0}
}

move = { 'w','a','a','s','s','d','d','d','w','w'}

2차원 행렬 map에서 2는 자신의 위치 1은 다른 사람의 위치 이며 0은 빈 공간이다.
1차원 행렬 move 'w','a','s','d'는 상하좌우로 이동하는 것을 의미한다.

*주어진 map에서 2의 개수는 1개 1의 개수는 랜덤 위치 또한 랜덤이다.
*2의 위치는 벽을 뚫을 수 없으며, 벽을 뚫어야 하는 움직임은 무효 처리된다.
*만났던 1을 다시만나는 경우 만남횟수는 카운트되지 않는다.

*/
int solution(int map[5][5], char move[10]) {

	int myY = 0;
	int myX = 0;
	int matchCounter = 0;
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			//printf("%d ", map[y][x]);
			if (map[y][x] == 2) {
				//printf("y,x = %d,%d", y, x);
				myY = y;
				myX = x;
			}
		}
		//printf("\n");
	}
	//printf("init myY,myX = %d,%d", myY, myX);
	//printf("\n");
	for (int i = 0; i < 10; i++) {
		//printf("%c ", move[i]);
		switch (move[i]) {
		case 'w':
			if (myY != 0) myY--;
			break;
		case 'a':
			if (myX != 0) myX--;
			break;
		case 's':
			if (myY < 4) myY++;
			break;
		case 'd':
			if (myX < 4)
				myX++;
			break;
		}
		if (map[myY][myX] == 1) {
			//printf("\nmyY,myX = %d,%d\n", myY, myX);
			matchCounter++;
			map[myY][myX] = 0;
			//printf("matchCounter = %d\n", matchCounter);
		}
	}
	//printf("\n");
	//printf("LAST myY,myX = %d,%d\n", myY, myX);
	int result = matchCounter;
	//printf("return : %d\n", result);


	return result;
}

//https://www.notion.so/siklab/5dbd834b8c73489e8cb2e48f4c1f7d8f?pvs=4#08b0d3110c8e4fd58ba9bdf997027c2c
		//1. 문제이해
		// // 2는 맵에 1개 뿐이다. 1의 개수,위치는 랜덤, 맵크기 고정, 움직임 횟수 고정
		//2. 알고리즘 구상
		// 2-1. 나의 위치 찾기
		// 2-2. move[i]대로 이동 후 해당 좌표의 사람유무 확인
		// 2-3. 카운팅
		// 2-4 예외처리 / 벽,회귀
		//3. 코딩

		// 난이도 조절
		// 1. 맵 사이즈 변화/고정 5*5 / 6*6 / 8*8
		// 2. 움직임 횟수 변화/고정 10 , 20 , 30
		// 3. 벽 마주 시 그 위치 그대로
		// 4. 돌아서 다시 만났을 때 카운트 x
		// 5. 가만히 있는 옵션 x 추가 w a d s x?

		// 링크로 구글드라이브의 파일과 발표자료를 나눠준다.
		// 시작 카운트
		// 10분 마다 힌트 투척

		//잘하기 위해서 
		// ppt이해도 
		// 정답 애니매이션
		// 코딩실력 뽐내기 / 문제는 쉬우면서 어떻게 코딩실력을 보여줄까
