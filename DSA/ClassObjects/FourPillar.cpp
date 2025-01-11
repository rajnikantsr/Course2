#include <iostream>
using namespace std;
class student {
    public : 
    int age;
    int weight; 
    string name;
    int getAge() {
        return this->age;
    }
    void setWeight(int w) { 
        this->weight = w;
    }
};

class Ravi : public student {
    public : 
    char gender;
    void sleep() {
        cout << "Ravi is sleeping " << endl;
    }
/*    int getWeight() {
        return this->weight;
    }*///for protected
};
int main() {
    Ravi first;
    // cout << first.getWeight() << endl;//for protected and private child class
    cout << "Everything is fine :)" << endl;
    cout << first.age << endl;
    cout << first.weight << endl;
    cout << first.gender << endl;
    first.setWeight(80);
    cout << first.weight << endl;
    first.sleep();
    return 0;
}