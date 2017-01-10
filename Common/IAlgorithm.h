#pragma once
#include <memory>
#include <list>
#include "Topology.h"

namespace Pathfinding
{
	struct Node;

	class IAlgorithm
	{
	public:
		IAlgorithm(std::shared_ptr<Topology> topology, const Node& start, const Node& end)
			: _topology(topology)
			, _start(start)
			, _end(end)
		{
			if (!_topology)
			{
				throw std::invalid_argument("The topology is null.");
			}
			if (!_topology->HasNode(start))
			{
				throw std::invalid_argument("The starting node is not existing in the topology.");
			}
			if (!_topology->HasNode(end))
			{
				throw std::invalid_argument("The end node is not existing in the topology.");
			}
		}

		virtual ~IAlgorithm() = default;

		virtual std::shared_ptr<std::list<std::shared_ptr<Node>>> FindPath() = 0;

	protected:
		std::shared_ptr<Topology> _topology;
		Node _start;
		Node _end;
	};
}
