//
// Created by manoel on 04/04/18.
//

#include "InputParser.hpp"

vector<btVector3> InputParser::positions = {btVector3( 25, 4, SIZE_DEPTH - 55 ),
                                            btVector3( 35, 4, 30 ),
                                            btVector3( 55, 4, 45 ),

                                            btVector3( SIZE_WIDTH - 15, 4, 55 ),
                                            btVector3( SIZE_WIDTH - 25, 4, SIZE_DEPTH - SIZE_DEPTH / 2.5 + 20 ),
                                            btVector3( SIZE_WIDTH - 55, 4, 85 )};

vector<btVector3> InputParser::angulations = {btVector3( 0, 90, 0 ),
                                              btVector3( 0, 90, 0 ),
                                              btVector3( 0, 90, 0 ),
                                              btVector3( 0, -140, 0 ),
                                              btVector3( 0, 90, 0 ),
                                              btVector3( 0, 90, 0 )};

btVector3 InputParser::positionBall = btVector3( 85, 0, 65 );

bool InputParser::useFile = false;

bool InputParser::parse(string path){

    ifstream file(path);
    if(!file.is_open()) return false;

    positions.clear(); angulations.clear();

    positions.resize(6);
    angulations.resize(6);

    useFile = true;

    int ang, x, y;

    for(int i=0 ; i<6 ; i++){
        file >> x; file >> y; file >> ang;

        positions[i] = btVector3(x, 4, y);
        angulations[i] = btVector3(0, ang, 0);
    }

    file >> x; file >> y;
    positionBall = btVector3(x, 0, y);

//    for(auto i : positions){
//        cout << i.x() << " " << i.z() << endl;
//    }
//
//    for(auto i : angulations){
//        cout << i.y() << endl;
//    }
//
//    cout << positionBall.x() << " " << positionBall.z() << endl;

    file.close();

    return true;
}