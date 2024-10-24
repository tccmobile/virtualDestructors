#include <iostream>
using namespace std;

// First example: WITHOUT virtual destructor (problematic)
class Base1 {
public:
    Base1() {
        cout << "Base1 constructor called\n";
    }
    
    // Non-virtual destructor - This is problematic!
    ~Base1() {
        cout << "Base1 destructor called\n";
    }
};

class Derived1 : public Base1 {
private:
    int* data;
    
public:
    Derived1() {
        cout << "Derived1 constructor called\n";
        data = new int[100];  // Allocate some memory
    }
    
    ~Derived1() {
        cout << "Derived1 destructor called\n";
        delete[] data;  // Clean up memory
    }
};

// Second example: WITH virtual destructor (correct)
class Base2 {
public:
    Base2() {
        cout << "Base2 constructor called\n";
    }
    
    // Virtual destructor - This is the correct way!
    virtual ~Base2() {
        cout << "Base2 destructor called\n";
    }
};

class Derived2 : public Base2 {
private:
    int* data;
    
public:
    Derived2() {
        cout << "Derived2 constructor called\n";
        data = new int[100];  // Allocate some memory
    }
    
    ~Derived2() {
        cout << "Derived2 destructor called\n";
        delete[] data;  // Clean up memory
    }
};

void demonstrateMemoryLeak() {
    cout << "\nExample 1: Without virtual destructor (MEMORY LEAK!)\n";
    cout << "------------------------------------------------\n";
    Base1* ptr1 = new Derived1();  // Create object
    delete ptr1;  // Try to clean up - THIS WILL LEAK MEMORY!
    
    cout << "\nExample 2: With virtual destructor (CORRECT)\n";
    cout << "----------------------------------------\n";
    Base2* ptr2 = new Derived2();  // Create object
    delete ptr2;  // Clean up - This works correctly
}

int main() {
    demonstrateMemoryLeak();
    
    cout << "\nNow demonstrating stack-based cleanup:\n";
    cout << "------------------------------------\n";
    {
        // Stack-based objects (these work fine in both cases)
        Base1 b1;
        Derived1 d1;
        Base2 b2;
        Derived2 d2;
    }  // Objects are destroyed here
    
    return 0;
}
