#pragma once
#include <memory>
#include "Node.h"
#include <unordered_set>

namespace Pathfinding
{
	class Topology
	{
	public:
		void AddPointToTopology(std::shared_ptr<Node> point) { _topology.insert(point); }
		void RemovePointFromTopology(std::shared_ptr<Node> point) { _topology.erase(point); }
		bool HasPoint(std::shared_ptr<Node> point) { return _topology.find(point) != _topology.end(); }

		void SetStartPoint(std::shared_ptr<Node> point) { _startPoint = point; _topology.insert(point); }
		void SetEndPoint(std::shared_ptr<Node> point) { _endPoint = point; _topology.insert(point); }
		std::shared_ptr<Node> GetStartPoint() const { return _startPoint; }
		std::shared_ptr<Node> GetEndPoint() const { return _endPoint; }

	private:
		std::unordered_set<std::shared_ptr<Node>> _topology;
		std::shared_ptr<Node> _startPoint;
		std::shared_ptr<Node> _endPoint;
	};
}
