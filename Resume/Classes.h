#pragma once
#include "libs.h"
class Block;
class Text;

void SetCol(int a);

void DelCursor();

void SetPos(int x, int y);

class Text
{
private:
	char text[1000];
public:
	void CinText();
	void ShowText();

	char* GetT();

	int Size();

	bool Empty() 
	{
		return strlen(this->text) <= 2;
	}
};

class Block
{
private:
	char znak;
	enum { X = 1, Y, SOB, DOR };
	int counter;
	int col;
public:
	int id_;
	int static id;
	Text t;
	int x;
	int y;
	int width;
	int heigth;

	void ShowText();

	void ShowId();

	Block();

	void Show();

	void ChangeZnak();

	void ChangeCol();


};


void AddBlok(int first, int size_, Block** a);

void ClearBlock(Block* a);
