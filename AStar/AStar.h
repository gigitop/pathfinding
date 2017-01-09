#pragma once

#include "IAlgorithm.h"

namespace Pathfinding
{
	class AStar : public IAlgorithm
	{
	public:
		AStar() = default;
		virtual ~AStar() = default;

		std::shared_ptr<std::list<std::shared_ptr<Node>>> FindPathes() override;
	};
}
