#include <iostream>
using namespace std;    

int main(){

    int month;
    cout << "Enter month number (1-12): ";
    cin >> month;

    switch(month){
        case 1:
            cout << "Ianurius (January)" << endl;
            break;
        case 2:
            cout << "Februarius (February)" << endl;
            break;
        case 3:
            cout << "Martius (March)" << endl;
            break;              
        case 4:
            cout << "Aprilis (April)" << endl;
            break;
        case 5:
            cout << "Maius (May)" << endl;
            break;
        case 6:
            cout << "Iunius (June)" << endl;
            break;
        case 7:
            cout << "Iulius (July)" << endl;
            break;
        case 8:
            cout << "Augustus (August)" << endl;
            break;
        case 9:
            cout << "September (September)" << endl;
            break;
        case 10:
            cout << "October (October)" << endl;
            break;
        case 11:
            cout << "November (November)" << endl;
            break;
        case 12:
            cout << "December (December)" << endl;
            break;
        default:
            cout << "Invalid month number!" << endl;
            break;
    }

    return 0;
}