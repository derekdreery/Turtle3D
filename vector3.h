#ifndef _VECTOR3_H
#define _VECTOR3_H

#include <ostream>

template <class T>
class Vector3
{
public:
    T x;
    T y;
    T z;
    
    Vector3(T x_p=0, T y_p=0, T z_p=0) : x(x_p), y(y_p), z(z_p) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    ~Vector3() {}
    
    inline void setCoords(const T& x_p, const T& y_p, const T& z_p)
        { x = x_p; y = y_p; z = z_p; }
    inline void getCoords(T& x_p, T& y_p, T& z_p)
        { x_p = x; y_p = y; z_p = z; }
        
    inline T norm() {return sqrt(x*x+y*y+z*z);}
    inline T dot(const Vector3& rhs)
        {return x*rhs.x+y*rhs.y+z*rhs.z;}
    inline Vector3 cross(const Vector3& rhs)
        {return Vector3(y*rhs.z-rhs.y*z, z*rhs.x-rhs.z*x, x*rhs.y-rhs.x*y);}
    
    Vector3& operator=(const Vector3& rhs)
        {if (this!=&rhs) {x=rhs.x; y=rhs.y; z=rhs.z;} return *this;}
        
    Vector3& operator+=(const Vector3& rhs)
        {x+=rhs.x; y+=rhs.y; z+=rhs.z; return *this;}
    Vector3& operator-=(const Vector3& rhs)
        {x-=rhs.x; y-=rhs.y; z-=rhs.z; return *this;}
    Vector3& operator*=(const T& rhs)
        {x*=rhs; y*=rhs; z*=rhs; return *this;}
    Vector3& operator/=(const T& rhs)
        {x/=rhs; y/=rhs; z/=rhs; return *this;}
                
    const Vector3 operator+(const Vector3& other)
        {return Vector3(*this)+=other;}
    const Vector3 operator-(const Vector3& other)
        {return Vector3(*this)-=other;}    
    const Vector3 operator*(const T& other)
        {return Vector3(*this)*=other;}    
    const Vector3 operator/(const T& other)
        {return Vector3(*this)/=other;}    
    
    bool operator==(const Vector3& rhs)
        {return x==rhs.x && y==rhs.y && z==rhs.z;}
    bool operator!=(const Vector3& rhs)
        {return x!=rhs.x || y!=rhs.y || z!=rhs.z;}
        
    friend std::ostream& operator<<(std::ostream& lhs, const Vector3& rhs)
        {lhs << "Vector3(" << rhs.x << "," << rhs.y << "," << rhs.z << ")"; return lhs;}
    
};

#endif /* _VECTOR3_H */
