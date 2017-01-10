#include "gmock/gmock.h"
#include "AStar.h"
#include "Topology.h"
#include "Node.h"
#include "PathNotFindException.h"

namespace Pathfinding
{
	TEST(AStarTest, ShouldThrowInvalidArgumentException)
	{
		Node start(0, 0);
		Node end(1, 0);

		ASSERT_THROW(AStar(nullptr, start, end), std::invalid_argument);

		auto topology = std::make_shared<Topology>();
		ASSERT_THROW(AStar(topology, start, end), std::invalid_argument);
		
		topology->AddNodeToTopology(start);
		ASSERT_THROW(AStar(topology, start, end), std::invalid_argument);

		topology->AddNodeToTopology(end);
		ASSERT_NO_THROW(AStar(topology, start, end));

		topology->RemoveNodeFromTopology(end);
		ASSERT_THROW(AStar(topology, start, end), std::invalid_argument);
	}

	TEST(AStarTest, ShouldFindSimplePath)
	{
		Node start(0, 0);
		Node end(1, 0);
		auto topology = std::make_shared<Topology>();
		topology->AddNodeToTopology(start);
		topology->AddNodeToTopology(end);

		AStar astar(topology, start, end);
		auto path = astar.FindPath();
		ASSERT_EQ(2, path->size());
	}

	TEST(AStarTest, ShouldFindBasicPath)
	{
		auto start = Node(1, 1);
		auto end = Node(4, 1);
		auto topology = std::make_shared<Topology>();
		for (int x = 0; x <= 5; x++)
		{
			for (int y = 0; y <= 5; y++)
			{
				topology->AddNodeToTopology(Node(x, y));
			}
		}

		AStar astar(topology, start, end);
		auto path = astar.FindPath();
		ASSERT_EQ(4, path->size());
	}

	TEST(AStarTest, ShouldFindPathWithWall)
	{
		auto start = Node(0, 0);
		auto end = Node(2, 0);
		auto topology = std::make_shared<Topology>();
		for (int x = 0; x <= 2; x++)
		{
			for (int y = 0; y <= 2; y++)
			{
				topology->AddNodeToTopology(Node(x, y));
			}
		}

		topology->RemoveNodeFromTopology(Node(1, 0));
		topology->RemoveNodeFromTopology(Node(1, 1));

		AStar astar(topology, start, end);
		auto path = astar.FindPath();
		ASSERT_EQ(5, path->size());
	}

	TEST(AStarTest, ShouldNotFindPath)
	{
		auto start = Node(0, 0);
		auto end = Node(2, 0);
		auto topology = std::make_shared<Topology>();
		for (int x = 0; x <= 2; x++)
		{
			for (int y = 0; y <= 2; y++)
			{
				topology->AddNodeToTopology(Node(x, y));
			}
		}

		topology->RemoveNodeFromTopology(Node(1, 0));
		topology->RemoveNodeFromTopology(Node(1, 1));
		topology->RemoveNodeFromTopology(Node(1, 2));

		AStar astar(topology, start, end);
		ASSERT_THROW(astar.FindPath(), PathNotFindException);
	}
}
