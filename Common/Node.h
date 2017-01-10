#pragma once

namespace Pathfinding
{
	struct Node
	{
		Node() = default;
		Node(int x, int y) : x(x), y(y) { }
		bool operator==(const Node& rhs) const { return x == rhs.x && y == rhs.y; }
		int x;
		int y;
	};
}

namespace std
{
	template <>
	struct hash<Pathfinding::Node>
	{
		size_t operator()(const Pathfinding::Node& k) const
		{
			using std::size_t;
			using std::hash;

			return ((hash<int>()(k.x) ^ (hash<int>()(k.y) << 1)) >> 1);
		}
	};
}
