#include <iostream>

#include "shapes/point.hpp"
#include "shapes/rectangle.hpp"

#include "shapes/color.hpp"

using namespace std;

void menu() {
    cout << "1 - Créer un dessin" << endl;
    cout << "2 - Quitter le programme" << endl;
}

void commands() {
    int command;

        menu();
        
        while(!(cin >> command)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valeur non valide" << endl;
        }

        switch (command)
        {
        case 1:
            cout << "Nice !";
            break;
        case 2:
            cout << "Bye !";
            return; 
        default:
            commands();
            break;
        }
}

int main() { 
    cout << colors[red];

    commands();
    return 1;
}