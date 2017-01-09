#include "gmock/gmock.h"
#include "AStar.h"
#include "PathNotFindException.h"
#include "Topology.h"
#include "Point.h"

namespace Pathfinding
{
	class AStarTestFixture : public testing::Test
	{
	public:
		AStarTestFixture() = default;
	};

	TEST_F(AStarTestFixture, ShouldFindEmptyPathWithNoTopology)
	{
		AStar astar;
		ASSERT_THROW(astar.FindPath(), PathNotFindException);
	}

	TEST_F(AStarTestFixture, ShouldFindSimplePath)
	{
		auto topology = std::make_shared<Topology>();
		topology->SetStartPoint(std::make_shared<Point>(0, 0));
		topology->SetEndPoint(std::make_shared<Point>(1, 0));

		AStar astar;
		astar.SetTopology(topology);
		auto path = astar.FindPath();
		ASSERT_EQ(2, path->size());
	}
}
