#include "gtest/gtest.h"
#include "../FineCode/IDataBase.h"
#include "../FineCode/Result.h"

TEST(UTResult, toString) {
    Employee employee1 = { 2015123099, {"VXIHTOTH", "JHOP"}, CL::CL3, {3112, 2609}, {1977, 12, 11}, Grade::ADV };
    Employee employee2 = { 2017112609, {"FB", "NTAWR"},      CL::CL4, {5645, 6122}, {1986, 11, 03}, Grade::PRO };

    Result *resultCount = new ResultCount("SCH");
    EXPECT_EQ(resultCount->toString(), "SCH,NONE");
    resultCount->insert(employee1);
    EXPECT_EQ(resultCount->toString(), "SCH,1");
    resultCount->insert(employee2);
    EXPECT_EQ(resultCount->toString(), "SCH,2");

    Result *resultTop = new ResultTop("SCH", 5);
    EXPECT_EQ(resultTop->toString(), "SCH,NONE");
    resultTop->insert(employee1);
    EXPECT_EQ(resultTop->toString(), "SCH,15123099,VXIHTOTH JHOP,CL3,010-3112-2609,19771211,ADV\n");
    resultTop->insert(employee1);
    resultTop->insert(employee2);
    EXPECT_EQ(resultTop->toString(), "SCH,15123099,VXIHTOTH JHOP,CL3,010-3112-2609,19771211,ADV\n"
                                     "SCH,17112609,FB NTAWR,CL4,010-5645-6122,19861103,PRO\n");
}