#ifndef Layer_hpp
#define Layer_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Layer
{
public:
    
//    Layer(const char* texturesheet);
//    ~Layer();
    
    virtual void Update()=0;
    virtual void Render()=0;

};

#endif /* Layer_hpp */
