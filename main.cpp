#include "Character.h"
// Global functions
void title();
void story();
void HUD();
void combat();
void combatHUD();
void createMonster();
void moving();
void levelUp();
void goForward();
void goBack();
void displayLocation();
void worldSize();

using namespace std;

int monsterHp = 0, monsterXp = 0, monsterLevel = 0;

// this references the current location of the character
int locationRef = 0;

// a pointer to a string location that will later get used as a dynamic array
string *locationPtr;

string monsterName[] = {"Giant", "Wardog", "Orge", "Wrath", "Deamon", "Elf"};
int currentMonsterNames = 6;
string currentMonster = " ";

int counter = 0;
int numRooms;

Character character;

/*The main function first creates an array of strings called locationPtr and
 * assigns values to each element in the array. Then it calls the story()
 * function, characterCreation() function, HUD() function and moving() function.
 * Finally, it pauses the system and returns 0. The story() function prints out
 * a story about a weary traveller and then calls worldSize(). It also has a for
 * loop that prints out "Creating Character" three times with increasing number
 * of dots each time before breaking out of the loop.*/
int main() {
  /*
  // our pointer will point to an array
  locationPtr = new string[numRooms];
  locationPtr[0] = "Forest";
  locationPtr[1] = "Path";
  locationPtr[2] = "Swamp";
  locationPtr[3] = "Ruins";
   locationPtr[4] = "Castle";
   locationPtr[5] = "Court";
 */
  title();
  story();

  character.characterCreation();

  HUD();
  moving();

  system("pause");

  return 0;
}

void title(){

  sleep(1);
  system("clear");
  cout <<"\n\n\n\n\n\n\n";
  cout << "\t\t\t\t\t\t\t\t----------------------------------------------------------\n";
  cout << "\t\t\t\t\t\t\t\t*                                                        *\n";
  cout << "\t\t\t\t\t\t\t\t*                Text Adventure Game                      *\n";
  cout << "\t\t\t\t\t\t\t\t*                                                        *\n";
  cout << "\t\t\t\t\t\t\t\t----------------------------------------------------------\n";

  cout << "\n\n\n";
  cout << "\t\t\t\t\t\t\t\t\t\t\t\tHow long will you survive???\n\n";
  cout << "\t\t\t\t\t\t\t\t\t\t\t\tYour game starts now!\n";
  sleep(3);
}

void story() {

  sleep(2);
  system("clear");
  cout << "\tA long time ago a weary traveller find themselves at an inn. "
          "\nTired from there long journey, they decide to grab a quick "
          "drink of ale then off to bed to rest. \nYou wake felling "
          "groggy but rested, you hear a scream from outside your window. "
          "\nUpon investigation you see monsters running from building to "
          "building ripping apart and devouring everyone they find. \nYou "
          "quickly turn grab your weapon and head for the exit ";

  worldSize();

  // displayLocation();  

  cin.ignore();
  // loading screen
  for (int i = 0; i <= counter; i++) {
    if (i == 0)
      cout << "Creating Character.\n";
    if (i == 1)
      cout << "Creating Character..\n";
    if (i == 2) {
      cout << "Creating Character...\n";
      break;
    }
    sleep(6);
    system("clear");
    counter++;
  }
}
/*HUD which stands for Heads Up Display. It is used to display character
 * information in a game such as their name, health, race, gender, level,
 * current experience points and experience points needed to reach the next
 * level. The HUD also calls two other functions: sleep() and system("clear")
 * which pauses the program for 4 seconds and then clears the screen. Finally,
 * it calls two other functions: displayLocation() and moving() which are used
 * to display the character's current location and allow them to traverse the
 * game.*/
void HUD() {
  sleep(4);
  system("clear");
  cout << "Name: " << character.name
       << "      Health: " << character.totalHealth
       << "\nRace: " << character.race << "\nGender: " << character.gender
       << "\nLevel: " << character.level << "\nXP: " << character.current_xp
       << "\nXP to next Level: " << character.xp_to_level << endl;
  displayLocation();
  moving();
}
/*combatHUD() that is used to display information about the character and the
 * current monster. It start by using functions: sleep() and system("clear"),
 * then it prints out information about the character and monster such as their
 * names, health, and levels in a simular way to the HUD. Finally, it calls
 * another function called displayLocation() */
void combatHUD() {
  sleep(4);
  system("clear");
  cout << "Name: " << character.name
       << "      |       Monster Name: " << currentMonster
       << "\nHealth: " << character.totalHealth
       << "        |       Monster Health: " << monsterHp
       << "\nLevel: " << character.level
       << "        |       Monster Level: " << monsterLevel << endl;
  displayLocation();
}
/*The function starts by displaying the combat HUD as above. Then prompts the
 * player to choose an action: attack, defend, or retreat by choose 1,2 or 3. */
