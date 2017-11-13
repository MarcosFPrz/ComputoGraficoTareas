#version 430 core

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec4 vColor;

out vec4 colorCube;
//uniform float angleCube;
uniform mat4 transformCube;

void main()
{
	colorCube = vColor;
	gl_Position = transformCube * vPosition;
}