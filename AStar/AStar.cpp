#include "AStar.h"
#include "PathNotFindException.h"
#include "Topology.h"

using namespace Pathfinding;

std::shared_ptr<std::list<std::shared_ptr<Point>>> AStar::FindPath()
{
	if (!_topology || !_topology->GetStartPoint() || !_topology->GetEndPoint())
	{
		throw PathNotFindException();
	}

	auto path = std::make_shared<std::list<std::shared_ptr<Point>>>();
	path->push_back(_topology->GetStartPoint());
	path->push_back(_topology->GetEndPoint());
	return path;
}
