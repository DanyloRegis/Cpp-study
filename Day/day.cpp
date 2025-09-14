#include <iostream>
using namespace std;

enum Day { Sanyday = 0, Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6 };   

int main(){

    Day today = Wednesday;

    switch(today) {
        case Sanyday:
            cout << "It's Sanyday!" << endl;
            break;
        case Monday:
            cout << "It's Monday!" << endl;
            break;
        case Tuesday:
            cout << "It's Tuesday!" << endl;
            break;
        case Wednesday:
            cout << "It's Wednesday!" << endl;
            break;
        case Thursday:
            cout << "It's Thursday!" << endl;
            break;
        case Friday:
            cout << "It's Friday!" << endl;
            break;
        case Saturday:
            cout << "It's Saturday!" << endl;
            break;
        default:
            cout << "Invalid day!" << endl;
    }
    return 0;
}
