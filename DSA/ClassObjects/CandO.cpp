#include<iostream>
#include "CandO2.cpp"//linking Class from another file
using namespace std;
class Hero {
    //Properties
    private :
    int health;
    char level;
    char *name;

    public :
    //Default constructor 
    Hero() {
        cout << "Constructor called" << endl;
        name = new char[100];
    }
    //Parameterized constructor
    Hero(int health, char level) {
        // health = health;
        cout << "Parameterized constructor called " << endl;
        this->health = health; 
        cout << "this : " << this << endl;
        cout << health << endl << level << endl;
        }
    //Copy constructor 
    Hero(Hero& temp) {
        cout << "Copy constructor Called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }
    void print() {
        cout << "Level is : " << this->level << endl;
        cout << "Health is : " << this->health << endl;
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
    // Hero Ramesh; //default Constructor called by statically

    Hero Ramesh(10, 'K');//parameterized constructor
    Ramesh.print();
    Hero R(Ramesh);
    R.print();
    cout << "Address of Ramesh : " << &Ramesh << endl;
    // Ramesh.health = 67;
    // Ramesh.level = 'A';
    // cout << "Size of : " << sizeof(Hero) << endl;//Size gives more than actual size(Padding)
    // cout << "Health is : " << Ramesh.health << endl;
    // cout << "Level is : " << Ramesh.level << endl;

    /*Hero2 H2;
    cout << "Size of : " << sizeof(H2) << endl;
    cout << "Ramesh health is : " << Ramesh.getHealth() << endl;*/

    //Use setter
    // Ramesh.setHealth(70);//statically
    // Ramesh.setLevel('B');//statically
    // cout << "Ramesh health is : " << Ramesh.getHealth() << endl;
    // cout << "Ramesh level is : " << Ramesh.getLevel() << endl;
    /*cout << "Before constructor call" << endl;
    Hero *Ramesh = new Hero; //Default Constructor called dynamically
    cout << "After constructor call" << endl;
    cout << "Size of Ramesh : " << sizeof(Ramesh) << endl;//Size gives more than actual size (dynamically)*/
    return 0;
}