#ifndef RigidBody_hpp
#define RigidBody_hpp

#include "Vector2D.h"

#define UNI_MASS 1.0f
#define GRAVITY 9.8f

#define FORWARD 1
#define BACKWARD -1

#define UPWARD 1
#define DOWNWARD -1

class RigidBody
{
public:
    RigidBody() {
        mass = UNI_MASS;
        gravity = GRAVITY;
    }
    
    // virtual ~RigidBody();
    
    // Setters for gravity and mass
    inline void SetMass(float m) { mass = m; }
    inline void SetGravity(float g) { gravity = g; }
    
    // Force
    inline void ApplyForce(Vector2D f) { force = f; }
    inline void ApplyForceX(float Fx) { force.x = Fx; }
    inline void ApplyForceY(float Fy) { force.y = Fy; }
    inline void UnsetForce() { force = Vector2D{0, 0}; }
    
    // Getters
    inline float Mass() { return mass; }
    inline Vector2D Position() { return position; }
    inline Vector2D Velocity() { return velocity; }
    inline Vector2D Acceleration() { return acceleration; }
    
    // Update methods
    void Update(float dt) {
        acceleration.x = force.x / mass;
        acceleration.y = gravity + force.y / mass;
        velocity = acceleration * dt;
        position = velocity * dt;
    }
    
    
private:
    float mass;
    float gravity;
    
    Vector2D force;
    
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    
};

#endif /* RigidBody_hpp */
