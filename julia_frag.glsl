#version 330 core

#ifdef GL_FRAGMENT_PRECISION_HIGH
precision highp float;
#else
precision mediump float;
#endif
precision mediump int;

in vec2 pos;
out vec4 FragColor;

uniform vec2 C;
uniform float R;
uniform float max_steps;
uniform vec4 max_color;
uniform vec4 min_color;

float cosh(float val){
    float tmp = exp(val);
    float cosH = (tmp + 1.0 / tmp) / 2.0;
    return cosH;
    }

float sinh(float val)
{
    float tmp = exp(val);
    float sinH = (tmp - 1.0 / tmp) / 2.0;
    return sinH;
}


void main(){
    vec4 base_color = vec4(0.0f, 0.0f, 0.0f, 1.0f);
    
    FragColor = base_color;
    float diff = 0.0f;
    float u;
    float v;
    float w_r = pos.x;
    float w_i = pos.y;
    float c_r = C.x;
    float c_i = C.y;
    
    for(int i = 0; i < max_steps; i++){
        u = w_r;
        v = w_i;
        
        %%%%%

        if (w_r*w_r + w_i*w_i > (R*R)){
            FragColor = mix(min_color, max_color, (1.0f/max_steps) * i);
            break;
            }
        }
    }