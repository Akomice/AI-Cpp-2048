#include "niveau_3.h"

int BEST;

void gdessine(Plateau plateau, RenderWindow& window) { 
    
    Font font;
    font.loadFromFile("ClearSans-Regular.ttf");
    
    Color fond(251,250,243);
    Color couleurGrisFonce(60,58,51);
    Color couleurRouge(246,94,61);
    Color couleurGris(164,147,129);
    Color couleurGris2(190,175,160);
    Color couleur_text2et4(119,110,101);
    Color couleur_text_reste(249,246,242);
    Color couleur_rect2(238,228,218);
    Color couleur_rect4(238,226,206);
    Color couleur_rect8(243,178,126);
    Color couleur_rect16(246,151,107);
    Color couleur_rect32(247,126,104);
    Color couleur_rect64(247,97,71);
    Color couleur_rect128(237,206,115);
    Color couleur_rect256(237,202,100);
    Color couleur_rect512(237,198,81);
    Color couleur_rect1024(238,199,68);
    Color couleur_rect2048(237,204,95);
    Color couleur_rect4096(254,61,62);
    Color couleur_reste(255,32,33);

    Vector2f size_score_best(85.f,48.f);                       //taille des rectangles score et best
    Vector2f size_new_quit(85.f,38.f);                         // idem pour new et quit


    Text text_2048("2048",font);
    text_2048.setFillColor(Color::White);                      //couleur du texte
    text_2048.setPosition(Vector2f(29.f, 53.f));               //position du texte
    text_2048.setCharacterSize(30);                            // taille du texte
    RectangleShape rectangle_2048;                             // declaration du rectangle
    rectangle_2048.setFillColor(couleur_rect2048);             //couleur du rectangle
    rectangle_2048.setPosition(Vector2f(16.f, 23.f));          //position du rectangle
    rectangle_2048.setSize(Vector2f(96.f, 96.f));              //taille du rectangle (.f signifie que c'est un flottant)

    Text text_score("SCORE",font);
    text_score.setFillColor(Color::White);
    text_score.setPosition(Vector2f(146.f,29.f));
    text_score.setCharacterSize(12);
    RectangleShape rectangle_score;
    rectangle_score.setFillColor(couleurGrisFonce);
    rectangle_score.setPosition(Vector2f(121.f,23.f));
    rectangle_score.setSize(size_score_best);

    int score = plateau[4][0];
    float x_score;
    float y_score = 45.f;
    if ( score < 10 ) {
        x_score = 160.f;
    } else if ( score < 100 ) {
        x_score = 152.f;
    } else if ( score < 1000 ) {
        x_score = 148.f;
    } else if ( score < 10000 ) {
        x_score = 142.f;
    } else if ( score < 100000 ) {
        x_score = 136.f;
    } else if ( score < 1000000 ) {
        x_score = 130.f;
    } 

    float x_best;
    float y_best = y_score;
    if ( BEST < 10 ) {
        x_best = 255.f;
    } else if ( BEST < 100 ) {
        x_best = 247.f;
    } else if ( BEST < 1000 ) {
        x_best = 241.f;
    } else if ( BEST < 10000 ) {
        x_best = 235.f;
    } else if ( BEST < 100000 ) {
        x_best = 229.f;
    } else if ( BEST < 1000000 ) {
        x_best = 223.f;
    }


    Text actual_score(to_string(score),font);                 // on convertit le score en string pour l'afficher
    actual_score.setFillColor(Color::White);
    actual_score.setPosition(Vector2f(x_score,y_score));
    actual_score.setCharacterSize(18);


    Text text_best("BEST",font);
    text_best.setFillColor(Color::White);
    text_best.setPosition(Vector2f(245.f,29.f));
    text_best.setCharacterSize(12);
    RectangleShape rectangle_best;
    rectangle_best.setFillColor(couleurGrisFonce);
    rectangle_best.setPosition(Vector2f(216.f,23.f));
    rectangle_best.setSize(size_score_best);

    if (BEST < score) {
         BEST = score; 
     }

    Text actual_best(to_string(BEST),font);
    actual_best.setFillColor(Color::White);
    actual_best.setPosition(Vector2f(x_best,y_best));
    actual_best.setCharacterSize(18);

    Text text_new("NEW",font);
    text_new.setFillColor(Color::White);
    text_new.setPosition(Vector2f(145.f,90.f));
    text_new.setCharacterSize(16);
    RectangleShape rectangle_new;
    rectangle_new.setFillColor(couleurRouge);
    rectangle_new.setPosition(Vector2f(121.f,81.f));
    rectangle_new.setSize(size_new_quit);

    Text text_quit("QUIT",font);
    text_quit.setFillColor(Color::White);
    text_quit.setPosition(Vector2f(240.f,90.f));
    text_quit.setCharacterSize(16);
    RectangleShape rectangle_quit;
    rectangle_quit.setFillColor(couleurRouge);
    rectangle_quit.setPosition(Vector2f(216.f,81.f));
    rectangle_quit.setSize(size_new_quit);

    Text phrase("Join the numbers and get to the 2048 tile!",font);
    phrase.setFillColor(couleurGris);
    phrase.setPosition(Vector2f(25.f,137.f));
    phrase.setCharacterSize(14);

    RectangleShape grille;
    grille.setFillColor(couleurGris);
    grille.setPosition(Vector2f(16.f,168.f));
    grille.setSize(Vector2f(285.f,285.f));

    Text text_case1("2",font), text_case2("4",font), text_case3("8",font), text_case4("16",font);
    Text text_case5("32",font), text_case6("64",font), text_case7("128",font), text_case8("256",font);
    Text text_case9("512",font), text_case10("1024",font), text_case11("2048",font), text_case12("4096",font);
    Text text_case13("8192",font), text_case14("16384",font), text_case15("32768",font), text_case16("65536",font);
    Text text_case17("131072",font);
    RectangleShape case1, case2, case3, case4, case5, case6, case7, case8, case9, case10, case11, case12, case13;

    vector<Text> text_plateau;
    vector<RectangleShape> case_plateau;
    Vector2f size_case(59.f,59.f);
    Text texte;
    RectangleShape rect;
    for ( int i = 0; i < 4; i++ ) {
        for ( int j = 0; j < 4; j++ ) {
            float x_texte = 45+69*j;
            float y_texte = 188+69*i;
            switch(plateau[i][j]) {
                case 0:
                    rect.setFillColor(couleurGris2);
                    break;
                case 2:
                    rect = case1;
                    rect.setFillColor(couleur_rect2);
                    texte = text_case1;
                    texte.setFillColor(couleur_text2et4);
                    break;
                case 4:
                    rect = case2;
                    rect.setFillColor(couleur_rect4);
                    texte = text_case2;
                    texte.setFillColor(couleur_text2et4);
                    break;
                case 8:
                    rect = case3;
                    rect.setFillColor(couleur_rect8);
                    texte = text_case3;
                    texte.setFillColor(couleur_text_reste);
                    break;
                case 16:
                    rect = case4;
                    rect.setFillColor(couleur_rect16);
                    texte = text_case4;
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 8;
                    break;
                case 32:
                    rect = case5;
                    rect.setFillColor(couleur_rect32);
                    texte = text_case5;
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 8;
                    break;
                case 64:
                    rect = case6;
                    rect.setFillColor(couleur_rect64);
                    texte = text_case6;
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 8;
                    break;
                case 128:
                    rect = case7;
                    rect.setFillColor(couleur_rect128);
                    texte = text_case7;
                    texte.setCharacterSize(25);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 13.5;
                    y_texte = y_texte + 3;
                    break;
                case 256:
                    rect = case8;
                    rect.setFillColor(couleur_rect256);
                    texte = text_case8;
                    texte.setCharacterSize(25);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 12;
                    y_texte = y_texte + 3;
                    break;
                case 512:
                    rect = case9;
                    rect.setFillColor(couleur_rect512);
                    texte = text_case9;
                    texte.setCharacterSize(25);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 12;
                    y_texte = y_texte + 3;
                    break;
                case 1024:
                    rect = case10;
                    rect.setFillColor(couleur_rect1024);
                    texte = text_case10;
                    texte.setCharacterSize(20);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 14.5;
                    y_texte = y_texte + 6;
                    break;
                case 2048:
                    rect = case11;
                    rect.setFillColor(couleur_rect2048);
                    texte = text_case11;
                    texte.setCharacterSize(20);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 14.5;
                    y_texte = y_texte + 6;
                    break;
                case 4096:
                    rect = case12;
                    rect.setFillColor(couleur_rect4096);
                    texte = text_case12;
                    texte.setCharacterSize(20);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 14.5;
                    y_texte = y_texte + 6;
                    break;
                case 8192:
                    rect = case13;
                    rect.setFillColor(couleur_reste);
                    texte = text_case13;
                    texte.setCharacterSize(20);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 14.5;
                    y_texte = y_texte + 6;
                    break;
                case 16384:
                    rect = case13;
                    rect.setFillColor(couleur_reste);
                    texte = text_case14;
                    texte.setCharacterSize(17);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 15;
                    y_texte = y_texte + 9;
                    break;
                case 32768:
                    rect = case13;
                    rect.setFillColor(couleur_reste);
                    texte = text_case15;
                    texte.setCharacterSize(17);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 15;
                    y_texte = y_texte + 9;
                    break;
                case 65536:
                    rect = case13;
                    rect.setFillColor(couleur_reste);
                    texte = text_case16;
                    texte.setCharacterSize(17);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 15;
                    y_texte = y_texte + 9;
                    break;
                case 131072:
                    rect = case13;
                    rect.setFillColor(couleur_reste);
                    texte = text_case17;
                    texte.setCharacterSize(15);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 15;
                    y_texte = y_texte + 9;
                    break;
            }
            float x_rectangle = 25+69*j;  //coordonnées d'une tuile au tour de boucle d'indices i,j
            float y_rectangle = 177+69*i;
            rect.setPosition(Vector2f(x_rectangle,y_rectangle));
            texte.setPosition(Vector2f(x_texte,y_texte));
            rect.setSize(size_case);
            case_plateau.push_back(rect);
            text_plateau.push_back(texte);
        }
    }


    while (window.isOpen())
    {
        Event event;
        //la première chose que nous faisons dans la boucle principale est de regarder si des évènements se sont produits.
        while (window.pollEvent(event)) //La fonction pollEvent renvoie true si un évènement était en attente, ou false s'il n'y en avait aucun.
        {
             //on vérifie le type de l'évènement, et on réagit en conséquence si celui-ci nous intéresse
            if (event.type == Event::Closed) { //ici on s'intéresse à l'évènement "fenêtre fermée"
                window.close();  //la fenêtre se ferme
                exit(0);} //faire en sorte de ne pas revenir dans le main, mais de fermer le programme
            if (event.type == Event::KeyPressed) {
                return;
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                Vector2i mousePos = Mouse::getPosition(window);
                if ((mousePos.x > 216.f) and (mousePos.x < 301.f)and (mousePos.y > 81.f) and (mousePos.y < 119.f)) {
                    window.close();
                    exit(0);
                }
                if ((mousePos.x > 121.f) and (mousePos.x < 206.f)and (mousePos.y > 81.f) and (mousePos.y < 119.f)) {
                    window.close();
                    main();
                }

            }
        }
        
        window.clear(fond);
        window.draw(rectangle_2048);
        window.draw(text_2048);
        window.draw(rectangle_score);
        window.draw(text_score);
        window.draw(rectangle_best);
        window.draw(text_best);
        window.draw(rectangle_new);
        window.draw(text_new);
        window.draw(rectangle_quit);
        window.draw(text_quit);
        window.draw(phrase);
        window.draw(grille);
        window.draw(actual_score);
        window.draw(actual_best);
        for ( int i = 0; i < 4; i++ ) {
            for ( int j = 0; j < 4; j++ ) {
                window.draw(case_plateau[4*i+j]); // (i,j) -> (4*i + j) est une bijection de {0,1,2,3}**2 dans {0,...,15}
                if ( plateau[i][j] != 0 ) {
                    window.draw(text_plateau[4*i+j]);
                }
            }
        }
        window.display();
    }
}

