#ifndef _QUATERNION_H
#define _QUATERNION_H

#define PI            3.14159265358979323846

class Quaternion  
{
public:
        
    Quaternion();
    Quaternion(float w_p, float x_p, float y_p, float z_p);
    ~Quaternion();
        
    void CreateMatrix(float *pMatrix); // row major ordering
    void CreateFromAxisAngle(float x_p, float y_p, float z_p, float deg_p);

    Quaternion operator *(const Quaternion &q);
    
    void normalise();

private:
    float x;
    float y;
    float z;
    float w;
};


#endif
