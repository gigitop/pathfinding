#include "gmock/gmock.h"
#include "AStar.h"

namespace Pathfinding
{
	class AStarTestFixture : public testing::Test
	{
	public:
		AStarTestFixture() = default;
	};

	TEST_F(AStarTestFixture, ShouldFindEmptyPathWithNoTopology)
	{
		auto astar = AStar();
		auto pathes = astar.FindPathes();
		ASSERT_EQ(0, pathes->size());
	}
}
