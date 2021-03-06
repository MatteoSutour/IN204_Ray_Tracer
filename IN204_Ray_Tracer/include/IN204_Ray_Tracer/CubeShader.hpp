#include <GL\glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

class CubeShader {
private:
    float cote;
    float* pos;

public:

    explicit CubeShader(float myCote, float myPos[3]) : cote(myCote), pos(myPos) {};
    ~CubeShader() {};

    void renderCubeShader(float cote, float* centre) {
        // Code pour le Vertex Shader (Position)
        const char* vertexShaderSource = "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0";

        // Code pour le Fragment Shader (Couleur)
        const char* fragmentShaderSource = "#version 330 core\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
            "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
            "}\0";

        //Sommets

        float vertices[] = {
            pos[0],  pos[1], pos[2],
            pos[0] + cote,  pos[1], pos[2],
            pos[0] + cote,  pos[1] + cote, pos[2],
            pos[0],  pos[1] + cote, pos[2],
            pos[0],  pos[1] + cote, pos[2] + cote,
            pos[0] + cote,  pos[1] + cote, pos[2] + cote,
            pos[0] + cote,  pos[1], pos[2] + cote,
            pos[0],  pos[1], pos[2] + cote
        };
        unsigned int indices[] = {  // note that we start from 0!
        0, 1, 2,
        2, 3, 0,
        2, 3, 5,
        3, 4, 5,
        1, 2, 5,
        1, 5, 6,
        0, 1, 6,
        0, 6, 7,
        4, 5, 6,
        4, 6, 7,
        0, 3, 4,
        0, 4, 7
        };

        unsigned int VBO;
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        unsigned int EBO;
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);

        int  success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        //Shader Program : fait le lien entre les shaders combinés
        unsigned int shaderProgram;
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        glUseProgram(shaderProgram);
        //On n'a plus besoin des vertex et fragment shaders liés dans le shader program :
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        //On doit spécifier comment OpenGL interprete les données de sommets :
        glBindVertexArray(VBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }
};