void gdessine2(Plateau plateau, RenderWindow& window) { 
    
    Font font;
    font.loadFromFile("A little sunshine.ttf");
    
    Color fond(Color::Black);
    Color couleur1(222,49,80); //cerise
    Color couleur2(159,43,104); //amaranth
    Color couleur3(255,192,203); //rose gold224,191,184
    Color couleur4(190,175,160);
    Color couleur5(119,110,101);
    Color couleur_text_reste(249,246,242);
    Color couleur_rect2(216, 191, 216); // Thistle
    Color couleur_rect4(248, 152, 128);  // salmon
    Color couleur_rect8(250, 160, 160); 
    Color couleur_rect16(210, 120, 114); 
    Color couleur_rect32(247,126,104);
    Color couleur_rect64(247,97,71);
    Color couleur_rect128(227, 115, 131);
    Color couleur_rect256(255, 127, 80);
    Color couleur_rect512(200, 40, 90);
    Color couleur_rect1024(129, 19, 49);
    Color couleur_rect2048(255, 150, 255);
    Color couleur_rect4096(254,61,62);
    Color couleur_reste(255,32,33);

    Vector2f size_score_best(85.f,48.f);                       //taille des rectangles score et best
    Vector2f size_new_quit(85.f,38.f);                         // idem pour new et quit

    Text text_2048("2048",font);
    text_2048.setFillColor(Color::White);                      //couleur du texte
    text_2048.setPosition(Vector2f(35.f, 53.f));               //position du texte
    text_2048.setCharacterSize(30);                            // taille du texte
    RectangleShape rectangle_2048;                             // declaration du rectangle
    rectangle_2048.setFillColor(couleur_rect2048);             //couleur du rectangle
    rectangle_2048.setPosition(Vector2f(16.f, 23.f));          //position du rectangle
    rectangle_2048.setSize(Vector2f(96.f, 96.f));              //taille du rectangle (.f signifie que c'est un flottant)

    Text text_score("SCORE",font);
    text_score.setFillColor(Color::White);
    text_score.setPosition(Vector2f(146.f,29.f));
    text_score.setCharacterSize(12);
    RectangleShape rectangle_score;
    rectangle_score.setFillColor(couleur1);
    rectangle_score.setPosition(Vector2f(121.f,23.f));
    rectangle_score.setSize(size_score_best);

    int score = plateau[4][0];
    float x_score;
    float y_score = 45.f;
    if ( score < 10 ) {
        x_score = 160.f;
    } else if ( score < 100 ) {
        x_score = 152.f;
    } else if ( score < 1000 ) {
        x_score = 148.f;
    } else if ( score < 10000 ) {
        x_score = 142.f;
    } else if ( score < 100000 ) {
        x_score = 136.f;
    } else if ( score < 1000000 ) {
        x_score = 130.f;
    } 

    float x_best;
    float y_best = y_score;
    if ( BEST < 10 ) {
        x_best = 255.f;
    } else if ( BEST < 100 ) {
        x_best = 247.f;
    } else if ( BEST < 1000 ) {
        x_best = 241.f;
    } else if ( BEST < 10000 ) {
        x_best = 235.f;
    } else if ( BEST < 100000 ) {
        x_best = 229.f;
    } else if ( BEST < 1000000 ) {
        x_best = 227.f;
    }


    Text actual_score(to_string(score),font);                 // on convertit le score en string pour l'afficher
    actual_score.setFillColor(Color::White);
    actual_score.setPosition(Vector2f(x_score,y_score));
    actual_score.setCharacterSize(18);


    Text text_best("BEST",font);
    text_best.setFillColor(Color::White);
    text_best.setPosition(Vector2f(245.f,29.f));
    text_best.setCharacterSize(12);
    RectangleShape rectangle_best;
    rectangle_best.setFillColor(couleur1);
    rectangle_best.setPosition(Vector2f(216.f,23.f));
    rectangle_best.setSize(size_score_best);

    if (BEST < score) {
         BEST = score; 
     }

    Text actual_best(to_string(BEST),font);
    actual_best.setFillColor(Color::White);
    actual_best.setPosition(Vector2f(x_best,y_best));
    actual_best.setCharacterSize(18);

    Text text_new("NEW",font);
    text_new.setFillColor(Color::White);
    text_new.setPosition(Vector2f(145.f,90.f));
    text_new.setCharacterSize(16);
    RectangleShape rectangle_new;
    rectangle_new.setFillColor(couleur2);
    rectangle_new.setPosition(Vector2f(121.f,81.f));
    rectangle_new.setSize(size_new_quit);

    Text text_quit("QUIT",font);
    text_quit.setFillColor(Color::White);
    text_quit.setPosition(Vector2f(247.f,90.f));
    text_quit.setCharacterSize(16);
    RectangleShape rectangle_quit;
    rectangle_quit.setFillColor(couleur2);
    rectangle_quit.setPosition(Vector2f(216.f,81.f));
    rectangle_quit.setSize(size_new_quit);

    Text phrase("Join the numbers and get to the 2048 tile!",font);
    phrase.setFillColor(couleur3);
    phrase.setPosition(Vector2f(25.f,137.f));
    phrase.setCharacterSize(14);

    RectangleShape grille;
    grille.setFillColor(couleur3);
    grille.setPosition(Vector2f(16.f,168.f));
    grille.setSize(Vector2f(285.f,285.f));

    Text text_case1("2",font), text_case2("4",font), text_case3("8",font), text_case4("16",font);
    Text text_case5("32",font), text_case6("64",font), text_case7("128",font), text_case8("256",font);
    Text text_case9("512",font), text_case10("1024",font), text_case11("2048",font), text_case12("4096",font);
    Text text_case13("8192",font), text_case14("16384",font), text_case15("32768",font), text_case16("65536",font);
    Text text_case17("131072",font);
    RectangleShape case1, case2, case3, case4, case5, case6, case7, case8, case9, case10, case11, case12, case13;

    vector<Text> text_plateau;
    vector<RectangleShape> case_plateau;
    Vector2f size_case(59.f,59.f);
    Text texte;
    RectangleShape rect;
    for ( int i = 0; i < 4; i++ ) {
        for ( int j = 0; j < 4; j++ ) {
            float x_texte = 45+69*j;
            float y_texte = 188+69*i;
            switch(plateau[i][j]) {
                case 0:
                    rect.setFillColor(couleur4);
                    break;
                case 2:
                    rect = case1;
                    rect.setFillColor(couleur_rect2);
                    texte = text_case1;
                    texte.setFillColor(couleur5);
                    break;
                case 4:
                    rect = case2;
                    rect.setFillColor(couleur_rect4);
                    texte = text_case2;
                    texte.setFillColor(couleur5);
                    break;
                case 8:
                    rect = case3;
                    rect.setFillColor(couleur_rect8);
                    texte = text_case3;
                    texte.setFillColor(couleur_text_reste);
                    break;
                case 16:
                    rect = case4;
                    rect.setFillColor(couleur_rect16);
                    texte = text_case4;
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 6;
                    break;
                case 32:
                    rect = case5;
                    rect.setFillColor(couleur_rect32);
                    texte = text_case5;
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 6;
                    break;
                case 64:
                    rect = case6;
                    rect.setFillColor(couleur_rect64);
                    texte = text_case6;
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 6;
                    break;
                case 128:
                    rect = case7;
                    rect.setFillColor(couleur_rect128);
                    texte = text_case7;
                    texte.setCharacterSize(25);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 6;
                    y_texte = y_texte + 3;
                    break;
                case 256:
                    rect = case8;
                    rect.setFillColor(couleur_rect256);
                    texte = text_case8;
                    texte.setCharacterSize(25);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 6;
                    y_texte = y_texte + 3;
                    break;
                case 512:
                    rect = case9;
                    rect.setFillColor(couleur_rect512);
                    texte = text_case9;
                    texte.setCharacterSize(25);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 6;
                    y_texte = y_texte + 3;
                    break;
                case 1024:
                    rect = case10;
                    rect.setFillColor(couleur_rect1024);
                    texte = text_case10;
                    texte.setCharacterSize(20);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 9;
                    y_texte = y_texte + 6;
                    break;
                case 2048:
                    rect = case11;
                    rect.setFillColor(couleur_rect2048);
                    texte = text_case11;
                    texte.setCharacterSize(20);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 9;
                    y_texte = y_texte + 6;
                    break;
                case 4096:
                    rect = case12;
                    rect.setFillColor(couleur_rect4096);
                    texte = text_case12;
                    texte.setCharacterSize(20);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 9;
                    y_texte = y_texte + 6;
                    break;
                case 8192:
                    rect = case13;
                    rect.setFillColor(couleur_reste);
                    texte = text_case13;
                    texte.setCharacterSize(20);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 9;
                    y_texte = y_texte + 6;
                    break;
                case 16384:
                    rect = case13;
                    rect.setFillColor(couleur_reste);
                    texte = text_case14;
                    texte.setCharacterSize(17);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 12;
                    y_texte = y_texte + 9;
                    break;
                case 32768:
                    rect = case13;
                    rect.setFillColor(couleur_reste);
                    texte = text_case15;
                    texte.setCharacterSize(17);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 12;
                    y_texte = y_texte + 9;
                    break;
                case 65536:
                    rect = case13;
                    rect.setFillColor(couleur_reste);
                    texte = text_case16;
                    texte.setCharacterSize(17);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 12;
                    y_texte = y_texte + 9;
                    break;
                case 131072:
                    rect = case13;
                    rect.setFillColor(couleur_reste);
                    texte = text_case17;
                    texte.setCharacterSize(15);
                    texte.setFillColor(couleur_text_reste);
                    x_texte = x_texte - 12;
                    y_texte = y_texte + 9;
                    break;
            }
            float x_rectangle = 25+69*j;  //coordonnées d'une tuile au tour de boucle d'indices i,j
            float y_rectangle = 177+69*i;
            rect.setPosition(Vector2f(x_rectangle,y_rectangle));
            texte.setPosition(Vector2f(x_texte,y_texte));
            rect.setSize(size_case);
            case_plateau.push_back(rect);
            text_plateau.push_back(texte);
        }
    }


    while (window.isOpen())
    {
        Event event;
        //la première chose que nous faisons dans la boucle principale est de regarder si des évènements se sont produits.
        while (window.pollEvent(event)) //La fonction pollEvent renvoie true si un évènement était en attente, ou false s'il n'y en avait aucun.
        {
             //on vérifie le type de l'évènement, et on réagit en conséquence si celui-ci nous intéresse
            if (event.type == Event::Closed) { //ici on s'intéresse à l'évènement "fenêtre fermée"
                window.close();  //la fenêtre se ferme
                exit(0);} //faire en sorte de ne pas revenir dans le main, mais de fermer le programme
            if (event.type == Event::KeyPressed) {
                return;
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                Vector2i mousePos = Mouse::getPosition(window);
                if ((mousePos.x > 216.f) and (mousePos.x < 301.f)and (mousePos.y > 81.f) and (mousePos.y < 119.f)) {
                    window.close();
                    exit(0);
                }
                if ((mousePos.x > 121.f) and (mousePos.x < 206.f)and (mousePos.y > 81.f) and (mousePos.y < 119.f)) {
                    window.close();
                    main();
                }

            }
        }
        
        window.clear(fond);
        window.draw(rectangle_2048);
        window.draw(text_2048);
        window.draw(rectangle_score);
        window.draw(text_score);
        window.draw(rectangle_best);
        window.draw(text_best);
        window.draw(rectangle_new);
        window.draw(text_new);
        window.draw(rectangle_quit);
        window.draw(text_quit);
        window.draw(phrase);
        window.draw(grille);
        window.draw(actual_score);
        window.draw(actual_best);
        for ( int i = 0; i < 4; i++ ) {
            for ( int j = 0; j < 4; j++ ) {
                window.draw(case_plateau[4*i+j]); // 4*i + j est une bijection de {0,1,2,3}**2 dans {0,...,15}
                if ( plateau[i][j] != 0 ) {
                    window.draw(text_plateau[4*i+j]);
                }
            }
        }
        window.display();
    }
}

