#include "Character.h"



void Story();
void HUD();
void Combat();
void CombatHUD();
void Moving();
void CreateMonster();
void LevelUp();


int monsterHp = 0, monsterXp = 0, monsterLevel = 0;

std::string monsterName[] = { "Giant", "Wardog", "Orge", "Wrath", "Deamon", "Elf" };
int currentMonsterNames = 5;
std::string currentMonster = " ";



int counter = 0;

Character character;



int main() {

    Story();

    character.characterCreation();

    HUD();
    Moving();

    CreateMonster();

    system("pause");

    return 0;
}

void Story() {

    Sleep(500);
    system("cls");
    std::cout << "A long time ago a weary traveller find themselves at an inn. \nTired from there long journey, they decide to grab a quick drink of ale then off to bed to rest. \nYou wake felling groggy but rested, you hear a scream from outside your window. \nUpon investigation you see monsters running from building to building ripping apart and devouring everyone they find. \nYou quickly turn grab your weapon and head for the exit ";

    std::cout << "\n\n\n";
    std::cout << "Click enter to move forward with your adventure";

    std::cin.ignore();


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
}

void HUD() {
    Sleep(500);
    system("cls");
    std::cout << "Name: " << character.name << "      Health: " << character.totalHealth << "\nRace: " << character.race << "\nGender: " << character.gender << "\nLevel: " << character.level << "\nXP: " << character.current_xp << "\nXP to next Level: " << character.xp_to_level << std::endl;
    Moving();
}

void CombatHUD() {
    Sleep(500);
    system("cls");
    std::cout << "Name: " << character.name << "      |       Monster Name: " << currentMonster << "\nHealth: " << character.totalHealth << "        |       Monster Health: " << monsterHp << "\nLevel: " << character.level << "        |       Monster Level: " << monsterLevel << std::endl;
}

void Combat() {
    CombatHUD();
    int playerAttack;
    int playerDamage = 8 * character.level / 2;
    int monsterAttack = 6 * monsterLevel / 2;

    if (character.totalHealth >= 1 && monsterHp) {
        std::cout << "\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Defend\n";
        std::cout << "3. RETREAT!!!\n";
        std::cout << "\n";

        std::cin >> playerAttack;

        if (playerAttack == 1) {
            //Attack
            std::cout << "You swing you weapon... You did " << playerDamage << " to the " << currentMonster << std::endl;
            monsterHp = monsterHp - playerDamage;
            Sleep(500);
            CombatHUD();

            if (monsterHp >= 1) {
                std::cout << "\n";
                std::cout << currentMonster << "is attacking!\n";
                character.totalHealth = character.totalHealth - monsterAttack;
                std::cout << "You suffered " << monsterAttack << "hp " << character.totalHealth << std::endl;

                if (character.totalHealth <= 0) {
                    character.totalHealth = 0;
                    system("cls");
                    std::cout << "You Were Killed!!! \nYou reached level: " << character.level << "you were obliterated by " << currentMonster << "\n Game Over...." << std::endl;
                    Sleep(3000);
                    exit(0);
                }
            }
            else if (monsterHp <= 0) {
                monsterHp = 0;
                std::cout << "\n";
                std::cout << "You have vanquished " << currentMonster << " you have gained experience " << monsterXp << " xp.\n";


                if (character.level != character.maxLevel) {
                    character.current_xp += monsterXp;
                    LevelUp();
                }

                Sleep(1000);
                HUD();
            }
            Sleep(1000);
            Combat();
        }
        else if (playerAttack == 2) {
            //Defend
            std::cout << "You Defend\n";
            int i = rand() % 100 + 1;
            if (i >= 50) {
                std::cout << "Your shield held strong\n";
                character.heal = character.level * 10 / 2;
                std::cout << "Your confidence grows strong. You have regained " << character.heal << std::endl;
                character.totalHealth += character.heal;
                Sleep(1000);
                Combat();
            }
            else {
                std::cout << "You defense has failed\n";
                character.totalHealth -= monsterAttack;
                std::cout << "Your weakness has cost you " << monsterAttack << " current hp " << character.totalHealth << std::endl;
                Sleep(1000);
                Combat();
            }

        }
        else if (playerAttack == 3) {
            //Retreat
            std::cout << "You sound the Retreat\n";
            int x = rand() % 100 + 1;
            if (x >= 50) {
                std::cout << "RETREAT!!!\n";
                HUD();
            }
            else {
                std::cout << "Your cowardice has been punished you failed to escape\n";
                std::cout << currentMonster << " attacks you viscously\n";
                character.totalHealth -= monsterAttack + 10;
                std::cout << "You weakness has costed you " << monsterAttack + 10 << "You health is now " << character.totalHealth << std::endl;
                Sleep(1000);
                Combat();
            }
        }
        else {
            std::cout << "Invalid Input Select Again Warrior\n";
            Sleep(1000);
            Combat();
        }
    }
}

