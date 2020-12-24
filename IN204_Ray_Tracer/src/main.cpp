#include "IN204_Ray_Tracer/IN204_Ray_Tracer.hpp"
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

int main(int argc, const char** argv) {
    std::cout << "Hello Matteo !" << std::endl;

    /*
    sf::Window window(sf::VideoMode(800, 600), "My window");

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
    */

    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;
    sf::Window window_gl(sf::VideoMode(800, 600), "OpenGL works !!", sf::Style::Default, settings);
    glEnable(GL_TEXTURE_2D);

    window_gl.setVerticalSyncEnabled(true);

    // chargement des ressources, initialisation des états OpenGL, ...

    // la boucle principale
    bool running = true;
    while (running)
    {
        // gestion des évènements
        sf::Event event;
        while (window_gl.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // on stoppe le programme
                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                // on ajuste le viewport lorsque la fenêtre est redimensionnée
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        // effacement les tampons de couleur/profondeur
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // dessin...

        // termine la trame courante (en interne, échange les deux tampons de rendu)
        window_gl.display();
    }

    // libération des ressources...

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