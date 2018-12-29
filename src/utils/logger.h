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

#ifndef OPENGGLAPP_LOGGER_H
#define OPENGGLAPP_LOGGER_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

constexpr auto LOGGER_NAME = "console";

static std::shared_ptr<spdlog::logger> logger() noexcept
{
	static auto g_logger = spdlog::get(LOGGER_NAME);

	if (g_logger == nullptr)
	{
		g_logger = spdlog::stdout_color_mt(LOGGER_NAME);
	}

	return g_logger;
}

static void logger_set_level(const spdlog::level::level_enum &level) noexcept
{
	logger()->set_level(level);
}


#endif //OPENGGLAPP_LOGGER_H
