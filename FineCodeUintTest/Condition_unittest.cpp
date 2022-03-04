#include "gtest/gtest.h"
#include "../FineCode/Condition.cpp"

TEST(Condition, isEqual)
{
    Employee employee1 = { 2015123099, {"VXIHTOTH", "JHOP"}, CL::CL3, {3112, 2609}, {1977, 12, 11}, Grade::ADV };
    Employee employee2 = { 2017112609, {"FB", "NTAWR"},      CL::CL4, {5645, 6122}, {1986, 11, 03}, Grade::PRO };

    // 1. employee1을 스스로의 기준으로 isEqual 검사를 했을 때 true가 나오는지 확인한다.
    // 2. employee2를 employee1의 기준으로 isEqual 검사를 했을 때 false가 나오는지 확인한다.
    //    단, employee1과 employee2의 기준이 서로 달라야함.

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

TEST(Condition, set)
{
    Employee employee1 = { 2015123099, {"VXIHTOTH", "JHOP"}, CL::CL3, {3112, 2609}, {1977, 12, 11}, Grade::ADV };
    Employee employee2 = { 2017112609, {"FB", "NTAWR"},      CL::CL4, {5645, 6122}, {1986, 11, 03}, Grade::PRO };

    // 1. employee2를 employee1의 기준으로 isEqual 검사를 했을 때 false가 나오는지 확인한다.
    //    단, employee1과 employee2의 기준이 서로 달라야함.
    // 2. employee2을 employee1의 기준으로 set 한다.
    // 3. employee2를 employee1의 기준으로 isEqual 검사를 했을 때 true가 나오는지 확인한다.
    // 4. (optional) 이후 테스트에 영향이 없도록 employee2의 값을 본래대로 되돌려놓는다.

    ConditionEmployeeNum conditionEmployeeNum( employee1.employeeNum );
    EXPECT_EQ(false, conditionEmployeeNum.isEqual(employee2));
    conditionEmployeeNum.set(employee2);
    EXPECT_EQ(true, conditionEmployeeNum.isEqual(employee2));

    ConditionName conditionName( employee1.name.first, employee1.name.last );
    ConditionName conditionNameBackup( employee2.name.first, employee2.name.last );
    EXPECT_EQ(false, conditionName.isEqual(employee2));
    conditionName.set(employee2);
    EXPECT_EQ(true, conditionName.isEqual(employee2));
    conditionNameBackup.set(employee2);

    ConditionNameFirst conditionNameFirst( employee1.name.first );
    EXPECT_EQ(false, conditionNameFirst.isEqual(employee2));
    conditionNameFirst.set(employee2);
    EXPECT_EQ(true, conditionNameFirst.isEqual(employee2));

    ConditionNameLast conditionNameLast( employee1.name.last );
    EXPECT_EQ(false, conditionNameLast.isEqual(employee2));
    conditionNameLast.set(employee2);
    EXPECT_EQ(true, conditionNameLast.isEqual(employee2));

    ConditionCl conditionCl( employee1.cl );
    EXPECT_EQ(false, conditionCl.isEqual(employee2));
    conditionCl.set(employee2);
    EXPECT_EQ(true, conditionCl.isEqual(employee2));

    ConditionPhoneNum conditionPhoneNum( employee1.phoneNum.mid, employee1.phoneNum.end );
    ConditionPhoneNum conditionPhoneNumBackup( employee2.phoneNum.mid, employee2.phoneNum.end );
    EXPECT_EQ(false, conditionPhoneNum.isEqual(employee2));
    conditionPhoneNum.set(employee2);
    EXPECT_EQ(true, conditionPhoneNum.isEqual(employee2));
    conditionPhoneNumBackup.set(employee2);

    ConditionPhoneNumMid conditionPhoneNumMid( employee1.phoneNum.mid );
    EXPECT_EQ(false, conditionPhoneNumMid.isEqual(employee2));
    conditionPhoneNumMid.set(employee2);
    EXPECT_EQ(true, conditionPhoneNumMid.isEqual(employee2));

    ConditionPhoneNumEnd conditionPhoneNumEnd( employee1.phoneNum.end );
    EXPECT_EQ(false, conditionPhoneNumEnd.isEqual(employee2));
    conditionPhoneNumEnd.set(employee2);
    EXPECT_EQ(true, conditionPhoneNumEnd.isEqual(employee2));

    ConditionBirthday conditionBirthday( employee1.birthday.year, employee1.birthday.month, employee1.birthday.day );
    ConditionBirthday conditionBirthdayBackup( employee2.birthday.year, employee2.birthday.month, employee2.birthday.day );
    EXPECT_EQ(false, conditionBirthday.isEqual(employee2));
    conditionBirthday.set(employee2);
    EXPECT_EQ(true, conditionBirthday.isEqual(employee2));
    conditionBirthdayBackup.set(employee2);

    ConditionBirthdayYear conditionBirthdayYear( employee1.birthday.year );
    EXPECT_EQ(false, conditionBirthdayYear.isEqual(employee2));
    conditionBirthdayYear.set(employee2);
    EXPECT_EQ(true, conditionBirthdayYear.isEqual(employee2));

    ConditionBirthdayMonth conditionBirthdayMonth( employee1.birthday.month );
    EXPECT_EQ(false, conditionBirthdayMonth.isEqual(employee2));
    conditionBirthdayMonth.set(employee2);
    EXPECT_EQ(true, conditionBirthdayMonth.isEqual(employee2));

    ConditionBirthdayDay conditionBirthdayDay( employee1.birthday.day );
    EXPECT_EQ(false, conditionBirthdayDay.isEqual(employee2));
    conditionBirthdayDay.set(employee2);
    EXPECT_EQ(true, conditionBirthdayDay.isEqual(employee2));

    ConditionCerti conditionCerti( employee1.certi );
    EXPECT_EQ(false, conditionCerti.isEqual(employee2));
    conditionCerti.set(employee2);
    EXPECT_EQ(true, conditionCerti.isEqual(employee2));
}

TEST(Condition, isValidEmployeeNum)
{
    // 1. 길이 조건에 대한 검사 결과가 적절한지 확인
    EXPECT_EQ(false, ConditionEmployeeNum::isValid(""));
    EXPECT_EQ(false, ConditionEmployeeNum::isValid("0"));
    EXPECT_EQ(false, ConditionEmployeeNum::isValid("0000000"));
    EXPECT_EQ(true,  ConditionEmployeeNum::isValid("00000000"));
    EXPECT_EQ(false, ConditionEmployeeNum::isValid("000000001"));
    EXPECT_EQ(false, ConditionEmployeeNum::isValid("0000000011111111"));

    // 2. 문자 구성 검사 결과가 적절한지 확인
    EXPECT_EQ(true,  ConditionEmployeeNum::isValid("00000000"));
    EXPECT_EQ(true,  ConditionEmployeeNum::isValid("99999999"));
    EXPECT_EQ(false, ConditionEmployeeNum::isValid("0000000A"));
    EXPECT_EQ(false, ConditionEmployeeNum::isValid("A0000000"));
    EXPECT_EQ(false, ConditionEmployeeNum::isValid("0000000 "));
    EXPECT_EQ(false, ConditionEmployeeNum::isValid(" 0000000"));
    EXPECT_EQ(false, ConditionEmployeeNum::isValid("0000000a"));
    EXPECT_EQ(false, ConditionEmployeeNum::isValid("a0000000"));

    // 3. 연도 검사 결과가 적절한지 확인
    EXPECT_EQ(false, ConditionEmployeeNum::isValid("68000000"));
    EXPECT_EQ(true,  ConditionEmployeeNum::isValid("69000000"));
    EXPECT_EQ(true,  ConditionEmployeeNum::isValid("99000000"));
    EXPECT_EQ(true,  ConditionEmployeeNum::isValid("00000000"));
    EXPECT_EQ(true,  ConditionEmployeeNum::isValid("21000000"));
    EXPECT_EQ(false, ConditionEmployeeNum::isValid("22000000"));
}

TEST(Condition, isValidName)
{
    // 1. 길이 조건에 대한 검사 결과가 적절한지 확인
    EXPECT_EQ(false, ConditionName::isValid(""));
    EXPECT_EQ(false, ConditionName::isValid("A "));
    EXPECT_EQ(true,  ConditionName::isValid("A A"));
    EXPECT_EQ(true,  ConditionName::isValid("AAAAA AAAAABBBB"));
    EXPECT_EQ(false, ConditionName::isValid("AAAAA AAAAABBBBB"));
    EXPECT_EQ(false, ConditionName::isValid("AAAAABBBBB CCCCCDDDDDEEEEEFFFFF"));

    // 2. 공백 개수 조건에 대한 검사 결과가 적절한지 확인
    EXPECT_EQ(false, ConditionName::isValid("AAAAAAAAAAABBBB"));
    EXPECT_EQ(true,  ConditionName::isValid("AAAAA AAAAABBBB"));
    EXPECT_EQ(false, ConditionName::isValid("AAAAA AAAA BBBB"));
    EXPECT_EQ(false, ConditionName::isValid("               "));

    // 3. 문자 구성 검사 결과가 적절한지 확인
    EXPECT_EQ(true,  ConditionName::isValid("ABCDE FGHIJKLMZ"));
    EXPECT_EQ(false, ConditionName::isValid("aBCDE FGHIJKLMZ"));
    EXPECT_EQ(false, ConditionName::isValid("ABCDE FGHIJKLMz"));
    EXPECT_EQ(false, ConditionName::isValid("0BCDE FGHIJKLMZ"));
    EXPECT_EQ(false, ConditionName::isValid("1BCDE FGHIJKLM9"));

    // 4. 공백 위치 검사 결과가 적절한지 확인
    EXPECT_EQ(true,  ConditionName::isValid("ABCDE FGHIJKLMZ"));
    EXPECT_EQ(false, ConditionName::isValid(" ABCDEFGHIJKLMZ"));
    EXPECT_EQ(false, ConditionName::isValid("ABCDEFGHIJKLMZ "));
}

TEST(Condition, isValidNameFirst)
{
    // 1. 길이 조건에 대한 검사 결과가 적절한지 확인
    EXPECT_EQ(false, ConditionNameFirst::isValid(""));
    EXPECT_EQ(true,  ConditionNameFirst::isValid("A"));

    // 2. 문자 구성 검사 결과가 적절한지 확인
    EXPECT_EQ(true,  ConditionNameFirst::isValid("ABCDZ"));
    EXPECT_EQ(false, ConditionNameFirst::isValid("aBCDZ"));
    EXPECT_EQ(false, ConditionNameFirst::isValid("ABCDz"));
    EXPECT_EQ(false, ConditionNameFirst::isValid("0BCDZ"));
    EXPECT_EQ(false, ConditionNameFirst::isValid("1BCD9"));
}

TEST(Condition, isValidNameLast)
{
    // 1. 길이 조건에 대한 검사 결과가 적절한지 확인
    EXPECT_EQ(false, ConditionNameLast::isValid(""));
    EXPECT_EQ(true,  ConditionNameLast::isValid("A"));

    // 2. 문자 구성 검사 결과가 적절한지 확인
    EXPECT_EQ(true,  ConditionNameLast::isValid("ABCDZ"));
    EXPECT_EQ(false, ConditionNameLast::isValid("aBCDZ"));
    EXPECT_EQ(false, ConditionNameLast::isValid("ABCDz"));
    EXPECT_EQ(false, ConditionNameLast::isValid("0BCDZ"));
    EXPECT_EQ(false, ConditionNameLast::isValid("1BCD9"));
}

TEST(Condition, isValidCl)
{
    // 1. 길이 조건에 대한 검사 결과가 적절한지 확인
    EXPECT_EQ(true,  ConditionCl::isValid("CL1"));
    EXPECT_EQ(false, ConditionCl::isValid("CL"));
    EXPECT_EQ(false, ConditionCl::isValid("CL11"));

    // 2. 문자 구성 검사 결과가 적절한지 확인
    EXPECT_EQ(true,  ConditionCl::isValid("CL1"));
    EXPECT_EQ(false, ConditionCl::isValid("CM1"));

    // 2. 숫자 범위 검사 결과가 적절한지 확인
    EXPECT_EQ(false, ConditionCl::isValid("CL0"));
    EXPECT_EQ(true,  ConditionCl::isValid("CL1"));
    EXPECT_EQ(true,  ConditionCl::isValid("CL4"));
    EXPECT_EQ(false, ConditionCl::isValid("CL5"));
    EXPECT_EQ(false, ConditionCl::isValid("CL8"));
}
