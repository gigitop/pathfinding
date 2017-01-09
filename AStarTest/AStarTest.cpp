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
		ASSERT_THROW(AStar(nullptr, nullptr, nullptr), std::invalid_argument);
		ASSERT_THROW(AStar(std::make_shared<Topology>(), std::make_shared<Node>(0, 0), std::make_shared<Node>(1, 0)), std::invalid_argument);
		ASSERT_THROW(AStar(std::make_shared<Topology>(), nullptr, nullptr), std::invalid_argument);
	}

	TEST_F(AStarTestFixture, ShouldFindSimplePath)
	{
		auto start = std::make_shared<Node>(0, 0);
		auto end = std::make_shared<Node>(1, 0);
		auto topology = std::make_shared<Topology>();
		topology->AddNodeToTopology(start);
		topology->AddNodeToTopology(end);

		AStar astar(topology, start, end);
		auto path = astar.FindPath();
		ASSERT_EQ(2, path->size());
	}

	TEST_F(AStarTestFixture, ShouldFindBasicPath)
	{
		auto start = std::make_shared<Node>(1, 1);
		auto end = std::make_shared<Node>(4, 1);
		auto topology = std::make_shared<Topology>();
		for (int x = 0; x < 4; x++)
		{
			for (int y = 0; y < 4; y++)
			{
				topology->AddNodeToTopology(std::make_shared<Node>(x, y));
			}
		}

		AStar astar(topology, start, end);
		auto path = astar.FindPath();
		ASSERT_EQ(2, path->size());
	}
}
