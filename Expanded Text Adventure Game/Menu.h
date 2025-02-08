#pragma once
#include <string>
#include <vector>
class Menu
{
public:
	Menu();
	~Menu();

	void AddMenuOption(const std::string& Option);
	void PrintMenuOptions();
	void SetMenuName(std::string Name);
	virtual void HandleMenuAction();

	std::vector<std::string> GetMenuOptions();

	int GetPlayerEnteredChoice();

	std::string GetMenuName();

	static const int LOWEST_MENU_NUMBER = 1;


protected:
	std::vector<std::string> MenuOptions;
	std::string MenuName;

	virtual void SetupMenu();
};

