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

TEST(Condition, isValidPhoneNum)
{
    // 1. 길이 조건에 대한 검사 결과가 적절한지 확인
    EXPECT_EQ(false, ConditionPhoneNum::isValid("010-3112-260"));
    EXPECT_EQ(true,  ConditionPhoneNum::isValid("010-3112-2609"));
    EXPECT_EQ(false, ConditionPhoneNum::isValid("010-3112-26099"));

    // 2. '-' 문자 위치 조건에 대한 검사 결과가 적절한지 확인
    EXPECT_EQ(false, ConditionPhoneNum::isValid("01-03112-2609"));
    EXPECT_EQ(true,  ConditionPhoneNum::isValid("010-3112-2609"));
    EXPECT_EQ(false, ConditionPhoneNum::isValid("010-31122-609"));

    // 3. 문자 구성 검사 결과가 적절한지 확인
    EXPECT_EQ(true,  ConditionPhoneNum::isValid("010-3112-2609"));
    EXPECT_EQ(false, ConditionPhoneNum::isValid("a10-3112-2609"));
    EXPECT_EQ(false, ConditionPhoneNum::isValid("010-3112-260Z"));
    EXPECT_EQ(false, ConditionPhoneNum::isValid("010-3112-260-"));

    // 4. 숫자 구성 검사 결과가 적절한지 확인
    EXPECT_EQ(true,  ConditionPhoneNum::isValid("010-3112-2609"));
    EXPECT_EQ(false, ConditionPhoneNum::isValid("011-3112-2609"));
    EXPECT_EQ(false, ConditionPhoneNum::isValid("110-3112-2609"));
}

TEST(Condition, isValidPhoneNumMid)
{
    // 1. 길이 조건에 대한 검사 결과가 적절한지 확인
    EXPECT_EQ(false, ConditionPhoneNumMid::isValid(""));
    EXPECT_EQ(false, ConditionPhoneNumMid::isValid("311"));
    EXPECT_EQ(true,  ConditionPhoneNumMid::isValid("3112"));
    EXPECT_EQ(false, ConditionPhoneNumMid::isValid("31124"));
    EXPECT_EQ(false, ConditionPhoneNumMid::isValid("31124444"));

    // 2. 문자 구성 검사 결과가 적절한지 확인
    EXPECT_EQ(true,  ConditionPhoneNumMid::isValid("3112"));
    EXPECT_EQ(false, ConditionPhoneNumMid::isValid("311a"));
    EXPECT_EQ(false, ConditionPhoneNumMid::isValid("311Z"));
    EXPECT_EQ(false, ConditionPhoneNumMid::isValid("311-"));
}

TEST(Condition, isValidPhoneNumEnd)
{
    // 1. 길이 조건에 대한 검사 결과가 적절한지 확인
    EXPECT_EQ(false, ConditionPhoneNumEnd::isValid(""));
    EXPECT_EQ(false, ConditionPhoneNumEnd::isValid("311"));
    EXPECT_EQ(true,  ConditionPhoneNumEnd::isValid("3112"));
    EXPECT_EQ(false, ConditionPhoneNumEnd::isValid("31124"));
    EXPECT_EQ(false, ConditionPhoneNumEnd::isValid("31124444"));

    // 2. 문자 구성 검사 결과가 적절한지 확인
    EXPECT_EQ(true,  ConditionPhoneNumEnd::isValid("3112"));
    EXPECT_EQ(false, ConditionPhoneNumEnd::isValid("311a"));
    EXPECT_EQ(false, ConditionPhoneNumEnd::isValid("311Z"));
    EXPECT_EQ(false, ConditionPhoneNumEnd::isValid("311-"));
}

