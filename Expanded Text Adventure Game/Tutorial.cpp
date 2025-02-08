#include "Tutorial.h"
#include <fstream>
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

const std::string Tutorial::SAVE_FILE = "Tutorial.txt";  // Definition of the static member.
const std::string Tutorial::NARRATOR_TAG = "Narrator: ";
const std::string Tutorial::SYSTEM_TAG = "System: ";

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

void Tutorial::PlayTutorial(std::string GameTitle, std::string PlayerName)
{
	if (TutorialProgress == -1)
	{
		cout << endl << SYSTEM_TAG << "Please ensure you pay very close to the tutorial, " << PlayerName << "!" << endl << endl;
		TutorialProgress = TUTORIAL_PROGRESS_WELCOME_MESSAGE;
	}
	switch (TutorialProgress)
	{
		case TUTORIAL_PROGRESS_WELCOME_MESSAGE:
		{
			cout << endl << SYSTEM_TAG << "---Welcome, to " << GameTitle << "---" << endl << endl;

			for (std::string phrase : WELCOME_MESSAGE)
			{
				cout << NARRATOR_TAG << phrase << endl;
				PressEnterToContinue(false);
			}
			IncrementTutorialProgress();
			PlayTutorial(GameTitle, PlayerName);
			break;
		}

		case TUTORIAL_PROGRESS_MENU:
		{
			cout << endl << SYSTEM_TAG << "---INGAME MENU INFORMATION---" << endl << endl;

			for (std::string phrase : IN_GAME_MENU)
			{
				cout << NARRATOR_TAG << phrase << endl;
				PressEnterToContinue(false);
			}
			IncrementTutorialProgress();
			PlayTutorial(GameTitle, PlayerName);
			break;
		}

		case TUTORIAL_PROGRESS_COMBAT:
		{
			cout << endl << SYSTEM_TAG << "---COMBAT MENU INFORMATION---" << endl << endl;

			for (std::string phrase : COMBAT_MENU)
			{
				cout << NARRATOR_TAG << phrase << endl;
				PressEnterToContinue(false);
			}
			IncrementTutorialProgress();
			PlayTutorial(GameTitle, PlayerName);
			break;
		}

		case TUTORIAL_PROGRESS_EXPLORATION:
		{
			cout << endl << SYSTEM_TAG << "---EXPLORATION MENU INFORMATION---" << endl << endl;

			for (std::string phrase : EXPLORATION_MENU)
			{
				cout << NARRATOR_TAG << phrase << endl;
				PressEnterToContinue(false);
			}
			IncrementTutorialProgress();
			PlayTutorial(GameTitle, PlayerName);
			break;
		}

		case TUTORIAL_PROGRESS_SKILLS:
		{
			cout << endl << SYSTEM_TAG << "---SKILLS INFORMATION---" << endl << endl;

			for (std::string phrase : SKILLS_TUTORIAL)
			{
				cout << NARRATOR_TAG << phrase << endl;
				PressEnterToContinue(false);
			}
			IncrementTutorialProgress();
			PlayTutorial(GameTitle, PlayerName);
			break;
		}

		case TUTORIAL_PROGRESS_COMPLETE:
		{
			cout << endl << SYSTEM_TAG << "---CLOSING DETAILS---" << endl << endl;

			for (std::string phrase : COMPLETE_TUTORIAL)
			{
				cout << NARRATOR_TAG << phrase << endl;
				PressEnterToContinue(false);
			}
			IncrementTutorialProgress();
			SaveTutorialFile();
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
	PressEnterToContinue(true);
	//SaveTutorialFile();
}

void Tutorial::PressEnterToContinue(bool SendMessage)
{
	if (SendMessage)
	{
		cout << "Press Enter to continue..." << endl << endl;
	}
	cin.get(); // Waits for Enter
}
