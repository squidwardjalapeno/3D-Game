#pragma once
#include<iostream>
#include<GLFW/glfw3.h>


class Window
{
public:

	GLFWwindow* window;
	Window(int width, int height);

};