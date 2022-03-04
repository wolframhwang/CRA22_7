#include "gtest/gtest.h"
#include "../FineCode/Condition.h"

TEST(Condition, isEqual)
{
    Employee employee1 = { 2015123099, {"VXIHTOTH", "JHOP"}, CL::CL3, {3112, 2609}, {1977, 12, 11}, Grade::ADV };
    Employee employee2 = { 2017112609, {"FB", "NTAWR"},      CL::CL4, {5645, 6122}, {1986, 11, 03}, Grade::PRO };

    ConditionEmployeeNum conditionEmployeeNum( employee1.employeeNum );
    EXPECT_EQ(true,  conditionEmployeeNum.isEqual(employee1));
    EXPECT_EQ(false, conditionEmployeeNum.isEqual(employee2));

    ConditionName conditionName( employee1.name.first, employee1.name.last );
    EXPECT_EQ(true,  conditionName.isEqual(employee1));
    EXPECT_EQ(false, conditionName.isEqual(employee2));

    ConditionNameFirst conditionNameFirst( employee1.name.first );
    EXPECT_EQ(true,  conditionNameFirst.isEqual(employee1));
    EXPECT_EQ(false, conditionNameFirst.isEqual(employee2));

    ConditionNameLast conditionNameLast( employee1.name.last );
    EXPECT_EQ(true,  conditionNameLast.isEqual(employee1));
    EXPECT_EQ(false, conditionNameLast.isEqual(employee2));

    ConditionCl conditionCl( employee1.cl );
    EXPECT_EQ(true,  conditionCl.isEqual(employee1));
    EXPECT_EQ(false, conditionCl.isEqual(employee2));

    ConditionPhoneNum conditionPhoneNum( employee1.phoneNum.mid, employee1.phoneNum.end );
    EXPECT_EQ(true,  conditionPhoneNum.isEqual(employee1));
    EXPECT_EQ(false, conditionPhoneNum.isEqual(employee2));

    ConditionPhoneNumMid conditionPhoneNumMid( employee1.phoneNum.mid );
    EXPECT_EQ(true,  conditionPhoneNumMid.isEqual(employee1));
    EXPECT_EQ(false, conditionPhoneNumMid.isEqual(employee2));

    ConditionPhoneNumEnd conditionPhoneNumEnd( employee1.phoneNum.end );
    EXPECT_EQ(true,  conditionPhoneNumEnd.isEqual(employee1));
    EXPECT_EQ(false, conditionPhoneNumEnd.isEqual(employee2));

    ConditionBirthday conditionBirthday( employee1.birthday.year, employee1.birthday.month, employee1.birthday.day );
    EXPECT_EQ(true,  conditionBirthday.isEqual(employee1));
    EXPECT_EQ(false, conditionBirthday.isEqual(employee2));

    ConditionBirthdayYear conditionBirthdayYear( employee1.birthday.year );
    EXPECT_EQ(true,  conditionBirthdayYear.isEqual(employee1));
    EXPECT_EQ(false, conditionBirthdayYear.isEqual(employee2));

    ConditionBirthdayMonth conditionBirthdayMonth( employee1.birthday.month );
    EXPECT_EQ(true,  conditionBirthdayMonth.isEqual(employee1));
    EXPECT_EQ(false, conditionBirthdayMonth.isEqual(employee2));

    ConditionBirthdayDay conditionBirthdayDay( employee1.birthday.day );
    EXPECT_EQ(true,  conditionBirthdayDay.isEqual(employee1));
    EXPECT_EQ(false, conditionBirthdayDay.isEqual(employee2));

    ConditionCerti conditionCerti( employee1.certi );
    EXPECT_EQ(true,  conditionCerti.isEqual(employee1));
    EXPECT_EQ(false, conditionCerti.isEqual(employee2));
}