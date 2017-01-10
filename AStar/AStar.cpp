#include "AStar.h"

using namespace Pathfinding;

std::shared_ptr<std::list<std::shared_ptr<Node>>> AStar::FindPath()
{
	auto path = std::make_shared<std::list<std::shared_ptr<Node>>>();
	bool success = Search(_start);
	if (success)
	{
		Node* node = &_end;
		while (_nodeMap[*node]->GetParent() != nullptr)
		{
			path->push_back(std::make_shared<Node>(node->x, node->y));
			node = _nodeMap[*node]->GetParent().get();
		}

		path->reverse();
		path->push_front(std::make_shared<Node>(_start));
	}

	return path;
}

bool AStar::Search(const Node& currentNode)
{
	_nodeMap[currentNode]->SetState(AStarNodeState::Closed);
	auto nextNodes = GetUntestedAdjacentAStarNodes(currentNode);

	nextNodes->sort([this](const Node& node1, const Node& node2)
	{
		return _nodeMap[node1]->F() < _nodeMap[node2]->F();
	});

	for (auto nextNode : *nextNodes)
	{
		if (nextNode == _end)
		{
			return true;
		}

		if (Search(nextNode))
		{
			return true;
		}
	}

	return false;
}

std::shared_ptr<std::list<Node>> AStar::GetUntestedAdjacentAStarNodes(const Node& fromNode)
{
	auto untestedNodes = std::make_shared<std::list<Node>>();
	auto nextNodes = GetAdjacentNodes(fromNode);

	for (auto node : *nextNodes)
	{
		auto astarNode = _nodeMap[node];
		if (astarNode->GetState() == AStarNodeState::Closed)
			continue;

		if (astarNode->GetState() == AStarNodeState::Open)
		{
			float traversalCost = AStarNode::GetTraversalCost(astarNode.get(), astarNode->GetParent());
			float g = _nodeMap[fromNode]->G() + traversalCost;
			if (g < astarNode->G())
			{
				astarNode->SetParent(_nodeMap[fromNode]);
				untestedNodes->emplace_back(Node(astarNode->x, astarNode->y));
			}
		}
		else
		{
			// If it's untested, set the parent and flag it as 'Open' for consideration
			astarNode->SetParent(_nodeMap[fromNode]);
			astarNode->SetState(AStarNodeState::Open);
			untestedNodes->emplace_back(node);
		}
	}

	return untestedNodes;
}

std::shared_ptr<std::list<Node>> AStar::GetAdjacentNodes(const Node& fromNode)
{
	auto adjacentNodes = std::make_shared<std::list<Node>>();

	for (int x = fromNode.x - 1; x <= fromNode.x + 1; ++x)
	{
		for (int y = fromNode.y - 1; y <= fromNode.y + 1; ++y)
		{
			if (fromNode.x == x && fromNode.y == y)
			{
				continue;
			}

			Node node(x, y);
			if (_topology->HasNode(node))
			{
				adjacentNodes->emplace_back(node);
			}
		}
	}

	return adjacentNodes;
}
