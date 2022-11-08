
#include<iostream>
#include<windows.h>
#include<string>
#include<algorithm>

void Story();
void HUD();
void Combat();
void CombatHUD();
void Moving();
void CreateMonster();
void LevelUp();

//global Variables

std::string name = " ", race = " ", gender = " ";
int level = 0, xp = 0, health = 0, totalHealth = 0, maxHealth = 0, nextLevel = 0, heal = 0;

int monsterHp = 0, monsterXp = 0, monsterLevel = 0;

std::string monsterName[] = {"Giant", "Wardog", "Orge", "Wrath", "Deamon", "Elf"};
int currentMonsterNames = 5;
std::string currentMonster = " ";

int counter = 3;

std::string playerRace[] = { "elf", "human", "dwarf", "darkelf", "wizard" };


int main(){

    Story();
    
    level = 1;
    xp = 0;
    nextLevel = 76;
    



    //character creation
    std::cout<<"Enter Your Characters Name: ";
    std::cin>> name;


    std::cout<<"Enter Your Characters Race\n";
    std::cout<<"Elf\n";
    std::cout<<"Human\n";
    std::cout<<"Dwarf\n";
    std::cout<<"DarkElf\n";
    std::cout<<"Wizard\n";
    std::cout<<"Type your chosen race below: \n\n";
    std::cin>> race;

    std::for_each(race.begin(), race.end(), [](char & c) {
        c = ::tolower(c);
    });

    for(int i = 0; i < sizeof(playerRace); i++) {
        if(race == "elf"){
            health = 80;
            break;
        }
        if(race == "human"){
            health = 85;
            break;
        }
        if(race == "dwarf"){
            health = 110;
            break;
        }
        if(race == "darkelf"){
            health = 75;
            break;
        }
        if(race == "wizard"){
            health = 100;
            break;
        }
        else{
            health = 100;
            break;
        }
    }

    std::cout<<"\n";
    std::cout<<"Enter Your Characters Gender: ";
    std::cin>> gender;

    //Character loading screen
    for(int i = 0; i < counter; i++){
        if(i == 0)
            std::cout <<"Creating Character.\n";
        if(i == 1)
            std::cout <<"Creating Character..\n";
        if(i == 2)
            std::cout <<"Creating Character...\n";

        Sleep(800);
        system("cls");
    }


    //Changing the first letter to uppercase no matter user input case
    name[0] = toupper(name[0]);
    race[0] = toupper(race[0]);
    gender[0] = toupper(gender[0]);

    //Long version of code above without using for loop

    // std::cout<< "Creating Character.\n";
    // Sleep(800);
    // system("cls");
    // std::cout<< "Creating Character..\n";
    // Sleep(800);
    // system("cls");
    // std::cout<< "Creating Character...\n";
    // Sleep(800);
    // system("cls");

    totalHealth = health;
    maxHealth = totalHealth;

    Sleep(4000);

    HUD();
    Moving();

    system("pause");

    return 0;
}

void Story(){
        Sleep(500);
    system("cls");
    std::cout << "A long time ago a weary traveller find themselves at an inn. \nTired from there long journey, they decide to grab a quick drink of ale then off to bed to rest. \nYou wake felling groggy but rested, you hear a scream from outside your window. \nUpon investigation you see monsters running from building to building ripping apart and devouring everyone they find. \nYou quickly turn grab your weapon and head for the exit ";

    std::cout << "\n\n\n";
    std::cout << "Click Enter to move forward...";

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
    std::cout << "Name: " << name << "      Health: "<< totalHealth << "\nRace: "<< race << "\nGender: "<< gender <<"\nLevel: "<< level <<"\nXP: "<< xp <<"\nXP to next Level: "<< nextLevel <<std::endl;
    Moving();
}

void CombatHUD(){
    Sleep(500);
    system("cls");
    std::cout << "Name: " << name << "      |       Monster Name: " << currentMonster << "\nHealth: "<< totalHealth << "        |       Monster Health: "<< monsterHp <<"\nLevel: "<< level << "        |       Monster Level: " << monsterLevel << std::endl;
}

