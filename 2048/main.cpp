#include <iostream>  
#include <windows.h>  
#include <ctime>  
using namespace std;

int const ROW = 4;
int const COL = 4;
int board[ROW][COL] = { 0 };

//give directions indices  
int const UP = 1;
int const DOWN = 2;
int const LEFT = 3;
int const RIGHT = 4;

//give states indices
int const GAME_OVER = 1;
int const GAME_WIN = 2;
int const GAME_CONTINUE = 3;

int Input() {
	int up_key = 0;
	int down_key = 0;
	int left_key = 0;
	int right_key = 0;
	int direction = 0;

	while (1) {
		up_key = GetAsyncKeyState(VK_UP);
		down_key = GetAsyncKeyState(VK_DOWN);
		left_key = GetAsyncKeyState(VK_LEFT);
		right_key = GetAsyncKeyState(VK_RIGHT);
		if (up_key) {
			direction = UP;
			break;
		}
		else if (down_key)
		{
			direction = DOWN;
			break;
		}
		else if (left_key)
		{
			direction = LEFT;
			break;
		}
		else if (right_key)
		{
			direction = RIGHT;
			break;
		}
		Sleep(100);
	}
	return direction;
}

int Judge() {
	int game_state = GAME_OVER;
	for (int i = 0; i != ROW; i++) {
		for (int j = 0; j != COL; j++) {
			if (board[i][j] == 2048)
				game_state = GAME_WIN;
			if (board[i][j] == 0)
				game_state = GAME_CONTINUE;
			if (i > 0) {
				if (board[i][j] == board[i - 1][j]) {
					game_state = GAME_CONTINUE;
				}
			}
			if (j > 0) {
				if (board[i][j] == board[i][j - 1]) {
					game_state = GAME_CONTINUE;
				}
			}
		}
	}
	
	return game_state;
}

void Print()
{
	system("cls");
	cout << endl;
	for (int i = 0; i < ROW; ++i)
	{
		cout << "---------------------------------" << endl;
		for (int j = 0; j < COL; ++j)
		{
			if (board[i][j] == 0)
			{
				cout << "|   \t";
			}
			else
			{
				cout << "|   " << board[i][j] << "\t";
			}
		}
		cout << "|" << endl;
	}
	cout << "---------------------------------" << endl;
}

void Num_generator() {
	int i = 0;
	int j = 0;
	do {
		i = rand() % ROW;
		j = rand() % COL;
	} while (board[i][j] != 0);
	int num_base = 1 + rand() % 2;// rand 1~2
	board[i][j] = 2 * num_base;
}

void Process(int direction) {
	switch (direction)
	{
	case UP:
		for (int i = ROW-1; i != 0; i--) {
			for (int j = 0; j != COL; j++) {
				if (board[i - 1][j] == 0)
				{
					board[i - 1][j] = board[i][j];
					board[i][j] = 0;
				}
				else
				{

					if (board[i - 1][j] == board[i][j])
					{
						board[i - 1][j] *= 2;
						board[i][j] = 0;
					}
				}
			}
		}
		break;
	case DOWN:
		for (int i = 0; i != ROW - 1; i++) {
			for (int j = 0; j != COL; j++) {
				if (board[i + 1][j] == 0)
				{
					board[i + 1][j] = board[i][j];
					board[i][j] = 0;
				}
				else
				{

					if (board[i + 1][j] == board[i][j])
					{
						board[i + 1][j] *= 2;
						board[i][j] = 0;
					}
				}
			}
		}
		break;
	case LEFT:
		for (int i = ROW-1; i != 0; i--) {
			for (int j = 0; j != COL; j++) {
				if (board[j][i - 1] == 0)
				{
					board[j][i - 1] = board[j][i];
					board[j][i] = 0;
				}
				else
				{

					if (board[j][i - 1] == board[j][i])
					{
						board[j][i - 1] *= 2;
						board[j][i] = 0;
					}
				}
			}
		}
		break;
	case RIGHT:
		for (int i = 0; i != ROW-1; i++) {
			for (int j = 0; j != COL; j++) {
				if (board[j][i + 1] == 0)
				{
					board[j][i + 1] = board[j][i];
					board[j][i] = 0;
				}
				else
				{

					if (board[j][i + 1] == board[j][i])
					{
						board[j][i + 1] *= 2;
						board[j][i] = 0;
					}
				}
			}
		}
		break;
	}
}

int main()
{
	//rand 
	srand((unsigned int)time(0));
	Num_generator();
	Num_generator();
	Print();
	int direction = 0;
	int gameState = 0;
	while (1)
	{
		direction = Input();
		gameState = Judge();
		cout << gameState << endl;
		cout << gameState << endl;
		if (direction && gameState == GAME_CONTINUE)
		{
			Process(direction);
			Num_generator();
			Print();
			Sleep(100);
		}
		else if (gameState == GAME_WIN)
		{
			Print();
			cout << "Win" << endl;
			break;
			
		}
		else if (gameState == GAME_OVER)
		{
			Print();
			cout << "lose" << endl;
			break;
			
		}
	}
	return gameState;
	
}