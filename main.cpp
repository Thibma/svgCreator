#include "main.hpp"

int main() {
    firstMenu();
    return 1;
}

// Menu n°1 (at start of the app)
void firstMenu() {
    int command;

    //cout << endl << endl << " || SVG CREATOR - By Thibault BALSAMO & Sophie Pelluet ||" << endl << endl;

    do {

        cout << endl << endl << " || SVG CREATOR - By Thibault BALSAMO & Sophie Pelluet ||" << endl << endl;
        
        cout << "1 - Créer un dessin" << endl;
        cout << "2 - Charger un dessin" << endl;
        cout << "3 - Afficher le contenu d'un dessin" << endl;
        cout << "4 - Quitter le programme" << endl;

        if (!(cin >> command)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valeur non valide" << endl;
        }

        switch (command) {
        case 1:
            createADraw();
            break;
        case 2:
            cout << "Charger" << endl << endl;
            break;
        case 3:
            cout << "Afficher" << endl << endl;
            break;
        case 4:
            cout << "Quitter" << endl << endl;
            return;
        default:
            break;
        }

    } while (command != 4);

}

// Menu 2.1 (1 - Créer un dessin)
void createADraw() {

    int width, height;
    string name;

    cout << endl << endl << " || CRÉATION D'UN DESSIN ||" << endl << endl;

    cout << "Choisir une largeur de dessin :" << endl;
    while(!(cin >> width)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valeur non valide" << endl;
    }

    cout << "Choisir une hauteur de dessin :" << endl;
    while(!(cin >> height)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valeur non valide" << endl;
    }

    cout << "Choisir un nom pour le dessin :" << endl;
    cin >> name;

    Svg svg(width, height, name);
    drawEditor(svg);
}

// Menu 3.1 (Edition d'un dessin)
void drawEditor(Svg svg) {
    int command;

    cout << " || ÉDITION D'UN DESSIN ||";

    do {
        cout << "1 - Créer une forme" << endl;
        cout << "2 - Afficher le contenu du dessin" << endl;
        cout << "3 - Fusionner avec un autre dessin" << endl;
        cout << "4 - Décaler tous les éléments d'un dessin" << endl;
        cout << "5 - Agrandir tous les éléments d'un dessin" << endl;
        cout << "6 - Sauvegarder le dessin" << endl;
        cout << "7 - Annuler" << endl;

        if (!(cin >> command)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valeur non valide" << endl;
        }

        switch (command) {
        case 1: {
            cout << "Créer une forme" << endl << endl;
            Shape shape = createShape();
            break;
        }
        case 2:
            cout << "Afficher" << endl << endl;
            break;
        case 3:
            cout << "Fusionner" << endl << endl;
            break;
        case 4:
            cout << "Décaler" << endl << endl;
            break;
        case 5:
            cout << "Agrandir" << endl << endl;
            break;
        case 6:
            cout << "Sauvegarder" << endl << endl;
            break;
        case 7:
            cout << "Annuler" << endl << endl;
            return;
        default:
            break;
        }

    } while (command != 7);
    
}

// Menu 4.1 (1 - Créer une forme)
Shape createShape() {
    int command;

    cout << " || CRÉATION D'UNE FORME ||";

    do {
        cout << "1 - Créer un rectangle" << endl;
        cout << "2 - Créer un cercle" << endl;
        cout << "3 - Créer un segment" << endl;
        cout << "4 - Créer un polygone" << endl;
        cout << "5 - Annuler" << endl;

        if (!(cin >> command)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valeur non valide" << endl;
        }

        switch (command) {
        case 1:
            cout << "Rectangle" << endl << endl;
            break;
        case 2:
            cout << "Cercle" << endl << endl;
            break;
        case 3:
            cout << "Segment" << endl << endl;
            break;
        case 4:
            cout << "Polygone" << endl << endl;
            break;
        case 5:
            cout << "Annuler" << endl << endl;
            return;
        default:
            break;
        }

    } while(command != 5);
}