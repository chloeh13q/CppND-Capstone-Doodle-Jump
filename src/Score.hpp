#ifndef Score_hpp
#define Score_hpp

#include "TextureManager.h"

class Score {
public:
    inline static Score* GetInstance() { return instance = (instance != nullptr)? instance : new Score(); }
    int GetScore() { return score; }
    void IncreaseScore(int n) { score += n; }

private:
    static Score* instance;
    Score() { score = 0; }
    int score;
};

#endif /* Score_hpp */
