#include "TestMenu.h"


TestMenu::TestMenu()
{
	SetupMenu();
}

void TestMenu::SetupMenu()
{
	SetMenuName("Test Menu");
	AddMenuOption(OPTION_ONE_TEST);
	AddMenuOption(OPTION_TWO_TEST);
	AddMenuOption(OPTION_THREE_TEST);
	AddMenuOption(OPTION_FOUR_TEST);
	AddMenuOption(OPTION_FIVE_TEST);
}
