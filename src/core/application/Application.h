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

#ifndef OPENGGLAPP_APPLICATION_H
#define OPENGGLAPP_APPLICATION_H

#include <map>
#include <GLFW/glfw3.h>
#include "input_event_type.h"
#include "../../utils/types.h"
#include "../IScene.h"

void glfw_error_callback(int error, const char *description) noexcept;

class Application
{
  public:
	Application();

	~Application();

	scene_id add_scene(IScene *scene) noexcept;

	void set_current_scene(scene_id id) noexcept;

	void run(Application *app) noexcept;

	void start() noexcept;

	void stop() noexcept;

  private:
	GLFWwindow *window;
	bool running;

	IScene *current_scene;
	std::map<scene_id, IScene *> scenes;

	void on_window_resize(width w, height h);

	void on_key(input::Event event);

	void on_mouse_button(input::MouseEvent event);

	void on_mouse_move(position_2D position);

	void on_mouse_wheel(direction_2D direction);

	static Application *application;

	static void glfw_on_resize(GLFWwindow *window, int w, int h) noexcept;

	static void glfw_on_key(GLFWwindow *window, int key, int scancode, int action, int mods) noexcept;

	static void glfw_on_mouse_button(GLFWwindow *window, int button, int action, int mods) noexcept;

	static void glfw_on_mouse_move(GLFWwindow *window, double x, double y) noexcept;

	static void glfw_on_mouse_wheel(GLFWwindow *window, double xoffset, double yoffset) noexcept;
};


#endif //OPENGGLAPP_APPLICATION_H