int jeu(RenderWindow& window){
    Font font;
    font.loadFromFile("ClearSans-Regular.ttf");
    Color fond(251,250,243);
    Color fond2(24,24,24);
    window.setVerticalSyncEnabled(true); //l'application se rafraîchit à la même fréquence que l'écran
    window.setPosition(Vector2i(450, 100)); //positionne la fenêtre au milieu de l'écran
    srand(time(0));

    Plateau P = plateauInitial();
    
	gdessine(P,window);
    while (!estTermine(P)) {
        window.clear(fond);
        Event event;
        int direction = 0;
        while (!window.pollEvent(event)) {
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                direction = 4;
                break;
            } else if (Keyboard::isKeyPressed(Keyboard::Right)) {
                direction = 3;
                break;
            } else if (Keyboard::isKeyPressed(Keyboard::Up)) {
                direction = 1;
                break;
            } else if (Keyboard::isKeyPressed(Keyboard::Down)) {
                direction = 2;
                break;
            }else if (event.type == Event::Closed) {
                window.close();
                return 0;
            }
        }
        if (direction != 0 and (P != deplacement(P,direction))) {
            P = ajouteCase(deplacement(P,direction));
        }
        if (!window.isOpen()) {
            return 0;
        }  
        gdessine(P,window);
        
    }
    
    while ( window.isOpen()) {
        window.clear(fond2);
        Text perdant("Vous avez perdu.. :(", font );
        Text perdant2("Mais n'abandonnez pas!\n Vous pouvez le faire :p",font);
        perdant.setFillColor(Color::Magenta);
        perdant2.setFillColor(Color::Magenta);
        perdant.setPosition(Vector2f(50.f,50.f));
        perdant2.setPosition(Vector2f(39.f,100.f));
        perdant.setCharacterSize(25);
        perdant2.setCharacterSize(23);
        
        Text text_new("Rejouer",font);
        text_new.setFillColor(Color::White);
        text_new.setPosition(Vector2f(47.f,290.f));
        text_new.setCharacterSize(16);
        RectangleShape rectangle_new;
        rectangle_new.setFillColor(Color::Black);
        rectangle_new.setPosition(Vector2f(31.f,281.f));
        rectangle_new.setSize(Vector2f(85.f,38.f));

        Text text_quit("Quitter",font);
        text_quit.setFillColor(Color::White);
        text_quit.setPosition(Vector2f(235.f,290.f));
        text_quit.setCharacterSize(16);
        RectangleShape rectangle_quit;
        rectangle_quit.setFillColor(Color::Black);
        rectangle_quit.setPosition(Vector2f(216.f,281.f));
        rectangle_quit.setSize(Vector2f(85.f,38.f));

        window.draw(perdant);
        window.draw(perdant2);
        window.draw(rectangle_new);
        window.draw(text_new);
        window.draw(rectangle_quit);
        window.draw(text_quit);
    
        window.display();
        if (Mouse::isButtonPressed(Mouse::Left)) {
            Vector2i mousePos = Mouse::getPosition(window);
            if ((mousePos.x > 216.f) and (mousePos.x < 301.f)and (mousePos.y > 281.f) and (mousePos.y < 319.f)) {
                window.close();
                exit(0);
            }
            if ((mousePos.x > 31.f) and (mousePos.x < 116.f) and (mousePos.y > 281.f) and (mousePos.y < 319.f)) {
                window.close();
                main();
            }

        }
    }

    return 0;
}

