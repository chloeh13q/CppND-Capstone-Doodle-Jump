#ifndef Vector2D_h
#define Vector2D_h

class Vector2D
{
public:
    int x, y;
    
    Vector2D(float x = 0, float y = 0) : x(x), y(y) {}
    
    inline Vector2D operator+(const Vector2D &v2) const {
        return Vector2D(x + v2.x, y + v2.y);
    }
    
    inline Vector2D operator-(const Vector2D &v2) const {
        return Vector2D(x - v2.x, y - v2.y);
    }
    
    inline Vector2D operator*(const float scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }
    
};

class Transform
{
public:
    float x, y;
    
    Transform(float x = 0, float y = 0): x(x), y(y) {}
    
    inline void TranslateX(float delta_x) { x += delta_x; }
    inline void TranslateY(float delta_y) { y += delta_y; }
    inline void Translate(Vector2D v) { x+= v.x; y+= v.y; }
    
};


class Point {
public:
    float x, y;
    
    Point(float x = 0, float y = 0) : x(x), y(y) {}
    
    inline Point operator+(const Point &p2) const {
        return Point(x + p2.x, y + p2.y);
    }
     
    inline friend Point operator+=(Point &p1, Point &p2) {
        p1.x += p2.x;
        p1.y += p2.y;
        return p1;
    }
    
    inline Point operator-(const Point &p2) const {
        return Point(x - p2.x, y - p2.y);
    }
    
    inline friend Point operator-=(Point &p1, Point &p2) {
        p1.x -= p2.x;
        p1.y -= p2.y;
        return p1;
    }
    
    inline Point operator*(const float scalar) const {
        return Point(x * scalar, y * scalar);
    }
    
};

#endif /* Vector2D_h */
