/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camera.cpp
 * Author: ConnorFlynn
 * 
 * Created on October 8, 2017, 3:52 PM
 */

#include "Camera.h"




/*********************\
 * Object Management *
\*********************/


/*
 * Name: Default Constructor
 * Desc: Creates an object with default values
 * Prec: None
 * Post: Creates an object with default values
 */
Camera::Camera()
{
    // Set default location info
    m_angle = 0.f;
    m_pitch = 45.f;
    m_dist = 20;
    
    // Set deltas to zero
    m_angle_delta = 0.f;
    m_pitch_delta = 0.f;
    m_dist_delta = 0;
}


/*
 * Name: Copy Constructor
 * Desc: Creates an object from an existing object
 * Prec: An existing Camera object
 * Post: Creates an object with the same state as the given object
 */
Camera::Camera(const Camera& orig)
{
    
}


/*
 * Name: Destructor
 * Desc: Destroys the object
 * Prec: None
 * Post: Destroys the object
 */
Camera::~Camera()
{
    
}




/*************\
 * Accessors *
\*************/


/*
 * Name: Get_Angle
 * Desc: Gets the camera's angle
 * Prec: None
 * Post: Returns m_angle
 */
float Camera::Get_Angle()
{
    return m_angle;
}


/*
 * Name: Get_Pitch
 * Desc: Gets the camera's pitch
 * Prec: None
 * Post: Returns m_pitch
 */
float Camera::Get_Pitch()
{
    return m_pitch;
}


/*
 * Name: Get_Dist
 * Desc: Gets the camera's distance from the camera focus
 * Prec: None
 * Post: Returns m_dist
 */
int Camera::Get_Dist()
{
    return m_dist;
}




/************\
 * Mutators *
\************/


/*
 * Name: Rotate
 * Desc: Rotates the camera around the focus by a specific amount
 * Prec: Two floats, the amount too rotate by and the amount of time to do it in
 * Post: Sets m_angle_delta and m_angle_time
 */
void Camera::Rotate(float angle, float time)
{
    
}


/*
 * Name: Rotate_To
 * Desc: Rotates the camera around the focus to a specific angle
 * Prec: Two floats, the angle to rotate to and the amount of time to do it in
 * Post: Calculates intermediate angle and runs Rotate
 */
void Camera::Rotate_To(float angle, float time)
{
    // Get angle equivalent below 360
    while(angle >= 360)
        angle -= 360;
    
    // Get the distances between the current and given angle in both directions
    float diff_1 = m_angle - angle;
    float diff_2 = angle - m_angle;
    // Set angle_diff to whichever one's absolute value is smallest
    float angle_diff = (abs(diff_1) < abs(diff_2)) ? diff_1 : diff_2;
    
    Rotate(angle_diff, time);
}