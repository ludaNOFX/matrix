#include <iostream>
#include <limits>
#include "input_utils.h"

using namespace std;

int getValidInput()
{
    int input_number;
    cin >> input_number;

    while (cin.fail() || cin.get() != '\n' || input_number <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Введите значение повторно: ";
        cin >> input_number;
    }

    return input_number;
}