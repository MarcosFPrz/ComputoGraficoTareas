#version 430 core

out vec4 fragmentColorCube;
in vec4 colorCube;

void main()
{
	fragmentColorCube = colorCube;
}