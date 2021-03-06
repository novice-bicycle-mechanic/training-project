// bypassHorse.cpp
// ������� �� ����� warpcore_1586201037.txt

#include <iostream>
#include <clocale>
#include <iomanip>
#include <conio.h>

#define N "\n"

using namespace std;


//------------------------------------------------------------------------


const int offset[9][2] =		// �������� ��������� ����� ������������ �������� ����
								// [9]-����� ���� � 1 �� 8, 0 - �� ������������
								// [2]-�������� �� ��������� (0) � ����������� (1)
{
	{0,0},				// ������ ��������, ����� ���� ������

	{+2,-1},{+2,+1},	// ���� � ������/�������

	{+1,+2},{-1,+2},	// ������ � ����/�����

	{-2,+1},{-2,-1},	// ����� � �������/������

	{-1,-2},{+1,-2}		// ����� � �����/����
};


//------------------------------------------------------------------------


int choosingMove		// ������� ������ ����
(
	int moveNum,			// ����� ������������ ����

	int path[][2],			// ���� ���� �� ��������� �����

	int chessboard[][8],	// ��������� �����

	bool defect[]				// ������ ������������� ����� �� ��������
)
{
	int rating[9]{};		// ������ ��������� �����: 0-������������, 1-8-���-�� �����, 9-������, 10-�����, 11-��� ������ �����

	int min = 99;			// ����������� ������ ����

	int numMin = 0;			// ����� ���� � ����������� �������

	int row1 = 0;			// ����� ������ ����� �������� �� ���������� ���� ������������ �������� ����

	int col1 = 0;			// ����� ������� ����� �������� �� ���������� ���� ������������ �������� ����

	int row2 = 0;			// ����� ������ ����� �������� �� ���������� ���� ������������ �������� ����

	int col2 = 0;			// ����� ������� ����� �������� �� ���������� ���� ������������ �������� ����

	for (size_t i = 1; i < 9; i++)	// ������ ��������� �����
	{
		row1 = path[moveNum][0] + offset[i][0];

		col1 = path[moveNum][1] + offset[i][1];

		// ��������, ��� ������� ���� � �������� ��������� �����

		if (((-1 < row1) && (row1 < 8)) && ((-1 < col1) && (col1 < 8)))
		{
			// ��������, ��� �� �������� ���� �� ����� ����

			if (chessboard[row1][col1] == 0)
			{
				// ������� ����������� ��������� ����� ������������ �������� ����

				for (size_t j = 0; j < 8; j++)
				{
					row2 = row1 + offset[j][0];

					col2 = col1 + offset[j][1];

					if (((-1 < row2) && (row2 < 8))

						&& ((-1 < col2) && (col2 < 8))

						&& (chessboard[row2][col2] == 0))
					{
						rating[i]++;	// ������� ��������� �����
					}
				}
			}
			else
			{
				rating[i] = 9;		// ������� ���� ������ - �� ���� ����� ����
			}
		}
		else
		{
			rating[i] = 11;		// ������� ���� ��� ������ ��������� �����
		}
	}

	for (size_t i = 1; i < 9; i++)
	{
		if (defect[i])
		{
			rating[i] = 10;		// ��� ���������� ���� ����� � �����
		}
	}

	for (size_t i = 1; i < 9; i++)	// ���������� ����������� ������ ��������� �����
	{
		if (min > rating[i])
		{
			min = rating[i];

			numMin = i;
		}
	}

	// ������� ������ ����

	if (min < 9)
	{
		return numMin;
	}
	else
	{
		return 0;
	}
}


//------------------------------------------------------------------------


