#include "gmock/gmock.h"

namespace Pathfinding
{
	class AStarTestFixture : public testing::Test
	{
	public:
		AStarTestFixture() = default;
	};

	TEST_F(AStarTestFixture, Test)
	{
		ASSERT_TRUE(true);
	}
}
