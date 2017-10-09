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

#include "Tile.h"



template <class T> class Vector_2D {
public:
    
    /*********************\
     * Object Management *
    \*********************/
    
    // Construct empty Vector_2D with given dimensions
    Vector_2D(unsigned int width, unsigned int height, T* empty_val)
    {
        // Set empty value member to the given empty value
        m_empty_val = empty_val;

        // For every column, add a new vector with {height} empty-value cells
        //      ie. make the contents a {height}x{width} table of empty-value cells
        for(int i = 0; i < width; i++)
            m_contents.push_back(new std::vector<T*>(height, empty_val));
    }
    // Construct Vector_2D with contents copied from given 2D vector
    Vector_2D(std::vector< std::vector < T > >, T* empty_val)
    {
        m_empty_val = empty_val;
    }
    // Copy constructor
    Vector_2D(const Vector_2D& orig)
    {
        
    }
    
    // Destructor
    virtual ~Vector_2D()
    {
        // Delete every column
        while(!m_contents.empty())
        {
            std::vector<T*> *column = m_contents.back();

            // Delete every cell
            while(!column->empty())
            {
                T* last = column->back();
                column->pop_back();
                delete last;
            }

            m_contents.pop_back();
            delete column;
        }
    }
    
    
    /*************\
     * Accessors *
    \*************/
    
    // Get the contents of a particular cell
    T Get(unsigned int x, unsigned int y)
    {
        return *(m_contents.at(x)->at(y));
    }
    
    // Get the width
    int Get_Width()
    {
        return m_width;
    }
    // Get the height
    int Get_Height()
    {
        return m_height;
    }

    
    
    /************\
     * Mutators *
    \************/
    
    // Add a given number of rows to the end
    void Add_Rows(unsigned int count)
    {
        // Add {count} empty cells to the end of every column
        for(int i = 0; i < m_width; i++)
            for(int j = 0; j < count; j++)
                m_contents.at(i)->push_back(m_empty_val);
    }
    // Insert a given number of rows at a given point
    void Insert_Rows(unsigned int index, unsigned int count)
    {
        // Insert {count} empty cells at {index} in every column
        for(int i = 0; i < m_width; i++)
            m_contents.at(i)->insert(index,count,m_empty_val);
    }
    
    // Add a given number of columns to the end
    void Add_Cols(unsigned int count)
    {
        // Add {count} columns of empty cells
        for(int i = 0; i < count; i++)
            m_contents.push_back(new std::vector<T*>(m_height,m_empty_val));
    }
    // Insert a given number of columns at a given point
    void Insert_Cols(unsigned int index, unsigned int count)
    {
        m_contents.insert(index, count, new std::vector<T*>(m_height, m_empty_val));
    }
    
    // Add a given number of rows AND columns to the end
    void Add_2D(unsigned int col_count, unsigned int row_count)
    {
        Add_Rows(row_count);
        Add_Cols(col_count);
    }
    // Insert a given number of rows AND columns at a given point
    void Insert_2D(unsigned int x, unsigned int y, unsigned int col_count,
            unsigned int row_count)
    {
        Insert_Rows(y,row_count);
        Insert_Cols(x,col_count);
    }
    
    // Set the contents of a particular cell
    void Set(unsigned int x, unsigned int y, const T &val)
    {
        m_contents.at(x)->at(y) = val;
    }
    
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

