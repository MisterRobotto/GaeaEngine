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
    
    /*********************\
     * Object Management *
    \*********************/
    
    // Construct a tile with given heights
    Tile(unsigned int nw, unsigned int ne, unsigned int sw, unsigned int se);
    // Copy Constructor
    Tile(const Tile& orig);
    // Destructor
    virtual ~Tile();
    
    
    /*************\
     * Accessors *
    \*************/
    
    //
    
    
    /************\
     * Mutators *
    \************/
    
    // Move the entire tile up or down
    void Translate(int distance);
    
private:
    
    /*************\
     * Functions *
    \*************/
    
    // Set the "official" tile height
    void AverageHeight();
    
    
    /********************\
     * Member Variables *
    \********************/
    
    // Northwest (top-left) corner height
    unsigned int m_nw_height;
    // Northeast (top-right) corner height
    unsigned int m_ne_height;
    // Southwest (bottom-left) corner height
    unsigned int m_sw_height;
    // Southeast (bottom-right) corner height
    unsigned int m_se_height;
    // "Official" tile height, average of the other four
    unsigned int m_height;
    
    // TODO: figure out how we're doing textures
};

#endif /* TILE_H */

