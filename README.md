# svgCreator

g++ -std=c++11 main.cpp shapes/point.cpp shapes/shape.cpp shapes/circle.cpp shapes/polygon.cpp shapes/rectangle.cpp shapes/stroke.cpp shapes/color.cpp svg/svg.cpp -o main.o

// bool verifyComponent(std::ifstream infile){
//     int indexStartBracket = 0;
//     int indexEndBracket = 0;
//     while(true){ 
//         int position = indexEndBracket;
//         indexStartBracket = line.find_first_of("<", position);
//         indexEndBracket = line.find_first_of(">", position + 1);

//         cout << endl;
//         cout << "position :" << position << endl;
//         cout << "start : " << indexStartBracket << endl;
//         cout << "end : " << indexEndBracket << endl;
        
//         if(indexEndBracket == -1 && indexStartBracket == -1 && position != 0){
//             return true;
//         }

//         if(indexEndBracket == -1 || indexStartBracket == - 1 || indexStartBracket >= indexEndBracket){
//             return false;
//         }
//     }
// }

// bool verifyBeginSVG(std::string line){
//     bool isStrucOK = true;
//     int indexStart1C = 0; // <svg
//     int indexEnd1C = 0; // >
//     // int indexStart2C = 0; // </svg
//     // int indexEnd2C = 0; // >
//     while(true){
//         int position1C = indexEnd2C;
//         int position2C = indexEnd2C;
//         indexStart1C = line.find_first_of("<svg", position1C);
//         indexEnd1C = line.find_first_of(">", position1C + 1);

//         // position2C = indexEnd2C;
//         // indexStart2C = line.find_first_of("</svg", position2C);
//         // indexEnd2C = line.find_first_of(">", position2C + 1);
        
//         if(position1C != 0 && indexStart1C == -1 && indexEnd1C == -1 && indexStart2C == -1 && indexEnd2C == -1){
//             return isStrucOK;
//         }

//         if(indexStart1C == -1 || indexEnd1C == - 1 || indexStart1C >= indexEnd1C || indexStart2C == -1 || indexEnd2C == - 1 || indexStart2C >= indexEnd2C || indexStart2C >= indexStart1C){
//             return false;
//         }
//     }
// }