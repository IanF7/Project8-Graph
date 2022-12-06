/*
* Ian Fletcher
* CST-201
* 12/1/2022
* This is my own code
*/

#include <iostream>

using namespace std;

//print method that takes in a 2D array of ints (O[n^2])
void print(int edges[15][15])
{
	cout << "     ";
	//uses a printf to make an outline for the table
	for (int i = 0; i < 15; i++)
	{
		printf("%-4d", i);
	}
	cout << endl;
	cout << endl;
	//uses a nested for loop and printf to print out all the weights in a table
	for (int i = 0; i < 15; i++)
	{
		printf("%-5d", i);
		for (int j = 0; j < 15; j++)
		{
			printf("%-4d", edges[i][j]);
		}
		cout << endl;
	}
}

//getNeighbors method that takes in a 2D array of ints, a string array, and an int (O[n])
void getNeighbors(int edges[15][15], string vertices[], int value)
{
	//prints out vertex at index of value
	cout << "The neighbors of " << vertices[value] << " are: ";
	//uses a for loop to print all vertecies that have a weight for the vertex at value
	for (int j = 0; j < 15; j++)
	{
		if (edges[value][j] != 0)
		{
			cout << vertices[j] << ", ";
		}
	}
}

//getDistance function that takes in 2D array of ints, 2 other ints, and returns an int (O[n^2])
int getDistance(int edges[15][15], int start, int end)
{
	//creates int distance to store sum of weights
	int distance = 0;
	//creates ints s and e to help with storing current positions
	int s = start;
	int e = end;
	//checks if the current value is greater than 0 and if so sets distance equal to the
	//value and returns distance
	if (edges[s][e] > 0)
	{
		distance = edges[start][end];
		return distance;
	}
	//runs while the value at s and end equals 0
	while (edges[s][end] == 0)
	{
		//runs while the value at s and e equals 0
		while (edges[s][e] == 0)
		{
			//decrements e
			e--;
			//checks if e is out of bounds and resets it
			if (e <= 0)
			{
				e = 14;
			}
		}
		//updates distance
		distance += edges[s][e];
		//sets s to the new e and resets e to end
		s = e;
		e = end;
		//checks if the value is greater than 0, updates distance, and returns distance
		if (edges[s][e] > 0)
		{
			distance += edges[s][e];
			return distance;
		}
	}
}

//main method
int main()
{
	//creates and populates array of strings called vertices
	string vertices[] = {"Mohave", "Coconico", "Navajo", "Apache", "Greenlee", "Cochise",
	"Santa Cruz", "Pima", "Pinal", "Graham", "Gila", "Yavapai", "La Paz", "Yuma", "Maricopa"};

	//creates and populates a 15 x 15 2D array of ints
	int edges[15][15];
	edges[0][1] = 14;
	edges[0][11] = 14;
	edges[0][12] = 9;

	edges[1][0] = 14;
	edges[1][2] = 9;
	edges[1][10] = 17;
	edges[1][11] = 9;

	edges[2][1] = 9;
	edges[2][3] = 5;
	edges[2][9] = 20;
	edges[2][10] = 13;

	edges[3][2] = 5;
	edges[3][4] = 17;
	edges[3][9] = 19;

	edges[4][3] = 17;
	edges[4][5] = 16;
	edges[4][9] = 4;

	edges[5][4] = 16;
	edges[5][6] = 8;
	edges[5][7] = 9;
	edges[5][9] = 12;

	edges[6][5] = 8;
	edges[6][7] = 6;

	edges[7][5] = 9;
	edges[7][6] = 6;
	edges[7][8] = 7;
	edges[7][9] = 12;
	edges[7][13] = 23;
	edges[7][14] = 10;

	edges[8][7] = 7;
	edges[8][9] = 13;
	edges[8][10] = 5;
	edges[8][14] = 6;

	edges[9][2] = 20;
	edges[9][3] = 19;
	edges[9][4] = 4;
	edges[9][5] = 12;
	edges[9][7] = 12;
	edges[9][8] = 13;
	edges[9][10] = 7;

	edges[10][1] = 17;
	edges[10][2] = 13;
	edges[10][8] = 5;
	edges[10][9] = 7;
	edges[10][11] = 18;
	edges[10][14] = 8;

	edges[11][0] = 14;
	edges[11][1] = 9;
	edges[11][10] = 18;
	edges[11][12] = 15;
	edges[11][14] = 9;

	edges[12][0] = 9;
	edges[12][11] = 15;
	edges[12][13] = 11;
	edges[12][14] = 15;

	edges[13][7] = 23;
	edges[13][12] = 11;
	edges[13][14] = 18;

	edges[14][7] = 10;
	edges[14][8] = 6;
	edges[14][10] = 8;
	edges[14][11] = 9;
	edges[14][12] = 15;
	edges[14][13] = 18;

	//fills in all remaining values with 0
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (edges[i][j] < 0)
			{
				edges[i][j] = 0;
			}
		}
	}

	//runs print given edges
	print(edges);
	cout << endl;
	//creates string input for user input
	string input;
	//creates int inputVal for the index of the input
	int inputVal = -1;
	//runs while input ins't equal to -1
	while (input != "-1")
	{
		//prompts user to enter county or -1
		cout << "Enter a county to search for or -1 to quit: ";
		cin >> input;
		cout << endl;
		//checks if input isn't -1
		if (input != "-1")
		{
			//uses a for loop to set the value of inputVal to the index of input
			for (int i = 0; i < 15; i++)
			{
				if (input == vertices[i])
				{
					inputVal = i;
					break;
				}
			}
			//checks if inputVal is -1 and is so prints out that county wasn't found
			if (inputVal == -1)
			{
				cout << "County not found" << endl;
			}
			//otherwise runs getNeighbors with edges, vertecies, and inputVal
			else
			{
				getNeighbors(edges, vertices, inputVal);
			}
		}
		cout << endl;
	}
	//creates ints start and end for user input
	int start = 0;
	int end = 0;
	//runs while start isn't equal to -1
	while (start != -1)
	{
		//prompts the user to enter a value or -1 to quit
		cout << "Enter a number 0-14 as a start county or -1 to quit: ";
		cin >> start;
		cout << endl;
		//if start isn't -1 and in bounds, runs the rest of the loop
		if (start != -1 && start <=14 && start >= 0)
		{
			//prompts the user to enter another value
			cout << "Enter a number 0-14 as an end county: ";
			cin >> end;
			cout << endl;
			//checks if end is in bounds
			if (end <= 14 && end >= 0)
			{
				//checks if the values are equal and if so prints out that there is a distance of
			//0 between the values
				if (start == end)
				{
					cout << "The distance between " << vertices[start] << " and " <<
						vertices[end] << " is 0" << endl;
				}
				//checks if the values are out of bounds and if so states that it was an invalid 
				//input
				else if (start < 0 || start > 15 || end < 0 || end > 15)
				{
					cout << "Invalid input" << endl;
				}
				//otherwise runs and prints results of getDistance given edges, start, and end
				else
				{
					cout << "The distance between " << vertices[start] << " and " <<
						vertices[end] << " is " << getDistance(edges, start, end) << endl;
				}
			}
		}
	}
}
