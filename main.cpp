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
        cout << "3 - Quitter le programme" << endl << "-> ";

        if (!(cin >> command)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valeur non valide" << endl << "-> ";
        }

        switch (command) {
        case 1:
            createADraw();
            break;
        case 2:
            cout << "Charger" << endl << endl;
            // TODO
            loadADraw();
            break;
        case 3:
            cout << "Quitter" << endl << endl;
            return;
        default:
            break;
        }

    } while (command != 3);

}

// Menu 2.1 (1 - Créer un dessin)
void createADraw() {

    int width, height;
    string name;

    cout << endl << endl << " || CRÉATION D'UN DESSIN ||" << endl << endl;

    width = getValueFromUser("Choisir une largeur de dessin :");
    height = getValueFromUser("Choisir une hauteur de dessin :");
    name = getStringFromUser("Choisir un nom pour le dessin :");

    Svg svg(width, height, name);

    vector<Rectangle *> rectangles;
    vector<Circle *> circles;
    vector<Stroke *> strokes;
    vector<Polygon *> polygons;

    vector<vector<Shape *> >shapes = {
        { rectangles.begin(), rectangles.end() },
        { circles.begin(), circles.end() },
        { strokes.begin(), strokes.end() },
        { polygons.begin(), polygons.end() }
    };

    svg.setShapes(shapes);

    drawEditor(svg);
}

// Menu 2.2 (2 - Charger un dessin)
void loadADraw() {
    /*
        Tu vas utiliser la fonction pour charger un objet Svg (avec getFile etc)
        Si le fichier est bien un fichier svg, on récupère toutes les infos avec
        la fonction de "Parser" et on stocke le tout dans un objet SVG et on appele
        la fonction drawEditor()
    */
}

// Menu 3.1 (Edition d'un dessin)
void drawEditor(Svg svg) {
    int command;

    cout << " || ÉDITION D'UN DESSIN ||" << endl << endl;

    do {
        cout << "1 - Créer une forme" << endl;
        cout << "2 - Afficher le contenu du dessin" << endl;
        cout << "3 - Fusionner avec un autre dessin" << endl;
        cout << "4 - Décaler tous les éléments d'un dessin" << endl;
        cout << "5 - Agrandir tous les éléments d'un dessin" << endl;
        cout << "6 - Sauvegarder le dessin" << endl;
        cout << "7 - Annuler" << endl << "-> ";

        if (!(cin >> command)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valeur non valide" << endl;
        }

        switch (command) {
        case 1: {
            cout << "Créer une forme" << endl << endl;
            createShape(svg.getShapes());
            break;
        }
        case 2:
            cout << "Afficher le dessin" << endl << endl;
            displayDraw(svg);
            break;
        case 3:
            cout << "Fusionner" << endl << endl;
            fusionDraw(svg);
            // TODO
            break;
        case 4:
            cout << "Décaler" << endl << endl;
            moveShapes(svg.getShapes());
            // TODO
            break;
        case 5:
            cout << "Agrandir" << endl << endl;
            upScaleShapes(svg.getShapes());
            // TODO
            break;
        case 6:
            cout << "Sauvegarder" << endl << endl;
            saveSvg(svg);
            // TODO
            break;
        case 7:
            cout << "Annuler" << endl << endl;
            // TODO
            // Demander à l'utilisateur si il est sur d'annuler
            return;
        default:
            break;
        }

    } while (command != 7);
    
}

// Menu 4.1 (1 - Créer une forme)
void createShape(vector<vector<Shape *> > &shapes) {
    int command;

    cout << " || CRÉATION D'UNE FORME ||" << endl << endl;

    do {
        cout << "1 - Créer un rectangle" << endl;
        cout << "2 - Créer un cercle" << endl;
        cout << "3 - Créer un segment" << endl;
        cout << "4 - Créer un polygone" << endl;
        cout << "5 - Annuler" << endl << "-> ";

        if (!(cin >> command)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valeur non valide" << endl;
        }

        switch (command) {
        case 1: {
            Rectangle *rectangle = createRectangle();
            shapes[0].push_back(rectangle);
            cout << "Rectangle ajouté !" << endl << endl;
            break;
        }
        case 2: {
            Circle *circle = createCircle();
            shapes[1].push_back(circle);
            cout << "Cercle ajouté !" << endl << endl;
            break;
        }
        case 3: {
            Stroke *stroke = createStroke();
            shapes[2].push_back(stroke);
            cout << "Segment ajouté !" << endl << endl;
            break;
        }
        case 4: {
            Polygon *polygon = createPolygon();
            shapes[3].push_back(polygon); 
            cout << "Polygone ajouté !" << endl << endl;
            break;
        }
        case 5:
            return;
        default:
            break;
        }

    } while(command < 0 && command > 5);
}

