#include "path.h"

class Turtle {

    Path mPath;
    
public:
    Turtle();
    ~Turtle();
    
    // local coordinate space
    void move(float forward, float right, float up);
    inline void forward(float dist) { move(dist, 0.f, 0.f); }
    inline void right(float dist) { move(0.f, dist, 0.f); }
    inline void up(float dist) { move(0.f, 0.f, dist); }
    
    // global coordinate space
    void translate(float x, float y, float z);
    void getCoords(const float& x, const float& y, const float& z);
    
    void rotate(float pitch, float yaw, float roll);
    inline void pitch(float amt) { rotate(amt, 0.f, 0.f); }
    inline void yaw(float amt) { rotate(0.f, amt, 0.f); }
    inline void roll(float amt) { rotate(0.f, 0.f, amt); }
    void getOrientation(const float& pitch, const float& yaw, const float& roll);
    
    void push();
    void pop();
    
    void off();
    void on();
    
    void setSpeed(float amt);
        
}; // Turtle class
