#version 330 core

#ifdef GL_FRAGMENT_PRECISION_HIGH
precision highp float;
#else
precision mediump float;
#endif
precision mediump int;

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 cons;
out vec2 pos;

uniform mat4 trans;

void main(){
    pos = vec2(aPos.x, aPos.y);
    gl_Position = trans * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    }