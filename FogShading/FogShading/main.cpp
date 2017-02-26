#include "glew.h"
#include "freeglut.h"
#include "ShaderLoader.hpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace Core;

GLuint program, vertex_shader, fragment_shader;
GLuint vertex_array_object;

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0); //clear red

	//use created program
	glUseProgram(program);

	//draw 3 certices as triangle
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glutSwapBuffers();
}

void Init()
{
	//load and compile shaders
	Core::ShaderLoader shader_loader = Core::ShaderLoader::ShaderLoader();
	program = shader_loader.CreateProgram("Vertex_Shader.glsl", "Fragment_Shader.glsl");

	//generate vertex array
	glGenVertexArrays(1, &vertex_array_object);
	glBindVertexArray(vertex_array_object);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}


int main(int argc, char**argv)
{
	// creating a windows using FreeGLUT
	glutInit(&argc, argv);											// initializing GLUT library
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);		//determine OpenGL dispay mode for new Window
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL Fogshading");

	glewInit();						// initializing glew
	Init();							// call initialition function

	glutDisplayFunc(renderScene);	// call render function

	glutMainLoop();
	glDeleteProgram(program);
	return 0;
}
