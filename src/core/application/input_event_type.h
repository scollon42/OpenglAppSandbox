/*
** Copyright © 18/12/18 scollon
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

#ifndef OPENGGLAPP_KEYEVENTTYPE_H
#define OPENGGLAPP_KEYEVENTTYPE_H

#include <GLFW/glfw3.h>
#include <string>

namespace input
{
	using input_code = int;
	using input_action = int;

	constexpr input_action PRESSED = GLFW_PRESS;
	constexpr input_action RELEASED = GLFW_RELEASE;
	constexpr input_action HOLD = GLFW_REPEAT;

	constexpr input_code Q = GLFW_KEY_Q;
	constexpr input_code W = GLFW_KEY_W;
	constexpr input_code E = GLFW_KEY_E;
	constexpr input_code R = GLFW_KEY_R;
	constexpr input_code T = GLFW_KEY_T;
	constexpr input_code Y = GLFW_KEY_Y;
	constexpr input_code U = GLFW_KEY_U;
	constexpr input_code I = GLFW_KEY_I;
	constexpr input_code O = GLFW_KEY_O;
	constexpr input_code P = GLFW_KEY_P;
	constexpr input_code A = GLFW_KEY_A;
	constexpr input_code S = GLFW_KEY_S;
	constexpr input_code D = GLFW_KEY_D;
	constexpr input_code F = GLFW_KEY_F;
	constexpr input_code G = GLFW_KEY_G;
	constexpr input_code H = GLFW_KEY_H;
	constexpr input_code J = GLFW_KEY_J;
	constexpr input_code K = GLFW_KEY_K;
	constexpr input_code L = GLFW_KEY_L;
	constexpr input_code Z = GLFW_KEY_Z;
	constexpr input_code X = GLFW_KEY_X;
	constexpr input_code C = GLFW_KEY_C;
	constexpr input_code V = GLFW_KEY_V;
	constexpr input_code B = GLFW_KEY_B;
	constexpr input_code N = GLFW_KEY_N;
	constexpr input_code M = GLFW_KEY_M;
	constexpr input_code F1 = GLFW_KEY_F1;
	constexpr input_code F2 = GLFW_KEY_F2;
	constexpr input_code F3 = GLFW_KEY_F3;
	constexpr input_code F4 = GLFW_KEY_F4;
	constexpr input_code F5 = GLFW_KEY_F5;
	constexpr input_code F6 = GLFW_KEY_F6;
	constexpr input_code F7 = GLFW_KEY_F7;
	constexpr input_code F8 = GLFW_KEY_F8;
	constexpr input_code F9 = GLFW_KEY_F9;
	constexpr input_code F10 = GLFW_KEY_F10;
	constexpr input_code F11 = GLFW_KEY_F11;
	constexpr input_code F12 = GLFW_KEY_F12;
	constexpr input_code F13 = GLFW_KEY_F13;
	constexpr input_code F14 = GLFW_KEY_F14;
	constexpr input_code F15 = GLFW_KEY_F15;
	constexpr input_code F16 = GLFW_KEY_F16;
	constexpr input_code F17 = GLFW_KEY_F17;
	constexpr input_code F18 = GLFW_KEY_F18;
	constexpr input_code F19 = GLFW_KEY_F19;
	constexpr input_code F20 = GLFW_KEY_F20;
	constexpr input_code F21 = GLFW_KEY_F21;
	constexpr input_code F22 = GLFW_KEY_F22;
	constexpr input_code F23 = GLFW_KEY_F23;
	constexpr input_code F24 = GLFW_KEY_F24;
	constexpr input_code F25 = GLFW_KEY_F25;

	constexpr input_code SPACE = GLFW_KEY_SPACE;
	constexpr input_code APOSTROPHE = GLFW_KEY_APOSTROPHE;
	constexpr input_code COMMA = GLFW_KEY_COMMA;
	constexpr input_code MINUS = GLFW_KEY_MINUS;
	constexpr input_code PERIOD = GLFW_KEY_PERIOD;
	constexpr input_code SLASH = GLFW_KEY_SLASH;
	constexpr input_code SEMICOLON = GLFW_KEY_SEMICOLON;
	constexpr input_code EQUAL = GLFW_KEY_EQUAL;
	constexpr input_code LEFT_BRACKET = GLFW_KEY_LEFT_BRACKET;
	constexpr input_code BACKSLASH = GLFW_KEY_BACKSLASH;
	constexpr input_code RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET;
	constexpr input_code GRAVE_ACCENT = GLFW_KEY_GRAVE_ACCENT;
	constexpr input_code ESCAPE = GLFW_KEY_ESCAPE;
	constexpr input_code ENTER = GLFW_KEY_ENTER;
	constexpr input_code TAB = GLFW_KEY_TAB;
	constexpr input_code BACKSPACE = GLFW_KEY_BACKSPACE;
	constexpr input_code INSERT = GLFW_KEY_INSERT;
	constexpr input_code DELETE = GLFW_KEY_DELETE;
	constexpr input_code RIGHT = GLFW_KEY_RIGHT;
	constexpr input_code LEFT = GLFW_KEY_LEFT;
	constexpr input_code DOWN = GLFW_KEY_DOWN;
	constexpr input_code UP = GLFW_KEY_UP;
	constexpr input_code PAGE_UP = GLFW_KEY_PAGE_UP;
	constexpr input_code PAGE_DOWN = GLFW_KEY_PAGE_DOWN;
	constexpr input_code HOME = GLFW_KEY_HOME;
	constexpr input_code END = GLFW_KEY_END;
	constexpr input_code CAPS_LOCK = GLFW_KEY_CAPS_LOCK;
	constexpr input_code SCROLL_LOCK = GLFW_KEY_SCROLL_LOCK;
	constexpr input_code NUM_LOCK = GLFW_KEY_NUM_LOCK;
	constexpr input_code PRINT_SCREEN = GLFW_KEY_PRINT_SCREEN;
	constexpr input_code PAUSE = GLFW_KEY_PAUSE;
	constexpr input_code NUM_0 = GLFW_KEY_KP_0;
	constexpr input_code NUM_1 = GLFW_KEY_KP_1;
	constexpr input_code NUM_2 = GLFW_KEY_KP_2;
	constexpr input_code NUM_3 = GLFW_KEY_KP_3;
	constexpr input_code NUM_4 = GLFW_KEY_KP_4;
	constexpr input_code NUM_5 = GLFW_KEY_KP_5;
	constexpr input_code NUM_6 = GLFW_KEY_KP_6;
	constexpr input_code NUM_7 = GLFW_KEY_KP_7;
	constexpr input_code NUM_8 = GLFW_KEY_KP_8;
	constexpr input_code NUM_9 = GLFW_KEY_KP_9;
	constexpr input_code NUM_DECIMAL = GLFW_KEY_KP_DECIMAL;
	constexpr input_code NUM_DIVIDE = GLFW_KEY_KP_DIVIDE;
	constexpr input_code NUM_MULTIPLY = GLFW_KEY_KP_MULTIPLY;
	constexpr input_code NUM_SUBTRACT = GLFW_KEY_KP_SUBTRACT;
	constexpr input_code NUM_ADD = GLFW_KEY_KP_ADD;
	constexpr input_code NUM_ENTER = GLFW_KEY_KP_ENTER;
	constexpr input_code NUM_EQUAL = GLFW_KEY_KP_EQUAL;
	constexpr input_code LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT;
	constexpr input_code LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL;
	constexpr input_code LEFT_ALT = GLFW_KEY_LEFT_ALT;
	constexpr input_code LEFT_SUPER = GLFW_KEY_LEFT_SUPER;
	constexpr input_code RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT;
	constexpr input_code RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL;
	constexpr input_code RIGHT_ALT = GLFW_KEY_RIGHT_ALT;
	constexpr input_code RIGHT_SUPER = GLFW_KEY_RIGHT_SUPER;
	constexpr input_code MENU = GLFW_KEY_MENU;

	constexpr input_code BUTTON_1 = GLFW_MOUSE_BUTTON_1;
	constexpr input_code BUTTON_2 = GLFW_MOUSE_BUTTON_2;
	constexpr input_code BUTTON_3 = GLFW_MOUSE_BUTTON_3;
	constexpr input_code BUTTON_4 = GLFW_MOUSE_BUTTON_4;
	constexpr input_code BUTTON_5 = GLFW_MOUSE_BUTTON_5;
	constexpr input_code BUTTON_6 = GLFW_MOUSE_BUTTON_6;
	constexpr input_code BUTTON_7 = GLFW_MOUSE_BUTTON_7;
	constexpr input_code BUTTON_8 = GLFW_MOUSE_BUTTON_8;

	struct Event
	{
		Event(input_code code, input_action action)
				:
				code(code), action(action)
		{}

		const input_code code;
		const input_action action;
	};

	using MouseEvent = Event;
}

#endif //OPENGGLAPP_KEYEVENTTYPE_H
