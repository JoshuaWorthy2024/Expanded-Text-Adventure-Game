#include <iostream>
#include <fstream>
#include <string>
#include "Tutorial.h"
#include "TestMenu.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


// Forward Declarations

const string PLAYER_SAVE_PATH = "PlayerSave.txt";
const string GAME_TITLE = "Requiem of the Reborn Assassin";

void SavePlayerData();
bool ReadPlayerData();
void PrintPlayerData();
bool HasInvalidSpaces(std::string EnteredString);

bool IsRunning = true;

// Player Stats
std::string gPlayerName = "";
int gPlayerHealth = 100;
int gPlayerMana = 100;
int gPlayerGold = 0;
int gPlayerLevel = 1;
int gPlayerExperience = 0;
int gPlayerAttackPower = 10;
int gPlayerDefencePower = 10;
bool gCompletedTutorial = false;

int gEnteredPlayerChoice = -1;

// key terms
const int SAVE_NAME_KEY = 0;
const int SAVE_HEALTH_KEY = 1;
const int SAVE_MANA_KEY = 2;
const int SAVE_GOLD_KEY = 3;
const int SAVE_LEVEL_KEY = 4;
const int SAVE_EXPERIENCE_KEY = 5;
const int SAVE_ATTACK_POWER_KEY = 6;
const int SAVE_DEFENCE_POWER_KEY = 7;
const int SAVE_TUTORIAL_PROGRESS_KEY = 8;

int main() 
{
	system("mode con: cols=240 lines=60");
	if (!ReadPlayerData())
	{
		bool EnteredValidName = false;
		//cout << "Please press enter to continue." << endl;
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flush buffer
		while (!EnteredValidName)
		{
			cout << "Enter your character's name: ";
			std::getline(cin, gPlayerName);
			if (gPlayerName.size() > 12)
			{
				cout << "You cannot enter a name that exceeds 12 characters.";
			}
			else
			{
				if (!HasInvalidSpaces(gPlayerName))
				{
					EnteredValidName = true;
				}
			}
			cout << endl << endl;
		}

		SavePlayerData();
	}
	
	// Tutorial Section
	Tutorial TutorialClass;
	gCompletedTutorial = TutorialClass.GetHasCompletedTutorial();

	SavePlayerData();

	if (!gCompletedTutorial)
	{
		TutorialClass.PlayTutorial(GAME_TITLE, gPlayerName);
		gCompletedTutorial = TutorialClass.GetHasCompletedTutorial();
	}

	if (gCompletedTutorial)
	{
		// check first quest distribution
		cout << "Tutorial completed...";
	}

	TestMenu TestMenuClass;
	TestMenuClass.PrintMenuOptions();
	gEnteredPlayerChoice = TestMenuClass.GetPlayerEnteredChoice();

	cout << "Player selected: " << gEnteredPlayerChoice; 
	while (IsRunning) 
	{

	}

	return 0;
}

void SavePlayerData() 
{
	std::ofstream SaveFile(PLAYER_SAVE_PATH);

	if (SaveFile.is_open()) 
	{
		SaveFile << SAVE_NAME_KEY << ": " << gPlayerName << endl;
		SaveFile << SAVE_HEALTH_KEY << ": " << gPlayerHealth << endl;
		SaveFile << SAVE_MANA_KEY << ": " << gPlayerMana << endl;
		SaveFile << SAVE_GOLD_KEY << ": " << gPlayerGold << endl;
		SaveFile << SAVE_LEVEL_KEY << ": " << gPlayerLevel << endl;
		SaveFile << SAVE_EXPERIENCE_KEY << ": " << gPlayerExperience << endl;
		SaveFile << SAVE_ATTACK_POWER_KEY << ": " << gPlayerAttackPower << endl;
		SaveFile << SAVE_DEFENCE_POWER_KEY << ": " << gPlayerDefencePower << endl;
		SaveFile << SAVE_TUTORIAL_PROGRESS_KEY << ": " << gCompletedTutorial << endl;
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
	std::ifstream SaveFile(PLAYER_SAVE_PATH);

	if (!SaveFile.is_open()) 
	{
		SaveFile.close();
		return false;
	}

	cout << "Reading player data..." << endl << endl;
	std::string line = "";
	std::string key = "";
	std::string value = "";

	while (SaveFile)
	{
			std::getline(SaveFile, line);

			if (!line.empty()) {
				int position = (int) line.find(':');
				key = line.substr(0, position);
				value = line.substr(position + 2);

				switch (std::stoi(key))
				{
				case SAVE_NAME_KEY:
				{
					gPlayerName = value;
					break;
				}
				case SAVE_HEALTH_KEY:
				{
					gPlayerHealth = std::stoi(value);
					break;
				}
				case SAVE_MANA_KEY:
				{
					gPlayerMana = std::stoi(value);
					break;
				}
				case SAVE_GOLD_KEY:
				{
					gPlayerGold = std::stoi(value);
					break;
				}
				case SAVE_LEVEL_KEY:
				{
					gPlayerLevel = std::stoi(value);
					break;
				}
				case SAVE_EXPERIENCE_KEY:
				{
					gPlayerExperience = std::stoi(value);
					break;
				}
				case SAVE_ATTACK_POWER_KEY:
				{
					gPlayerAttackPower = std::stoi(value);
					break;
				}
				case SAVE_DEFENCE_POWER_KEY:
				{
					gPlayerDefencePower = std::stoi(value);
					break;
				}
				case SAVE_TUTORIAL_PROGRESS_KEY:
				{
					gCompletedTutorial = std::stoi(value);
					break;
				}
				default:
				{
					cout << "-Unknown key placed: " << key << endl;
					break;
				}
				}
			}
	}
	PrintPlayerData();
	// load data etc
	return true;
}

void PrintPlayerData() 
{
	cout << "Name: " << gPlayerName << endl;
	cout << "Health: " << gPlayerHealth << endl;
	cout << "Mana: " << gPlayerMana << endl;
	cout << "Gold: " << gPlayerGold << endl;
	cout << "Level: " << gPlayerLevel << endl;
	cout << "Experience: " << gPlayerExperience << endl;
	cout << "Attack: " << gPlayerAttackPower << endl;
	cout << "Defense: " << gPlayerDefencePower << endl;
	cout << "Completed Tutorial: " << gCompletedTutorial << endl << endl;
}

bool HasInvalidSpaces(std::string EnteredString)
{
	if (EnteredString.find('\n') == 0 || EnteredString.find(' ') == 0)
	{
		cout << "You cannot start a name with a space." << endl << endl;
		return true;
	}
	for (char Letter : EnteredString)
	{
		if (Letter == '\n' || Letter == ' ' || Letter == '\\' || Letter == '/')
		{
			cout << "You cannot enter more than one space or invalid characters such as \\ or /." << endl << endl;
			return true;
		}
	}

	return false;
}