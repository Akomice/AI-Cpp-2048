#include "niveau_3.h"

int main() {
    int choix_couleur = 0;
    Font font;
    Font font_cute;
    Color fond(249,228,183);
    Color texte(40,40,40);
    Color box(250, 160, 160);
    font.loadFromFile("ClearSans-Regular.ttf");
    font_cute.loadFromFile("A little sunshine.ttf");
    RenderWindow window(VideoMode(317, 471), "2048");
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
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);
                    if ((mousePos.x > 30.f) and (mousePos.x < 45.f)and (mousePos.y > 105.f) and (mousePos.y < 120.f)) {
                        choix_couleur = 1;
                    } else if ((mousePos.x > 185.f) and (mousePos.x < 200.f)and (mousePos.y > 105.f) and (mousePos.y < 120.f)) {
                        choix_couleur = 2;
                    } else if ((mousePos.x > 25.f) and (mousePos.x < 110.f)and (mousePos.y > 320.f) and (mousePos.y < 358.f)) {
                        if (choix_couleur == 1) {
                            jeu(window);
                        } else if (choix_couleur == 2) {
                            jeu2(window);
                        }
                    } else if ((mousePos.x > 145.f) and (mousePos.x < 295.f)and (mousePos.y > 320.f) and (mousePos.y < 358.f)) {
                        if (choix_couleur == 1) {
                            jeu3(window);
                        } else if (choix_couleur == 2) {
                            jeu4(window);
                        }
                    }
                }
            }
        }
        Text theme("Theme",font);
        theme.setFillColor(texte);
        theme.setPosition(Vector2f(110,20));

        Text modedejeu("Mode de jeu",font);
        modedejeu.setFillColor(texte);
        modedejeu.setPosition(Vector2f(80,220));

        Text original("Original",font);
        original.setFillColor(texte);
        original.setPosition(Vector2f(65,100));
        original.setCharacterSize(20);

        Text cutepink("Cute Pink",font_cute);
        cutepink.setFillColor(texte);
        cutepink.setPosition(Vector2f(220,100));
        cutepink.setCharacterSize(20);

        Text classique("Classique",font);
        classique.setFillColor(texte);
        classique.setPosition(Vector2f(34.f,330.f));
        classique.setCharacterSize(16);
        RectangleShape rect_classique;
        rect_classique.setFillColor(box);
        rect_classique.setPosition(Vector2f(25.f,320.f));
        rect_classique.setSize(Vector2f(85.f,38.f));

        RectangleShape check_box1;
        check_box1.setFillColor(box);
        check_box1.setPosition(Vector2f(30.f,105.f));
        check_box1.setSize(Vector2f(15.f,15.f));

        RectangleShape check_box2;
        check_box2.setFillColor(box);
        check_box2.setPosition(Vector2f(185.f,105.f));
        check_box2.setSize(Vector2f(15.f,15.f));

        RectangleShape cross11(Vector2f(15, 2));
        cross11.rotate(45);
        cross11.setPosition(Vector2f(33.f,107.f));
        cross11.setFillColor(Color::Red);

        RectangleShape cross22(Vector2f(15, 2));
        cross22.rotate(135);
        cross22.setPosition(Vector2f(198.f,109.f));
        cross22.setFillColor(Color::Red);

        RectangleShape cross21(Vector2f(15, 2));
        cross21.rotate(45);
        cross21.setPosition(Vector2f(188.f,107.f));
        cross21.setFillColor(Color::Red);

        RectangleShape cross12(Vector2f(15, 2));
        cross12.rotate(135);
        cross12.setPosition(Vector2f(43.f,109.f));
        cross12.setFillColor(Color::Red);

        Text chanceux("Es-tu chanceux ?",font);
        chanceux.setFillColor(texte);
        chanceux.setPosition(Vector2f(157.f,330.f));
        chanceux.setCharacterSize(16);
        RectangleShape rect_chanceux;
        rect_chanceux.setFillColor(box);
        rect_chanceux.setPosition(Vector2f(145.f,320.f));
        rect_chanceux.setSize(Vector2f(150.f,38.f));

        Text bienvenue("Bienvenue sur le 2048 de Yannis et Sandra !\n       On espere que tu vas t'amuser <3",font);
        bienvenue.setFillColor(texte);
        bienvenue.setPosition(Vector2f(13.f,424.f));
        bienvenue.setCharacterSize(15);

        window.clear(fond);
        window.draw(rect_classique);
        window.draw(classique);
        window.draw(theme);
        window.draw(original);
        window.draw(cutepink);
        window.draw(check_box1);
        window.draw(check_box2);

       if (choix_couleur == 1) {
            window.draw(cross11);
            window.draw(cross12);
            window.draw(check_box2);
       } else if (choix_couleur == 2) {
            window.draw(cross21);
            window.draw(cross22);
            window.draw(check_box1);
       }
        window.draw(modedejeu);
        window.draw(rect_chanceux);
        window.draw(chanceux);
        window.draw(bienvenue);
        window.display();
    }
}