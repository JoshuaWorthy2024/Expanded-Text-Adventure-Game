#pragma once
#include <string>
#include <array>

class Tutorial
{
public:
	Tutorial();
	~Tutorial();

	static const std::string NARRATOR_TAG;
	static const std::string SYSTEM_TAG;

	static const int TUTORIAL_PROGRESS_WELCOME_MESSAGE = 0;
	static const int TUTORIAL_PROGRESS_MENU = 1;
	static const int TUTORIAL_PROGRESS_COMBAT = 2;
	static const int TUTORIAL_PROGRESS_EXPLORATION = 3;
	static const int TUTORIAL_PROGRESS_SKILLS = 4;
	static const int TUTORIAL_PROGRESS_COMPLETE = 5;


	static const int WELCOME_MESSAGE_LENGTH = 6;
	const std::array<std::string, WELCOME_MESSAGE_LENGTH> WELCOME_MESSAGE = {
		"Welcome, fearless adventurer! A world of magic, danger, and unimaginable power awaits you.",
		"In this tutorial, you'll learn the essential skills to navigate through the unknown and survive the challenges ahead.",
		"Master the art of stealth, unlock your magical abilities, and harness your assassin instincts.",
		"Every corner of this world hides secrets, powerful allies, and deadly enemies.",
		"Pay close attention to each lesson, for the choices you make will shape your destiny.",
		"Prepare yourself for a journey like no other. A journey that will test your courage, wit, and will to survive."
	};

	static const int IN_GAME_MENU_LENGTH = 8;
	const std::array<std::string, IN_GAME_MENU_LENGTH> IN_GAME_MENU = {
		"1. View Quest Log - Check your current quests and objectives.",
		"2. Open Inventory - Examine the items, weapons, and potions in your possession.",
		"3. View Weapons - Review your equipped and unequipped weapons, their stats, and abilities.",
		"4. View Skills - Explore your character's learned abilities, upgrades, and potential new skills.",
		"5. View Character - See your stats, skills, and available magical abilities.",
		"6. Explore the Map - Get an overview of your current location and nearby areas.",
		"7. Save Game - Save your current progress so you can resume later.",
		"8. Exit Game - Quit the game and return to the main menu or desktop."
	};

	static const int COMBAT_MENU_LENGTH = 7;
	const std::array<std::string, COMBAT_MENU_LENGTH> COMBAT_MENU = {
		"1. Attack - Choose your attack type to deal damage to your opponent.",
		"2. View Participant Details - Check stats, health, and abilities for both you and your opponent(s).",
		"3. Open Inventory - Use healing items, potions, or change weapons during combat.",
		"4. Defend - Reduce incoming damage from enemy attacks.",
		"5. Use Magic - Cast spells or use special abilities to influence the battle.",
		"6. Flee - Attempt to escape from combat (may be risky or fail depending on conditions).",
		"7. Pass Turn - Skip your turn if you want to wait for a better opportunity."
	};

	static const int EXPLORATION_MENU_LENGTH = 7;
	const std::array<std::string, EXPLORATION_MENU_LENGTH> EXPLORATION_MENU = {
		"1. Move - Choose a direction to explore (e.g., North, South, East, West).",
		"2. Search Area - Look around for hidden items, enemies, or points of interest.",
		"3. View Map - Check the current layout of the area you're in or the overall map.",
		"4. Interact - Use this option to talk to NPCs, inspect objects, or engage with the environment.",
		"5. Check Quest Log - Review active quests, objectives, and any hints for your journey.",
		"6. Use Item - Access your inventory and use items that might help during exploration.",
		"7. Rest - Take a break to recover health, mana, or energy if necessary."
	};

	static const int SKILLS_TUTORIAL_LENGTH = 4;
	const std::array<std::string, SKILLS_TUTORIAL_LENGTH> SKILLS_TUTORIAL = {
		"Welcome to the **Skills** section! As you progress through your adventure, you'll have the chance to gain new skills. These can be unlocked as you level up or by completing specific tasks and quests.",

		"1. **Skill Growth**: The skills you gain will depend on your actions and the challenges you face. Some skills may be powerful, while others may be weaker, but all are useful in their own way.",

		"2. **Infinite Growth**: Your character can continue to grow and evolve as you progress. New abilities will open up to match your journey, allowing you to shape your playstyle.",

		"3. **Experiment & Adapt**: Try out different skills and combinations to find what works best for you. Your potential is endless—there’s always something new to learn and master!"
	};


	static const int COMPLETE_TUTORIAL_LENGTH = 4;
	const std::array<std::string, COMPLETE_TUTORIAL_LENGTH> COMPLETE_TUTORIAL = {
		"Congratulations, adventurer! You've completed the tutorial and are now ready to embark on your journey!",

		"Remember, this world is vast and full of opportunities. Continue to grow, explore, and uncover the secrets that lie ahead!",

		"Special thanks to **JoshuaWorthy2024** for developing this adventure and **ChatGPT** for helping create the storyline!",

		"You can explore more of the project on GitHub: https://github.com/JoshuaWorthy2024"
	};

	static const std::string SAVE_FILE;

	bool PlayingTutorial = false;
	int TutorialProgress = -1;

	void PlayTutorial(std::string GameTitle, std::string PlayerName);
	void SaveTutorialFile();
	bool ReadTutorialFile();
	bool GetHasCompletedTutorial();
	void IncrementTutorialProgress();
	void PressEnterToContinue(bool SendMessage);
};

