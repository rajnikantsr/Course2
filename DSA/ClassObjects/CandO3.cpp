#include<iostream>
#include<cstring>
using namespace std;
class Hero {
    //Properties
    private :
    int health;
    public :
    char level;
    char *name;

    public :
    Hero() {
        cout << "Simple constructor called : " << endl;
        name = new char[100];
    }
    //Copy constructor(On writing own copy constructor inbuilt default constructor no more exist)
    // Hero(Hero& temp) {//& is only for not trapping in infinite loop(on pass by value temp copy formed by suresh and after making copy copy constructor called)
    //     cout << "Copy constructor Called" << endl;
    //     this->name = temp.name;
    //     this->health = temp.health;
    //     this->level = temp.level;
    // }
    //Deep constructor
    Hero(Hero& temp) {
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
        cout << "copy constructor called" << endl;
        this->level = temp.level;
        this->health = temp.health;
    }
    void print() {
        cout << "[ Name is : " << this->name << endl;
        cout << "Level is : " << this->level << endl;
        cout << "Health is : " << this->health << " ]" << endl;
        cout << endl;
    }
    int getHealth() {
        return health;
    }
    char getLevel() {
        return level;
    }
    void setHealth(int h) {
        health = h;
    }
    void setLevel(char ch) {
        level = ch;
    }
    void setName(char name[]) {
        strcpy(this->name, name);
    }
};
int main() {
/*    // Hero Suresh;
    // Suresh.setHealth(70);
    // Suresh.setLevel('C');
    // Suresh.print();
    // Hero Ramesh(Suresh);
    // Ramesh.print();//Copy constructor*/
    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Babbar";
    hero1.setName(name);
    hero1.print();
    Hero hero2(hero1);//Shallow copy <- Default constructor 
    //Hero hero2 = hero1;
    hero2.print();
    hero1.name[0] = 'G';
    hero1.print();
    hero2.print();
    hero1 = hero2;//copy assignment operator   
    return 0;
}