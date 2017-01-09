#pragma once

#include "IAlgorithm.h"
#include "Node.h"

namespace Pathfinding
{
	class Topology;

	class AStar : public IAlgorithm
	{
	public:
		AStar() = default;
		virtual ~AStar() = default;

		std::shared_ptr<std::list<std::shared_ptr<Node>>> FindPath() override;
		void SetTopology(std::shared_ptr<Topology> topology) { _topology = std::move(topology); }

	private:
		std::shared_ptr<Topology> _topology;
		std::unique_ptr<Node> _currentPoint;
	};
}
