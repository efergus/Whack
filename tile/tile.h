#pragma once
#include "vec.h"
class Group;

class Tile
{
private:
public:
    Vec2 pos;
    Vec2 size;
    Group* parent = nullptr;
    bool in_use;
    uint id;
    //bool visible;

    Tile();
    Tile(float x, float y, float w, float h);
    virtual ~Tile();

    virtual void update(){};
    virtual void update_all(){};
    Vec2 global_pos();
    void ssize(Vec2& s);
    void spos(Vec2& s);
};

inline Tile::Tile()
{
    pos = Vec2(0,0);
    size = Vec2(0,0);
}
inline Tile::Tile(float x, float y, float w, float h)
{
    pos.x = x;
    pos.y = y;
    size.x = w;
    size.y = h;
}
inline Tile::~Tile()
{
}

inline void Tile::ssize(Vec2& s){
    size = s;
}
inline void Tile::spos(Vec2& s){
    pos = s;
}