#version 330 core

in vec3 vecColor;
in vec3 Normal;

out vec3 FragColor;

void main() {
    if(vecColor == vec3(-1.0, -1.0, -1.0)) {
        float c = dot(Normal, vec3(0.8,0.7,0.6));
        FragColor = vec3(c,c,c);
    } else {
        FragColor = vecColor;
    }
}