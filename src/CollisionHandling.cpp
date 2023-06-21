#pragma once
#include "CollisionHandling.h"

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include "KeyMonster.h"
#include "Wall.h"
#include "Door.h"
#include "Bullet.h"
#include "GameController.h"
//#include "SpaceShip.h"
//#include "SpaceStation.h"
//#include "Asteroid.h"
#include "MovingObject.h"

namespace // anonymous namespace — the standard way to make function "static"
{

    // primary collision-processing functions
    void KeyMonsterWithWall(Object& keyMonster,
        Object& wall , GameController&game)
    {
        keyMonster.moveToPrevPos();
    }

    void WallWithKeyMonster(Object& wall,
        Object& keyMonster , GameController& game)
    {
        KeyMonsterWithWall(keyMonster,wall,game);
    }

    void KeyMonsterWithDoor (Object& keyMonster,
        Object& door, GameController& game)
    {
        if (door.isDoorOpen())
            return;
        keyMonster.moveToPrevPos();
    }

    void DoorWithKeyMonster(Object& door,
        Object& keyMonster, GameController& game)
    {

        KeyMonsterWithDoor(keyMonster, door,game);
    }

    void BulletWithWall(Object& bullet,
        Object& wall, GameController& game)
    {
        game.eraseObject(bullet, BULLET);
    }

    void WallWithBullet(Object& wall,
        Object& bullet, GameController& game)
    {
        BulletWithWall(bullet, wall, game);
    }

    void BulletWithDoor(Object& bullet,
        Object& door, GameController& game)
    {
        if (door.isDoorOpen())
            return;
        game.eraseObject(bullet, BULLET);
    }

    void DoorWithBullet(Object& door,
        Object& bullet, GameController& game)
    {
        BulletWithDoor(bullet, door, game);
    }


  
    
    void KeyMonsterWithBullet (Object& keyMonster,
        Object& bullet, GameController& game)
    {
        game.eraseObject(bullet, BULLET);
        game.eraseObject(keyMonster, KEYMONSTER);
    } 
    void BulletWithKeyMonster(Object& bullet,
        Object& keyMonster, GameController& game)
    {
         BulletWithKeyMonster(keyMonster, bullet, game);
    }

    


    using HitFunctionPtr = std::function<void(Object&, Object& , GameController &)>;
    // typedef void (*HitFunctionPtr)(Object&, Object&);
    using Key = std::pair<std::type_index, std::type_index>;
    // std::unordered_map is better, but it requires defining good hash function for pair
    using HitMap = std::map<Key, HitFunctionPtr>;

    HitMap initializeCollisionMap()/////////////
    {
        HitMap phm;
        phm[Key(typeid(KeyMonster), typeid(Wall))] = &KeyMonsterWithWall;
        phm[Key(typeid(Wall), typeid(KeyMonster))] = &WallWithKeyMonster; 
        phm[Key(typeid(KeyMonster), typeid(Door))] = &KeyMonsterWithDoor;
        phm[Key(typeid(Door), typeid(KeyMonster))] = &DoorWithKeyMonster;

        phm[Key(typeid(Bullet), typeid(Wall))] = &BulletWithWall;
        phm[Key(typeid(Wall), typeid(Bullet))] = &WallWithBullet;
        phm[Key(typeid(Bullet), typeid(Door))] = &BulletWithDoor;
        phm[Key(typeid(Door), typeid(Bullet))] = &DoorWithBullet;


        phm[Key(typeid(KeyMonster), typeid(Bullet))] = &KeyMonsterWithBullet;
        phm[Key(typeid(Bullet), typeid(KeyMonster))] = &BulletWithKeyMonster;

        //...
        return phm;
    }

    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }


}

void processCollision(Object& object1, Object& object2, GameController& game)
{
    auto phf = lookup(typeid(object1), typeid(object2));

    if (phf)        phf(object1, object2, game);

}