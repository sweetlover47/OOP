#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include "gtest/gtest.h"
#include "TritSet.h"

TEST(TritSetTests, DefaultCostructor) {
	TritSet a;
	EXPECT_EQ(0, a.capacity());
}

TEST(TritSetTests, ParametrCostructor) {
	TritSet a(1000);
	size_t allocLength = a.capacity();
	EXPECT_TRUE(allocLength >= 1000 * 2 / 8 / sizeof(size_t));
}


TEST(TritSetTests, TritSet_and_TritSet)
{
	TritSet SetA(1000);
	TritSet SetB(2000);
	TritSet SetC = SetA & SetB;
	EXPECT_EQ(SetB.capacity(), SetC.capacity());
	SetA[0] = TRUE;
	SetA[2] = TRUE;
	SetB[1] = FALSE;
	SetB[2] = TRUE;
	SetC = SetA & SetB;
	EXPECT_EQ(UNKNOWN, SetC[0]);
	EXPECT_EQ(FALSE, SetC[1]);
	EXPECT_EQ(TRUE, SetC[2]);
	EXPECT_EQ(UNKNOWN, SetC[1001]);
}

TEST(TritSetTests, TritSet_or_TritSet)
{
	TritSet SetA(1000);
	TritSet SetB(2000);
	TritSet SetC = SetA | SetB;
	EXPECT_EQ(SetB.capacity(), SetC.capacity());
	SetA[0] = TRUE;
	SetA[2] = FALSE;
	SetB[1] = FALSE;
	SetB[2] = FALSE;
	SetC = SetA | SetB;
	EXPECT_EQ(TRUE, SetC[0]);
	EXPECT_EQ(UNKNOWN, SetC[1]);
	EXPECT_EQ(FALSE, SetC[2]);
	EXPECT_EQ(UNKNOWN, SetC[1001]);
}

TEST(TritSetTests, TritSet_not_TritSet)
{
	TritSet SetA(1000);
	TritSet SetC = ~SetA;
	EXPECT_EQ(SetA.capacity(), SetC.capacity());
	SetA[0] = TRUE;
	SetA[2] = FALSE;
	SetC = ~SetA;
	EXPECT_EQ(FALSE, SetC[0]);
	EXPECT_EQ(UNKNOWN, SetC[1]);
	EXPECT_EQ(TRUE, SetC[2]);
	EXPECT_EQ(UNKNOWN, SetC[999]);
}

TEST(TritSetTests, length)
{
	TritSet a;
	a[1000] = TRUE;
	EXPECT_EQ(1001, a.length());
}

TEST(TritSetTests, capacity)
{
	TritSet a;
	a[1000] = TRUE;
	size_t allocLength = a.capacity();
	EXPECT_TRUE(allocLength >= 1000 * 2 / 8 / sizeof(size_t));
	a[1600] = UNKNOWN;
	EXPECT_EQ(allocLength, a.capacity());
	a[1600] = FALSE;
	EXPECT_TRUE(allocLength < a.capacity());
}

TEST(TritSetTests, cardinality)
{
	TritSet a;
	EXPECT_EQ(1, a.cardinality(UNKNOWN));
	EXPECT_EQ(0, a.cardinality(FALSE));
	EXPECT_EQ(0, a.cardinality(TRUE));
	a[0] = FALSE;
	EXPECT_EQ(1, a.cardinality(FALSE));
	EXPECT_EQ(0, a.cardinality(UNKNOWN));
	EXPECT_EQ(0, a.cardinality(TRUE));
	a[1000] = TRUE;
	EXPECT_EQ(1, a.cardinality(FALSE));
	EXPECT_EQ(999, a.cardinality(UNKNOWN));
	EXPECT_EQ(1, a.cardinality(TRUE));
	a[1000] = FALSE;
	unordered_map<Trit, int, hash<int>> unordered = a.cardinality();
	EXPECT_EQ(unordered[UNKNOWN], 999);
	EXPECT_EQ(unordered[TRUE], 0);
	EXPECT_EQ(unordered[FALSE], 2);
	a[1000] = UNKNOWN;
	unordered = a.cardinality();
	EXPECT_EQ(unordered[UNKNOWN], 0);
	EXPECT_EQ(unordered[TRUE], 0);
	EXPECT_EQ(unordered[FALSE], 1);
}

TEST(TritSetTests, shrink)
{
	TritSet a(1000);
	a[1000] = TRUE;
	size_t allocLength = a.capacity();
	a.shrink();
	EXPECT_TRUE(a.capacity() == allocLength);
	a[1000] = UNKNOWN;
	EXPECT_TRUE(a.capacity() == allocLength);
	a.shrink();
	EXPECT_EQ(0, a.capacity());
}

TEST(TritSetTests, trim)
{
	TritSet a(1000);
	for (int i = 0; i < 100; ++i)
		a[i] = TRUE;
	TritSet b = a;
	a.trim(500);
	int count = 0;
	for (int i = 0; i < 1000; ++i)
	{
		if (a[i] == b[i])
			++count;
	}
	EXPECT_EQ(1000, count);
	a.trim(43);
	count = 0;
	for (int i = 0; i < 1000; ++i)
	{
		if (a[i] == b[i])
			++count;
	}
	EXPECT_EQ(943, count);
	a.trim(0);
	count = 0;
	for (int i = 0; i < 1000; ++i)
	{
		if (a[i] == b[i])
			++count;
	}
	EXPECT_EQ(900, count);
}

TEST(TritSetTests, get_trit)
{
	TritSet a(1000);
	for (int i = 0; i < 1000; ++i)
		a[i] = i % 2 ? FALSE : TRUE;
	EXPECT_EQ(FALSE, a[41]);
	EXPECT_EQ(TRUE, a[500]);
	EXPECT_EQ(UNKNOWN, a[1000000]);
}

TEST(TritSetTests, resizeTritSet)
{
	TritSet a(1600);
	int allocLength = a.capacity();
	a[999] = TRUE;
	EXPECT_EQ(allocLength, a.capacity());
	a[20000000] = UNKNOWN;
	EXPECT_EQ(allocLength, a.capacity());
	a[2000] = FALSE;
	EXPECT_TRUE(allocLength < a.capacity());
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}