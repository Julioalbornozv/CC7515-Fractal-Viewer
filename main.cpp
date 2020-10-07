#include "Renderer.h"
#include "ShaderManager.h"
#include <iostream>
#include <string>
#include <map>

#define WIDTH 1000
#define HEIGHT 1000


int main(int argc, char** argv){
    std::map<int, std::string> options;
    options[0] = "w_r = u*u - v*v + c_r;w_i = 2.0*u*v + c_i;\n";
    options[1] = "w_r = u*u*u - 3.0*u*v*v + c_r;w_i = 3.0*u*u*v - v*v*v + c_i;\n";
    options[2] = "w_r = exp(u)*u*cos(v) - exp(u)*v*sin(v) +c_r;w_i = exp(u)*v*cos(v) + exp(u)*u*sin(v) +c_i;\n";
    options[3] = "w_r = u*u*cos(u)*cosh(v) - v*v*cos(u)*cosh(v) + 2*u*v*sin(u)*sinh(v) +c_r;w_i = 2*u*v*cos(u)*cosh(v) - u*u*sin(u)*sinh(v) + v*v*sin(u)*sinh(v)+c_i;\n";
    
    // Initialize GLFW
    // Initialize OpenGL
    Monitor screen = Monitor(WIDTH, HEIGHT);
    
    
    // Query formula
    std::string equation;
    int input;
    std::cout << "Select a formula to be computed:\n    0.- z^2+C\n    1.- z^3+C\n    2.- z*exp(z)\n    3.- z^2*cos(z)" << std::endl;
    std::cin >> input;
    
    equation = options[input];
    // Initialize OpenGL and GLFW
    Renderer Rd = Renderer(&screen);
    
    // Compile shaders
    ShaderManager manager = ShaderManager("julia_vert.glsl", equation, "julia_frag.glsl");
    int shaderProgram = manager.compile_shaders();
    
    // Run render loop
    Rd.run(shaderProgram);
    }