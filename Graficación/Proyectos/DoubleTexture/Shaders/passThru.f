#version 430 core

out vec4 fColor;
out vec4 fColor2;
out vec4 fColor3;
in vec4 color;
uniform sampler2D texture0;
uniform sampler2D texture1;
uniform sampler2D texture3;

in vec2 textureCoords;

void main()
{
    fColor =  mix (texture(texture0, textureCoords), texture(texture1, textureCoords), 0.5);
}
