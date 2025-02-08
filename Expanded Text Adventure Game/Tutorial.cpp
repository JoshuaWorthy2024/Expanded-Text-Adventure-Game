#include "Tutorial.h"
#include <fstream>
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

const std::string Tutorial::SAVE_FILE = "Tutorial.txt";  // Definition of the static member.

const int WELCOME_MESSAGE_LENGTH = 3;
const std::string Tutorial::WELCOME_MESSAGE[] = { "Greetings, adventurer! We're excited to guide you through the basics of your journey.",
"In this tutorial, you'll learn how to navigate the game, engage in combat, explore the world, and meet important characters.", "Follow the instructions carefully to make sure you're fully prepared for your adventure!" };

Tutorial::Tutorial()
{
	TutorialProgress = -1;
	if (!ReadTutorialFile())
	{
		SaveTutorialFile();
	}
}

Tutorial::~Tutorial()
{

}

void Tutorial::PlayTutorial(std::string PlayerName)
{
	if (TutorialProgress == -1)
	{
		cout << endl << "Please ensure you pay very close to the tutorial, " << PlayerName << "!" << endl << endl;
		TutorialProgress = TUTORIAL_PROGRESS_WELCOME_MESSAGE;
	}
	switch (TutorialProgress)
	{
		case TUTORIAL_PROGRESS_WELCOME_MESSAGE:
		{
			for (std::string phrase : WELCOME_MESSAGE)
			{
				cout << phrase << endl;
			}
			cout << endl << "Next, you will learn about the menus!" << endl << endl;
			IncrementTutorialProgress();
			PlayTutorial(PlayerName);
			break;
		}

		case TUTORIAL_PROGRESS_MENU:
		{
			IncrementTutorialProgress();
			PlayTutorial(PlayerName);
			break;
		}

		case TUTORIAL_PROGRESS_COMBAT:
		{
			IncrementTutorialProgress();
			PlayTutorial(PlayerName);
			break;
		}

		case TUTORIAL_PROGRESS_EXPLORATION:
		{
			IncrementTutorialProgress();
			PlayTutorial(PlayerName);
			break;
		}

		case TUTORIAL_PROGRESS_NPCS:
		{
			IncrementTutorialProgress();
			PlayTutorial(PlayerName);
			break;
		}

		case TUTORIAL_PROGRESS_COMPLETE:
		{
			IncrementTutorialProgress();
			break;
		}
	}
}

void Tutorial::SaveTutorialFile()
{
	std::ofstream SaveFile(SAVE_FILE);
	if (SaveFile.is_open())
	{
		SaveFile << TutorialProgress;
		SaveFile.close();
		cout << "Saved Tutorial Progress file." << endl;
	}
}

bool Tutorial::ReadTutorialFile()
{
	std::ifstream SaveFile(SAVE_FILE);
	if (SaveFile.is_open())
	{
		int number = -1;
		while (SaveFile >> number)
		{
			TutorialProgress = number;
		}
		SaveFile.close();
		return true;
	}
	cout << "Save File not found. Creating.." << endl << endl;
	return false;
}

bool Tutorial::GetHasCompletedTutorial()
{
	return TutorialProgress >= TUTORIAL_PROGRESS_COMPLETE;
}

void Tutorial::IncrementTutorialProgress()
{
	TutorialProgress++;
	PressEnterToContinue();
	//SaveTutorialFile();
}

void Tutorial::PressEnterToContinue()
{
	cout << "Press Enter to continue...";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears input buffer
	cin.get(); // Waits for Enter
}