// Menu 4.1.1 (1 - Créer un rectangle)
Rectangle *createRectangle() {
    int x, y;
    int width, height;

    int stroke;
    Color strokeColor, fillColor;

    cout << endl << endl << " || CRÉATION D'UN RECTANGLE ||" << endl << endl;

    x = getValueFromUser("Choisir la coordonnée 'x' :");
    y = getValueFromUser("Choisir la coordonnée 'y' :");
    width = getValueFromUser("Choisir la largeur du rectangle :");
    height = getValueFromUser("Choisir la hauteur du rectangle :");
    stroke = getValueFromUser("Choisir la taille du tracé :");
    strokeColor = getColor("Choisissez la couleur du tracé :");
    fillColor = getColor("Choisissez la couleur de fond :");

    return new Rectangle(Point(x, y), width, height, stroke, strokeColor, fillColor);
}

// Menu 4.1.2 (2 - Créer un cercle)
Circle *createCircle() {
    int x, y;
    int radius;

    int stroke;
    Color strokeColor, fillColor;

    cout << endl << endl << " || CRÉATION D'UN CERCLE ||" << endl << endl;

    x = getValueFromUser("Choisir la coordonnée du point central 'x' :");
    y = getValueFromUser("Choisir la coordonnée du point central 'y' :");
    radius = getValueFromUser("Choisir la distance du rayon du cercle :");
    stroke = getValueFromUser("Choisissez la taille du tracé :");
    strokeColor = getColor("Choisissez la couleur du tracé :");
    fillColor = getColor("Choisissez la couleur de fond :");

    return new Circle(radius, Point(x, y), stroke, strokeColor, fillColor);
}

// Menu 4.1.3 (3 - Créer un segment)
Stroke *createStroke() {
    int firstPointX, firstPointY;
    int secondPointX, secondPointY;

    int stroke;
    Color strokeColor, fillColor;

    firstPointX = getValueFromUser("Choisir la coordonnée 'x' du premier point");
    firstPointY = getValueFromUser("Choisir la coordonnée 'y' du premier point");
    secondPointX = getValueFromUser("Choisir la coordonnée 'x' du second point");
    secondPointY = getValueFromUser("Choisir la coordonnée 'y' du second point");
    stroke = getValueFromUser("Choisissez la taille du tracé :");
    strokeColor = getColor("Choisissez la couleur du tracé :");
    fillColor = getColor("Choisissez la couleur de fond :");

    return new Stroke(Point(firstPointX, firstPointY), Point(secondPointX, secondPointY), stroke, strokeColor, fillColor);
}

// Menu 4.1.4 (4 - Créer un polygone)
Polygon *createPolygon() {
    int numbersOfPoints;
    vector<Point> points;

    int stroke;
    Color strokeColor, fillColor;
    
    numbersOfPoints = getValueFromUser("Choisir le nombres de points du polygone :");

    for (int i = 0; i < numbersOfPoints; i++) {
        int x, y;
        x = getValueFromUser("Choisir la coordonnée 'x' du point n°" + to_string(i+1) + ": ");
        y = getValueFromUser("Choisir la coordonnée 'y' du point n°" + to_string(i+1) + ": ");
        points.push_back(Point(x, y));
    }

    stroke = getValueFromUser("Choisissez la taille du tracé :");
    strokeColor = getColor("Choisissez la couleur du tracé :");
    fillColor = getColor("Choisissez la couleur de fond :");

    return new Polygon(numbersOfPoints, points, stroke, strokeColor, fillColor);
}

