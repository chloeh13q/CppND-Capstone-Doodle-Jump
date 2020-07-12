#ifndef Camera_hpp
#define Camera_hpp

#include "Vector2D.h"
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

class Camera {
public:
    inline static Camera* GetInstance() { return instance = (instance != nullptr)? instance : new Camera(); }
    inline SDL_Rect GetViewBox() { return viewBox; }
    inline Vector2D GetPosition() { return position; }
    inline void SetTarget(Point* t) { target = t; }
    void Update(float dt);
    void Clean();
    
private:
    static Camera* instance;
    Camera() { viewBox = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}; }
    Point* target;
    Vector2D position;
    SDL_Rect viewBox;

};

#endif /* Camera_hpp */
