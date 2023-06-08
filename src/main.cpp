#include <iostream>
#include "GameController.h"

int main()
{
	GameController a;
	a.run();
}
//}
//#include <SFML/Graphics.hpp>
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Player Movement");
//
//    sf::RectangleShape player(sf::Vector2f(50, 50));
//
//    player.setFillColor(sf::Color::Red);
//
//    player.setPosition(400, 300);
//
//
//    float movementSpeed = 0.03f;
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        // تحريك اللاعب
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//        {
//            
//            player.move(-movementSpeed, 0);
//        }
//        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//        {
//            player.move(movementSpeed, 0);
//        }
//        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//        {
//            player.move(0, -movementSpeed);
//        }
//        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//        {
//            player.move(0, movementSpeed);
//        }
//
//        window.clear();
//        window.draw(player);
//        window.display();
//    }
//
//    return 0;
//}
