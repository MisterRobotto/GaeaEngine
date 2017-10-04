/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector_2D.cpp
 * Author: katsu
 * 
 * Created on October 4, 2017, 12:00 PM
 */

#include "Vector_2D.h"


/*
 * Name: Constructor(int, int)
 * Desc: Creates an object with the given dimensions
 * Prec: Two unsigned ints representing the width and height; a T pointer
 *              representing the value to put in empty cells
 * Post: Creates the object as a {height}x{width} table of empty-value cells
 */
template <class T> Vector_2D<T>::Vector_2D(unsigned int width,
        unsigned int height, T *empty_val)
{
    // Set empty value member to the given empty value
    m_empty_val = empty_val;
    
    // For every column, add a new vector with {height} empty-value cells
    //      ie. make the contents a {height}x{width} table of empty-value cells
    for(int i = 0; i < width; i++)
        m_contents.push_back(new std::vector<T*>(height, empty_val));
}


/*
 * Name: Constructor(vector<vector<T>>)
 * Desc: Creates an object from the given 2D vector
 * Prec: A vector of vectors of T
 * Post: Creates the object with the contents of the given 2D vector
 */
template <class T> Vector_2D<T>::Vector_2D(std::vector< std::vector < T > >)
{
    // TODO
}


/*
 * Name: Copy Constructor
 * Desc: Creates an object as a copy of the given one
 * Prec: A Vector_2D object
 * Post: Creates the object with the same state as the given one
 */
template <class T> Vector_2D<T>::Vector_2D(const Vector_2D& orig)
{
    // TODO
}


/*
 * Name: Destructor
 * Desc: Destructs the object
 * Prec: None
 * Post: Destructs the object
 */
template <class T> Vector_2D<T>::~Vector_2D()
{
    // TODO
}


/*
 * Name: Gets
 * Desc: Gets the contents of a given cell
 * Prec: Two unsigned ints representing the cell's x and y coordinates
 * Post: Returns the contents of the given cell
 */
template <class T> T Vector_2D<T>::Get(unsigned int x, unsigned int y)
{
    return *(m_contents.at(x).at(y));
}


/*
 * Name: Get_Width
 * Desc: Returns current table width
 * Prec: None
 * Post: Returns m_width
 */
template <class T> int Vector_2D<T>::Get_Width()
{
    return m_width;
}


/*
 * Name: Get_Height
 * Desc: Returns current table height
 * Prec: None
 * Post: Returns m_height
 */
template <class T> int Vector_2D<T>::Get_Height()
{
    return m_height;
}


/*
 * Name: Add_Rows
 * Desc: Adds a given number of rows to the end of the table
 * Prec: An unsigned int, the number of rows to add
 * Post: Adds a given number of empty-value rows to the end of the table
 */
template <class T> void Vector_2D<T>::Add_Rows(unsigned int count)
{
    // Add {count} empty cells to the end of every column
    for(int i = 0; i < m_width; i++)
        for(int j = 0; j < count; j++)
            m_contents.at(i).push_back(m_empty_val);
}


/*
 * Name: Insert_Rows
 * Desc: Inserts a given number of rows at a given point
 * Prec: Two unsigned ints, the index at which to insert and how many
 * Post: Inserts a given number of empty-value rows at the given point
 */
template <class T> void Vector_2D<T>::Insert_Rows(unsigned int index,
        unsigned int count)
{
    // Insert {count} empty cells at {index} in every column
    for(int i = 0; i < m_width; i++)
        m_contents.at(i).insert(index,count,m_empty_val);
}


/*
 * Name: Add_Cols
 * Desc: Adds a given number of columns to the end of the table
 * Prec: An unsigned int, the number of columns to add
 * Post: Adds a given number of empty-value columns to the end of the table
 */
template <class T> void Vector_2D<T>::Add_Cols(unsigned int count)
{
    // Add {count} columns of empty cells
    for(int i = 0; i < count; i++)
        m_contents.push_back(new std::vector<T*>(m_height,m_empty_val));
}


/*
 * Name: Insert_Cols
 * Desc: Inserts a given number of columns at a given point
 * Prec: Two unsigned ints, the index at which to insert and how many
 * Post: Inserts a given number of empty-value columns at the given point
 */
template <class T> void Vector_2D<T>::Insert_Cols(unsigned int index,
        unsigned int count)
{
    m_contents.insert(index, count, new std::vector<T*>(m_height, m_empty_val));
}


/*
 * Name: Add_2D
 * Desc: Adds a given number of rows AND columns to the end of the table
 * Prec: Two unsigned ints; the number of columns and number of rows to add
 * Post: Adds a given number of empty-value columns and empty-value rows to the
 *              end of the table
 */
template <class T> void Vector_2D<T>::Add_2D(unsigned int col_count,
        unsigned int row_count)
{
    Add_Rows(row_count);
    Add_Cols(col_count);
}


/*
 * Name: Insert_2D
 * Desc: Inserts a given number of rows AND columns at a given point
 * Prec: Four unsigned ints; the coordinate at which to insert and the numbers
 *              of columns and rows to add,
 * Post: Adds a given number of empty-value columns and empty-value rows at the
 *              given point
 */
template <class T> void Vector_2D<T>::Insert_2D(unsigned int x, unsigned int y,
        unsigned int col_count,unsigned int row_count)
{
    Insert_Rows(y,row_count);
    Insert_Cols(x,col_count);
}