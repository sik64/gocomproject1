#include "solution.h"
/*
< ���� ���� >
�־��� map���� �ڽ��� ��ġ(2)�� �������� �־��� move��� �̵������� ������ ����� ���� return�ϴ� �Լ� solution()�� �ϼ��Ͻÿ�.
solution �Լ��� �Ű������� ������ ���� 5*5 ��� map[5][5]�� 10���� ���ҷ� �̷��� �迭 move[10]�� �޴´�.

����)
map = {
	{0,0,0,0,1},
	{0,1,0,0,0},
	{0,0,0,2,0},
	{0,1,0,0,1},
	{0,0,0,0,0}
}

move = { 'w','a','a','s','s','d','d','d','w','w'}

2���� ��� map���� 2�� �ڽ��� ��ġ 1�� �ٸ� ����� ��ġ �̸� 0�� �� �����̴�.
1���� ��� move 'w','a','s','d'�� �����¿�� �̵��ϴ� ���� �ǹ��Ѵ�.

*�־��� map���� 2�� ������ 1�� 1�� ������ ���� ��ġ ���� �����̴�.
*2�� ��ġ�� ���� ���� �� ������, ���� �վ�� �ϴ� �������� ��ȿ ó���ȴ�.
*������ 1�� �ٽø����� ��� ����Ƚ���� ī��Ʈ���� �ʴ´�.

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
		//1. ��������
		// // 2�� �ʿ� 1�� ���̴�. 1�� ����,��ġ�� ����, ��ũ�� ����, ������ Ƚ�� ����
		//2. �˰��� ����
		// 2-1. ���� ��ġ ã��
		// 2-2. move[i]��� �̵� �� �ش� ��ǥ�� ������� Ȯ��
		// 2-3. ī����
		// 2-4 ����ó�� / ��,ȸ��
		//3. �ڵ�

		// ���̵� ����
		// 1. �� ������ ��ȭ/���� 5*5 / 6*6 / 8*8
		// 2. ������ Ƚ�� ��ȭ/���� 10 , 20 , 30
		// 3. �� ���� �� �� ��ġ �״��
		// 4. ���Ƽ� �ٽ� ������ �� ī��Ʈ x
		// 5. ������ �ִ� �ɼ� x �߰� w a d s x?

		// ��ũ�� ���۵���̺��� ���ϰ� ��ǥ�ڷḦ �����ش�.
		// ���� ī��Ʈ
		// 10�� ���� ��Ʈ ��ô

		//���ϱ� ���ؼ� 
		// ppt���ص� 
		// ���� �ִϸ��̼�
		// �ڵ��Ƿ� �˳��� / ������ ����鼭 ��� �ڵ��Ƿ��� �����ٱ�
