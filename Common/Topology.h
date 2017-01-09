#pragma once
#include <memory>
#include "Node.h"
#include <unordered_set>

namespace Pathfinding
{
	class Topology
	{
	public:
		void AddNodeToTopology(std::shared_ptr<Node> node) { _topology.insert(node); }
		void RemoveNodeFromTopology(std::shared_ptr<Node> node) { _topology.erase(node); }
		bool HasNode(std::shared_ptr<Node> node) { return _topology.find(node) != _topology.end(); }

	private:
		std::unordered_set<std::shared_ptr<Node>> _topology;
	};
}
