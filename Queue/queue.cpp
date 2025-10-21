#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<string> cards;
    int i = 0;
    
    do {
        cout << "Adding a card to the queue." << endl;
        
        // ADICIONAR cartões à fila
        string cardName;
        cout << "Enter card name: ";
        cin >> cardName;
        cards.push(cardName);
        
        i++;
    } while (i < 3);
    
    cout << "All cards added to the queue." << endl;
    
    while(!cards.empty()) {
        cout << "Removing card: " << cards.front() << endl;
        cards.pop();
    }
    
    return 0;
}