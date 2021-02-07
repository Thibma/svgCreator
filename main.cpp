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
    std::string filename;
    bool menu = true;

    do{
        cout << "Veuillez sélectionner un fichier .svg" << endl << "-> ";

        if (!(cin >> filename)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valeur non valide" << endl << "-> ";
        }

        menu = filename.find(".svg") == std::string::npos;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valeur non valide" << endl << "-> ";
    } while(menu);   

    Svg svg = parser(filename);
    drawEditor(svg);
}

Svg parser(std::string filename) {
    std::ifstream infile(filename);
    std::string line;
    vector<Rectangle *> rectangles;
    vector<Circle *> circles;
    vector<Polygon *> polygons;
    vector<Stroke *> strokes;
    
    try{
        if(!std::getline(infile, line) || !verifyStartFile(line)){
            throw "Fichier illisible";
        }
        Svg svg = getSvgFromLine(line, filename);

        while (std::getline(infile, line))
        {
            std::cout << line << std::endl;
            std::istringstream iss(line);

            try {
                if(isComponent(line, "rect")){
                    Rectangle *rectangle = getRectangleFromLine(line);
                    rectangles.push_back(rectangle);
                }          

                if(isComponent(line, "circle")){
                    Circle *circle = getCircleFromLine(line);
                    circles.push_back(circle);
                }   

                if(isComponent(line, "polygon")){
                    Polygon *polygon = getPolygonFromLine(line);
                    polygons.push_back(polygon);
                }

                if(isComponent(line, "line")){
                    Stroke *stroke = getStrokeFromLine(line);
                    strokes.push_back(stroke);
                }

            } catch(const char* e){
                std::cout << e << endl;
            }
        }

        vector<vector<Shape *> >shapes = {
            { rectangles.begin(), rectangles.end() },
            { circles.begin(), circles.end() },
            { strokes.begin(), strokes.end() },
            { polygons.begin(), polygons.end() }
        };

        svg.setShapes(shapes);
        displayDraw(svg);
        return svg;
    
    } catch(const char *e){
        std::cout << e << endl;
    }
}

Svg getSvgFromLine(std::string line, std::string name){
    int width = getIntProperty(line, "width");
    if(!width) throw "Width missing";

    int height = getIntProperty(line, "height");
    if(!height) throw "Height missing";

    return Svg(width, height, name);
}

Rectangle *getRectangleFromLine(std::string line){
    int width = getIntProperty(line, "width");
    if(!width) throw "Width missing";

    int height = getIntProperty(line, "height");
    if(!height) throw "Height missing";

    int x = getIntProperty(line, "x");
    if(!x) throw "X missing";

    int y = getIntProperty(line, "y");   
    if(!y) throw "Y missing";

    int strokeWidth = getIntProperty(line, "stroke-width");    
    if(!strokeWidth) throw "Stroke Width missing";

    Color stroke = getColorFromLine(line, "stroke");
    Color fill = getColorFromLine(line, "fill");

    return new Rectangle(Point(x, y), width, height, strokeWidth, stroke, fill);
}

Circle *getCircleFromLine(std::string line){
    int r = getIntProperty(line, "r");
    if(!r) throw "Radius missing";

    int x = getIntProperty(line, "cx");
    if(!x) throw "X missing";

    int y = getIntProperty(line, "cy");
    if(!y) throw "Y missing";

    int strokeWidth = getIntProperty(line, "stroke-width");    
    if(!strokeWidth) throw "Stroke Width missing";
    
    Color stroke = getColorFromLine(line, "stroke");
    Color fill = getColorFromLine(line, "fill");

    return new Circle(r, Point(x, y), strokeWidth, stroke, fill);
}

Polygon *getPolygonFromLine(std::string line){
    vector<Point> points = getPointsFromLine(line);
    int strokeWidth = getIntProperty(line, "stroke-width");    
    if(!strokeWidth) throw "Stroke Width missing";

    Color stroke = getColorFromLine(line, "stroke");
    Color fill = getColorFromLine(line, "fill");

    return new Polygon(points.size(), points, strokeWidth, stroke, fill);
}

Stroke *getStrokeFromLine(std::string line){
    int x1 = getIntProperty(line, "x1");
    if(!x1) throw "Stroke Width missing";

    int y1 = getIntProperty(line, "y1");
    if(!y1) throw "Stroke Width missing";

    int x2 = getIntProperty(line, "x2");
    if(!x2) throw "Stroke Width missing";

    int y2 = getIntProperty(line, "y2");
    if(!y2) throw "Stroke Width missing";

    int strokeWidth = getIntProperty(line, "stroke-width");    
    if(!strokeWidth) throw "Stroke Width missing";

    Color stroke = getColorFromLine(line, "stroke");
    Color fill = getColorFromLine(line, "fill"); 

    return new Stroke(Point(x1, y1), Point(x2, y2), strokeWidth, stroke, stroke);
}

