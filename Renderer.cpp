#include "Renderer.h"
#include <iostream>

#define WIDTH 1000
#define HEIGHT 1000

int n = 0;
glm::mat4 trans = glm::mat4(1.0f);

Renderer::Renderer(Monitor* screen){
    window = screen->GLFW_init();
    screen->OpenGL_init();
    }

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_Q && action == GLFW_PRESS && n > 0 && n <= 10){
        n--;
        }
    else if (key == GLFW_KEY_E && action == GLFW_PRESS && n >= 0 && n < 9){
        n++;
        }
    }

void mouse_input(GLFWwindow* win, int button, int action, int mods){
    double xpos, ypos;
    glfwGetCursorPos(win, &xpos, &ypos);
        
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
        
         //GLFW -> OpenGL normalized
        //float n_x = (2 *xpos)/WIDTH - 1;
        //float n_y = (-2*ypos)/HEIGHT + 1;
        
        //center[0] -= n_x;
        //center[1] -= n_y;
        //trans = glm::translate(trans, glm::vec3(center[0], center[1], 0.0f));
        trans = glm::scale(trans, glm::vec3(2.0f, 2.0f, 2.0f));
        
        }
    else if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS){
        trans = glm::scale(trans, glm::vec3(0.5f, 0.5f,0.5f));
        
        }
    }
    
void Renderer::manage_input(){
    
    std::cout << "Current setting: " << names[n] << " = " << *settings[n] << "           \r";
        
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
		glfwSetWindowShouldClose(window, true);
		}   
    
    // Modify setting
    else if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS && *settings[n] < maximum[n]){
        *settings[n] += intervals[n];
        }
    else if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS && *settings[n] > minimum[n]){
        *settings[n] -= intervals[n];
        }
    }
   
void Renderer::run(int programID){
    glfwSetMouseButtonCallback(window, mouse_input);
    glfwSetKeyCallback(window, key_callback);
    
    float vertices[] = {    
         2.0f,  2.0f, 0.0f,  // top right
         2.0f, -2.0f, 0.0f,  // bottom right
         -2.0f, -2.0f, 0.0f,  // bottom left
         -2.0f, 2.0f, 0.0f   // top left 
        };
    
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
        };
    
    GLuint VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0); 
    
    trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
    
    while (!glfwWindowShouldClose(window)){
        manage_input();
        
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(programID);
        
        GLuint cID = glGetUniformLocation(programID, "C");
        GLuint rID = glGetUniformLocation(programID, "R");
        GLuint sID = glGetUniformLocation(programID, "max_steps");
        GLuint tID = glGetUniformLocation(programID, "trans");
        GLuint rcID = glGetUniformLocation(programID, "max_color");
        GLuint lcID = glGetUniformLocation(programID, "min_color");
        
        glUniform2fv(cID, 1, c);
        glUniform4fv(rcID, 1, right_color);
        glUniform4fv(lcID, 1, left_color);
        glUniform1f(rID, R);
        glUniform1f(sID, ms);
        glUniformMatrix4fv(tID, 1, GL_FALSE, glm::value_ptr(trans));
        
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
        }
        
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(programID);

    glfwTerminate();
    }