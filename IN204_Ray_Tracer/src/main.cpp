#include "IN204_Ray_Tracer/IN204_Ray_Tracer.hpp"
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

int main(int argc, const char** argv) {
    std::cout << "Hello world" << std::endl;

    sf::Window window(sf::VideoMode(800, 600), "My window");


    /*sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;
    sf::Window window_gl(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, settings);
    glEnable(GL_TEXTURE_2D);*/

    // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
    while (window.isOpen()) {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la
        // précédente itération
        sf::Event event;
        while (window.pollEvent(event)) {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}

/*JSON => rapidjson
XML => rapidxml
Graphics 
SFML
QT
wxWidgets
Bibliothèque étendant la bibliothèque générale de C++: Boost
Bibliothèqe pour lire les archives => 7zip.
*/