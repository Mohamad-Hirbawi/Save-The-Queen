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
#include "MovingObject.h"

namespace // anonymous namespace � the standard way to make function "static"
{

    // primary collision-processing functions
    void BulletWithWall(Object& bullet,
        Object&, GameController& game)
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

    void monsterWithWall(Object& monster,
        Object& , GameController& )
    {
        monster.moveToPrevPos();
    }

    void WallWithMonster(Object& wall,
        Object& monster, GameController& game)
    {
        monsterWithWall(monster, wall, game);
    }

    void MonsterWithDoor(Object& monster,
        Object& door, GameController& )
    {
        if (door.isDoorOpen())
            return;
        monster.moveToPrevPos();
    }

    void DoorWithMonster(Object& door,
        Object& monster, GameController& game)
    {
        MonsterWithDoor(monster, door, game);
    }

    void KeyMonsterWithBullet (Object& keyMonster,
        Object& bullet, GameController& game)
    {
        game.playSound(fireTouch);
        game.creatKey(keyMonster.getposition());
        game.eraseObject(bullet, BULLET);
        game.eraseObject(keyMonster, KEYMONSTER);
    } 
    void BulletWithKeyMonster(Object& bullet,
        Object& keyMonster, GameController& game)
    {
        KeyMonsterWithBullet(keyMonster, bullet, game);
    }

    void BallMonsterWithBullet(Object& ballMonster,
        Object& bullet, GameController& game)
    {
        game.playSound(fireTouch);
        game.eraseObject(bullet, BULLET);
        game.eraseObject(ballMonster, BALLMONSTER);
    } 
    void BulletWithBallMonster(Object& bullet,
        Object& ballMonster, GameController& game)
    {
        BallMonsterWithBullet(ballMonster, bullet, game);
    }

    void BeastMonsterWithBullet(Object& beastMonster,
        Object& bullet, GameController& game)
    {
        game.eraseObject(bullet, BULLET);
        beastMonster.dicreaseLifeBeast();
        if (beastMonster.getLifeBeast() == 0)
        {
            game.playSound(BeastMonsterDead);
            game.eraseObject(beastMonster, BEASTMONSTER);
        }
    } 
    void BulletWithBeastMonster(Object& bullet,
        Object& beastMonster, GameController& game)
    {
        BeastMonsterWithBullet(beastMonster, bullet, game);
    }

    void MonsterWithPrince(Object&,
        Object&, GameController& game)
    {
        game.dead();
    }

    void PrinceWithMonster(Object& prince,
        Object& monster, GameController& game)
    {
        MonsterWithPrince(monster, prince, game);
    }
   
   
    void BulletWithPrince(Object& bullet,
        Object&, GameController& game)
    {
        game.eraseObject(bullet, BULLET);
        game.dead();
    }

    void PrinceWithBullet(Object& prince,
        Object& bullet, GameController& game)
    {
        BulletWithPrince(bullet, prince, game);
    }
     
      // prince collision-processing functions
    void PrinceWithWall(Object& prince,
        Object&, GameController& )
    {
        prince.moveToPrevPos();
    }

    void WallWithPrince(Object& wall,
        Object& prince, GameController& game)
    {
        PrinceWithWall(prince, wall, game);
    }


    void queenWithWall(Object& queen,
        Object&, GameController&)
    {
        queen.moveToPrevPos();
    }

    void wallWithqueen(Object& wall,
        Object&queen, GameController&game)
    {
        queenWithWall(queen, wall, game);

    }


