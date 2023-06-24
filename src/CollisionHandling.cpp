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
#include "Opener.h"
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

    void BallMonsterWithWall(Object& ballMonster,
        Object& wall, GameController& game)
    {
        ballMonster.moveToPrevPos();
    }

    void WallWithBallMonster(Object& wall,
        Object& ballMonster, GameController& game)
    {
        BallMonsterWithWall(ballMonster, wall, game);
    }

    void BallMonsterWithDoor(Object& ballMonster,
        Object& door, GameController& game)
    {
        if (door.isDoorOpen())
            return;
        ballMonster.moveToPrevPos();
    }

    void DoorWithBallMonster(Object& door,
        Object& ballMonster, GameController& game)
    {
        BallMonsterWithDoor(ballMonster, door, game);
    }


  
    
    void KeyMonsterWithBullet (Object& keyMonster,
        Object& bullet, GameController& game)
    {
        game.creatKey(keyMonster.getposition());
        game.eraseObject(bullet, BULLET);
        game.eraseObject(keyMonster, KEYMONSTER);
    } 
    void BulletWithKeyMonster(Object& bullet,
        Object& keyMonster, GameController& game)
    {
         BulletWithKeyMonster(keyMonster, bullet, game);
    }

    void BallMonsterWithBullet(Object& ballMonster,
        Object& bullet, GameController& game)
    {
        game.eraseObject(bullet, BULLET);
        game.eraseObject(ballMonster, BALLMONSTER);
    } 
    void BulletWithBallMonster(Object& bullet,
        Object& ballMonster, GameController& game)
    {
        BallMonsterWithBullet(ballMonster, bullet, game);
    }

  
       
    void KeyMonsterWithPrince(Object& keyMonster,
        Object& prince, GameController& game)
    {
        game.dead();
    }

    void PrinceWithKeyMonster(Object& prince,
        Object& keyMonster, GameController& game)
    {
        KeyMonsterWithPrince(keyMonster, prince, game);
    }
    
    void BallMonsterWithPrince(Object& ballMonster,
        Object& prince, GameController& game)
    {
        game.dead();
    }

    void PrinceWithBallMonster(Object& prince,
        Object& ballMonster, GameController& game)
    {
        BallMonsterWithPrince(ballMonster, prince, game);
    } 

   
    void BulletWithPrince(Object& bullet,
        Object& prince, GameController& game)
    {
        game.eraseObject(bullet, BULLET);
        game.dead();
    }

    void PrinceWithBullet(Object& prince,
        Object& bullet, GameController& game)
    {
        BulletWithPrince(bullet, prince, game);
    }
     
    //
      // prince collision-processing functions
    void PrinceWithWall(Object& prince,
        Object& wall, GameController& game)
    {
        prince.moveToPrevPos();
    }

    void WallWithPrince(Object& wall,
        Object& prince, GameController& game)
    {
        prince.moveToPrevPos();

        PrinceWithWall(prince, wall, game);
    }

    void PrinceWithDoor(Object& prince,
        Object& door, GameController& game)
    {
        if (door.isDoorOpen())
            return;
        if (game.haveKey())
        {
            door.getIcon().setTexture(*Textures::instance().getIcon(OPENDOOR));
            door.setDoorOpen();
        }
        else
            prince.moveToPrevPos();
    }

    void DoorWithPrince(Object& door,
        Object& prince, GameController& game)
    {
        PrinceWithDoor(prince, door, game);
    }

    void PrinceWithStair(Object& prince,
        Object& stair, GameController& game)
    {
        prince.setPrinceCollisStair();
    }

    void StairWithPrince(Object& stair,
        Object& prince, GameController& game)
    {
        PrinceWithStair(prince, stair, game);
    }

    void PrinceWithCoin(Object& prince,
        Object& coin, GameController& game) 
    { 
        game.dicreaseCoin();
        game.eraseObject(coin, STATICS);
        game.increaseScore(EATCOIN);
    }

    void CoinWithPrince(Object& coin, 
        Object& prince, GameController& game)
    {
        PrinceWithCoin(prince, coin, game);
    }

    void PrinceWithGiftBuleet(Object& prince,
        Object& giftBullet, GameController& game)
    {
        game.eraseObject(giftBullet, STATICS);
        game.increaseBullet();
    }

    void GiftBuleetWithPrince(Object& giftBullet,
        Object& prince, GameController& game)
    {
        PrinceWithGiftBuleet(prince, giftBullet, game);
    } 
    
    void PrinceWithGiftAddLife(Object& prince,
        Object& giftlife, GameController& game)
    {
        game.eraseObject(giftlife, STATICS);
        game.addLife();
    }

    void GiftAddLifeWithPrince(Object& giftlife,
        Object& prince, GameController& game)
    {
        PrinceWithGiftAddLife(prince, giftlife, game);
    } 
    
    void PrinceWithGiftIncreasingTime(Object& prince,
        Object& giftTime, GameController& game)
    {
        game.eraseObject(giftTime, STATICS);
        game.increaseTime();
    }

    void GiftIncreasingTimeWithPrince(Object& giftTime,
        Object& prince, GameController& game)
    {
        PrinceWithGiftIncreasingTime(prince, giftTime, game);
    }

    void PrinceWithKey(Object& prince,
        Object& key, GameController& game)
    {
        game.eraseObject(key, STATICS);
        game.increaseKey();
    }

    void KeyWithPrince(Object& key,
        Object& prince, GameController& game)
    {
        PrinceWithKey(prince, key, game);
    }

    void PrinceWithGate(Object& prince, Object& gate, GameController& game) {

        if (game.chekCoin())
        {
            game.eraseObject(gate, STATICS);
            game.newLevel();
        }
    }
    void GateWithPrince(Object& gate, Object& prince, GameController& game) {

        PrinceWithGate(prince, gate, game);
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

        phm[Key(typeid(BallMonster), typeid(Wall))] = &BallMonsterWithWall;
        phm[Key(typeid(Wall), typeid(BallMonster))] = &WallWithBallMonster;
        phm[Key(typeid(BallMonster), typeid(Door))] = &BallMonsterWithDoor;
        phm[Key(typeid(Door), typeid(BallMonster))] = &DoorWithBallMonster;




        phm[Key(typeid(KeyMonster), typeid(Bullet))] = &KeyMonsterWithBullet;
        phm[Key(typeid(Bullet), typeid(KeyMonster))] = &BulletWithKeyMonster;
        phm[Key(typeid(BallMonster), typeid(Bullet))] = &BallMonsterWithBullet;
        phm[Key(typeid(Bullet), typeid(BallMonster))] = &BulletWithBallMonster;

       
        // prince with moving
        phm[Key(typeid(KeyMonster), typeid(Prince))] = &KeyMonsterWithPrince;
        phm[Key(typeid(Prince), typeid(KeyMonster))] = &PrinceWithKeyMonster;
        phm[Key(typeid(Bullet), typeid(Prince))] = &BulletWithPrince;
        phm[Key(typeid(Prince), typeid(Bullet))] = &PrinceWithBullet;
        phm[Key(typeid(BallMonster), typeid(Prince))] = &BallMonsterWithPrince;
        phm[Key(typeid(Prince), typeid(BallMonster))] = &PrinceWithBallMonster;
        // prince with static
        phm[Key(typeid(Prince), typeid(Wall))] = &PrinceWithWall;
        phm[Key(typeid(Wall), typeid(Prince))] = &WallWithPrince;
        phm[Key(typeid(Prince), typeid(Door))] = &PrinceWithDoor;
        phm[Key(typeid(Door), typeid(Prince))] = &DoorWithPrince;
        phm[Key(typeid(Prince), typeid(Stair))] = &PrinceWithStair;
        phm[Key(typeid(Stair), typeid(Prince))] = &StairWithPrince;
        
        phm[Key(typeid(Gate), typeid(Prince))] = &GateWithPrince;
        phm[Key(typeid(Prince), typeid(Gate))] = &PrinceWithGate;
        

        phm[Key(typeid(Prince), typeid(Coin))] = &PrinceWithCoin;
        phm[Key(typeid(Coin), typeid(Prince))] = &CoinWithPrince;
        
        phm[Key(typeid(Prince), typeid(GiftBuleet))] = &PrinceWithGiftBuleet;
        phm[Key(typeid(GiftBuleet), typeid(Prince))] = &GiftBuleetWithPrince;
        phm[Key(typeid(Prince), typeid(AddLife))] = &PrinceWithGiftAddLife;
        phm[Key(typeid(AddLife), typeid(Prince))] = &GiftAddLifeWithPrince;
        phm[Key(typeid(Prince), typeid(IncreasingTime))] = &PrinceWithGiftIncreasingTime;
        phm[Key(typeid(IncreasingTime), typeid(Prince))] = &GiftIncreasingTimeWithPrince;
        phm[Key(typeid(Prince), typeid(Opener))] = &PrinceWithKey;
        phm[Key(typeid(Opener), typeid(Prince))] = &KeyWithPrince;

        

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