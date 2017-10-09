/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Map.cpp
 * Author: katsu
 * 
 * Created on October 4, 2017, 11:52 AM
 */

#include <stdlib.h>

#include "Map.h"




/***********************\
 * Non-Class Utilities *
\***********************/


/*
 * Name: getInts
 * Desc: Extracts the integers from a set
 * Prec: A string to extract from; four int references, the ints to extract to
 * Post: Extracts the integers from the string into the int references
 */
void getInts(std::string set, int &ne, int &nw, int &se, int &sw)
{
    int index = set.find_first_of(',');
    ne = atoi(set.substr(0,index).c_str());
    set = set.substr(index+1);
    index = set.find_first_of(',');
    nw = atoi(set.substr(0,index).c_str());
    set = set.substr(index+1);
    index = set.find_first_of(',');
    se = atoi(set.substr(0,index).c_str());
    set = set.substr(index+1);
    index = set.find_first_of(',');
    sw = atoi(set.substr(0,index).c_str());
}




/*********************\
 * Object Management *
\*********************/


Map::Map(std::string filename)
{
    std::fstream file;
    file.open(filename);
    
    char line_c[80];
    std::string line;
    std::vector< std::vector < Tile > > tiles;
    int ne, nw, se, sw;
    
    while(!file.eof())
    {
        std::vector< Tile > column;
        file.getline(line_c, 80);
        line = line_c;
        int open = line.find_first_of('[');
        int close = line.find_first_of(']');
        while(open != std::string::npos && close != std::string::npos)
        {
            std::string set = line.substr(open+1,close-1);
            line = line.substr(close+1);
            getInts(line, ne, nw, se, sw);
            Tile tile(ne, nw, se, sw);
            column.push_back(tile);
            open = line.find_first_of('[');
            close = line.find_first_of(']');
        }
        tiles.push_back(column);
    }
    
    m_map = new Vector_2D<Tile>(tiles, empty);
}

Map::Map(const Map& orig)
{
    
}

Map::~Map()
{
    
}




/*************\
 * Accessors *
\*************/


/*
 */
//...




/************\
 * Mutators *
\************/


/*
 */
//...