#include "pch.h"
#include "../SimiliarityChecker/SimiliarityChecker.cpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(SimilarityCheck, CompareLength_EQ) {
	int result = SimChecker().compareLength("ASD", "DSA");
	EXPECT_EQ(60, result);
}

TEST(SimilarityCheck, CompareLength_1to2) {
	int result = SimChecker().compareLength("A", "BB");
	EXPECT_EQ(0, result);
}

TEST(SimilarityCheck, CompareLength_2to3) {
	int result = SimChecker().compareLength("AA", "AAA");
	EXPECT_EQ(30, result);
}

TEST(SimilarityCheck, CompareLength_5to3) {
	int result = SimChecker().compareLength("AAABB", "BAA");
	EXPECT_EQ(20, result);
}