#include "gtest/gtest.h"
#include "gmock/gmock.h"


TEST(environmentTest, passingTest)
{
    EXPECT_EQ(true, true);
}

struct Fixture: public testing::Test
{
    int sth;
    Fixture(): sth(7){}
};

TEST_F(Fixture, testUsingFixture)
{
    EXPECT_EQ(sth, 7);
}

struct FreeMock
{
    MOCK_METHOD0(run, void());
};

TEST(environmentTest, mockPassingTest)
{
    testing::NiceMock<FreeMock> niceMock;
    testing::StrictMock<FreeMock> strictMock;
    EXPECT_CALL(niceMock, run()).Times(1);
    niceMock.run();
}

struct Params {
    int val;
};

bool operator==(const Params& lhs, const Params& rhs)
{
    return lhs.val == rhs.val;
}

struct ParametricTests : public ::testing::TestWithParam<Params>
{

};

TEST_P(ParametricTests, aTest)
{
    auto params = GetParam();
    EXPECT_EQ(params.val % 2, 0);
}

INSTANTIATE_TEST_CASE_P(ParametricInstatiation, ParametricTests, ::testing::Values(Params{2}, Params{4}));
