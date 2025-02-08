#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const string SavePath = "PlayerSave.txt";

void SavePlayerData();
bool ReadPlayerData();
void PrintPlayerData();

bool IsRunning = true;

// Player Stats
int gPlayerHealth = 100;
int gPlayerMana = 100;
int gPlayerGold = 0;
int gPlayerLevel = 1;
int gPlayerExperience = 0;
int gAttackPower = 10;
int gDefensePower = 10;

int main() 
{
	if (!ReadPlayerData()) 
	{
		SavePlayerData();
	}
	
	while (IsRunning) 
	{

	}

	return 0;
}

void SavePlayerData() 
{
	std::ofstream SaveFile(SavePath);

	if (SaveFile.is_open()) 
	{
		SaveFile << gPlayerHealth << endl;
		SaveFile << gPlayerMana << endl;
		SaveFile << gPlayerGold << endl;
		SaveFile << gPlayerLevel << endl;
		SaveFile << gPlayerExperience << endl;
		SaveFile << gAttackPower << endl;
		SaveFile << gDefensePower << endl;
		SaveFile.close();
		PrintPlayerData();
	}
	else
	{
		cout << "Could not save file. Closing..";
		IsRunning = false;
	}
}

bool ReadPlayerData() 
{
	std::ifstream SaveFile(SavePath);

	if (!SaveFile.is_open()) 
	{
		SaveFile.close();
		return false;
	}

	cout << "Reading player data...";
	// load data etc
	return true;
}

void PrintPlayerData() 
{
	cout << "Health: " << gPlayerHealth << endl;
	cout << "Mana: " << gPlayerMana << endl;
	cout << "Gold: " << gPlayerGold << endl;
	cout << "Level: " << gPlayerLevel << endl;
	cout << "Experience: " << gPlayerExperience << endl;
	cout << "Attack: " << gAttackPower << endl;
	cout << "Defense: " << gDefensePower << endl << endl;
}