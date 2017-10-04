/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tile.h
 * Author: katsu
 *
 * Created on October 4, 2017, 11:49 AM
 */

#ifndef TILE_H
#define TILE_H

class Tile {
public:
    Tile();
    Tile(const Tile& orig);
    virtual ~Tile();
private:
    // Northwest (top-left) corner height
    int nw_height;
    // Northeast (top-right) corner height
    int ne_height;
    // Southwest (bottom-left) corner height
    int sw_height;
    // Southeast (bottom-right) corner height
    int se_height;
    // "Official" tile height, average of the other four
    int height;
};

#endif /* TILE_H */

