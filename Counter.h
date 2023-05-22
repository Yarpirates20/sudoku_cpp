#ifndef COUNTER_H
#define COUNTER_H

using namespace std;
class Counter
{
    // Functions and variables that can be called from code not part of class
    // Specifies interface of class
public:
    // Function with same name, no return value
    // Called whenever an object of this class is instantiated
    Counter(int myValue); // constructor
    // Returns variable for which direct access is not allowed from outside
    // const at end means function does not modify the object
    int getValue() const; // getter function
    // Modifies object, increment value of internal int by 1
    void increment();
    void decrement();

private:
    int value;
};

#endif // COUNTER_H