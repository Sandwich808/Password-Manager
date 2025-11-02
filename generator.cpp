#include "Generator.h"

#include <iostream>
#include <random>

using namespace std;

Generator() {

}

int seedGenerator() {
    random_device device;
    mt19937 mt(device());
    return mt();
}

int generate()
{
    int length = (abs(seedGenerator()) % 6) + 12;
    cout << length << "\n";
    string password = "";
    for (int i = 0; i < length; i++) {
        int seed = seedGenerator();
        int range = abs(seedGenerator()) % 4;
        string others = "!@#$^%&*()-_=+[]{}|;:.,?/'";
        char temp = 0;
        switch (range) { //Decides a range to pick from
        case 0:
            temp = (abs(seed) % 10) + 48; //0-9
            break;
        case 1:
            temp = (abs(seed) % 26) + 65; //lowercase
            break;
        case 2:
            temp = (abs(seed) % 26) + 97; //uppercase
            break;
        case 3:
            temp = others[(abs(seed) % others.length())];
            break;
        }
        password += temp;
    }
    cout << password << "\n";
}