    void PrinceWithDoor(Object& prince,
        Object& door, GameController& game)
    {
        if (door.isDoorOpen())
            return;
        if (game.haveKey())
        {
            game.playSound(gateOpen);
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
        Object& stair, GameController&)
    {

        if (std::abs(prince.getposition().x - stair.getposition().x) <= 15)
        {
            if (prince.getposition().y - stair.getposition().y > -49)// long prince
                prince.setPrinceCollisStairUp();
            if (
                prince.getposition().y - stair.getposition().y <100)// long stair
                prince.setPrinceCollisStairDown();

        }
    }

    void StairWithPrince(Object& stair,
        Object& prince, GameController& game)
    {
        PrinceWithStair(prince, stair, game);
    }

    void PrinceWithCoin(Object&,
        Object& coin, GameController& game) 
    { 
        game.playSound(TC);
        game.dicreaseCoin();
        game.eraseObject(coin, STATICS);
        game.increaseScore(EATCOIN);
    }

    void CoinWithPrince(Object& coin, 
        Object& prince, GameController& game)
    {
        PrinceWithCoin(prince, coin, game);
    }

    void PrinceWithGiftBuleet(Object&,
        Object& giftBullet, GameController& game)
    {
        game.playSound(GiftSound);
        game.eraseObject(giftBullet, STATICS);
        game.increaseBullet();
    }

    void GiftBuleetWithPrince(Object& giftBullet,
        Object& prince, GameController& game)
    {
        PrinceWithGiftBuleet(prince, giftBullet, game);
    } 
    
    void PrinceWithGiftAddLife(Object&,
        Object& giftlife, GameController& game)
    {
        game.playSound(GiftSound);
        game.eraseObject(giftlife, STATICS);
        game.addLife();
    }

    void GiftAddLifeWithPrince(Object& giftlife,
        Object& prince, GameController& game)
    {
        PrinceWithGiftAddLife(prince, giftlife, game);
    } 
    
    void PrinceWithGiftIncreasingTime(Object&,
        Object& giftTime, GameController& game)
    {
        game.playSound(GiftSound);
        game.eraseObject(giftTime, STATICS);
        game.increaseTime();
    }

    void GiftIncreasingTimeWithPrince(Object& giftTime,
        Object& prince, GameController& game)
    {

        PrinceWithGiftIncreasingTime(prince, giftTime, game);
    }

    void PrinceWithKey(Object&,
        Object& key, GameController& game)
    {
        game.playSound(keyDrop);
        game.eraseObject(key, STATICS);
        game.increaseKey();
    }

    void KeyWithPrince(Object& key,
        Object& prince, GameController& game)
    {
        PrinceWithKey(prince, key, game);
    }

    void PrinceWithGate(Object&, Object& gate, GameController& game) {

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
        phm[Key(typeid(Queen), typeid(Wall))] = &queenWithWall;
        phm[Key(typeid(Wall), typeid(Queen))] = &wallWithqueen;

        phm[Key(typeid(KeyMonster), typeid(Wall))] = &monsterWithWall;
        phm[Key(typeid(Wall), typeid(KeyMonster))] = &WallWithMonster;
        phm[Key(typeid(KeyMonster), typeid(Door))] = &MonsterWithDoor;
        phm[Key(typeid(Door), typeid(KeyMonster))] = &DoorWithMonster;

        phm[Key(typeid(Bullet), typeid(Wall))] = &BulletWithWall;
        phm[Key(typeid(Wall), typeid(Bullet))] = &WallWithBullet;
        phm[Key(typeid(Bullet), typeid(Door))] = &BulletWithDoor;
        phm[Key(typeid(Door), typeid(Bullet))] = &DoorWithBullet;

        phm[Key(typeid(BallMonster), typeid(Wall))] = &monsterWithWall;
        phm[Key(typeid(Wall), typeid(BallMonster))] = &WallWithMonster;
        phm[Key(typeid(BallMonster), typeid(Door))] = &MonsterWithDoor;
        phm[Key(typeid(Door), typeid(BallMonster))] = &DoorWithMonster;

        phm[Key(typeid(BeastMonster), typeid(Wall))] = &monsterWithWall;
        phm[Key(typeid(Wall), typeid(BeastMonster))] = &WallWithMonster;
        phm[Key(typeid(BeastMonster), typeid(Door))] = &MonsterWithDoor;
        phm[Key(typeid(Door), typeid(BeastMonster))] = &DoorWithMonster;




        phm[Key(typeid(KeyMonster), typeid(Bullet))] = &KeyMonsterWithBullet;
        phm[Key(typeid(Bullet), typeid(KeyMonster))] = &BulletWithKeyMonster;
        phm[Key(typeid(BallMonster), typeid(Bullet))] = &BallMonsterWithBullet;
        phm[Key(typeid(Bullet), typeid(BallMonster))] = &BulletWithBallMonster;
        phm[Key(typeid(BeastMonster), typeid(Bullet))] = &BeastMonsterWithBullet;
        phm[Key(typeid(Bullet), typeid(BeastMonster))] = &BulletWithBeastMonster;

       
        // prince with moving
        phm[Key(typeid(KeyMonster), typeid(Prince))] = &MonsterWithPrince;
        phm[Key(typeid(Prince), typeid(KeyMonster))] = &PrinceWithMonster;
        phm[Key(typeid(Bullet), typeid(Prince))] = &BulletWithPrince;
        phm[Key(typeid(Prince), typeid(Bullet))] = &PrinceWithBullet;
        phm[Key(typeid(BallMonster), typeid(Prince))] = &MonsterWithPrince;
        phm[Key(typeid(Prince), typeid(BallMonster))] = &PrinceWithMonster;
        phm[Key(typeid(BeastMonster), typeid(Prince))] = &MonsterWithPrince;
        phm[Key(typeid(Prince), typeid(BeastMonster))] = &PrinceWithMonster;

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