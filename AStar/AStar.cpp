#include "AStar.h"
#include "Topology.h"

using namespace Pathfinding;

std::shared_ptr<std::list<std::shared_ptr<Node>>> AStar::FindPath()
{
	auto path = std::make_shared<std::list<std::shared_ptr<Node>>>();
	path->push_back(_start);
	path->push_back(_end);
	return path;
}