vector<Point> getPointsFromLine(std::string line){
    vector<Point> points;
    vector<std::string> strPoints;
    std::string toFindStart = " points=\"";
    std::size_t start = line.find(toFindStart);
    std::size_t end = line.find('"', toFindStart.size() + start);

    std::string property = line.substr(start + toFindStart.size(), end - start - 1 - toFindStart.size());
    start = 0;
    end = 0;
    while(true){
        if(start==std::string::npos) break;
        end = property.find(" ", start );

        if(end==std::string::npos){
            std::string point = property.substr(start);
            strPoints.push_back(point);
            break;
        }

        std::string point = property.substr(start, end - start);
        strPoints.push_back(point);
        start = end + 1;
    }

    for (vector<string>::iterator strPoint = strPoints.begin(); strPoint != strPoints.end(); ++strPoint)
    {
        std::size_t indexX = (*strPoint).find(",");
        std::string strX = (*strPoint).substr(0, indexX);
        std::string strY = (*strPoint).substr(indexX).substr(1);

        int x = std::stoi(strX);
        int y = std::stoi(strY);
        points.push_back(Point(x, y));
    }

    return points;
}

Color getColorFromLine (std::string line, std::string property){
    std::string strColor = getProperty(line, property); 
    std::size_t index = strColor.find('"');
    if(index == std::string::npos) {
        strColor = strColor.substr(0, strColor.size()-1);
    }

    Color color (strColor);
    return color;
}

int getIntProperty(std::string line, std::string property){
    std::string strValue = getProperty(line, property); 
    if(strValue == "") return NULL;

    return std::stoi(strValue);;
}

bool verifyStartFile(std::string line){
    std:string startComponent = "<svg ";
    int position = 0;

    while(true){
        int indexStartBracket = 0;
        int indexEndBracket = 0;

        indexStartBracket = line.find_first_of("<svg ", position);
        indexEndBracket = line.find_first_of(">", position + 1);
        // récupérer hauteur, width, largeur
        
        if(indexEndBracket == -1 && indexStartBracket == -1 && position != 0){
            return true;
        }

        if(indexEndBracket == -1 || indexStartBracket == - 1 || indexStartBracket >= indexEndBracket){
            return false;
        }

        position = indexEndBracket;
    }
}

std::string getProperty(std::string line, std::string property){
    std::string toFindStart = " " + property + "=\"";

    std::size_t start = line.find(toFindStart);
    if(start==std::string::npos){ return ""; }

    std::size_t end = line.find('"', start);
    if(end==std::string::npos){ return ""; }

    std::string result = line.substr(start + toFindStart.size(), end - start - 1);
    return result;
}

bool isComponent(std::string line, std::string component){
    std:string startComponent = "<" + component + " ";
    std::string endComponent = "/>";
    int position = 0;

    while(true){
        int indexStartBracket = 0;
        int indexEndBracket = 0;

        indexStartBracket = line.find(startComponent, position);
        indexEndBracket = line.find(endComponent, position + 1);

        bool isValid = (indexEndBracket != -1 && indexStartBracket != -1 && indexStartBracket >= indexEndBracket) || indexEndBracket == -1 && indexStartBracket == -1 && position != 0;
        bool isError = indexEndBracket == -1 || indexStartBracket == - 1 || indexStartBracket >= indexEndBracket;
        if(isValid){ return true; }
        if(isError){ return false; }

        position = indexEndBracket;
    }
    return true;
}

bool verifyBrackets(std::string line, std::string component){
    std:string startComponent = "<" + component + " ";
    std::string endComponent = component == "svg" ? "svg>" : "/>";
    int position = 0;

    while(true){
        int indexStartBracket = 0;
        int indexEndBracket = 0;

        indexStartBracket = line.find_first_of(startComponent, position);
        indexEndBracket = line.find_first_of(endComponent, position + 1);
        
        if(indexEndBracket == -1 && indexStartBracket == -1 && position != 0){
            return true;
        }

        if(indexEndBracket == -1 || indexStartBracket == - 1 || indexStartBracket >= indexEndBracket){
            return false;
        }

        position = indexEndBracket;
    }
}

