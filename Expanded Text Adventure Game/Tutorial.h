#pragma once
#include <string>
#include <array>

class Tutorial
{
public:
	Tutorial();
	~Tutorial();

	static const int TUTORIAL_PROGRESS_WELCOME_MESSAGE = 0;
	static const int TUTORIAL_PROGRESS_MENU = 1;
	static const int TUTORIAL_PROGRESS_COMBAT = 2;
	static const int TUTORIAL_PROGRESS_EXPLORATION = 3;
	static const int TUTORIAL_PROGRESS_NPCS = 4;
	static const int TUTORIAL_PROGRESS_COMPLETE = 5;


	static const int WELCOME_MESSAGE_LENGTH = 3;
	const std::array<std::string, WELCOME_MESSAGE_LENGTH> WELCOME_MESSAGE = { "Greeting, adventurer! We're excited to guide you...", "In this tutorial, you'll learn how to navigate the game...",
		"Follow the instructions carefully to make sure you're fully prepared for your adventure!"
	};

	static const std::string SAVE_FILE;

	bool PlayingTutorial = false;
	int TutorialProgress = -1;

	void PlayTutorial(std::string PlayerName);
	void SaveTutorialFile();
	bool ReadTutorialFile();
	bool GetHasCompletedTutorial();
	void IncrementTutorialProgress();
	void PressEnterToContinue();
};

