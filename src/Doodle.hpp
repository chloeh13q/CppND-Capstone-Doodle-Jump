#ifndef Doodle_hpp
#define Doodle_hpp

#include "GameObject.hpp"
#include "RigidBody.hpp"
#include "TextureManager.h"
#include "Inputs.hpp"
#include "Vector2D.h"
#include "Collider.h"
#include "CollisionHandler.hpp"

#define JUMP_TIME 20.0f
#define JUMP_FORCE 40.0f

class Doodle : public GameObject {
    
public:
    Doodle(Properties* props);
    void Update(float dt);
    void Render();
    void Clean();
    inline Point* GetOrigin() { return origin; }
    
private:
    SDL_Texture* objTexture;
//    int x, y;
    int height, width;
    RigidBody* rigidBody;
    Transform* transform;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    Point* origin;
    
    bool isGrounded;
    bool isJumping;
    
    float jumpTime;
    float jumpForce;
    
    Collider* collider;
    Vector2D lastSafePosition;
};

#endif /* Doodle_hpp */
