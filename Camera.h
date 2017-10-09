/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camera.h
 * Author: ConnorFlynn
 *
 * Created on October 8, 2017, 3:52 PM
 */

#ifndef CAMERA_H
#define CAMERA_H

class Camera {
public:
    
    /*********************\
     * Object Management *
    \*********************/
    
    // Default Constructor
    Camera();
    // Copy Constructor
    Camera(const Camera& orig);
    // Destructor
    virtual ~Camera();
    
    
    /*************\
     * Accessors *
    \*************/
    
    // Get the angle
    float Get_Angle();
    // Get the pitch
    float Get_Pitch();
    // Get the distance
    int Get_Dist();
    
    
    /************\
     * Mutators *
    \************/
    
    // Rotate a given amount around the center point
    void Rotate(float angle, float time);
    // Rotate to a given angle around the center point
    void Rotate_To(float angle, float time);
    
private:
    // Angle on X-Y plane, 0 being "north"
    float m_angle;
    // Amount/Remaining amount to shift 
    float m_angle_delta;
    // Amount to change per tick
    float m_angle_speed;
    
    // Angle relative to ground, 0 being perpendicular to the ground
    float m_pitch;
    // Amount/Remaining amount to shift 
    float m_pitch_delta;
    // Amount to change per tick
    float m_pitch_speed;
    
    // Distance from camera focus
    int m_dist;
    // Amount/Remaining amount to shift 
    int m_dist_delta;
    // Amount to change per tick
    int m_dist_speed;
};

#endif /* CAMERA_H */

