/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tile.cpp
 * Author: katsu
 * 
 * Created on October 4, 2017, 11:49 AM
 */

#include "Tile.h"
#include <cmath>




/*********************\
 * Object Management *
\*********************/


/*
 * Name: Constructor(int, int, int, int)
 * Desc: Creates an object with the given heights
 * Prec: Four ints, the heights of each corner, in order:
 *              nw ; north-west ; top-left
 *              ne ; north-east ; top-right
 *              sw ; south-west ; bottom-left
 *              se ; south-east ; bottom-right
 * Post: Creates the object with the given corner heights and averaged height
 */
Tile::Tile(unsigned int nw, unsigned int ne, unsigned int sw, unsigned int se)
{
    // Set corner heights
    m_nw_height = nw;
    m_ne_height = ne;
    m_sw_height = sw;
    m_se_height = se;
    
    AverageHeight();
}


/*
 * Name: Copy Constructor
 * Desc: Creates an object as a copy of the given one
 * Prec: A Tile object
 * Post: Creates the object with the same state as the given one
 */
Tile::Tile(const Tile& orig)
{
}


/*
 * Name: Destructor
 * Desc: Destructs the object
 * Prec: None
 * Post: Destructs the object
 */
Tile::~Tile()
{
}




/*************\
 * Accessors *
\*************/


/*
 */
// First Accessor placeholder




/************\
 * Mutators *
\************/


/*
 * Name: Translate
 * Desc: Moves the entire tile up or down
 * Prec: An int, the distance to displace the tile
 * Post: Changes the heights by the given distance
 */
void Tile::Translate(int distance)
{
    m_nw_height += distance;
    m_ne_height += distance;
    m_sw_height += distance;
    m_se_height += distance;
    m_height += distance;
}


/*
 * Name: AverageHeight()
 * Desc: Sets the "official" height
 * Prec: None
 * Post: Sets the "official" height, currently as the average of the corners
 */
void Tile::AverageHeight()
{
    double avg = (m_nw_height + m_ne_height + m_sw_height + m_se_height)/4.0;
    m_height = round(avg);
}