bool getComponent(std::string line, string component){
    std:string startComponent = "<" + component;
    std::string endComponent = component == "svg" ? "svg>" : "/>";
    int position = 0;

    while(true){
        int indexStartBracket = line.find_first_of(startComponent, position);
        int indexEndBracket = line.find_first_of(endComponent, position + 1);
        
        if(indexEndBracket == -1 && indexStartBracket == -1 && position != 0){
            return true;
        }

        if(indexEndBracket == -1 || indexStartBracket == - 1 || indexStartBracket >= indexEndBracket){
            return false;
        }

        position = indexEndBracket;
    }
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
            return;
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
    cout << endl << endl << " || MOVE SHAPES ||" << endl << endl;

    int value = getValueFromUser("Choisir la valeur de déplacement :");

    vector<Rectangle>rectangles;
    vector<Circle>circles;
    vector<Stroke> strokes;
    vector<Polygon>polygons;;


//    for (int i = 0; i < shapes.size(); i++) {
//         for (int j = 0; j < shapes[i].size(); j++) {
//             switch (i)
//             {
//             case 0: {
//                 Rectangle *rect = dynamic_cast<Rectangle*>(shapes[0][i]);
//                 Rectangle result = Rectangle(rect->getPoint(), rect->getWidth(), rect->getHeight(), rect->getStroke(), rect->getStrokeColor(), rect->getFillColor()) + value;
//                 rectangles.push_back(result);
//                 break;
//             }
//             case 1: {
//                 Circle *circle = dynamic_cast<Circle*>(shapes[1][j]);
//                 Circle result = Circle(circle->getRadius(), circle->getCenter(), circle->getStroke(), circle->getStrokeColor(), circle->getFillColor()) + value;
//                 circles.push_back(result);
//             }
//             case 2: {
//                 Stroke *stroke = dynamic_cast<Stroke*>(shapes[2][j]);
//                 Stroke result = Stroke(stroke->getFirstPoint(), stroke->getSecondPoint(), stroke->getStroke(), stroke->getStrokeColor(), stroke->getFillColor()) + value;
//                 strokes.push_back(result);
//                 break;
//             }
//             case 3: {
//                 Polygon *polygon = dynamic_cast<Polygon*>(shapes[3][j]);
//                 // Polygon result = Polygon(polygon->getNumbersOfPoints(), polygon->getPoints(), polygon->getStroke(), polygon->getStrokeColor(), polygon->getFillColor()) + value;
//                 polygons.push_back(*polygon);
//                 break;
//             }
//             default:
//                 break;
//             }
//         }
//     }

    vector<vector<Shape *>>sh = {
        { rectangles.begin(), rectangles.end() },
        { circles.begin(), circles.end() },
        { strokes.begin(), strokes.end() },
        { polygons.begin(), polygons.end() }
    };

    
    // shapes = sh;
        cout << "Appuyez sur \"Entrée\" pour continuer..." << endl;
    fflush(stdin);
    while (getchar() != '\n');
}

// Menu 4.5 (5 - Agrandir tous les éléments du dessin)
void upScaleShapes(vector<vector<Shape *>> &shapes) {
    cout << endl << endl << " || UPSCALE ||" << endl << endl;

    int multi = getValueFromUser("Choisir la valeur d'upscale :");

    vector<Rectangle>rectangles;
    vector<Circle>circles;
    vector<Stroke> strokes;
    vector<Polygon>polygons;;


//    for (int i = 0; i < shapes.size(); i++) {
//         for (int j = 0; j < shapes[i].size(); j++) {
//             switch (i)
//             {
//             case 0: {
//                 Rectangle *rect = dynamic_cast<Rectangle*>(shapes[0][i]);
//                 Rectangle result = Rectangle(rect->getPoint(), rect->getWidth(), rect->getHeight(), rect->getStroke(), rect->getStrokeColor(), rect->getFillColor()) * multi;
//                 rectangles.push_back(result);
//                 break;
//             }
//             case 1: {
//                 Circle *circle = dynamic_cast<Circle*>(shapes[1][j]);
//                 Circle result = Circle(circle->getRadius(), circle->getCenter(), circle->getStroke(), circle->getStrokeColor(), circle->getFillColor()) * multi;
//                 circles.push_back(result);
//             }
//             case 2: {
//                 Stroke *stroke = dynamic_cast<Stroke*>(shapes[2][j]);
//                 Stroke result = Stroke(stroke->getFirstPoint(), stroke->getSecondPoint(), stroke->getStroke(), stroke->getStrokeColor(), stroke->getFillColor()) * multi;
//                 strokes.push_back(result);
//                 break;
//             }
//             case 3: {
//                 Polygon *polygon = dynamic_cast<Polygon*>(shapes[3][j]);
//                 // Polygon result = Polygon(polygon->getNumbersOfPoints(), polygon->getPoints(), polygon->getStroke(), polygon->getStrokeColor(), polygon->getFillColor()) * multi;
//                 polygons.push_back(*polygon);
//                 break;
//             }
//             default:
//                 break;
//             }
//         }
//     }

    vector<vector<Shape *>>sh = {
        { rectangles.begin(), rectangles.end() },
        { circles.begin(), circles.end() },
        { strokes.begin(), strokes.end() },
        { polygons.begin(), polygons.end() }
    };

    
    // shapes = sh;
    cout << "Appuyez sur \"Entrée\" pour continuer..." << endl;
    fflush(stdin);
    while (getchar() != '\n');
}