TEST(Condition, isValidBirthday)
{
    // 1. 길이 조건에 대한 검사 결과가 적절한지 확인
    EXPECT_EQ(false, ConditionBirthday::isValid("1977121"));
    EXPECT_EQ(true,  ConditionBirthday::isValid("19771211"));
    EXPECT_EQ(false, ConditionBirthday::isValid("197712111"));

    // 2. 문자 구성 검사 결과가 적절한지 확인
    EXPECT_EQ(true,  ConditionBirthday::isValid("19771211"));
    EXPECT_EQ(false, ConditionBirthday::isValid("1977121Z"));
    EXPECT_EQ(false, ConditionBirthday::isValid("1977121 "));

    // 3. 숫자 범위 검사 결과가 적절한지 확인
    EXPECT_EQ(true,  ConditionBirthday::isValid("19771211"));
    EXPECT_EQ(false, ConditionBirthday::isValid("19771200"));
    EXPECT_EQ(false, ConditionBirthday::isValid("19771232"));
    EXPECT_EQ(false, ConditionBirthday::isValid("19770011"));
    EXPECT_EQ(false, ConditionBirthday::isValid("19771311"));
}

TEST(Condition, isValidBirthdayYear)
{
    // 1. 길이 조건에 대한 검사 결과가 적절한지 확인
    EXPECT_EQ(false, ConditionBirthdayYear::isValid("197"));
    EXPECT_EQ(true,  ConditionBirthdayYear::isValid("1977"));
    EXPECT_EQ(false, ConditionBirthdayYear::isValid("19777"));

    // 2. 문자 구성 검사 결과가 적절한지 확인
    EXPECT_EQ(true,  ConditionBirthdayYear::isValid("1977"));
    EXPECT_EQ(false, ConditionBirthdayYear::isValid("197A"));
    EXPECT_EQ(false, ConditionBirthdayYear::isValid("197 "));
}

TEST(Condition, isValidBirthdayMonth)
{
    // 1. 길이 조건에 대한 검사 결과가 적절한지 확인
    EXPECT_EQ(false, ConditionBirthdayMonth::isValid("1"));
    EXPECT_EQ(true,  ConditionBirthdayMonth::isValid("12"));
    EXPECT_EQ(false, ConditionBirthdayMonth::isValid("123"));

    // 2. 문자 구성 검사 결과가 적절한지 확인
    EXPECT_EQ(true,  ConditionBirthdayMonth::isValid("12"));
    EXPECT_EQ(false, ConditionBirthdayMonth::isValid("1A"));
    EXPECT_EQ(false, ConditionBirthdayMonth::isValid("1 "));

    // 3. 숫자 범위 검사 결과가 적절한지 확인
    EXPECT_EQ(false, ConditionBirthdayMonth::isValid("00"));
    EXPECT_EQ(true,  ConditionBirthdayMonth::isValid("01"));
    EXPECT_EQ(true,  ConditionBirthdayMonth::isValid("12"));
    EXPECT_EQ(false, ConditionBirthdayMonth::isValid("13"));
}

TEST(Condition, isValidBirthdayDay)
{
    // 1. 길이 조건에 대한 검사 결과가 적절한지 확인
    EXPECT_EQ(false, ConditionBirthdayDay::isValid("1"));
    EXPECT_EQ(true,  ConditionBirthdayDay::isValid("12"));
    EXPECT_EQ(false, ConditionBirthdayDay::isValid("123"));

    // 2. 문자 구성 검사 결과가 적절한지 확인
    EXPECT_EQ(true,  ConditionBirthdayDay::isValid("12"));
    EXPECT_EQ(false, ConditionBirthdayDay::isValid("1A"));
    EXPECT_EQ(false, ConditionBirthdayDay::isValid("1 "));

    // 3. 숫자 범위 검사 결과가 적절한지 확인
    EXPECT_EQ(false, ConditionBirthdayDay::isValid("00"));
    EXPECT_EQ(true,  ConditionBirthdayDay::isValid("01"));
    EXPECT_EQ(true,  ConditionBirthdayDay::isValid("31"));
    EXPECT_EQ(false, ConditionBirthdayDay::isValid("32"));
}

