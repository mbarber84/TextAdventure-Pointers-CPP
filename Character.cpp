#include "Character.h"

Character::Character()
{
	name = " ";
	race = " ";
	gender = " ";

	playerRace = {"elf", "human", "dwarf", "darkelf", "wizard"};

	level = 0, health = 0, totalHealth = 0, maxHealth = 0, heal = 0;

    level = 1, current_xp = 0, base_xp = 76, xp_to_level = base_xp, minLevel = 1, maxLevel = 60;

}


//character creation
void Character::characterCreation() {

    int counter = 0;

    std::cout << "Enter Your Characters Name: ";
    std::cin >> name;


    std::cout << "Enter Your Characters Race\n";
    std::cout << "Elf\n";
    std::cout << "Human\n";
    std::cout << "Dwarf\n";
    std::cout << "DarkElf\n";
    std::cout << "Wizard\n";
    std::cout << "Type your chosen race below: \n\n";
    std::cin >> race;


    std::for_each(race.begin(), race.end(), [](char& c) {
        c = ::tolower(c);
        });

    for (int i = 0; i < sizeof(playerRace); i++) {
        if (race == "elf") {
            health = 80;
            break;
        }
        if (race == "human") {
            health = 85;
            break;
        }
        if (race == "dwarf") {
            health = 110;
            break;
        }
        if (race == "darkelf") {
            health = 75;
            break;
        }
        if (race == "wizard") {
            health = 100;
            break;
        }
        else {
            health = 100;
            break;
        }
    }

    std::cout << "\n";
    std::cout << "Enter Your Characters Gender: ";
    std::cin >> gender;
    system("cls");


    //Character loading screen
    for (int i = 0; i <= counter; i++) {
        if (i == 0)
            std::cout << "Creating Character.\n";
        if (i == 1)
            std::cout << "Creating Character..\n";
        if (i == 2) {
            std::cout << "Creating Character...\n";
            break;
        }
           

        Sleep(800);
        system("cls");
        counter++;
    }

    //Changing the first letter to uppercase no matter user input case
    name[0] = toupper(name[0]);
    race[0] = toupper(race[0]);
    gender[0] = toupper(gender[0]);

    totalHealth = health;
    maxHealth = totalHealth;

    Sleep(4000);
}


