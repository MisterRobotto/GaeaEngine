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

#include "Tile.h"
#include "Vector_2D.h"

class Map {
public:
    Map();
    Map(const Map& orig);
    virtual ~Map();
private:
    Vector_2D<Tile> m_map;
};

#endif /* MAP_H */

