#include "Counter.h"
using namespace std;

Counter::Counter(int myValue)
    : value(myValue)
{
}

int Counter::getValue() const
{
    return value;
}

void Counter::increment()
{
    value++;
}

void Counter::decrement()
{
    value--;
}