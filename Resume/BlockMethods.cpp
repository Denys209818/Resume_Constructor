#include "libs.h"
#include "Classes.h"

void Block::ShowText()
{
	int k = 0;
	int s = 1;
	SetPos(this->x + 1, this->y + s);
	for (int i = 0; i < this->t.Size() + 1; i++)
	{

		if (k < this->width - 1)
		{
			cout << this->t.GetT()[i];
			k++;
		}
		else
		{
			s++;
			cout << endl;
			SetPos(this->x + 1, this->y + s);
			i--;
			k = 0;
		}
	}
	SetCol(7);
}

void Block::ShowId()
{
	int k = 0;
	int s = 1;
	SetPos(this->x + 1, this->y + s);
	cout << this->id_;
	SetCol(7);
}

Block::Block()
{
	char * e = t.GetT();
	strcpy_s(e, strlen(" ") + 1, " ");
	this->id_ = Block::id;
	Block::id++;
	this->x = 1;
	this->y = 1;
	this->width = 7;
	this->heigth = 10;
	this->znak = 'x';
	this->counter = 1;
	this->col = 7;
}

void Block::Show()
{
	SetCol(this->col);
	for (int i = 0; i < this->heigth; i++)
	{
		SetPos(this->x, this->y + i);
		if (i == 0 || i == this->heigth - 1)
		{
			for (int j = 0; j < this->width + 1; j++)
			{
				cout << this->znak;
			}
			cout << endl;
		}
		else
		{
			cout << this->znak;
			for (int j = 0; j < this->width - 1; j++)
			{
				cout << " ";
			}
			cout << this->znak << endl;
		}
	}
	SetCol(7);
}

void Block::ChangeZnak()
{
	this->counter < 4 ? this->counter++ : this->counter = 1;
	switch (this->counter)
	{
	case X: {this->znak = 'x'; break; }
	case Y: {this->znak = 'y'; break; }
	case SOB: {this->znak = '@'; break; }
	case DOR: {this->znak = '='; break; }
	}
}

void Block::ChangeCol()
{
	this->col < 12 ? this->col++ : this->col = 1;
}
