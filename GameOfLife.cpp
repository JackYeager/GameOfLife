//Includes libraries that will be in use throughout the program as well as a const declaration
#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <thread>
#include <chrono>
#include <windows.h>
#define scl 25


//This function counts the neighbours of a given index (that is alive) in the grid and counts the neighbours and inserts the index 
//into a vector if it fails to meet a condition
void neighbourTerminal(int grid[scl][scl], int i, int j, std::vector < std::pair<int, int> > &terminal) {
	//liveCount will be declared to be 0 at the beggining of each call so it maintains consistency across different cases
	int liveCount = 0;

	//General Case where the index is between the range of 0 and scl
	if ((i > 0 && i < scl) && (j > 0 && j < scl)) {
		//Loops through neighbours and counts all alive cells (1's)
		for (int k = -1; k <= 1; k++) {
			for (int l = -1; l <= 1; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount < 2 | liveCount > 3) {
			terminal.push_back(std::make_pair(i, j));
		}
	}

	//Case where the first index is at the beggining and the second index is general
	else if (i == 0 && (j > 0 && j < scl)) {
		for (int k = 0; k <= 1; k++) {
			for (int l = -1; l <= 1; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount < 2 | liveCount > 3) {
			terminal.push_back(std::make_pair(i, j));
		}
	}

	//Case where the first index is at the end and the second index is general
	else if (i == scl && (j > 0 && j < scl)) {
		for (int k = -1; k <= 0; k++) {
			for (int l = -1; l <= 1; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount < 2 | liveCount > 3) {
			terminal.push_back(std::make_pair(i, j));
		}
	}

	//Case where the first index is general and the second index is at the beggining
	else if ((i > 0 && i < scl) && j == 0) {
		for (int k = -1; k <= 1; k++) {
			for (int l = 0; l <= 1; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount < 2 | liveCount > 3) {
			terminal.push_back(std::make_pair(i, j));
		}
	}

	//Case where the first index is general and the second index is at the end
	else if ((i > 0 && i < scl) && j == scl) {
		for (int k = -1; k <= 1; k++) {
			for (int l = -1; l <= 0; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount < 2 | liveCount > 3) {
			terminal.push_back(std::make_pair(i, j));
		}
	}

	//Case where both indices are at the beggining
	else if (i == 0 && j == 0) {
		for (int k = 0; k <= 1; k++) {
			for (int l = 0; l <= 1; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount < 2 | liveCount > 3) {
			terminal.push_back(std::make_pair(i, j));
		}
	}

	//Case where first index is at the end and the second index is at the beggining
	else if (i == scl && j == 0) {
		for (int k = -1; k <= 0; k++) {
			for (int l = 0; l <= 1; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount < 2 | liveCount > 3) {
			terminal.push_back(std::make_pair(i, j));
		}
	}

	//Case where first index is at the beggining and the second index is at the end
	else if (i == 0 && j == scl) {
		for (int k = 0; k <= 1; k++) {
			for (int l = -1; l <= 0; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount < 2 | liveCount > 3) {
			terminal.push_back(std::make_pair(i, j));
		}
	}

	//Case where first index and second index is at the end
	else if (i == scl && j == scl) {
		for (int k = -1; k <= 0; k++) {
			for (int l = -1; l <= 0; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount < 2 | liveCount > 3) {
			terminal.push_back(std::make_pair(i, j));
		}
	}
}


//This function counts the neighbours of a given index(that is dead) in the grid and counts the neighbours and inserts the index
//into a vector if it meets a condition
void neighbourExpectant(int grid[scl][scl], int i, int j, std::vector < std::pair<int, int> > &expectant) {
	//liveCount will be declared to be 0 at the beggining of each call so it maintains consistency across different cases
	int liveCount = 0;
	//General Case where the index is between the range of 0 and scl
	if ((i > 0 && i < scl) && (j > 0 && j < scl)) {
		//Loops through and counts all 0's and spawns an alive cell if the number is exactly 3
		for (int k = -1; k <= 1; k++) {
			for (int l = -1; l <= 1; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount == 3) {
			expectant.push_back(std::make_pair(i, j));
		}
	}

	//Case where first index is at the bggining and the second index is general
	else if (i == 0 && (j > 0 && j < scl)) {
		for (int k = 0; k <= 1; k++) {
			for (int l = -1; l <= 1; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount == 3) {
			expectant.push_back(std::make_pair(i, j));
		}
	}

	//Case where first index is at the end and the second index is general
	else if (i == scl && (j > 0 && j < scl)) {
		for (int k = -1; k <= 0; k++) {
			for (int l = -1; l <= 1; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount == 3) {
			expectant.push_back(std::make_pair(i, j));
		}
	}

	//Case where first index is general and the second index is at the beggining
	else if ((i > 0 && i < scl) && j == 0) {
		for (int k = -1; k <= 1; k++) {
			for (int l = 0; l <= 1; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount == 3) {
			expectant.push_back(std::make_pair(i, j));
		}
	}

	//Case where first index is general and the second index is at the end
	else if ((i > 0 && i < scl) && j == scl) {
		for (int k = -1; k <= 1; k++) {
			for (int l = -1; l <= 0; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount == 3) {
			expectant.push_back(std::make_pair(i, j));
		}
	}

	//Case where both indices are at the beggining
	else if (i == 0 && j == 0) {
		for (int k = 0; k <= 1; k++) {
			for (int l = 0; l <= 1; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount == 3) {
			expectant.push_back(std::make_pair(i, j));
		}
	}

	//Case where the first index is at the end and the second index is at the beggining
	else if (i == scl && j == 0) {
		for (int k = -1; k <= 0; k++) {
			for (int l = 0; l <= 1; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount == 3) {
			expectant.push_back(std::make_pair(i, j));
		}
	}

	//Case where the first index is at the beggining and the second index is at the end
	else if (i == 0 && j == scl) {
		for (int k = 0; k <= 1; k++) {
			for (int l = -1; l <= 0; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount == 3) {
			expectant.push_back(std::make_pair(i, j));
		}
	}

	//Case where both indices are at the end
	else if (i == scl && j == scl) {
		for (int k = -1; k <= 0; k++) {
			for (int l = -1; l <= 0; l++) {
				if (k == 0 && l == 0) {}
				else {
					if (grid[i + k][j + l] == 1) {
						liveCount += 1;
					}
				}
			}
		}

		if (liveCount == 3) {
			expectant.push_back(std::make_pair(i, j));
		}
	}
}

//nextGen is the function that updates the grid one iteration at a time
int nextGen(int grid[scl][scl]) {
	//Vectors that will hold all terminal cells (1's that are to be turned into 0's) 
	//and expectant cells (0's that are to be turned into 1's)
	std::vector < std::pair<int, int> > terminal;
	std::vector < std::pair<int, int> > expectant;

	for (int i = 0; i < scl; i++) {
		for (int j = 0; j < scl; j++) {
			//Terminal checking is only done on alive cells (1's)
			if (grid[i][j] == 1) {
				neighbourTerminal(grid, i, j, terminal);
			}
			//Expectant Checking is only done on dead cells (0's)
			else if (grid[i][j] == 0) {
				neighbourExpectant(grid, i, j, expectant);
			}
		}
	}

	//Loops through terminal vector and turns every element on Grid found in the vector into dead cells
	for (int i = 0; i < terminal.size(); i++) {
		grid[terminal[i].first][terminal[i].second] = 0;
	}

	//Loops through expectant vector and turns every element on Grid found in the vector into alive cells
	for (int i = 0; i < expectant.size(); i++) {
		grid[expectant[i].first][expectant[i].second] = 1;
	}

	return grid[scl][scl];
}

int main(){
	srand(time(NULL));
	int init = 0;
	int count;
	int grid[scl][scl] = {};
	HANDLE con;

	//Generate the board with every cell having a 1/3 chance of being an alive cell
	for (int i = 0; i < scl; i++) {
		for (int j = 0; j < scl; j++) {
			if (rand() % 3 == 1) {
				grid[i][j] = 1;
			}
		}
	}


	std::cout << "How many iterations do you want to see?" << std::endl;
	std::cin >> count;

	con = GetStdHandle(STD_OUTPUT_HANDLE);

	//Rest of the code is used to output the grid. For display purposes, alive cells (1's) have been outputted
	//as red 0's to contrast agasint the dead cells which are bright white 0's
	for (int i = 0; i < scl; i++) {
		for (int j = 0; j < scl; j++) {
			if (grid[i][j] == 1) {
				SetConsoleTextAttribute(con, 12);
				std::cout << "0" << " ";
			}
			else {
				SetConsoleTextAttribute(con, 15);
				std::cout << grid[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
	
	std::cout << std::endl << std::endl;
	//If a user wants to see a specified amount they will enter the amount otherwise they can enter a negative 
	//number to see the program run indefinitely
	if (count > 0) {
		while (init <= count) {
			std::system("CLS");
			grid[scl][scl] = nextGen(grid);
			for (int i = 0; i < scl; i++) {
				for (int j = 0; j < scl; j++) {
					if (grid[i][j] == 1) {
						SetConsoleTextAttribute(con, 12);
						std::cout << "0" << " ";
					}
					else {
						SetConsoleTextAttribute(con, 15);
						std::cout << grid[i][j] << " ";
					}
				}
				std::cout << std::endl;
			}
			SetConsoleTextAttribute(con, 7);
			std::cout << std::endl << std::endl;
			init += 1;
			std::this_thread::sleep_for(std::chrono::milliseconds(750));
		}
	}
	else {
		while (true) {
			std::system("CLS");
			grid[scl][scl] = nextGen(grid);
			for (int i = 0; i < scl; i++) {
				for (int j = 0; j < scl; j++) {
					if (grid[i][j] == 1) {
						SetConsoleTextAttribute(con, 12);
						std::cout << "0" << " ";
					}
					else {
						SetConsoleTextAttribute(con, 15);
						std::cout << grid[i][j] << " ";
					}
				}
				std::cout << std::endl;
			}
			SetConsoleTextAttribute(con, 7);
			std::cout << std::endl << std::endl;
			init += 1;
			std::this_thread::sleep_for(std::chrono::milliseconds(750));
		}
	}


	return 0;
}
