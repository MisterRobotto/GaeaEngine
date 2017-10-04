/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector_2D.h
 * Author: katsu
 *
 * Created on October 4, 2017, 12:00 PM
 */

#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include <vector>



template <class T> class Vector_2D {
public:
    
    /*********************\
     * Object Management *
    \*********************/
    
    // Construct empty Vector_2D with given dimensions
    Vector_2D(unsigned int width, unsigned int height, T* empty_val);
    // Construct Vector_2D with contents copied from given 2D vector
    Vector_2D(std::vector< std::vector < T > >);
    // Copy constructor
    Vector_2D(const Vector_2D& orig);
    
    // Destructor
    virtual ~Vector_2D();
    
    
    /*************\
     * Accessors *
    \*************/
    
    // Get the contents of a particular cell
    T Get(unsigned int x, unsigned int y);
    
    // Get the width
    int Get_Width();
    // Get the height
    int Get_Height();
    
    
    /************\
     * Mutators *
    \************/
    
    // Add a given number of rows to the end
    void Add_Rows(unsigned int count);
    // Insert a given number of rows at a given point
    void Insert_Rows(unsigned int index, unsigned int count);
    
    // Add a given number of columns to the end
    void Add_Cols(unsigned int count);
    // Insert a given number of columns at a given point
    void Insert_Cols(unsigned int index, unsigned int count);
    
    // Add a given number of rows AND columns to the end
    void Add_2D(unsigned int col_count, unsigned int row_count);
    // Insert a given number of rows AND columns at a given point
    void Insert_2D(unsigned int x, unsigned int y, unsigned int col_count,
            unsigned int row_count);
    
private:
    // 2D Vector holding our contents
    std::vector< std::vector < T* >* > m_contents;
    // Dimensions
    int m_width;
    int m_height;
    // Value that an empty cell should be set to
    T *m_empty_val;
};

#endif /* VECTOR_2D_H */