void saveSvg(Svg svg) {
    cout << " || SAUVEGARDE DU DESSIN ||" << endl << endl;
    cout << "Sauvegarde en cours..." << endl;
    string dataOut;
    dataOut.append("<?xml version=\"1.0\" standalone=\"no\"?>\n");
    dataOut.append("<svg width=\"" + to_string(svg.getWidth()) + "\" height=\"" + to_string(svg.getHeight()) + "\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n");
    for (int i = 0; i < svg.getShapes().size(); i++) {
        for (int j = 0; j < svg.getShapes()[i].size(); j++) {
            switch (i)
            {
            case 0: {
                Rectangle *rect = dynamic_cast<Rectangle*>(svg.getShapes()[0][j]);
                dataOut.append("  <rect x=\"" + to_string(rect->getPoint().getX()) + 
                "\" y=\"" + to_string(rect->getPoint().getY()) +
                "\" width=\"" + to_string(rect->getWidth()) + 
                "\" height=\"" + to_string(rect->getHeight()) +
                "\" stroke=\"" + rect->getStrokeColor().getString() +
                "\" fill=\"" + rect->getFillColor().getString() +
                "\" stroke-width=\"" + to_string(rect->getStroke()) + "\"/>\n");
                break;
            }
            case 1: {
                Circle *circle = dynamic_cast<Circle*>(svg.getShapes()[1][j]);
                dataOut.append("  <circle cx=\"" + to_string(circle->getCenter().getX()) + 
                "\" cy=\"" + to_string(circle->getCenter().getY()) +
                "\" r=\"" + to_string(circle->getRadius()) + 
                "\" stroke=\"" + circle->getStrokeColor().getString() +
                "\" fill=\"" + circle->getFillColor().getString() +
                "\" stroke-width=\"" + to_string(circle->getStroke()) + "\"/>\n");
                break;
            }
            case 2: {
                Stroke *stroke = dynamic_cast<Stroke*>(svg.getShapes()[2][j]);
                dataOut.append("  <line x1=\"" + to_string(stroke->getFirstPoint().getX()) + 
                "\" x2=\"" + to_string(stroke->getSecondPoint().getX()) +
                "\" y1=\"" + to_string(stroke->getFirstPoint().getY()) + 
                "\" y2=\"" + to_string(stroke->getSecondPoint().getY()) +
                "\" stroke=\"" + stroke->getStrokeColor().getString() +
                "\" fill=\"" + stroke->getFillColor().getString() +
                "\" stroke-width=\"" + to_string(stroke->getStroke()) + "\"/>\n");
                break;
            }
            case 3: {
                Polygon *polygon = dynamic_cast<Polygon*>(svg.getShapes()[3][j]);
                dataOut.append("  <polygon points=\"");
                for (int k = 0; k < polygon->getPoints().size(); k++) {
                    dataOut.append(to_string(polygon->getPoints()[k].getX()) + " " + to_string(polygon->getPoints()[k].getY()));
                    if (k < polygon->getPoints().size() - 1) {
                        dataOut.append(" ");
                    }
                }
                dataOut.append("\" stroke=\"" + polygon->getStrokeColor().getString() +
                "\" fill=\"" + polygon->getFillColor().getString() +
                "\" stroke-width=\"" + to_string(polygon->getStroke()) + "\"/>\n");
                break;
            }
            default:
                break;
            }
        }
    }
    dataOut.append("</svg>");

    ofstream outFile(svg.getName() + ".svg");
    outFile << dataOut << endl;
    outFile.close();
    cout << "Sauvegarde terminée !" << endl;
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