void Combat(){
    CombatHUD();
    int playerAttack;
    int playerDamage = 8 * level / 2;
    int monsterAttack = 6 * monsterLevel / 2;

    if(totalHealth >= 1 && monsterHp){
        std::cout <<"\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Defend\n";
        std::cout << "3. RETREAT!!!\n";
        std::cout << "\n";

        std::cin >> playerAttack;

        if(playerAttack == 1){
            //Attack
            std::cout << "You swing you weapon... You did " << playerDamage << " to the " << currentMonster << std::endl;
            monsterHp = monsterHp - playerDamage;
            Sleep(500);
            CombatHUD();
            
            if(monsterHp >= 1){
                std::cout << "\n";
                std::cout << currentMonster <<"is attacking!\n";
                totalHealth = totalHealth - monsterAttack;
                std::cout << "You suffered " << monsterAttack << "hp " << totalHealth << std::endl;

                if(totalHealth <= 0){
                    totalHealth = 0;
                    system("cls");
                    std::cout << "You Were Killed!!! \nYou reached level: " << level << "you were obliterated by " << currentMonster << "\n Game Over...." << std::endl;
                    Sleep(3000);
                    exit(0);
                }
            }else if (monsterHp <= 0){
                monsterHp = 0;
                LevelUp();
                std::cout << "\n";
                std::cout << "You have vanquished " << currentMonster << " you have gained experience " << monsterXp << " xp.\n";
                Sleep(1000);
                HUD();
            }
            Sleep(1000);
            Combat();
        }else if(playerAttack == 2){
            //Defend
            std::cout << "You Defend\n";
            int i = rand() % 100 + 1;
            if( i >= 50){
                std::cout << "Your shield held strong\n";
                heal = level * 10 / 2;
                std::cout << "Your confidence grows strong. You have regained " << heal << std::endl;
                totalHealth += heal;
                Sleep(1000);
                Combat();
            }
            else {
                std::cout << "You defense has failed\n";
                totalHealth -= monsterAttack;
                std::cout << "Your weakness has cost you " << monsterAttack << " current hp " << totalHealth << std::endl;
                Sleep(1000);
                Combat();
            }

        }else if(playerAttack == 3){
            //Retreat
            std::cout << "You sound the Retreat\n";
            int x = rand() % 100 + 1;
            if(x >= 50){
                std::cout << "RETREAT!!!\n";
                HUD();
            }
            else{
                std::cout << "Your cowardice has been punished you failed to escape\n";
                std::cout << currentMonster << " attacks you viscously\n";
                totalHealth -= monsterAttack + 10;
                std::cout << "You weakness has costed you " << monsterAttack + 10 << "You health is now " << totalHealth << std::endl;
                Sleep(1000);
                Combat();
            }
        }
        else{
            std::cout<<"Invalid Input Select Again Warrior\n";
            Sleep(1000);
            Combat();
        }
    }
}

void Moving() {

    int choice;
    std::cout<<"\n\n";
    std::cout<<"1. Move Forward\n";
    std::cout<<"2. Sit and Rest\n";
    std::cout<<"3. Return the way you came\n";
    std::cout<<"\n";

    std::cin>>choice;

    if(choice == 1){
        int temp = rand() % 100 + 1;
        std::cout<< "You being moving forward...\n";
        if (temp >= 50){
           //Encounter Monster
            CreateMonster();
            std::string tempName = monsterName[rand() % currentMonsterNames];
            std::cout<< "A " << tempName << "! Prepare to defend yourself!\n";
            currentMonster = tempName;
            Sleep(1000);
            Combat();
        }
        std::cout<< "You find nothing! Dare to carry on?";
        Sleep(1000);
        HUD();
    }else if(choice == 2){
        std::cout<< "You step up camp, eat and sleep to rest\n";
        if(totalHealth <= 99){
            totalHealth +=10 * level;
        }
        std::cout << "You fell asleep and healed, your health has increase and is now " << totalHealth << std::endl;
        Sleep(1000);
        HUD();
    }else if(choice == 3){
       int temp = rand() % 100 + 1;
        std::cout<< "You being running away...\n";
        if (temp >= 50){
           //Encounter Monster
            CreateMonster();
            std::string tempName = monsterName[rand() % currentMonsterNames];
            std::cout<< "A " << tempName << "! Prepare to defend yourself!\n";
            currentMonster = tempName;
            Sleep(1000);
            Combat();
        }
        std::cout<< "You find nothing! Dare to carry on?";
        Sleep(1000);
        HUD();

    }else{
        std::cout<<"Invalid Input Select Again Warrior\n";
        Sleep(1000);
        Moving();
    }

}

void LevelUp(){
    xp = xp + monsterXp;

    if(xp >= nextLevel){
        level++;
        nextLevel = nextLevel * 3 / 2;
        totalHealth = totalHealth + 20;
        maxHealth = totalHealth;
        std::cout << "Your looking strong and wiser....Congratulations you're now level " << level << std::endl;
        std::cout << "Your new level has brought you more health by 20 points! Your new max health is " << totalHealth << std::endl;
        Sleep(2000);
        HUD();
    }
}

void CreateMonster(){
    monsterHp = 30;
    monsterLevel = (rand() % 3) + level;

    /*if(monsterLevel == 0){
        monsterLevel = (rand() % 3) + level;
    }*/
    //review value
    monsterHp = (rand() % 30) * monsterLevel;

    /*if(monsterHp == 0){
        monsterHp = (rand() % 30) * totalHealth;
    }*/

    monsterXp = monsterHp;

    if(monsterHp == 0)
        CreateMonster();
    if(monsterLevel == 0)
        CreateMonster();
}

