#include "Doodle.hpp"
#include "TextureManager.h"

SDL_Rect srcRect, destRect;

Doodle::Doodle(Properties* p) : GameObject(p) {
    
    width = p->width;
    height = p->height;
    
    transform = new Transform(0, 0);
    rigidBody = new RigidBody();
    rigidBody->SetGravity(25.0f);
    rigidBody->SetMass(0.5f);
    
    float px = p->X + p->width / 2;
    float py = p->Y + p->height / 2;
    origin = new Point(px, py);
    
    jumpTime = JUMP_TIME;
    jumpForce = JUMP_FORCE;
    
    collider = new Collider();
    collider->SetBuffer(0, 0, 0, 15);
}


void Doodle::Update(float dt) {
    rigidBody->UnsetForce();
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_LEFT)) {
        rigidBody->ApplyForceX(15 * BACKWARD);
        flip = SDL_FLIP_NONE;
    }
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_RIGHT)) {
        rigidBody->ApplyForceX(15 * FORWARD);
        flip = SDL_FLIP_HORIZONTAL;
    }
    
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_SPACE) && isGrounded) {
           isJumping = true;
           isGrounded = false;
           rigidBody->ApplyForceY(jumpForce * DOWNWARD);
    }
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_SPACE) && isJumping && jumpTime > 0) {
        jumpTime -= 1;
        rigidBody->ApplyForceY(jumpForce * DOWNWARD);
    } else {
        isJumping = false;
        jumpTime = JUMP_TIME;
    }
    
    rigidBody->Update(dt);
    lastSafePosition.x = transform->x;
    transform->x += rigidBody->Position().x;
    collider->Set(transform->x, transform->y, 80, 80);

    if (CollisionHandler::GetInstance()->MapCollision(collider->Get())) {
        transform->x = lastSafePosition.x;
    }

    rigidBody->Update(dt);
    lastSafePosition.y = transform->y;
    transform->y += rigidBody->Position().y;
    collider->Set(transform->x, transform->y, 80, 80);
    
    if (CollisionHandler::GetInstance()->MapCollision(collider->Get())) {
        isGrounded = true;
        transform->y = lastSafePosition.y;
    } else {
        isGrounded = false;
    }
    
    origin->x = transform->x + width / 2;
    origin->y = transform->y + height / 2;
}

void Doodle::Render() {
    Vector2D cam = Camera::GetInstance()->GetPosition();
    TextureManager::GetInstance()->Render("doodle", transform->x - cam.x, transform->y - cam.y, 80, 80, flip);
    SDL_Rect box = collider->Get();
    box.x -= cam.x;
    box.y -= cam.y;
    SDL_RenderDrawRect(Game::renderer, &box);
}

void Doodle::Clean() {
    free(transform);
    free(rigidBody);
    free(collider);
    free(origin);
}
