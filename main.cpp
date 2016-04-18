// Example program
#include <iostream>
#include <string>
using namespace std;

//A combatant contolled by the CPU.
class CPU
{
    private:
    int lightAttack();   //70% hit chance, 1-5 damage
    int heavyAttack();   //40% hit chance, 3-8 damage
    int recover();       //50% success rate, 2-7 recovery
    
    public:
    int HP = 20;
    string name = "Floyd";
    void updateHP(int);  // Decrements HP by amount supplied by parameter.
    int turn();          // Generates the CPUs move choice and calls corresponding function.
    
};
//A combatant controlled by the user.
class Human
{
    private:
    int lightAttack();   //70% hit chance, 1-5 damage
    int heavyAttack();   //40% hit chance, 3-8 damage
    int recover();       //50% success rate, 2-7 recovery
    
    public:
    int HP = 20;
    string name;
    void updateHP(int);  // Decrements HP by amount supplied by parameter.
    int turn();
};

int main()
{   
    cout << "You are standing in a boxing ring staring down Moneyman Mayweather.  You're not sure where you are or how you \ngot here but as the bell rings" << 
    " and Moneyman pounds his gloves together, it's clear you have to do something...\n\n";
    srand(time(NULL));
    int p1Damage;
    int p2Damage;
    Human p1;
    CPU p2;
    
    while(p1.HP > 0 && p2.HP > 0)
    {
        p1Damage = p1.turn();
        p2.updateHP(p1Damage);
        
        p2Damage = p2.turn();
        p1.updateHP(p2Damage);
        cout << endl << endl << "CPU HP = " << p2.HP << endl << "Human HP = " << p1.HP << endl << endl;
    }
    if(p1.HP < 0)
        cout << "CPU wins!";
    else
        cout << "Human wins!";


    
    
    return 0;
};

// Decrements the CPU's HP by adjust.  
void CPU::updateHP(int adjust)
{
    HP -= adjust;
};

// Generates the CPU's move choice and calls the corresponding function to execute the move.
// Calls lightAttack() 65% of the time, heavyAttack() 20% and recover() 15%.
int CPU::turn()
{   

    int choice = rand() % 100 + 1;
    if(choice <= 65)
    {   
        int damage = lightAttack();
        return damage;
    }
    else if(choice <= 85)
    {
        int damage = heavyAttack();
        return damage;
    }
    else
    {
        recover();
        return 0;
    }
};

// Light attack which hits 70% of the time for 1-5 damage.
int CPU::lightAttack()
{
    int hit = rand() % 100 + 1;
    if(hit <= 70)
    {
        int damage;
        damage = rand() % 5 + 1;
        cout << "CPU light attack damage = " << damage << endl;
        return damage;
    }
    else
    {
        cout << "CPU light attack miss" << endl;
        return 0;
    }
};

//Heavy attack which hits 40% of the time for 3-8 damage.
int CPU::heavyAttack()
{
    int hit = rand() % 100 + 1;
    if(hit <= 40)
    {
        int damage;
        damage = rand() % 5 + 3;
        cout << "CPU heavy attack damage = " << damage << endl;
        return damage;
    }
    else
    {
        cout << "CPU heavy attack miss" << endl;
        return 0;
    }
};

//Recovers between 2 and 7 HP 50% of the time.
int CPU::recover()
{
    int hit = rand() % 100 + 1; 
    if(hit <= 50)
    {
        int heal;
        heal = rand() % 5 + 2;
        this->HP += heal;
        cout << "CPU recovery = " << heal << endl;
        return 0;
    }  
    else
    {
        cout << "CPU recovery miss" << endl;   
        return 0;
    }
};

// Decrements the Human's HP by adjust.
void Human::updateHP(int adjust)
{
    HP -= adjust;
};

// Light attack which hits 70% of the time for 1-5 damage.
int Human::lightAttack()
{
    int hit = rand() % 100 + 1;
    if(hit <= 70)
    {
        int damage;
        damage = rand() % 5 + 1;
        cout << "You land a quick jab for " << damage << " damage." << endl;
        return damage;
    }
    else
    {
        cout << "You toss out a quick jab but Floyd shrugs it off." << endl;
        return 0;
    }
};

//Heavy attack which hits 40% of the time for 3-8 damage.
int Human::heavyAttack()
{
    int hit = rand() % 100 + 1;
    if(hit <= 40)
    {
        int damage;
        damage = rand() % 5 + 3;
        cout << "You connect with a wicked cross for " << damage << " damage." << endl;
        return damage;
    }
    else
    {
        cout << "Floyd dodges your reckless attack." << endl;
        return 0;
    }
};

//Recovers between 2 and 7 HP 50% of the time.
int Human::recover()
{
    int hit = rand() % 100 + 1; 
    if(hit <= 50)
    {
        int heal;
        heal = rand() % 5 + 2;
        this->HP += heal;
        cout << "You steady yourself and recover " << heal << " damage." << endl;
        return 0;
    }  
    else
    {
        cout << "You try to catch your breath but Floyd won't let you." << endl;   
        return 0;
    }
};

//Asks the user for a move choice and validates the choice.  Then calls the appropriate function.
int Human::turn()
{
    cout << "What do you want to do?  Enter 'L' for Light Attack, 'H' for Heavy Attack or 'R' for Recover: ";
    char choice; 
    cin >> choice;
    while(!(choice == 'l' || choice == 'L' || choice == 'h' || choice == 'H' || choice == 'r' || choice == 'R'))
    {
        cout <<"Not a valid selection.  Enter 'L' for Light Attack, 'H' for Heavy Attack or 'R' for Recover: ";
        cin >> choice;
    };
    if(choice == 'L' || choice == 'l')
    {   
        int damage = lightAttack();
        return damage;
    }
    else if(choice == 'H' || choice == 'h')
    {
        int damage = heavyAttack();
        return damage;
    }
    else
    {
        recover();
        return 0;
    }
};
