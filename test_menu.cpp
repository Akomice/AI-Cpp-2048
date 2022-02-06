#include "niveau_3.h"
using namespace sf;
using namespace std;

int main() {
    Font font;
    Color fond(27,27,27);
    Color texte(250, 160, 160);
    font.loadFromFile("clear-sans/ClearSans-Regular.ttf");
    RenderWindow window(VideoMode(317, 471), "Menu");
    window.setVerticalSyncEnabled(true); //l'application se rafraîchit à la même fréquence que l'écran
    window.setPosition(Vector2i(450, 100)); //positionne la fenêtre au milieu de l'écran
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) { 
                window.close(); 
                exit(0);
            }
            if (event.type == Event::KeyPressed) {
                return 0;
            }
        }
        Text theme("Theme",font);
        theme.setFillColor(Color::White);
        theme.setPosition(Vector2f(120,20));

        Text modedejeu("Mode de jeu",font);
        modedejeu.setFillColor(Color::White);
        modedejeu.setPosition(Vector2f(80,220));

        Text original("Original",font);
        original.setFillColor(Color::White);
        original.setPosition(Vector2f(65,100));
        original.setCharacterSize(20);

        Text cutepink("Cute Pink",font);
        cutepink.setFillColor(Color::White);
        cutepink.setPosition(Vector2f(220,100));
        cutepink.setCharacterSize(20);

        Text text_new("Classique",font);
        text_new.setFillColor(Color::White);
        text_new.setPosition(Vector2f(34.f,330.f));
        text_new.setCharacterSize(16);
        RectangleShape rectangle_new;
        rectangle_new.setFillColor(texte);
        rectangle_new.setPosition(Vector2f(25.f,320.f));
        rectangle_new.setSize(Vector2f(85.f,38.f));

        Text chanceux("Es-tu chanceux ?",font);
        chanceux.setFillColor(Color::White);
        chanceux.setPosition(Vector2f(157.f,330.f));
        chanceux.setCharacterSize(16);
        RectangleShape rect_chanceux;
        rect_chanceux.setFillColor(texte);
        rect_chanceux.setPosition(Vector2f(145.f,320.f));
        rect_chanceux.setSize(Vector2f(150.f,38.f));

        Text bienvenue("Bienvenue sur le 2048 de Yannis et Sandra !\n       On espere que tu vas t'amuser <3",font);
        bienvenue.setFillColor(texte);
        bienvenue.setPosition(Vector2f(13.f,424.f));
        bienvenue.setCharacterSize(15);

        window.clear(Color::Black);
        window.draw(rectangle_new);
        window.draw(text_new);
        window.draw(theme);
        window.draw(original);
        window.draw(cutepink);
        window.draw(modedejeu);
        window.draw(rect_chanceux);
        window.draw(chanceux);
        window.draw(bienvenue);
        window.display();

        //if (Mouse::isButtonPressed(Mouse::Left)) {
            //Vector2i mousePos = Mouse::getPosition(window);
            //if ((mousePos.x > 121.f) and (mousePos.x < 206.f)and (mousePos.y > 81.f) and (mousePos.y < 119.f)) {
               // jeu();
           // } 
       // }
    }
    
}