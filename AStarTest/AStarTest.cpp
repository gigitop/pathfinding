#include "gmock/gmock.h"
#include "AStar.h"
#include "PathNotFindException.h"
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
		astar.SetTopology(topology);
		auto path = astar.FindPath();
		ASSERT_EQ(2, path->size());
	}
}