bool nextMove		// ������� ���������� ���������� ����
(
	int moveNumber,			// ����� ������������ ����

	int path[][2],			// ���� ���� �� ��������� �����

	int chessboard[][8]		// ��������� �����	
)
{
	bool defect[9]{};			// ������ ������������� ����� �� �������� (true - )

	int numMove = 0;		// ����� ���������� ����

	do
	{
		numMove = choosingMove(moveNumber, path, chessboard, defect);	// ����� ���������� ���� 

		if (numMove)								// ���� ����� ���������� ���� �� ����� 0
		{
			if (moveNumber < 64)					// ���� ����� ���� ������ ����������� (� ������ +1 �����)
			{
				int row = path[moveNumber][0];		// ����� ������ ���� ������������ ����

				int col = path[moveNumber][1];		// ����� ������� ���� ������������ ����

				moveNumber++;						// ����� ���������� ����

				path[moveNumber][0] = row + offset[numMove][0];		// ����� ���� ���������� ����

				path[moveNumber][1] = col + offset[numMove][1];		// ����� ������� ���������� ����

				chessboard[path[moveNumber][0]][path[moveNumber][1]] = moveNumber;

				if (nextMove(moveNumber, path, chessboard)) // ���� ��������� ������ ������� true
				{
					return true;		// - ����� ��� �������� - ����� �� ���� �������
				}
				else										// �����, ���� ��������� ������ ������� false
				{
					defect[numMove] = true;		// ������� ������� ���

//					chessboard[path[moveNumber][0]][path[moveNumber][1]] = 0;

					continue;					// � �������� ��������� �� ���������� ���
				}
			}
			else	// �����, ���� ����� ���� ����� ��� ������ ����������� - ����� ��� ��������
			{
				return true;	// ������� �� ������� � ���� ����� ���������� �������
			}
		}
		else	// �����, ���� ����� ���������� ���� ����� 0 - �����
		{
			return false;		// ������� �� ������� �� ���������� �������
		}

	} while (true);
}


//------------------------------------------------------------------------


int main()
{
	setlocale(LC_ALL, "ru");

	//------------------------

	//                     warpcore_1586201037.txt

	// ����: �������

	//                            ������� 1

	//     ������� ������ "����� ����� ��������� �����". ������� �����

	// ���������� �������� ��� ���������� �� ����������.


	int path[65][2]{};				// ���� ���� �� ��������� �����

	int chessboard[8][8]{};			// ��������� �����

	int byte1char = 0;				// ������ ���� ���� ������� ������� �������

	enum key { ESC = 27 };			// ���� ������� ������

	bool symbolNumber = 1;			// ����� ������� � ����������� ������ ��������� �����


	cout
		<< "                     warpcore_1586201037.txt"

		N N" ����: �������. ��������."

		N N"                            ������� 1"

		N N"     ������� ������ \"����� ����� ��������� �����\". ������� �����"

		N N" ���������� �������� ��� ���������� �� ����������."

		<< N << endl;

	cout
		<< "     ��� ������ ����� ��������� ����� ��������� �������� \"�������"

		N N" ����������\": \"��� ������ ����� ���� ������� �� �� ����, � ��������"

		N N" ����� ����� �� ����������� ����� ��� �� ���������� �����. ����"

		N N" ����� ����� ���������, �� ����� ����� �� ����� �� ���\"."

		N N"     ���������, ��� ���� ���� �� �������."

		<< N << endl;

	cout
		<< " ������� ����, � �������� �������� ����� ����� ��������� �����"

		N N" (����� (a,b,c,d,e,f,g,h) � ����� (1-8)) > ";

	// ���� ����������� ����

	do
	{
		byte1char = _getch();

		if (_kbhit()) { (void)_getch(); }

		if (symbolNumber)
		{
			if (((int)('a') <= byte1char) && (byte1char <= (int)('h')))
			{
				path[1][1] = byte1char - (int)('a');

				cout << (char)byte1char;

				symbolNumber = !symbolNumber;

				byte1char = 0;
			}
		}
		else
		{
			if (((int)('1') <= byte1char) && (byte1char <= (int)('8')))
			{
				path[1][0] = 8 - (byte1char - (int)('0'));

				cout << (char)byte1char;

				symbolNumber = !symbolNumber;

				byte1char = 0;

				break;
			}
		}

	} while (true);

	chessboard[path[1][0]][path[1][1]] = 1;		// ������ � ��������� ���� ����� ����

	// ����� ��������� �����

	(void)nextMove(1, path, chessboard);		// ������� ���������� �����

	// ����� ��������� ����� �� �����

	cout << N N << endl;

	for (size_t i = 0; i < 8; i++)
	{
		cout << setw(15) << (char)(8 - i + (int)('0')) << setw(3) << "|";

		for (size_t j = 0; j < 8; j++)
		{
			cout << setw(4) << chessboard[i][j];
		}

		cout << endl;

		if (i < 7) { cout << setw(18) << "|" << endl; }
	}

	cout << setw(13) << "" << setw(1) << "----+---------------------------------" << endl;

	cout << setw(18) << "|";

	for (size_t i = 0; i < 8; i++)
	{
		cout << setw(4) << (char)(i + (int)('a'));
	}

	cout << N << endl;

	//------------------------

	return 0;
}