void Moving() {

    int choice;
    std::cout << "\n\n";
    std::cout << "1. Move Forward\n";
    std::cout << "2. Sit and Rest\n";
    std::cout << "3. Return the way you came\n";
    std::cout << "\n";

    std::cin >> choice;

    if (choice == 1) {
        int temp = rand() % 100 + 1;
        std::cout << "You being moving forward...\n";
        if (temp >= 50) {
            //Encounter Monster
            CreateMonster();
            std::string tempName = monsterName[rand() % currentMonsterNames];
            std::cout << "A " << tempName << "! Prepare to defend yourself!\n";
            currentMonster = tempName;
            Sleep(1000);
            Combat();
        }
        std::cout << "You find nothing! Dare to carry on?";
        Sleep(1000);
        HUD();
    }
    else if (choice == 2) {
        std::cout << "You step up camp, eat and sleep to rest\n";
        if (character.totalHealth <= 99) {
            character.totalHealth += 10 * character.level;
        }
        std::cout << "You fell asleep and healed, your health has increase and is now " << character.totalHealth << std::endl;
        Sleep(1000);
        HUD();
    }
    else if (choice == 3) {
        int temp = rand() % 100 + 1;
        std::cout << "You being running away...\n";
        if (temp >= 50) {
            //Encounter Monster
            CreateMonster();
            std::string tempName = monsterName[rand() % currentMonsterNames];
            std::cout << "A " << tempName << "! Prepare to defend yourself!\n";
            currentMonster = tempName;
            Sleep(1000);
            Combat();
        }
        std::cout << "You find nothing! Dare to carry on?";
        Sleep(1000);
        HUD();

    }
    else {
        std::cout << "Invalid Input Select Again Warrior\n";
        Sleep(1000);
        Moving();
    }

}

void LevelUp() {
    
    if (character.current_xp >= character.xp_to_level) {
        character.xp_to_level += floor(character.level + 25 * pow(2, character.level / 7));
        character.totalHealth = floor(character.totalHealth + 13 * pow(2, character.level / 8));

        if (character.level >= character.minLevel && character.level <= character.maxLevel) {
            character.level++;
        }
        else {
            character.level = 60;
        }

        character.maxHealth = character.totalHealth;
        std::cout << "Your looking strong and wiser....Congratulations you're now level " << character.level << std::endl;
        std::cout << "Your new level has brought you more health! Your new max health is " << character.totalHealth << std::endl;
        std::cout << "\n";
        Sleep(1500);
        LevelUp();
    }

    Sleep(2000);
    HUD();
}

void CreateMonster() {
    monsterHp = 30;
    monsterLevel = (rand() % 3) + character.level;

    /*if(monsterLevel == 0){
        monsterLevel = (rand() % 3) + level;
    }*/
    //review value
    monsterHp = (rand() % 30) * monsterLevel;

    /*if(monsterHp == 0){
        monsterHp = (rand() % 30) * totalHealth;
    }*/

    monsterXp = monsterHp;

    if (monsterHp == 0)
        CreateMonster();
    if (monsterLevel == 0)
        CreateMonster();
}

