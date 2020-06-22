#include "libs.h"
#include "Classes.h"

void SetCol(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

void DelCursor()
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);

}

void SetPos(int x, int y)
{
	COORD cPos;
	cPos.X = x;
	cPos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cPos);
}





void AddBlok(int first, int size_, Block** a)
{
	for (int k = first; k < size_; k++)
	{
		int ch = 1;

		while (ch != 13)
		{
			system("cls");
			for (int i = 0; i < k; i++)
			{
				a[i]->Show();
				a[i]->ShowText();
			}
			a[k]->Show();
			ch = _getch();
			switch (ch)
			{
			case 224:
			{
				switch (_getch())
				{
				case 72:
				{
					a[k]->y -= 5;
					break;
				}
				case 80:
				{
					a[k]->y += 5;
					break;
				}
				case 75:
				{
					a[k]->x -= 5;
					break;
				}//left
				case 77:
				{
					a[k]->x += 5;
					break;
				}//right
				} break;
			}
			case (int)'w': { a[k]->heigth += 3; break; }
			case (int)'s': { a[k]->heigth -= 3; break; }
			case (int)'a': { a[k]->width -= 3; break; }
			case (int)'d': { a[k]->width += 3; break; }
			case (int)'t': { a[k]->ChangeZnak(); break; }
			case (int)'c': { a[k]->ChangeCol(); break; }


			}
		}

		SetPos(0, 0);
		a[k]->t.CinText();
		system("cls");
		for (int i = 0; i < k; i++)
		{
			a[i]->Show();
			a[i]->ShowText();
		}

		a[k]->Show();
		a[k]->ShowText();
		//_getch();
	}


	//SetPos(0, 35);
}

void ClearBlock (Block* a)
{
	for (int i = 0; i < a->heigth; i++)
	{
		SetPos(a->x, a->y + i);
		if (i == 0 || i == a->heigth - 1)
		{
			for (int j = 0; j < a->width + 1; j++)
			{
				cout << " ";
			}
			cout << endl;
		}
		else
		{
			cout << " ";
			for (int j = 0; j < a->width - 1; j++)
			{
				cout << " ";
			}
			cout << " " << endl;
		}
	}

}