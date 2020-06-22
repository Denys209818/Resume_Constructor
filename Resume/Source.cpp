#include "libs.h"
#include "Classes.h"

int Block::id = 0;
void main()
{
	setlocale(LC_CTYPE, "ukr");
	DelCursor();
	int size = 2;

	Block** a = new Block * [size];

	for (int i = 0; i < 2; i++)
	{
		a[i] = new Block();
	}
	int size_ = Block::id;
	int first = 0;


	AddBlok(first, size_, a);
	first = 2;
	int c = 1;
	while (true)
	{
		DelCursor();
		c = _getch();
		switch (c)
		{
		case 43:
		{
			size_++;
			for (int i = first; i < size_; i++)
			{
				while (size_ >= size)
				{
					Block** temp = new Block * [size * 2];
					for (int i = 0; i < size; i++)
					{
						temp[i] = a[i];
					}
					a = temp;
					size *= 2;
				}
				DelCursor();
				a[i] = new Block();
				int cha = 1;
				do
				{
					
					DelCursor();
					for (int i = 0; i < first; i++)
					{
						a[i]->Show();
						a[i]->ShowText();
					}

					a[i]->Show();
					cha = _getch();
					ClearBlock(a[i]);
					SetPos(0, a[i]->y + a[i]->heigth);
					switch (cha)
					{
					case 224:
					{
						switch (_getch())
						{
						case 72:
						{
							a[i]->y -= 5;
							break;
						}
						case 80:
						{
							a[i]->y += 5;
							break;
						}
						case 75:
						{
							a[i]->x -= 5;
							break;
						}//left
						case 77:
						{
							a[i]->x += 5;
							break;
						}//right
						} break;
					}
					case (int)'w': { a[i]->heigth += 3; break; }
					case (int)'s': { a[i]->heigth -= 3; break; }
					case (int)'a': { a[i]->width -= 3; break; }
					case (int)'d': { a[i]->width += 3; break; }
					case (int)'t': { a[i]->ChangeZnak(); break; }
					case (int)'c': { a[i]->ChangeCol(); break; }


					}


				} while (cha != 13);
				while (a[i]->t.Empty()) 
				{
				a[i]->t.CinText();
				}
				system("cls");
				for (int i = 0; i < first; i++)
				{
					a[i]->Show();
					a[i]->ShowText();
				}
				a[i]->Show();
				a[i]->ShowText();
			}
			first++;
			break;
		}
		case 45:
		{
			int d;
			char n;
			SetPos(0,0);
			cout << "Видалити блок? y/n";
			cin >> n;
			if (n != 'n') 
			{
				for (int i = 0; i < size_; i++)
				{
					a[i]->Show();
					a[i]->ShowId();
				}
				SetPos(0, 0);
				cout << "Введiть номер блоку - ";
				cin >> d;
				system("cls");
				Block** temp = new Block * [size_ - 1];
				for (int i = 0; i < d; i++)
				{
					temp[i] = a[i];
				}

				for (int i = d + 1; i < size_; i++)
				{
					temp[i - 1] = a[i];
					temp[i - 1]->id_--;
				}
				size_--;
				first--;
				Block::id--;
				delete a[d];
				a = temp;
			}
			else 
			{
				system("cls");
				cout << "Видалення вiдмiнено!" << endl;
				_getch();
				system("cls");
			}
			for (int i = 0; i < size_; i++)
				{
					a[i]->Show();
					a[i]->ShowText();
				}
			break;
		}
		case 32: 
		{
			for (int i = 0; i < size_; i++)
			{
				a[i]->Show();
				a[i]->ShowText();
			}
		}
		case 'r': 
		{
			int d;
			system("cls");
			for (int i = 0; i < size_; i++) 
			{
				a[i]->Show();
				a[i]->ShowId();
			}
			SetPos(0,0);
			cout << "Введiть номер блока - ";
			cin >> d;
			int cha = 1;
			do
			{

				DelCursor();
				for (int i = 0; i < first; i++)
				{
					a[i]->Show();
					a[i]->ShowText();
				}

				a[d]->Show();
				cha = _getch();
				ClearBlock(a[d]);
				SetPos(0, a[d]->y + a[d]->heigth);
				switch (cha)
				{
				case 224:
				{
					switch (_getch())
					{
					case 72:
					{
						a[d]->y -= 5;
						break;
					}
					case 80:
					{
						a[d]->y += 5;
						break;
					}
					case 75:
					{
						a[d]->x -= 5;
						break;
					}//left
					case 77:
					{
						a[d]->x += 5;
						break;
					}//right
					} break;
				}
				case (int)'a': { a[d]->width -= 3; break; }
				case (int)'d': { a[d]->width += 3; break; }
				case (int)'t': { a[d]->ChangeZnak(); break; }
				case (int)'c': { a[d]->ChangeCol(); break; }
				case (int)'w': { a[d]->heigth += 3; break; }
				case (int)'s': { a[d]->heigth -= 3; break; }


				}


			} while (cha != 13);
			for (int i = 0; i < 100; i++) 
			{
				SetPos(i,0);
				cout << " ";
			}
			for (int i = 0; i < size_; i++) 
			{
				a[i]->Show();
				a[i]->ShowText();
			}

			break;
		}
		}



	}

}