int jeu2(RenderWindow& window){

    Font font;
    font.loadFromFile("ClearSans-Regular.ttf");
    Color fond(27,27,27);
    window.setVerticalSyncEnabled(true); //l'application se rafraîchit à la même fréquence que l'écran
    window.setPosition(Vector2i(450, 100)); //positionne la fenêtre au milieu de l'écran
    srand(time(0));

    Plateau P = plateauInitial();
    // Plateau P = { {2,4,8,16}, {32,64,128,256}, {512,1024,2048,0}, {4096,2,4096,4096},{0} };
    //Plateau P = {{2,2,8,16},{256,128,64,32},{512,1024,2048,4096},{65536,32768,16384,8192},{2}};
	gdessine2(P,window);
    while (!estTermine(P)) {
        window.clear(fond);
        int direction = 0;
        Event event;
        while (!window.pollEvent(event)) {
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                direction = 4;
                break;
            } else if (Keyboard::isKeyPressed(Keyboard::Right)) {
                direction = 3;
                break;
            } else if (Keyboard::isKeyPressed(Keyboard::Up)) {
                direction = 1;
                break;
            } else if (Keyboard::isKeyPressed(Keyboard::Down)) {
                direction = 2;
                break;
            }else if (event.type == Event::Closed) {
                window.close();
                return 0;
            }

        }
        if (direction != 0 and (P != deplacement(P,direction))) {
            P = ajouteCase(deplacement(P,direction));
        }
        if (!window.isOpen()) {
            return 0;
        }  
        gdessine2(P,window);
        
    }

    

    while ( window.isOpen()) {
        window.clear(fond);
        Text perdant("Vous avez perdu.. :(", font );
        Text perdant2("Mais n'abandonnez pas!\n Vous pouvez le faire :p",font);
        perdant.setFillColor(Color::Magenta);
        perdant2.setFillColor(Color::Magenta);
        perdant.setPosition(Vector2f(50.f,50.f));
        perdant2.setPosition(Vector2f(39.f,100.f));
        perdant.setCharacterSize(25);
        perdant2.setCharacterSize(23);
        
        Text text_new("Rejouer",font);
        text_new.setFillColor(Color::White);
        text_new.setPosition(Vector2f(47.f,290.f));
        text_new.setCharacterSize(16);
        RectangleShape rectangle_new;
        rectangle_new.setFillColor(Color::Black);
        rectangle_new.setPosition(Vector2f(31.f,281.f));
        rectangle_new.setSize(Vector2f(85.f,38.f));

        Text text_quit("Quitter",font);
        text_quit.setFillColor(Color::White);
        text_quit.setPosition(Vector2f(235.f,290.f));
        text_quit.setCharacterSize(16);
        RectangleShape rectangle_quit;
        rectangle_quit.setFillColor(Color::Black);
        rectangle_quit.setPosition(Vector2f(216.f,281.f));
        rectangle_quit.setSize(Vector2f(85.f,38.f));

        window.draw(perdant);
        window.draw(perdant2);
        window.draw(rectangle_new);
        window.draw(text_new);
        window.draw(rectangle_quit);
        window.draw(text_quit);
    
        window.display();
        if (Mouse::isButtonPressed(Mouse::Left)) {
            Vector2i mousePos = Mouse::getPosition(window);
            if ((mousePos.x > 216.f) and (mousePos.x < 301.f)and (mousePos.y > 281.f) and (mousePos.y < 319.f)) {
                window.close();
                exit(0);
            }
            if ((mousePos.x > 31.f) and (mousePos.x < 116.f) and (mousePos.y > 281.f) and (mousePos.y < 319.f)) {
                window.close();
                main();
            }

        }
    }

    return 0;
}

