#include <iostream>

#define ROWS 5
#define COLS 5

using namespace std;

bool recursive(char maze[ROWS][COLS], size_t yPosition = 1, size_t xPosition = 1)
{
	/* For testing
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLS; j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl; */

	if (maze[yPosition][xPosition] == 'E')
	{
		return true;
	}
	else if (maze[yPosition][xPosition] == 'X')
	{
		return false;
	}
	else
	{
		maze[yPosition][xPosition] = 'X';
		return recursive(maze, yPosition + 1, xPosition) || recursive(maze, yPosition, xPosition + 1) || recursive(maze, yPosition - 1, xPosition) || recursive(maze, yPosition, xPosition - 1);
	}
}

int main(void)
{
	
	char maze[ROWS][COLS] = {
		{'X','X','X','X','X'},
		{'X',' ',' ',' ','X'},
		{'X',' ','X',' ','X'},
		{'X',' ','X',' ','E'},
		{'X','X','X','X','X'}
	};

	cout << recursive(maze) << endl;

	return 0;
}