
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Windows.h"
using namespace std;

enum Race { Human = 0, Elf, Draft, Dark_elf, Nord, Katget };
enum Class { Assasin, Knife, Archer, Visart, Muschect };
enum Gender { Man, Woman };
enum Weapon {};
enum Plate {};
enum Move { Stop = 0, Up, Down, Left, Right };
bool GameOver{ false };
bool mapChange{ true };       
ifstream currentMapName;
string mapName{ "Start-loc.txt" };

struct Character //персонаж
{
	char skin{ '☺' };
	string name{ "Tester" };
	Race chRace{ Human };
	Class chClass{ Assasin };
	Gender chGender{ Man };
	double chHp{ 250.00 };
	double chAttac1{ 350.00 };
	double chAttac2{ 150.00 };
	double chAttac3{ 50.00 };
	double chspeed{ 3 };//скорость хода перса
	double chVinoslivost{ 500.00 };
	Move chMove{ Stop };
	int x{ 5 };
	int y{ 7 };
	
};

Character character;

void Setup();
void Input();
void Logic();
void drawMap(string currentMap);//передае карту
int main()
{
	Setup();//редактор персонажей
	while (GameOver == false)
	{
		Input();
		Logic();
	}
}

vector<string>currentMap;
void Setup()
{
	int temp{0};
	system ("cls");
	cout << "Hello,Its Character Edidior\n";
	cout << "Whats your name?" << "\n";
	getline(cin, character.name);
	cout << "Hello, " << character.name << "!\n";

	cout << "Choose your class?\n" << "0-Assasin\n";
	cout << "1-Knife\n";
	cout << "2-Archer\n";
	cout << "3-Visart\n";
	cout << "4-Muschect\n";
	std::cin >> temp;
	switch (temp)
	{
	case 0: character.chClass = Assasin; break;
	case 1: character.chClass = Knife; break;
	case 2: character.chClass = Archer; break;
	case 3: character.chClass = Visart; break;
	case 4: character.chClass = Muschect; break;

	}

	switch (character.chClass)
	{
	case 0: cout << "you are Assasin\n"; break;
	case 1: cout << "you are Knife\n"; break;
	case 2:cout  << "you are Archer\n"; break;
	case 3: cout << "you are Visart\n"; break;
	case 4: cout << "you are Muschect\n"; break;
	}
	cout << "Choose your race?\n" << "0-Human\n";
	cout << "1-Elf\n";
	cout << "2-Draft\n";
	cout << "3-Dark_elf\n";
	cout << "4-Nord\n";
	cout << "5-Katget\n";
	std::cin >> temp;
	
	switch (temp)
	{
	case 0: character.chRace = Human; break;
	case 1: character.chRace = Elf; break;
	case 2: character.chRace = Draft; break;
	case 3: character.chRace = Dark_elf; break;
	case 4: character.chRace = Nord; break;
	case 5: character.chRace = Katget; break;

	}

	switch (character.chRace)
	{
	case 0: cout << "you are Human\n"; break;
	case 1: cout << "you are Elf\n"; break;
	case 2:cout << "you are Draft\n"; break;
	case 3: cout << "you are Dark_elf\n"; break;
	case 4: cout << "you are Nord\n"; break;
	case 5: cout << "you are Katget\n"; break;
	}
	cout << "Choose your Gender?\n" << "0-Man\n";
	cout << "1-Woman\n";
	std::cin >> temp;

	switch (temp)
	{
	case 0: character.chGender = Man; break;
	case 1: character.chGender = Woman; break;
	}

	switch (character.chGender)
	{
	case 0: cout << "you are Man\n"; break;
	case 1: cout << "you are Woman\n"; break;
	}
	drawMap(mapName);
}

void Input()
{

}
void Logic()
{

}
void drawMap(string mapName)
{
	int maphight;
	int mapwidth;
	system("cls");
	if (mapChange == true)
	{
		string str{ "" };
		currentMapName.open(mapName);
		if (!currentMapName.is_open())
		{
			cout << "Global error";
		}
		while (getline(currentMapName, str))
		{
			currentMap.push_back(str);
		}
		mapChange = false;
		maphight = currentMap.size();
		mapwidth = currentMap.back().size();
	}
	for (int i = 0; i < maphight; ++i)
	{
		for (int j = 0; i < mapwidth; ++i)
		{
			
			if ((i == character.x) && (j == character.y))
			{
				currentMap[i][j] = character.skin;
			}
		}
			cout << currentMap[i] << '\n';
	}
}

