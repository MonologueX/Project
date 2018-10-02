#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void InitBoard(char arr[ROW][COL], size_t row, size_t col);
void DisplayBoad(char arr[ROW][COL], size_t row, size_t col);
void PlayMove(char arr[ROW][COL], size_t row, size_t col);
void ComputerMove(char arr[ROW][COL], size_t row, size_t col);
size_t IsWine(char arr[ROW][COL], size_t row, size_t col);

void InitBoard(char arr[ROW][COL], size_t row, size_t col)//初始化
{
	size_t i = 0;
	for (i = 0; i < row; i++)
	{
		size_t j = 0;
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void DisplayBoard(char arr[ROW][COL], size_t row, size_t col)//打印
{
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (i < row - 1)
					printf("---");
				if (j < col - 1)

					printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(char arr[ROW][COL], size_t row, size_t col)//玩家玩
{
	size_t x = 0;
	size_t y = 0;
	while (1)
	{
		printf("请输入坐标：>");
		scanf("%d %d", &x, &y);
		if (((x > 0) && (x <= row)) && ((y > 0) && (y <= col)))// 判断坐标是否合理
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = 'x';
				break;
			}
			else
			{
				printf("坐标已被占用");

			}
		}
		else
			printf("输入坐标不合理\n");
	}
}

void ComputerMove(char arr[ROW][COL], size_t row, size_t col)
{
	size_t x = 0;
	size_t y = 0;
	size_t i = 0;
	int count = 0;

	for (i = 0; i < row; i++)
	{
		count = 0;
		if ((arr[i][0] == arr[i][1]) && arr[i][1] != ' ')
		{
			if (arr[i][2] == ' ')
			{
				arr[i][2] = '0';
				count++;
				break;
			}	
		}
		else if ((arr[i][0] == arr[i][2]) && arr[i][0] != ' ')
		{
			if (arr[i][1] == ' ')
			{
				arr[i][1] = '0';
				count++;
				break;
			}
		}
		else if ((arr[i][1] == arr[i][2] && arr[i][1] != ' '))
		{
			if (arr[i][0] == ' ')
			{
				arr[i][0] = '0';
				count++;
				break;
			}
		}

		else if ((arr[0][i] == arr[1][i]) && arr[0][i] != ' ')
		{
			if (arr[2][i] == ' ')
			{
				arr[2][i] = '0';
				count++;
				break;
			}
		}
		else if ((arr[0][i] == arr[2][i]) && arr[0][i] != ' ')
		{
			if (arr[1][i] == ' ')
			{
				arr[1][i] = '0';
				count++;
				break;
			}
		}
		else if ((arr[2][i] == arr[1][i]) && arr[2][i] != ' ')
		{
			if (arr[0][i] == ' ')
			{
				arr[0][i] = '0';
				count++;
				break;
			}
		}

		else if ((arr[0][0] == arr[1][1]) && arr[0][0] != ' ')
		{
			if (arr[2][2] == ' ')
			{
				arr[2][2] = '0';
				count++;
				break;
			}
		}
		else if ((arr[0][0] == arr[2][2]) && arr[0][0] != ' ')
		{
			if (arr[1][1] == ' ')
			{
				arr[1][1] = '0';
				count++;
				break;
			}
		}
		else if ((arr[2][2] == arr[1][1]) && arr[2][2] != ' ')
		{
			if (arr[0][0] == ' ')
			{
				arr[0][0] = '0';
				count++;
				break;
			}
		}

		else if ((arr[0][2] == arr[1][1]) && arr[1][1] != ' ')
		{
			if (arr[2][0] == ' ')
			{
				arr[2][0] = '0';
				count++;
				break;
			}
		}
		else if ((arr[0][2] == arr[2][0]) && arr[0][2] != ' ')
		{
			if (arr[1][1] == ' ')
			{
				arr[1][1] = '0';
				count++;
				break;
			}
		}
		else if ((arr[2][0] == arr[1][1]) && arr[2][0] != ' ')
		{
			if (arr[0][2] == ' ')
			{
				arr[0][2] = '0';
				count++;
				break;
			}
		}
	}

	if (0 == count)
	{
		while (1)
		{
			x = rand() % row;
			y = rand() % col;
			if (arr[x][y] == ' ')
			{
				arr[x][y] = '0';
				break;
			}
		}	
	}

}

size_t Isfull(char arr[ROW][COL], size_t row, size_t col)
{
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

size_t IsWine(char arr[ROW][COL], size_t row, size_t col)
{
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < row; i++)
	{
		if ((arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2]) && (arr[i][1] != ' '))
		{
			return 1;
		}
	}
	for (j = 0; i < col; j++)
	{
		if ((arr[0][j] == arr[1][j]) && (arr[1][j] == arr[2][j]) && (arr[1][j] != ' '))
		{
			return 1;
		}
	}
	if ((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]) && (arr[1][1] != ' '))
	{
		return 1;
	}
	if ((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0]) && (arr[1][1] != ' '))
	{
		return 1;
	}
	if (Isfull(arr, row, col))
	{
		return 0;
	}
	return -1;
}

void menu()
{
	printf("*************************\n");
	printf("*********1.game**********\n");
	printf("*********0.exit**********\n");
	printf("*************************\n");

}

void game()
{
	size_t ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		IsWine(board, ROW, COL);
		ret = IsWine(board, ROW, COL);
		if (ret == 0)
		{
			printf("平局！\n");
			break;
		}
		else if (ret == 1)
		{
			printf("玩家赢！\n");
			break;
		}

		else
		{
			printf("轮到电脑下棋\n");
			ComputerMove(board, ROW, COL);
			DisplayBoard(board, ROW, COL);
			ret = IsWine(board, ROW, COL);
			if (ret == 0)
			{
				printf("平局！\n");
				break;
			}
			else if (ret == 1)
			{
				printf("很遗憾，您输了！！！\n");
				break;
			}
		}
	}
}
void test()
{
	size_t input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1: game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			break;
		}
	} while (input);

}
int main()
{
	test();
	system("pause");
	return 0;
}