void combat() {
  combatHUD();
  int playerAttack;
  int playerDamage = 8 * character.level / 2;
  int monsterAttack = 6 * monsterLevel / 2;

  if (character.totalHealth >= 1 && monsterHp) {
    cout << "\n";
    cout << "1. Attack\n";
    cout << "2. Defend\n";
    cout << "3. RETREAT!!!\n";
    cout << "\n";

    cin >> playerAttack;
    /*If the player chooses to attack, it calculates the damage done to the
     * monster and subtracts it from its health. If the monsters health is still
     * > 1     the monster will attack back and the character will lose health
     * points*/
    if (playerAttack == 1) {
      // Attack
      cout << "You swing you weapon... You did " << playerDamage
           << " hit points of damage to the " << currentMonster << endl;
      monsterHp = monsterHp - playerDamage;
      sleep(4);
      combatHUD();

      if (monsterHp >= 1) {
        cout << "\n";
        cout << currentMonster << " is attacking!\n";
        character.totalHealth = character.totalHealth - monsterAttack;
        cout << "You suffered " << monsterAttack << " hp of damage "
             << character.totalHealth << " hp remaining" << endl;

        if (character.totalHealth <= 0) {
          character.totalHealth = 0;
          system("clear");
          cout << "You Were Killed!!! \nYou reached level: " << character.level
               << "you were obliterated by " << currentMonster
               << "\n Game Over...." << endl;
          sleep(3);
          exit(0);
        }
      } else if (monsterHp <= 0) {
        monsterHp = 0;
        cout << "\n";
        cout << "You have vanquished " << currentMonster
             << " you have gained experience " << monsterXp << " xp.\n";

        if (character.level != character.maxLevel) {
          character.current_xp += monsterXp;
          levelUp();
        }
        sleep(1);
        HUD();
      }
      sleep(1);
      combat();
      /*If the player chooses to defend, there is a 50% chance that their
       * defense       will be successful and they will regain some of their
       * lost health.                If failed, they will take damage from the
       * monster's attack.*/
    } else if (playerAttack == 2) {
      // Defend
      cout << "You Defend\n";
      int i = rand() % 100 + 1;
      if (i >= 50) {
        cout << "Your shield held strong\n";
        character.heal = character.level * 10 / 2 == character.maxHealth;
        cout << "Your confidence grows strong. You have regained "
             << character.heal << endl;
        character.totalHealth += character.heal;
        sleep(1);
        combat();
      } else {
        cout << "You defense has failed\n";
        character.totalHealth -= monsterAttack;
        cout << "Your weakness has cost you " << monsterAttack << " current hp "
             << character.totalHealth << endl;
        sleep(1);
        combat();
      }
      /*If the player chooses to retreat, there is also a 50% chance that they
       * will     successfully escape from combat without taking any damage.
       * Otherwise, they        will take extra damage from an unsuccessful
       * attempt at retreating.*/
    } else if (playerAttack == 3) {
      // Retreat
      goBack();
      displayLocation();
      cout << "You sound the Retreat\n";
      int x = rand() % 100 + 1;
      if (x >= 50) {
        cout << "RETREAT!!!\n";
        HUD();
      } else {
        cout << "Your cowardice has been punished you failed to escape\n";
        cout << currentMonster << " attacks you viscously\n";
        character.totalHealth -= monsterAttack + 10;
        cout << "You weakness has costed you " << monsterAttack + 10
             << "You health is now " << character.totalHealth << endl;
        sleep(1);
        combat();
      }
    } else {
      cout << "Invalid Input Select Again Warrior\n";
      sleep(1);
      combat();
    }
  }
}
/*moving() function allows the player to choose how they want to move in the
 * game. it gives the user three options for the player to choose from: move
 * forward - 1, sit and rest - 2, or return the way they came - 3.*/
