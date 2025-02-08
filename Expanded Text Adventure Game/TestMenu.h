#pragma once
#include "Menu.h"
class TestMenu :
    public Menu
{
public:
    TestMenu();

protected:
    void SetupMenu() override;

    const int OPTION_ONE_INT = 1;
    const std::string OPTION_ONE_TEST = "Testing Option 1";

    const int OPTION_TWO_INT = 2;
    const std::string OPTION_TWO_TEST = "Testing Option 2";

    const int OPTION_THREE_INT = 3;
    const std::string OPTION_THREE_TEST = "Testing Option 3";

    const int OPTION_FOUR_INT = 4;
    const std::string OPTION_FOUR_TEST = "Testing Option 4";

    const int OPTION_FIVE_INT = 5;
    const std::string OPTION_FIVE_TEST = "Testing Option 5";
};

