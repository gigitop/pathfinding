#include "gmock/gmock.h"
#include "AStar.h"
#include "Topology.h"
#include "Node.h"

namespace Pathfinding
{
	class AStarTestFixture : public testing::Test
	{
	public:
		AStarTestFixture() = default;
	};

	TEST_F(AStarTestFixture, ShouldThrowInvalidArgumentException)
	{
		//TOOD: More test needed.
		ASSERT_THROW(AStar(nullptr, Node(0, 0), Node(1, 0)), std::invalid_argument);
		ASSERT_THROW(AStar(std::make_shared<Topology>(), Node(0, 0), Node(1, 0)), std::invalid_argument);
	}

	TEST_F(AStarTestFixture, ShouldFindSimplePath)
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

	TEST_F(AStarTestFixture, ShouldFindBasicPath)
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


	TEST_F(AStarTestFixture, ShouldFindPathWithWall)
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
}