int jeu3(RenderWindow& window){
    Font font;
    font.loadFromFile("ClearSans-Regular.ttf");
    Color fond(251,250,243);
    Color fond2(24,24,24);
    window.setVerticalSyncEnabled(true); //l'application se rafraîchit à la même fréquence que l'écran
    window.setPosition(Vector2i(450, 100)); //positionne la fenêtre au milieu de l'écran
    srand(time(0));

    Plateau P = {{2,2,8,16},{256,128,64,32},{512,1024,2048,4096},{65536,32768,16384,8192},{0}};
	gdessine(P,window);
    while (!estTermine(P)) {
        window.clear(fond);
        Event event;
        int direction = 0;
        while (!window.pollEvent(event)) {
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                direction = 4;
                break;
            } else if (Keyboard::isKeyPressed(Keyboard::Right)) {
                direction = 3;
                break;
            } else if (Keyboard::isKeyPressed(Keyboard::Up)) {
                direction = 1;
                break;
            } else if (Keyboard::isKeyPressed(Keyboard::Down)) {
                direction = 2;
                break;
            }else if (event.type == Event::Closed) {
                window.close();
                return 0;
            }
        }
        if (direction != 0 and (P != deplacement(P,direction))) {
            P = ajouteCase(deplacement(P,direction));
        }
        if (!window.isOpen()) {
            return 0;
        }  
        gdessine(P,window);
        
    }
    window.clear(fond);

    while ( window.isOpen()) {
        window.clear(fond2);
        Text perdant("Vous avez perdu.. :(", font );
        Text perdant2("Mais n'abandonnez pas!\n Vous pouvez le faire :p",font);
        perdant.setFillColor(Color::Magenta);
        perdant2.setFillColor(Color::Magenta);
        perdant.setPosition(Vector2f(50.f,50.f));
        perdant2.setPosition(Vector2f(39.f,100.f));
        perdant.setCharacterSize(25);
        perdant2.setCharacterSize(23);
        
        Text text_new("Rejouer",font);
        text_new.setFillColor(Color::White);
        text_new.setPosition(Vector2f(47.f,290.f));
        text_new.setCharacterSize(16);
        RectangleShape rectangle_new;
        rectangle_new.setFillColor(Color::Black);
        rectangle_new.setPosition(Vector2f(31.f,281.f));
        rectangle_new.setSize(Vector2f(85.f,38.f));

        Text text_quit("Quitter",font);
        text_quit.setFillColor(Color::White);
        text_quit.setPosition(Vector2f(235.f,290.f));
        text_quit.setCharacterSize(16);
        RectangleShape rectangle_quit;
        rectangle_quit.setFillColor(Color::Black);
        rectangle_quit.setPosition(Vector2f(216.f,281.f));
        rectangle_quit.setSize(Vector2f(85.f,38.f));

        window.draw(perdant);
        window.draw(perdant2);
        window.draw(rectangle_new);
        window.draw(text_new);
        window.draw(rectangle_quit);
        window.draw(text_quit);
    
        window.display();
        if (Mouse::isButtonPressed(Mouse::Left)) {
            Vector2i mousePos = Mouse::getPosition(window);
            if ((mousePos.x > 216.f) and (mousePos.x < 301.f)and (mousePos.y > 281.f) and (mousePos.y < 319.f)) {
                window.close();
                exit(0);
            }
            if ((mousePos.x > 31.f) and (mousePos.x < 116.f) and (mousePos.y > 281.f) and (mousePos.y < 319.f)) {
                window.close();
                main();
            }

        }
    }

    return 0;
}