void moving() {

  int choice;

  cout << "\n\n";
  cout << "1. Move Forward\n";
  cout << "2. Sit and Rest\n";
  cout << "3. Return the way you came\n";
  cout << "\n";

  cin >> choice;

  if (choice == 1) {
    int temp =
        rand() % 100 +
        1; // generates a random number between 1 and 100, and if it is greater
           // than or equal to 50, it creates a monster for the user to fight.
    cout << "You being moving forward...\n";
    goForward();

    if (temp >= 50) {
      // Encounter Monster
      createMonster();
      string tempName = monsterName[rand() % currentMonsterNames];
      cout << "\n\nA " << tempName << "! Prepare to defend yourself!\n";
      currentMonster = tempName;
      sleep(1);
      combat();
    }
    displayLocation();
    cout << "\n\nYou find nothing! Dare to carry on?\n";
    sleep(1);
    HUD();
  } else if (choice == 2) {
    displayLocation();
    cout << "You step up camp, eat and sleep to rest\n";
    if (character.totalHealth <=
        99) { // checks the character's total health is less than or equal
              // to 99. If so, it increases the character's total health by 10
      character.totalHealth += 10 * character.level;
    }
    cout << "You fell asleep and healed, your health has increase and is now "
         << character.totalHealth << endl;
    sleep(1);
    HUD();
  } else if (choice == 3) {
    goBack();
    displayLocation();
    int temp =
        rand() % 100 +
        1; // a random number between 1 and 100 is generated. If the
           // number is greater than or equal to 50, a monster is created.
    cout << "You move back with caution...\n";
    if (temp >= 50) {
      // Encounter Monster
      createMonster();
      string tempName = monsterName[rand() % currentMonsterNames];
      cout << "A " << tempName << "! Prepare to defend yourself!\n";
      currentMonster = tempName;
      sleep(1);
      combat();
    }
    cout << "You find nothing! Dare to carry on?\n";
    sleep(1);
    HUD();

  } else {
    cout << "Invalid Input Select Again Warrior\n";
    sleep(1);
    moving();
  }
}
/*levelUp() checks if the character's current_xp is greater than or equal to the
 * xp_to_level to level up. If  current_xp is => xp_to_level then xp_to_level is
 * increased by an amount based on the current level and so is the total
 * health*/
void levelUp() {

  if (character.current_xp >= character.xp_to_level) {
    character.xp_to_level +=
        floor(character.level + 25 * pow(2, character.level / 7));
    character.totalHealth =
        floor(character.totalHealth + 13 * pow(2, character.level / 8));

    if (character.level >= character.minLevel &&
        character.level <= character.maxLevel) {
      character.level++;
    } else {
      character.level =
          60; // The character's level is then increased by one, unless it has
              // reached its maximum level, in which case it is set to 60.
    }

    character.maxHealth = character.totalHealth;
    cout << "Your looking strong and wiser....Congratulations you're now level "
         << character.level << endl;
    cout
        << "Your new level has brought you more health! Your new max health is "
        << character.totalHealth << endl;
    cout << "\n";
    sleep(1);
    levelUp();
  }

  sleep(2);
  HUD();
}
/*createMonster() is a funtion to create a monster with a random level and
 * health points. */
void createMonster() {
  monsterHp = 30;
  monsterLevel =
      (rand() % 3) +
      character
          .level; // monster's level is determined by taking a random number
                  // between 0 and 3 and adding it to the character's level.
  // review value
  monsterHp = (rand() % 30) * monsterLevel;
  monsterXp =
      monsterHp; // health points are determined by taking a random number
                 // between 0 and 30, multiplying it by the monster's level, and
                 // assigning it to the variable monsterHp.

  if (monsterHp == 0)
    createMonster();
  if (monsterLevel == 0)
    createMonster();
}
/*goForward() is used to move the location reference forward*/
void goForward() {
  if (locationRef < (numRooms - 1)) {
    locationRef++;
  } else {
    locationRef = 0;
  }
}
/*goBack() is used to move the location refrence backwards*/
void goBack() {
  if (locationRef > 0) {
    locationRef--;
  } else {
    locationRef = numRooms - 1;
  }
}
/*The displayLocation() function prints out the location of the user using a
 * pointer to an array of strings. The worldSize() function creates an array of
 * strings called world, which contains 8 possible locations. It then asks the
 * user how many terrain locations they would like their world to have and
 * stores this value in the numRooms variable. It then creates a new string
 * array with numRooms elements and assigns each element a random location from
 * the world array.*/
void displayLocation() {
  cout << "\n\nYou are at the " << locationPtr[locationRef] << "\n\n";
}

void worldSize() {
  int roomType;     // used to pick a room
  int possibleLocs; // how many possible locations
  string world[] = {"The unforgiving Forest",
                    "An Unlit Foggy Path",
                    "A Misty Cold Damp Swamp",
                    "The Ancient Ruins of a Rampart",
                    "A Dilapidated Castle",
                    "The Court Yard of a Castle",
                    "St. George’s Church of the Accult",
                    "The Forbidden City"};

  possibleLocs = sizeof(world) / sizeof(world[0]);
  srand((unsigned)time(0));

  cout << "\n\nHow many terrain locations would you like your world to "
          "have?\n\n";
  cin >> numRooms;
  locationPtr = new string[numRooms];

  for (int index = 0; index < numRooms; index++) {
    roomType = rand() % possibleLocs;
    locationPtr[index] = world[roomType];
  } /* The locationPtr array is then populated with the corresponding world
       location for each room type.*/
  system("clear");

  /*This is for test purposes to ensure the locations were printing out.
    for (int index = 0; index < numRooms; index++) {
    cout << "\n\n" << locationPtr[index] << "\n\n" << endl;
  }*/
}