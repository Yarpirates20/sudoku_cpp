#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <iterator>
#include <fstream>
#include <cstdio>
#include <algorithm>
// #include "Counter.h"
// #include "Cell.h"
using namespace std;

// #### CELL CLASS DEFINITION #####
class Cell
{
    public:
        Cell();
        bool onlyOne() const;
        int getOne() const;
        bool valid() const;
        bool eliminate(int i);
        vector<int> get() const;
        void setValue(int i);
        bool has(int i) const;
        int count() const;


    private:
        std::vector<int> values;
};

// CELL METHODS
// Contructor: populates each Cell with a vector of the digits 1-9
Cell::Cell()
{
    values = {1, 2, 3, 4, 5, 6, 7, 8, 9};
}

// Returns true if values only has one element
bool Cell::onlyOne() const
{
    return values.size() == 1;
}

// Returns the value of the single element if values has only one, else throws exception
int Cell::getOne() const
{
    if (!onlyOne())
    {
        throw std::runtime_error("getOne() called but multiple values exist");
    }
    return *values.begin();
}

//Clears values vector first, then adds given integer i
void Cell::setValue(int i)
{
    values.clear();
    values.push_back(i);

}

// Returns true if values isn't empty (thus invalid)
bool Cell::valid() const 
{
    return values.size() != 0;
}

// Returns size of vector values
int Cell::count() const
{
    return values.size();
}

// Removes parameter i from values vector
bool Cell::eliminate(int i)
{
    values.erase(std::remove(values.begin(), values.end(), i), values.end());
    return valid();

}

// Returns all the elements of values
vector<int> Cell::get() const 
{
    return values;
}

// Returns true if values vector has paramter i
bool Cell::has(int i) const
{
    return std::find(values.begin(), values.end(), i) != values.end();
}


/* #### PUZZLE CLASS DEFINITION #### */
class Puzzle 
{
    public:
        Puzzle();
        bool solved() const;

    private:
        std::array<Cell, 81> cells;
};

// Puzzle Methods
/* Puzzle constructor needs no contents as default Cell constructor initialises cell */
Puzzle::Puzzle()
{
}

// Checks whether all cells have only one number, and only return true if that is the case (thus should initially be false)
bool Puzzle::solved() const
{
    for (auto& p : cells)
    {
        if(!p.onlyOne())
        {
            return false;
        }
        return true;
    }

    return ;
}


/* #### MAIN #### */
int main()
{
    Cell c1;

    cout << c1.count() << "\n";
    bool ret = c1.eliminate(7);
    cout << c1.count() << "\n";
    cout << ret << "\n";

    c1.setValue(3);
    cout << c1.count() << "\n";
    cout << c1.valid() << "\n";
    cout << c1.onlyOne() << "\n";

    auto values = c1.get();
    for(const auto& v : values)
    {
        cout << v << "\n";
    }

    return 0;
}

/* Counter
    cout << c1 << endl;
    Counter a(3);
    a.increment();
    std::cout << a.getValue() << "\n";
    Counter b(12);
    std::cout << b.getValue() << "\n";
    Counter c(6);
    c.decrement();
    cout << c.getValue() << "\n"; */