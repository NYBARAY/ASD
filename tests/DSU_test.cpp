#include "DSU.h"
#include <gtest/gtest.h>

TEST(DSULibTest, unitetest) {
	DSU set(10);

	set.unite(3, 5);
	set.unite(3, 1);

	EXPECT_EQ(set.find(5), 3);
}

TEST(DSULibTest, unitetest2) {
	DSU set(10);

	set.unite(1, 2);
	set.unite(1, 3);
	set.unite(4, 5);
	set.unite(4, 6);

	set.unite(1, 4);

	EXPECT_EQ(set.find(4), 1);
	EXPECT_EQ(set.find(5), 1);
	EXPECT_EQ(set.find(6), 1);

}

TEST(DSULibTest, unitetest2other) {
	DSU set(10);

	set.unite(1, 2);
	set.unite(1, 3);
	set.unite(4, 5);
	set.unite(4, 6);

	set.unite(4, 1);

	EXPECT_EQ(set.find(4), 4);
	EXPECT_EQ(set.find(5), 4);
	EXPECT_EQ(set.find(6), 4);
	EXPECT_EQ(set.find(1), 4);
	EXPECT_EQ(set.find(2), 4);
	EXPECT_EQ(set.find(3), 4);

}

TEST(DSULibTest, pathcompression) {
	DSU set(10);

	set.unite(1, 2);
	set.unite(3, 4);
	set.unite(4, 5);
	set.unite(5, 6);
	set.unite(6, 7);
	set.unite(7, 8);

	set.unite(1, 3);

	EXPECT_EQ(set.find(8), 1);
	EXPECT_EQ(set.find(7), 1);
	EXPECT_EQ(set.find(6), 1);
	EXPECT_EQ(set.find(3), 1);

}





