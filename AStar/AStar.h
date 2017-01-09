#pragma once

#include "IAlgorithm.h"
#include "Node.h"

namespace Pathfinding
{
	class Topology;

	class AStar : public IAlgorithm
	{
	public:
		AStar(std::shared_ptr<Topology> topology, std::shared_ptr<Node> start, std::shared_ptr<Node> end)
			: IAlgorithm(topology, start, end)
		{
		}
		
		virtual ~AStar() = default;

		std::shared_ptr<std::list<std::shared_ptr<Node>>> FindPath() override;

	private:
		std::unique_ptr<Node> _currentPoint;
	};
}
