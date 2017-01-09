#pragma once

namespace Pathfinding
{
	struct Node
	{
		Node() = default;
		Node(int x, int y) : x(x), y(y) { }
		int x;
		int y;
	};
}
