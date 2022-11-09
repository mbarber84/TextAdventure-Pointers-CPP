#include "Character.h"

Character::Character() {
  name = " ";
  race = " ";
  gender = " ";

  playerRace = {"elf", "human", "dwarf", "darkelf", "wizard"};

  level = 0, health = 0, totalHealth = 0, maxHealth = 0, heal = 0;

  level = 1, current_xp = 0, base_xp = 76, xp_to_level = base_xp, minLevel = 1,
  maxLevel = 60;
}

// character creation
void Character::characterCreation() {

  int counter = 0;

  std::cout << "Enter Your Characters Name: ";
  std::cin >> name;

  std::string *ptr_a = &name; // pointer

  std::cout << "Enter Your Characters Race\n";
  std::cout << "Elf\n";
  std::cout << "Human\n";
  std::cout << "Dwarf\n";
  std::cout << "DarkElf\n";
  std::cout << "Wizard\n";
  std::cout << "Type your chosen race below: \n\n";
  std::cin >> race;

  std::string *ptr_b = &race; // pointer

  // Changes the entered string to lower case
  std::for_each(race.begin(), race.end(), [](char &c) { c = ::tolower(c); });

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
    } else {
      health = 100;
      break;
    }
  }
  // Note above all use lowercase to match changed user entry
  // else is empty so user doesnt have to use give race but will get generic
  // health
  std::cout << "\n";
  std::cout << "Enter Your Characters Gender: ";
  std::cin >> gender;
  system("clear");

  std::string *ptr_c = &gender; // pointer

  // Character loading screen
  for (int i = 0; i <= counter; i++) {
    if (i == 0)
      std::cout << "Creating Character.\n";
    if (i == 1)
      std::cout << "Creating Character..\n";
    if (i == 2) {
      std::cout << "Creating Character...\n";
      break;
    }

    sleep(3);
    system("clear");
    counter++;
  }

  // Changing the first letter to uppercase no matter user input case
  name[0] = toupper(name[0]);
  race[0] = toupper(race[0]);
  gender[0] = toupper(gender[0]);

  totalHealth = health;
  maxHealth = totalHealth;

  std::cout << "This is the new pointer value: " << *ptr_a
            << "\n"; // print value of the variable using * operator for ptr_a
  std::cout
      << "This is the memory address of the variable: " << &name
      << "\n"; // obtaining and printing the memory address of the variable
  std::cout << "This is the new pointer value: " << *ptr_b
            << "\n"; // print value of the variable using * operator for ptr_b
  std::cout
      << "This is the memory address of the variable: " << &race
      << "\n"; // obtaining and printing the memory address of the variable
  std::cout << "This is the new pointer value: " << *ptr_c
            << "\n"; // print value of the variable using * operator for ptr_c
  std::cout
      << "This is the memory address of the variable: " << &gender
      << "\n"; // obtaining and printing the memory address of the variable
  sleep(2);
}
