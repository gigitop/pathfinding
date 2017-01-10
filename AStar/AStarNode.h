#pragma once
#include <Node.h>
#include <memory>

namespace Pathfinding
{
	enum class AStarNodeState
	{
		/// <summary>
		/// The node has not yet been considered in any possible paths
		/// </summary>
		Untested,
		/// <summary>
		/// The node has been identified as a possible step in a path
		/// </summary>
		Open,
		/// <summary>
		/// The node has already been included in a path and will not be considered again
		/// </summary>
		Closed
	};

	class AStarNode : public Node
	{
	public:
		AStarNode(const Node& node, const Node& endNode)
			: Node(node.x, node.y)
		{
			_h = GetTraversalCost(this, endNode);
		}

		std::shared_ptr<AStarNode> GetParent() const { return _parent; }
		void SetParent(const std::shared_ptr<AStarNode> node)
		{
			_parent = node;
			_g = _parent->_g + GetTraversalCost(this, _parent);
		}

		float G() const { return _g; }
		float H() const { return _h; }
		float F() const { return _g + _h; }

		AStarNodeState GetState() const { return _state; }
		void SetState(AStarNodeState state) { _state = state; }

		static float GetTraversalCost(AStarNode const* const node, const Node& otherNode)
		{
			float deltaX = static_cast<float>(otherNode.x - node->x);
			float deltaY = static_cast<float>(otherNode.y - node->y);
			return sqrt(deltaX * deltaX + deltaY * deltaY);
		}

		static float GetTraversalCost(AStarNode const* const node, const std::shared_ptr<AStarNode> otherNode)
		{
			float deltaX = static_cast<float>(otherNode->x - node->x);
			float deltaY = static_cast<float>(otherNode->y - node->y);
			return sqrt(deltaX * deltaX + deltaY * deltaY);
		}

	private:
		std::shared_ptr<AStarNode> _parent;
		AStarNodeState _state = AStarNodeState::Untested;
		float _g = 0.0f;
		float _h = 0.0f;
	};
}