// Menu 4.2 (2 - Afficher le contenu d'un dessin)
void displayDraw(Svg svg) {
    cout << " || AFFICHAGE DU DESSIN ||" << endl << endl;
    cout << "Nom : " << svg.getName() << endl; 
    cout << "Largeur : " << svg.getWidth() << endl;
    cout << "Hauteur : " << svg.getHeight() << endl;
    cout << "Formes : {" << endl;
    for (int i = 0; i < svg.getShapes().size(); i++) {
        for (int j = 0; j < svg.getShapes()[i].size(); j++) {
            switch (i)
            {
            case 0: {
                Rectangle *rect = dynamic_cast<Rectangle*>(svg.getShapes()[0][j]);
                cout << "   < Rectangle > { " 
                << "x: \"" << rect->getPoint().getX()
                << "\", y: \"" << rect->getPoint().getY()
                << "\", largeur: \"" << rect->getWidth()
                << "\", hauteur: \"" << rect->getHeight()
                << "\", taille-contour: \"" << rect->getStroke()
                << "\", couleur-contour: \"" << rect->getStrokeColor().getString()
                << "\", couleur-fond: \"" << rect->getFillColor().getString()
                << "\" }" << endl;
                break;
            }
            case 1: {
                Circle *circle = dynamic_cast<Circle*>(svg.getShapes()[1][j]);
                cout << "   < Cercle > { " 
                << "x: \"" << circle->getCenter().getX()
                << "\", y: \"" << circle->getCenter().getY()
                << "\", rayon: \"" << circle->getRadius()
                << "\", taille-contour: \"" << circle->getStroke()
                << "\", couleur-contour: \"" << circle->getStrokeColor().getString()
                << "\", couleur-fond: \"" << circle->getFillColor().getString()
                << "\" }" << endl;
                break;
            }
            case 2: {
                Stroke *stroke = dynamic_cast<Stroke*>(svg.getShapes()[2][j]);
                cout << "   < Segment > { " 
                << "x1: \"" << stroke->getFirstPoint().getX()
                << "\", y1: \"" << stroke->getFirstPoint().getY()
                << "\", x2: \"" << stroke->getSecondPoint().getX()
                << "\", y2: \"" << stroke->getSecondPoint().getY()
                << "\", taille-contour: \"" << stroke->getStroke()
                << "\", couleur-contour: \"" << stroke->getStrokeColor().getString()
                << "\", couleur-fond: \"" << stroke->getFillColor().getString()
                << "\" }" << endl;
                break;
            }
            case 3: {
                Polygon *polygon = dynamic_cast<Polygon*>(svg.getShapes()[3][j]);
                cout << "   < Polygone > { " 
                << "Nombre de points: \"" << polygon->getNumbersOfPoints()
                << "\", Points: { \"" << endl;
                for (int k = 0; k < polygon->getPoints().size(); k++) {
                    cout << "       x" << k+1 << ": \"" << polygon->getPoints()[k].getX()
                    << "\", y" << k+1 << ": \"" << polygon->getPoints()[k].getY() << "\"" << endl; 
                }
                cout << "   }\"," << endl << "taille-contour: \"" << polygon->getStroke()
                << "\", couleur-contour: \"" << polygon->getStrokeColor().getString()
                << "\", couleur-fond: \"" << polygon->getFillColor().getString()
                << "\" }" << endl;
                break;
            }
            default:
                break;
            }
        }
    }
    cout << "Appuyez sur \"Entrée\" pour continuer..." << endl;
    fflush(stdin);
    while (getchar() != '\n');
}

// Menu 4.3 (3 - Fusionner avec un autre dessin)
void fusionDraw(Svg &svg) {
    /*
        On passe l'adresse du dessin (pour directement le modifier)
        On appelle la fonction pour importer un fichier SVG
        On le parse et on récupère les infos. Si le dessin est plus grand, on prend
        ses dimensions, on récupère ses "shapes"
        On boucle et on ajoute les shapes du dessin importé dans le dessin original 
    */
}

// Menu 4.4 (4 - Décaler tous les éléments du dessin)
void moveShapes(vector<vector<Shape *> > &shapes) {
    /*
        On passe l'adresse des formes (pour directement le modifier)
        On demande a l'utilisateur un point (x,y) qui va décaler les points
        On fait une boucle qui va modifier tous les points de chaque shapes
        (rectangle : x et y,
         cercle : centre,
         segment : les deux points,
         polygone : tous les points)
    */
}

// Menu 4.5 (5 - Agrandir tous les éléments du dessin)
void upScaleShapes(vector<vector<Shape *> > &shapes) {
    /*
        On passe l'adresse des formes (pour directement le modifier)
        On demande à l'utilisateur un facteur d'agrandissement (positif obligé)
        On fait une boucle qui va modifier les tailles de chaque shapes en multipliant par le facteur
        (rectangle : width et height,
         cercle : rayon,
         segment : les deux points (mais jsp comment),
         polygone : tous les points (mais jsp comment))
    */
}

void saveSvg(Svg svg) {
    /*
        On va créer un fichier.
        A l'aide d'une fonction qui va parser nos objets, on créer une string qui va
        faire le contenu du fichier.
        On prends en exemple le svg
    */
}

int getValueFromUser(string userMessage) {
    int value;
    cout << userMessage << endl << "-> ";
    while(!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valeur non valide" << endl << "-> ";
    }
    return value;
}

string getStringFromUser(string userMessage) {
    string value;
    cout << userMessage << endl << "-> ";
    cin.ignore();
    getline(cin, value);
    return value;
}

Color getColor(string userMessage) {
    int command;

    cout << userMessage << endl;

    do {

        cout << "1 - Rouge" << endl;
        cout << "2 - Bleu" << endl;
        cout << "3 - Vert" << endl;
        cout << "4 - Blanc" << endl;
        cout << "5 - Noir" << endl;
        cout << "6 - Transparent" << endl << "-> ";

        if (!(cin >> command)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valeur non valide" << endl << "-> ";
        }

        switch (command)
        {
        case 1:
            return Color::RED;
        case 2:
            return Color::BLUE;
        case 3:
            return Color::GREEN;
        case 4:
            return Color::WHITE;
        case 5:
            return Color::BLACK;
        case 6:
            return Color::TRANSPARENT;
        default:
            break;
        }

    } while(true);
}