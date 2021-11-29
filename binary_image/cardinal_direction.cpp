#include"cardinal_direction.h"

istream& operator>> (istream& in, CardinalDirection& x)
{
    int val;

    if (in >> val) {
        switch (val) {
        case 1: case 3:
            x = CardinalDirection(val); break;
        default:
            throw out_of_range("Invalid value for type X");
        }
    }

    return in;
}
