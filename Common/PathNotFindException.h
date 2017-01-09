#pragma once
#include <exception>

namespace Pathfinding
{
	class PathNotFindException : public std::exception
	{
	public:
		explicit PathNotFindException() :exception()
		{
		}

		explicit PathNotFindException(char const* const msg) : exception(msg)
		{
		}
	};
}