int jeu4(RenderWindow& window){
    Font font;
    font.loadFromFile("ClearSans-Regular.ttf");
    Color fond2(24,24,24);
    window.setVerticalSyncEnabled(true); //l'application se rafraîchit à la même fréquence que l'écran
    window.setPosition(Vector2i(450, 100)); //positionne la fenêtre au milieu de l'écran
    srand(time(0));

    Plateau P = {{2,2,8,16},{256,128,64,32},{512,1024,2048,4096},{65536,32768,16384,8192},{0}};
	gdessine2(P,window);
    while (!estTermine(P)) {
        window.clear(fond2);
        int direction = 0;
        Event event;
        while (!window.pollEvent(event)) {
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                direction = 4;
                break;
            } else if (Keyboard::isKeyPressed(Keyboard::Right)) {
                direction = 3;
                break;
            } else if (Keyboard::isKeyPressed(Keyboard::Up)) {
                direction = 1;
                break;
            } else if (Keyboard::isKeyPressed(Keyboard::Down)) {
                direction = 2;
                break;
            }else if (event.type == Event::Closed) {
                window.close();
                return 0;
            }
        }
        if (direction != 0 and (P != deplacement(P,direction))) {
            P = ajouteCase(deplacement(P,direction));
        }
        if (!window.isOpen()) {
            return 0;
        }  
        gdessine2(P,window);
        
    }
    window.clear(fond2);

    while ( window.isOpen()) {
        window.clear(fond2);
        Text perdant("Vous avez perdu.. :(", font );
        Text perdant2("Mais n'abandonnez pas!\n Vous pouvez le faire :p",font);
        perdant.setFillColor(Color::Magenta);
        perdant2.setFillColor(Color::Magenta);
        perdant.setPosition(Vector2f(50.f,50.f));
        perdant2.setPosition(Vector2f(39.f,100.f));
        perdant.setCharacterSize(25);
        perdant2.setCharacterSize(23);
        
        Text text_new("Rejouer",font);
        text_new.setFillColor(Color::White);
        text_new.setPosition(Vector2f(47.f,290.f));
        text_new.setCharacterSize(16);
        RectangleShape rectangle_new;
        rectangle_new.setFillColor(Color::Black);
        rectangle_new.setPosition(Vector2f(31.f,281.f));
        rectangle_new.setSize(Vector2f(85.f,38.f));

        Text text_quit("Quitter",font);
        text_quit.setFillColor(Color::White);
        text_quit.setPosition(Vector2f(235.f,290.f));
        text_quit.setCharacterSize(16);
        RectangleShape rectangle_quit;
        rectangle_quit.setFillColor(Color::Black);
        rectangle_quit.setPosition(Vector2f(216.f,281.f));
        rectangle_quit.setSize(Vector2f(85.f,38.f));

        window.draw(perdant);
        window.draw(perdant2);
        window.draw(rectangle_new);
        window.draw(text_new);
        window.draw(rectangle_quit);
        window.draw(text_quit);
    
        window.display();
        if (Mouse::isButtonPressed(Mouse::Left)) {
            Vector2i mousePos = Mouse::getPosition(window);
            if ((mousePos.x > 216.f) and (mousePos.x < 301.f)and (mousePos.y > 281.f) and (mousePos.y < 319.f)) {
                window.close();
                exit(0);
            }
            if ((mousePos.x > 31.f) and (mousePos.x < 116.f) and (mousePos.y > 281.f) and (mousePos.y < 319.f)) {
                window.close();
                main();
            }

        }
    }

    return 0;
}

