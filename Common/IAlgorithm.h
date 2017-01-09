#pragma once
#include <memory>
#include <list>

namespace Pathfinding
{
	struct Node;

	class IAlgorithm
	{
	public:
		IAlgorithm() = default;
		virtual ~IAlgorithm() = default;

		virtual std::shared_ptr<std::list<std::shared_ptr<Node>>> FindPath() = 0;
	};
}
