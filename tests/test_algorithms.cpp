#include <gtest/gtest.h>
#include "stack.h"
#include "algorithms.h"
#include <string>

TEST(TestAlgorithms, CheckBreckets) {
	std::string b1 = { "" };
	EXPECT_TRUE(check_breckets(b1));
}

TEST(TestAlgorithms, CB2) {
	std::string b2 = { "()" };
	EXPECT_TRUE(check_breckets(b2));
}

TEST(TestAlgorithms, CB3) {
	std::string b3 = { "([{}])" };
	EXPECT_TRUE(check_breckets(b3));
}

TEST(TestAlgorithms, CB4) {
	std::string b4 = { "{[](){({})}}" };
	EXPECT_TRUE(check_breckets(b4));
}

TEST(TestAlgorithms, CB5) {
	std::string b5 = { "(" };
	EXPECT_FALSE(check_breckets(b5));
}

TEST(TestAlgorithms, CB6) {
	std::string b6 = { "{[}" };
	EXPECT_FALSE(check_breckets(b6));
}

TEST(TestAlgorithms, CB7) {
	std::string b7 = { ")" };
	EXPECT_FALSE(check_breckets(b7));
}