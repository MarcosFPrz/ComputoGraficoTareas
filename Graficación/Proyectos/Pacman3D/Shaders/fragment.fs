#version 430 core

out vec4 fragmentColor;
uniform vec4 vColor;

void main()
{
	fragmentColor = vColor;
}