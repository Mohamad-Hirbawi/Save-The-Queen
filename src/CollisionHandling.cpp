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

//#include "SpaceShip.h"
//#include "SpaceStation.h"
//#include "Asteroid.h"
#include "MovingObject.h"

namespace // anonymous namespace — the standard way to make function "static"
{

    // primary collision-processing functions
    void KeyMonsterWithWall(Object& keyMonster,
        Object& wall)
    {
        keyMonster.moveToPrevPos();
    }

    void WallWithKeyMonster(Object& wall,
        Object& keyMonster)
    {
        keyMonster.moveToPrevPos();
    }

    void KeyMonsterWithDoor (Object& keyMonster,
        Object& door)
    {
        keyMonster.moveToPrevPos();
    }

    void DoorWithKeyMonster(Object& door,
        Object& keyMonster)
    {
        keyMonster.moveToPrevPos();
    } 
    
    void KeyMonsterWithBullet (Object& keyMonster,
        Object& bullet)
    {
        keyMonster.moveToPrevPos();
    }

    void BulletWithKeyMonster(Object& bullet,
        Object& keyMonster)
    {
        keyMonster.moveToPrevPos();
    }

    


    using HitFunctionPtr = std::function<void(Object&, Object&)>;
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
        phm[Key(typeid(KeyMonster), typeid(Bullet))] = &KeyMonsterWithBullet;
        phm[Key(typeid(Bullet), typeid(KeyMonster))] = &BulletWithKeyMonster;
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

void processCollision(Object& object1, Object& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));

    if (phf)        phf(object1, object2);

}