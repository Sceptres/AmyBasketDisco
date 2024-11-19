#version 330 core

in vec3 vecColor;
in vec3 Normal;
in vec2 TextCoord;

out vec4 FragColor;

uniform sampler2D Texture;

void main() {
    if(vecColor == vec3(-1.0, -1.0, -1.0)) { // If the system is not in debug mode, ignore vecColor
        FragColor = texture(Texture, TextCoord);
    } else {
        FragColor = vec4(vecColor, 1.0);
    }
}