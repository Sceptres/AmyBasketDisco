#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 inTextCoord;

out vec3 vecColor;
out vec3 Normal;
out vec2 TextCoord;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform bool isDebug;

void main() {
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    FragPos = aPos;

    if(!isDebug) { // If the system is not in debug mode, color verticies as expected
        vecColor = vec3(-1.0, -1.0, -1.0);
    } else { // If the system is in debug mode set all verticies color to black
        vecColor = vec3(0.0, 0.0, 0.0);
    }

    Normal = normal;            // Set vertex normal
    TextCoord = inTextCoord;    // Set vertex texture coordinate
}