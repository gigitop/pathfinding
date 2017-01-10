#pragma once
#include "Node.h"
#include <unordered_set>

namespace Pathfinding
{
	class Topology
	{
	public:
		void AddNodeToTopology(const Node& node) { _topology.insert(node); }
		void RemoveNodeFromTopology(const Node& node) { _topology.erase(node); }
		bool HasNode(const Node& node) { return _topology.find(node) != _topology.end(); }
		std::unordered_set<Node> Get() const { return _topology; }

	private:
		std::unordered_set<Node> _topology;
	};
}
