#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <windows.h>                  //header files
using namespace std;
int gameid;
bool checkValue(int arr[][5], int n)
//index 1 is declared after 2nd with comma
{
	bool found = false;
	for (int i = 0; i < 5; i++)          //generating tables
	{									//randomly generating numbers into their positions
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j] == n)
			{
				found = true;						//breaking the loop because of same numbers in the table
				break;
			}
		}
	}
	return found;						//returning value to the main function
}
int filehandling(int num) {
	ofstream fout;
	fout.open("Game History.txt", ios::app);
	cout << gameid;
	fout.close();
	return 1;
}
bool IsWin(int player, int arr[][5])
{
	gameid = rand() % 1000;
	int complete = 0, count1 = 0, count2 = 0;
	for (int i = 0; i < 5; i++)
	{
		count1 = 0, count2 = 0;				//count1 for rows and count2 for columns
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j] == 0)				   //for all columns in rows
			{
				count1++;
			}
			if (arr[j][i] == 0)				  //for all rows in columns
			{
				count2++;
			}
		}
		if (count1 == 5)
			complete++;
		if (count2 == 5)				//complete getting increment for for being all elements in rows and columns each zero
			complete++;
	}
	count1 = 0;
	for (int i = 0; i < 5; i++)
	{
		if (arr[i][i] == 0)
		{
			count1++;
		}
	}
	if (count1 == 5) {
		complete++;
		ofstream fout;
		fout.open("Game History.txt", ios::app);
		cout << gameid << endl;
		fout << "Player" << player << "Wins" << endl;
		cout << "---------------------------------" << endl;
		fout.close();
	}
	count1 = 0;
	for (int i = 1; i < 5; i++)
	{
		if (arr[i][4 - i] == 0)						//for diagonal conditions
		{
			count1++;
		}
	}
	if (count1 == 5) {
		complete++;
		ofstream fout;
		cout << gameid;
		fout.open("Game History.txt", ios::app);
		cout << gameid << endl;
		fout << "Player" << player << "Wins" << endl;
		cout << "---------------------------------" << endl;
		fout.close();
	}
	if (complete >= 5)
		return true;
	else
		return false;
}
void output(int arr[][5])                     //printing tables
{
	for (int i = 0; i < 5; i++)
	{
		cout << setw(15) << "|";
		for (int j = 0; j < 5; j++)
		{
			cout << setw(3) << arr[i][j] << "|";
		}
		cout << endl;
	}
}
int exit() {
	cout << "Thank you for playing. Good bye :)" << endl;
	for (int i = 0; i < 6; i--) {
		cout << "";
	}
	return 0;
	system("Pause");
}
int main()
{                             //generating random game id
	(srand(time(0)));
	gameid = ((rand() % 999) + 1000);
	system("color 4");
	cout << "00000000000    00    00000         00     0000000000000    000000000" << endl;
	cout << "00       00          00  00        00     0000000000000    000000000" << endl;
	cout << "00       00    00    00   00       00     00               00     00" << endl;
	cout << "00       00    00    00    00      00     00               00     00" << endl;
	cout << "00       00    00    00     00     00     00               00     00" << endl;
	cout << "00000000000    00    00      00    00     00               00     00" << endl;
	cout << "00000000000    00    00       00   00     00   00000000    00     00" << endl;
	cout << "00       00    00    00        00  00     00         00    00     00" << endl;
	cout << "00       00    00    00         00 00     00         00    00     00" << endl;
	cout << "00       00    00    00          0000     00         00    00     00" << endl;
	cout << "00       00    00    00           000     0000000000000    000000000" << endl;
	cout << "00000000000    00    00            00     0000000000000    000000000" << endl;
	Sleep(1500);
	system("cls");
	cout << "(a) Play the game.\n" << endl;
	cout << "(b) How to play?\n" << endl;
	cout << "(c) Game history.\n" << endl;
	cout << "(d) Exit.\n" << endl;
	char a;
	cin >> a;
	system("cls");
	switch (a) {
	case 'a': case 'A':
		cout << "\t\t\t" << "Game ID: " << gameid;
		break;
	case 'b': case'B':
		cout << "Welcome to the game.\n\n" << endl;
		cout << "This is a multiplayer game.\n\n" << endl;
		cout << "This game will have two tables.\n\n" << endl;
		cout << "Player 1 will be going first.\n\n" << endl;
		cout << "Both players will select numbers from the given table.\n\n" << endl;
		cout << "The entered number will become zero.\n\n" << endl;
		cout << "The first player who will complete their table will win.\n\n" << endl;
		system("pause");
		break;
	case 'c': case'C':
		cout << "Game Id: " << gameid;
		filehandling(gameid);
		break;
	case 'd': case'D':
		exit();
	default:
		cout << "INVALID INPUT....";
		system("pause");
		break;

	}
	system("color 2");
	srand(time(0));
	int player = 1, chose, num;
	bool is_win;
	int arr[5][5] = { {0},{0},{0},{0},{0} }, arr1[5][5] = { {0},{0},{0},{0},{0} };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			do
			{
				num = rand() % 25 + 1;				//for randomly generating numbers
				if (!checkValue(arr, num)) //arr is array here
				//num  is ACTUALLY N here
				{
					arr[i][j] = num;
					break;
				}
			} while (checkValue(arr, num));
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			do
			{
				num = rand() % 25 + 1;
				if (!checkValue(arr1, num))
				{
					arr1[i][j] = num;
					break;
				}
			} while (checkValue(arr1, num));
		}
	}
	do
	{
		cout << "\n\nPlayer 1:\n\n";
		output(arr);
		cout << "\n\nPlayer 2:\n\n";
		output(arr1);
		cout << "\n\nSelect any number for player " << player << ": ";
		cin >> chose;
		if (player == 1)
		{
			if (checkValue(arr, chose) == true)		//chcecking for inputted value by the user from the randomly generating numbers
			{
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						if (arr[i][j] == chose)
						{
							arr[i][j] = 0;					//for player1
						}
					}
				}
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						if (arr1[i][j] == chose)
						{
							arr1[i][j] = 0;			//for player 2
						}
					}
				}
				is_win = IsWin(player, arr);
			}
			else
			{
				cout << "Enter: ";
			}
		}
		else
		{
			if (checkValue(arr1, chose) == true)
			{
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						if (arr[i][j] == chose)
						{
							arr[i][j] = 0;
						}
					}
				}
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						if (arr1[i][j] == chose)
						{
							arr1[i][j] = 0;
						}
					}
				}
				is_win = IsWin(player, arr1);
			}
		}
		if (is_win)
			cout << "player " << player << "has won the game.\n\n\n";
		if (player == 1)
			player = 2;
		else
			player = 1;
	} while (is_win == false);
	system("pause");
	return 0;
}