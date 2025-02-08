#include "Menu.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

std::vector<std::string> Menu::GetMenuOptions()
{
	return MenuOptions;
}

Menu::Menu()
{
	SetupMenu();
}

Menu::~Menu()
{
}

void Menu::AddMenuOption(const std::string& Option)
{
	MenuOptions.push_back(Option);
}

int Menu::GetPlayerEnteredChoice()
{
	int EnteredChoice = -1;
	do
	{
		cout << endl << "Enter a choice (" << LOWEST_MENU_NUMBER << "-" << MenuOptions.size() << ") : ";
		cin >> EnteredChoice;

		if (EnteredChoice < LOWEST_MENU_NUMBER || EnteredChoice > MenuOptions.size())
		{
			EnteredChoice = -1;
		}
	} while (EnteredChoice == -1);

	return EnteredChoice;
}

std::string Menu::GetMenuName()
{
	return MenuName;
}

void Menu::SetupMenu()
{
}


void Menu::PrintMenuOptions()
{
	cout << endl << endl << "---" << MenuName << "---" << endl;
	int counter = 1;
	for (std::string Option : MenuOptions)
	{
		cout << counter << ") " << Option << endl;
		counter++;
	}
	cout << "---";
	for (char c : MenuName)
	{
		cout << "-";
	}
	cout << "---" << endl << endl;
}

void Menu::SetMenuName(std::string Name)
{
	MenuName = Name;
}

void Menu::HandleMenuAction()
{
	cout << "No action found..." << endl;
}
