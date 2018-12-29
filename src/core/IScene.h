/*
** Copyright © 17/12/18 scollon
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
** any claim, damages or other liability, whether in an input_action of contract, tort or otherwise, arising
** from, out of or in connection with the software or the use or other dealings in the Software.
** Except as contained in this notice, the name of the scollon shall not be used in advertising or
** otherwise to promote the sale, use or other dealings in this Software without prior written
** authorization from the scollon.
*/

#ifndef OPENGGLAPP_SCENE_H
#define OPENGGLAPP_SCENE_H

#include "utils/types.h"
#include "application/input_event_type.h"

using scene_id = unsigned long;

class IScene
{
  public:
	IScene() : running(true) {};
	~IScene() = default;

	virtual void render() = 0;
	virtual void on_start() = 0;
	virtual void on_stop() = 0;
	virtual void on_update() = 0;
	virtual void on_window_resize(width w, height h) = 0;
	virtual void on_key(input::Event event) = 0;
	virtual void on_mouse_button(input::MouseEvent event) = 0;
	virtual void on_mouse_move(position_2D position) = 0;
	virtual void on_mouse_wheel(direction_2D direction) = 0;
	virtual bool is_running() const { return running; };
  private:
	bool running;
};


#endif //OPENGGLAPP_SCENE_H
