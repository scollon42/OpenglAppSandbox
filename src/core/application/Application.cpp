/*
** Copyright © 16/12/18, scollon
**
** Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
** associated documentation files (the “Software”), to deal in the Software without restriction,
** including without limitation the rights to use, copy, modify, merge, publish, distribute,
** sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in all copies or substantial
** portions of the Software.
**
** The Software is provided “as is”, without warranty of any kind, express or implied,
** including but not limited to the warranties of merchantability, fitness for a particular
** purpose and noninfingement. In no event shall the authors or copyright holders X be liable for
** any claim, damages or other liability, whether in an input_action of contract, tort or otherwise, arising
** from, out of or in connection with the software or the use or other dealings in the Software.
** Except as contained in this notice, the name of the scollon shall not be used in advertising or
** otherwise to promote the sale, use or other dealings in this Software without prior written
** authorization from the scollon.
*/

#include <glad/glad.h>
#include "Application.h"
#include "../../utils/logger.h"

Application * Application::application = nullptr;

void glfw_error_callback(int error, const char *description) noexcept
{
	logger()->error("Glfw Error [{0}] : {1}.", error, description);
}

Application::Application()
		:
		window(nullptr),
		running(false)
{}

Application::~Application()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

scene_id Application::add_scene(IScene *scene) noexcept
{
	scene_id id = scenes.size();
	scenes[id] = scene;
	return id;
}

void Application::set_current_scene(scene_id id) noexcept
{
	current_scene = scenes[id];
}

void Application::run(Application *app) noexcept
{
	running = true;
	application = app;

	if (current_scene == nullptr)
		current_scene = scenes[0];

	logger()->debug("Glfw version : {0}.", glfwGetVersionString());

	glfwSetErrorCallback(glfw_error_callback);

	if (!glfwInit())
	{
		logger()->error("Failed to initialized GLFW");
		return ;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(800, 600, "test", nullptr, nullptr);

	if (!window)
	{
		logger()->error("Failed to create window");
		return ;
	}

	glfwMakeContextCurrent(window);

	glfwSetWindowSizeCallback(window, glfw_on_resize);
	glfwSetKeyCallback(window, glfw_on_key);
	glfwSetMouseButtonCallback(window, glfw_on_mouse_button);
	glfwSetCursorPosCallback(window, glfw_on_mouse_move);
	glfwSetScrollCallback(window, glfw_on_mouse_wheel);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		logger()->error("Failed to initialized GLAD");
		return ;
	}

	logger()->debug("OpenGL version [{0}].", glGetString(GL_VERSION));
	logger()->debug("OpenGL vendor [{0}].", glGetString(GL_VENDOR));
	logger()->debug("OpenGL renderer [{0}].", glGetString(GL_RENDERER));

	while (running)
	{
		start();

		while (running && current_scene->is_running())
		{
			glClear(GL_COLOR_BUFFER_BIT);

			current_scene->render();

			glfwSwapBuffers(window);
			glfwPollEvents();
			current_scene->on_update();
			running &= (glfwWindowShouldClose(window) != GL_TRUE);
		}

		stop();
	}
}

void Application::start() noexcept
{
	current_scene->on_start();
}

void Application::stop() noexcept
{
	current_scene->on_stop();
}

void Application::on_window_resize(width w, height h)
{
	current_scene->on_window_resize(w, h);
}

void Application::on_key(input::Event event)
{
	current_scene->on_key(event);
}

void Application::on_mouse_button(input::Event event)
{
	current_scene->on_mouse_button(event);
}

void Application::on_mouse_move(position_2D position)
{
	current_scene->on_mouse_move(position);
}

void Application::on_mouse_wheel(direction_2D direction)
{
	current_scene->on_mouse_wheel(direction);
}

void Application::glfw_on_resize(GLFWwindow *window, int w, int h) noexcept
{
	logger()->debug("Glfw event resize [{0} / {1}].", w, h);
	application->on_window_resize(w, h);
}

void Application::glfw_on_key(GLFWwindow *window, int key, int scancode, int action, int mods) noexcept
{
	logger()->debug("Glfw event input ({0}, {1}, {2}, {3}).", key, scancode, action, mods);
	application->on_key(input::Event(key, action));
}

void Application::glfw_on_mouse_button(GLFWwindow *window, int button, int action, int mods) noexcept
{
	logger()->debug("Glfw event mouse button [{0}, {1}, {2}].", button, action, mods);
	application->on_mouse_button(input::Event(button, action));
}

void Application::glfw_on_mouse_move(GLFWwindow *window, double x, double y) noexcept
{
	logger()->debug("Glfw event mouse move [{0} / {1}].", x, y);
	application->on_mouse_move(position_2D(x, y));
}

void Application::glfw_on_mouse_wheel(GLFWwindow *window, double xoffset, double yoffset) noexcept
{
	logger()->debug("Glfw event mouse wheel [{0} / {1}].", xoffset, yoffset);
	application->on_mouse_wheel(direction_2D(xoffset, yoffset));
}
