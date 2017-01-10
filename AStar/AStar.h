#pragma once

#include "IAlgorithm.h"
#include "Node.h"
#include <unordered_map>
#include "AStarNode.h"

namespace Pathfinding
{
	class Topology;

	class AStar : public IAlgorithm
	{
	public:
		AStar(std::shared_ptr<Topology> topology, const Node& start, const Node& end)
			: IAlgorithm(topology, start, end)
		{
			for (auto& node : topology->Get())
			{
				_nodeMap[node] = std::make_shared<AStarNode>(node, end);
			}
			_nodeMap[start]->SetState(AStarNodeState::Open);
		}
		
		virtual ~AStar() = default;

		std::shared_ptr<std::list<std::shared_ptr<Node>>> FindPath() override;

	private:
		bool Search(const Node& currentNode);
		std::shared_ptr<std::list<Node>> GetUntestedAdjacentAStarNodes(const Node& fromNode);
		std::shared_ptr<std::list<Node>> GetAdjacentNodes(const Node& fromNode) const;

		std::unordered_map<Node, std::shared_ptr<AStarNode>> _nodeMap;
	};
}
