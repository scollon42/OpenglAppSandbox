#include <iostream>
#include <glad/glad.h>
#include "src/core/application/Application.h"
#include "src/core/IScene.h"
#include "src/scene/BaseScene.h"

//#define _DEBUG_
int main() {
#ifdef _DEBUG_
	logger_set_level(spdlog::level::debug);
#endif

    auto app = new Application;
    BaseScene scene;

    auto id = app->add_scene(&scene);
	app->set_current_scene(id);
	app->run(app);

	delete app;
    return 0;
}