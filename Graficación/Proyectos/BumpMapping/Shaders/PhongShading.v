#version 430 core

layout (location = 0) in vec4 vPosition;

uniform mat4 mTransform;
uniform mat4 camera;
uniform mat4 perspective;

uniform float fTime;
out vec4 observedPosition;


void main()
{
	vec4 vNewVec = vPosition;
	//calculamos la altura de este vertice

	//Esto va a llegar interpolado
	observedPosition = vPosition;

	gl_Position = perspective * camera * mTransform * vNewVec;
}