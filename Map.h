/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Map.h
 * Author: katsu
 *
 * Created on October 4, 2017, 11:52 AM
 */

#ifndef MAP_H
#define MAP_H

#include <string>
#include <fstream>
#include <vector>

#include "Tile.h"
#include "Vector_2D.h"

class Map {
public:
        
    /*********************\
     * Object Management *
    \*********************/
    
    // Construct map from given file
    Map(std::string filename);
    // Copy Constructor
    Map(const Map& orig);
    // Destructor
    virtual ~Map();
    
    
    
    /*************\
     * Accessors *
    \*************/
    
    //
    //...
    
    
    /************\
     * Mutators *
    \************/
    
    //
    //...
    
private:
    Vector_2D<Tile> *m_map;
    Tile *empty = new Tile(0,0,0,0);
};

#endif /* MAP_H */

