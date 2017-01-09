#pragma once
#include <memory>
#include <list>

namespace Pathfinding
{
	struct Point;

	class IAlgorithm
	{
	public:
		IAlgorithm() = default;
		virtual ~IAlgorithm() = default;

		virtual std::shared_ptr<std::list<std::shared_ptr<Point>>> FindPath() = 0;
	};
}
