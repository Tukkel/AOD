#include <iostream>

#define ROWS 10
#define COLS 5

bool dfs(char maze[ROWS][COLS], int row, int col);
bool cell_safe(char maze[ROWS][COLS], int row, int col) {
	if (maze[row][col] != 'X' && maze[row][col] != 'M' && row >= 0 && row < ROWS && col >= 0 && col < COLS)
		return true;
	else
		return false;
}

int main()
{
	char maze[ROWS][COLS] = {
		{'X', 'X', 'X', 'X', 'X',},
		{'X', ' ', 'X', ' ', ' ',},
		{'X', ' ', ' ', ' ', 'X',},
		{'X', 'X', 'X', ' ', 'X',},
		{'X', ' ', 'X', ' ', ' ',},
		{'X', ' ', 'X', 'X', ' ',},
		{' ', ' ', ' ', ' ', ' ',},
		{'X', ' ', 'X', 'X', 'X',},
		{' ', ' ', ' ', ' ', 'E',},
		{'X', ' ', 'X', 'X', 'X',}
	};

	bool path_found = dfs(maze, 1, 1);

	if (path_found)
		std::cout << "Path has been found!" << std::endl;
	else
		std::cout << "Path has NOT been found!" << std::endl;
}

bool dfs(char maze[ROWS][COLS], int row, int col)
{
	if (maze[row][col] == 'E') {
		std::cout << "Exit found!" << std::endl;
		return true;
	}

	maze[row][col] = 'M';

	int directions_y[4] = { 1, -1, 0, 0 };
	int directions_x[4] = { 0, 0, 1, -1 };

	for (int i = 0; i < 4; i++) {
		int new_row = row + directions_y[i];
		int new_col = col + directions_x[i];

		if (cell_safe(maze, new_row, new_col)) {
			if (dfs(maze, new_row, new_col)) {
				return true;
			}
		}

	}

	return false;
}
