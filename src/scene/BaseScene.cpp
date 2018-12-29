/*
** Copyright © 19/12/18 scollon
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
** purpose and noninfringement. In no event shall the authors or copyright holders X be liable for
** any claim, damages or other liability, whether in an action of contract, tort or otherwise, arising
** from, out of or in connection with the software or the use or other dealings in the Software.
** Except as contained in this notice, the name of the scollon shall not be used in advertising or
** otherwise to promote the sale, use or other dealings in this Software without prior written
** authorization from the scollon.
*/

#include <glad/glad.h>
#include "../utils/logger.h"
#include "../utils/types.h"
#include "BaseScene.h"
#include <iostream> // TODO replace cout by logger

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                   "}\n\0";
unsigned int VBO, VAO;
int shaderProgram;

BaseScene::BaseScene() : IScene()
{
}

void BaseScene::render()
{
	glClearColor(1.0, 0.0, 0.0, 1.0);

	glBindVertexArray(
			VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glUseProgram(shaderProgram);
}

void BaseScene::on_start()
{
	logger()->info("Start.");
	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader,
	               1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader,
		                   512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog <<
		          std::endl;
	}
// fragment shader
	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader,
	               1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
// check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader,
		                   512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog <<
		          std::endl;
	}
// link shaders
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader
	);
	glAttachShader(shaderProgram, fragmentShader
	);
	glLinkProgram(shaderProgram);
// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram,
		                    512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog <<
		          std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

// set up vertex data (and buffer(s)) and configure vertex attributes
// ------------------------------------------------------------------
	float vertices[] = {
			-0.5f, -0.5f, 0.0f, // left
			0.5f, -0.5f, 0.0f, // right
			0.0f, 0.5f, 0.0f  // top
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void BaseScene::*) 0);
	glEnableVertexAttribArray(0);

// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);
}

void BaseScene::on_stop()
{
	logger()->info("Stop.");
}

void BaseScene::on_update()
{

}

void BaseScene::on_window_resize(width w, height h)
{
	logger()->info("Window resize : {0} / {1}.", w, h);
}

void BaseScene::on_key(input::Event event)
{
	logger()->info("Key {0} with input_action {1}.", event.code, event.action);
}

void BaseScene::on_mouse_button(input::MouseEvent event)
{
	logger()->info("Mouse button {0} with input_action {1}.", event.code, event.action);
}

void BaseScene::on_mouse_move(position_2D position)
{
	logger()->info("Mouse position ({0}, {1}).", position.x, position.y);
}

void BaseScene::on_mouse_wheel(direction_2D direction)
{
	logger()->info("Mouse wheel direction : ({0}, {1}).", direction.x, direction.y);
}