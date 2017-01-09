#pragma once
#include <memory>
#include "Point.h"
#include <unordered_set>

namespace Pathfinding
{
	class Topology
	{
	public:
		void AddPointToTopology(std::shared_ptr<Point> point) { _topology.insert(point); }
		void RemovePointFromTopology(std::shared_ptr<Point> point) { _topology.erase(point); }
		bool HasPoint(std::shared_ptr<Point> point) { return _topology.find(point) != _topology.end(); }

		void SetStartPoint(std::shared_ptr<Point> point) { _startPoint = point; _topology.insert(point); }
		void SetEndPoint(std::shared_ptr<Point> point) { _endPoint = point; _topology.insert(point); }
		std::shared_ptr<Point> GetStartPoint() const { return _startPoint; }
		std::shared_ptr<Point> GetEndPoint() const { return _endPoint; }

	private:
		std::unordered_set<std::shared_ptr<Point>> _topology;
		std::shared_ptr<Point> _startPoint;
		std::shared_ptr<Point> _endPoint;
	};
}
