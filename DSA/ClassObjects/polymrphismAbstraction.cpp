#include <iostream>
using namespace std;   
class A {
    public:
    void sayHello() {
        cout << "Hello from class A" << endl;
    }
    int sayHello(string name, int n) {
        cout << "Hello from class A" << endl;
        cout << name << endl;
        return 1;  
    }
    void sayHello(string name) {
        cout << "Hello from class B" << endl << name << endl;
    }
};
class B {
    public:
    int a;
    int b;
    public:
    int add() {
        return a + b;
    }
    void operator+ (B &obj) {
        int value1 = this->a;
        int value2 = obj.a;
        cout << "Output" << value2-value1 << endl;
    }
    void operator() () {
        cout << "Mai bracket hu " << this->a << endl;
    }
};
class animal {
    public:
    void speak() {
        cout << "Animal speaking" << endl;
    }
};
class dog : public animal {
    public:
    void speak() {
        cout << "Dog barking" << endl;
    }
};
int main() {
    A object;
    string name = "Rajnikant";
    object.sayHello(name);
    //operator overloading
    B obj1, obj2;
    obj1.a = 10;
    obj2.a = 20;
    obj1+obj2;
    obj1 ();
    //runtime polymorphism
    dog obj;
    obj.speak();
    return 0;
}