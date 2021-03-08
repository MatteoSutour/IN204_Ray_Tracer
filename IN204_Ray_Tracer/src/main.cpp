#include "IN204_Ray_Tracer/IN204_Ray_Tracer.hpp"
#include "IN204_Ray_Tracer/CubeShader.hpp"
#include "IN204_Ray_Tracer/Vec3.hpp"
#include "IN204_Ray_Tracer/Sphere.hpp"
#include "IN204_Ray_Tracer/Cube.hpp"
#include "IN204_Ray_Tracer/lancerRayon.hpp"

#include <GL\glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

int main(int argc, const char** argv) {
    std::cout << "Hello Matteo" << std::endl;


    //srand48(13);
    std::vector<std::unique_ptr<Object>> objects;
    // position, radius, surface color, reflectivity, transparency, emission color
    objects.push_back(std::unique_ptr<Object>(new Sphere(Vec3f(0.0, -10004, -20), 10000, Vec3f(0.2f, 0.2f, 0.2f), 0.5, 0.0)));
    objects.push_back(std::unique_ptr<Object>(new Sphere(Vec3f(-10, 4, -20), 4, Vec3f(1.00f, 0.20f, 0.20f), 1, 0.5)));
    objects.push_back(std::unique_ptr<Object>(new Sphere(Vec3f(0.0, 0, -20), 4, Vec3f(0.20f, 0.80f, 0.80f), 1, 0.5)));
    objects.push_back(std::unique_ptr<Object>(new Sphere(Vec3f(8.0, -1, -15), 2, Vec3f(0.10f, 0.90f, 0.46f), 1, 0.5)));
    objects.push_back(std::unique_ptr<Object>(new Sphere(Vec3f(6.0, 0, -25), 3, Vec3f(0.65f, 0.77f, 0.97f), 1, 0.5)));
    objects.push_back(std::unique_ptr<Object>(new Sphere(Vec3f(-5.5, 0, -15), 3, Vec3f(0.6f, 0.6f, 0.0f), 1, 0.5)));
    //objects.push_back(std::unique_ptr<Object>(new Cube(Vec3f(-5.5, 0, -15), Vec3f(0, 5.5, -20.5), Vec3f(0.90f, 0.90f, 0.90f), 1, 0.0)));
    // light
    // Le dernier argument correspond à emissionColor, si emissionColor > 0 alors il s'agit d'une lumière.
    objects.push_back(std::unique_ptr<Object>(new Sphere(Vec3f(0.0, 20, -30), 3, Vec3f(0.00, 0.00, 0.00), 0, 0.0, Vec3f(3))));
    render(objects);


    /*
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;
    sf::Window window_gl(sf::VideoMode(800, 600), "OpenGL works !!", sf::Style::Default, settings);
    glEnable(GL_TEXTURE_2D);

    window_gl.setVerticalSyncEnabled(true);

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        // Problem: glewInit failed, something is seriously wrong.
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

    // chargement des ressources, initialisation des états OpenGL, ...

    float pos[3] = { 0.0f, 0.0f, 0.0f };
    CubeShader MyCube(0.5f, pos);

    MyCube.renderCubeShader(0.5f, pos);

    // la boucle principale
    bool running = true;
    while (running)
    {
        // gestion des �v�nements
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
                // on ajuste le viewport lorsque la fen�tre est redimensionn�e
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        // effacement les tampons de couleur/profondeur
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // dessin...
        //glUseProgram(shaderProgram);
        //glBindVertexArray(VBO);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        // termine la trame courante (en interne, �change les deux tampons de rendu)
        window_gl.display();
    }

    // lib�ration des ressources...
    */
    
    return 0;
}