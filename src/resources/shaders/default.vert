#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 normal;

out vec3 vecColor;
out vec3 Normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform bool isDebug;

void main() {
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    if(!isDebug) {
        vecColor = vec3(-1.0, -1.0, -1.0);
    } else {
        vecColor = vec3(0.0, 0.0, 0.0);
    }

    Normal = normal;
}