TEST(Condition, isValidCerti)
{
    // ADV / PRO / EX 외의 내용은 모두 false로 판단해야 한다.
    EXPECT_EQ(true,  ConditionCerti::isValid("EX"));
    EXPECT_EQ(true,  ConditionCerti::isValid("PRO"));
    EXPECT_EQ(true,  ConditionCerti::isValid("ADV"));

    EXPECT_EQ(false, ConditionCerti::isValid(""));
    EXPECT_EQ(false, ConditionCerti::isValid("PRO "));
    EXPECT_EQ(false, ConditionCerti::isValid("PROO"));
    EXPECT_EQ(false, ConditionCerti::isValid("INVALID_STRING"));
}

TEST(Condition, make)
{
    Employee employee = { 2015123099, {"VXIHTOTH", "JHOP"}, CL::CL3, {3112, 2609}, {1977, 12, 11}, Grade::ADV };

    // 1. Condition::make를 통해 각 Condition type별 Entry를 생성한다.
    // 2. nullptr이 아닌 값이 반환되었는지 확인한다.
    // 3. 원하는대로 값이 설정되었는지 확인한다.

    ConditionPtr conditionEmployeeNum = Condition::make("employeeNum", "15123099");
    ASSERT_NE(nullptr, conditionEmployeeNum);
    EXPECT_EQ(true, conditionEmployeeNum->isEqual(employee));

    ConditionPtr conditionName = Condition::make("name", "VXIHTOTH JHOP");
    ASSERT_NE(nullptr, conditionName);
    EXPECT_EQ(true, conditionName->isEqual(employee));

    ConditionPtr conditionNameFirst = Condition::make("nameFirst", "VXIHTOTH");
    ASSERT_NE(nullptr, conditionNameFirst);
    EXPECT_EQ(true, conditionNameFirst->isEqual(employee));

    ConditionPtr conditionNameLast = Condition::make("nameLast", "JHOP");
    ASSERT_NE(nullptr, conditionNameLast);
    EXPECT_EQ(true, conditionNameLast->isEqual(employee));

    ConditionPtr conditionCl = Condition::make("cl", "CL3");
    ASSERT_NE(nullptr, conditionCl);
    EXPECT_EQ(true, conditionCl->isEqual(employee));

    ConditionPtr conditionPhoneNum = Condition::make("phoneNum", "010-3112-2609");
    ASSERT_NE(nullptr, conditionPhoneNum);
    EXPECT_EQ(true, conditionPhoneNum->isEqual(employee));

    ConditionPtr conditionPhoneNumMid = Condition::make("phoneNumMid", "3112");
    ASSERT_NE(nullptr, conditionPhoneNumMid);
    EXPECT_EQ(true, conditionPhoneNumMid->isEqual(employee));

    ConditionPtr conditionPhoneNumEnd = Condition::make("phoneNumEnd", "2609");
    ASSERT_NE(nullptr, conditionPhoneNumEnd);
    EXPECT_EQ(true, conditionPhoneNumEnd->isEqual(employee));

    ConditionPtr conditionBirthday = Condition::make("birthday", "19771211");
    ASSERT_NE(nullptr, conditionBirthday);
    EXPECT_EQ(true, conditionBirthday->isEqual(employee));

    ConditionPtr conditionBirthdayYear = Condition::make("birthdayYear", "1977");
    ASSERT_NE(nullptr, conditionBirthdayYear);
    EXPECT_EQ(true, conditionBirthdayYear->isEqual(employee));

    ConditionPtr conditionBirthdayMonth = Condition::make("birthdayMonth", "12");
    ASSERT_NE(nullptr, conditionBirthdayMonth);
    EXPECT_EQ(true, conditionBirthdayMonth->isEqual(employee));

    ConditionPtr conditionBirthdayDay = Condition::make("birthdayDay", "11");
    ASSERT_NE(nullptr, conditionBirthdayDay);
    EXPECT_EQ(true, conditionBirthdayDay->isEqual(employee));

    ConditionPtr conditionCerti = Condition::make("certi", "ADV");
    ASSERT_NE(nullptr, conditionCerti);
    EXPECT_EQ(true, conditionCerti->isEqual(employee));
}
