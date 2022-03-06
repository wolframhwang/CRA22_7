#include "gtest/gtest.h"
#include "../FineCode/IDataBase.h"
#include "../FineCode/Condition.cpp"
#include "../FineCode/Result.h"

TEST(RT, ResultTest) {
    Result *result = new Result();

    EXPECT_EQ(result->getEntryCount(), 0);
    result->setEntryCountPlus();
    EXPECT_EQ(result->getEntryCount(), 1);
    result->setEntryCountPlus();
    EXPECT_EQ(result->getEntryCount(), 2);
    result->setEntryCountPlus();
    EXPECT_EQ(result->getEntryCount(), 3);
}