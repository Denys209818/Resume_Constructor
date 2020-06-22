#include "libs.h"
#include "Classes.h"

void Text::CinText()
{
	char* p = new char[1000];
	system("cls");
	cout << "¬ведить текст блока: ";
	cin.getline(p, 1000);
	strcpy_s(text, strlen(p)+1, p);
	delete p;
}
void Text::ShowText()
{
	SetConsoleOutputCP(1251);
	cout << text;
	SetConsoleOutputCP(866);

}

char* Text::GetT()
{
	return this->text;
}

int Text::Size()
{
	return strlen(this->text);
}