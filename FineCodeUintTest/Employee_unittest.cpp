#include "gtest/gtest.h"
#include "../FineCode/Employee.h"

TEST(UT_Employee, Constructor) {
    // 1. 기본 생성자를 이용해 Employee 객체를 초기화한다.
    // 2. 객체의 각 변수가 원하는 값으로 초기화 되었는지 확인한다.

    Employee employee1 = { 2015123099, {"VXIHTOTH", "JHOP"}, CL::CL3, {3112, 2609}, {1977, 12, 11}, Grade::ADV };
    EXPECT_EQ(2015123099, employee1.employeeNum);
    EXPECT_EQ("VXIHTOTH", employee1.name.first);
    EXPECT_EQ("JHOP",     employee1.name.last);
    EXPECT_EQ(CL::CL3,    employee1.cl);
    EXPECT_EQ(3112,       employee1.phoneNum.mid);
    EXPECT_EQ(2609,       employee1.phoneNum.end);
    EXPECT_EQ(1977,       employee1.birthday.year);
    EXPECT_EQ(12,         employee1.birthday.month);
    EXPECT_EQ(11,         employee1.birthday.day);
    EXPECT_EQ(Grade::ADV, employee1.certi);

    Employee employee2 = { 2017112609, {"FB", "NTAWR"},      CL::CL4, {5645, 6122}, {1986, 11, 03}, Grade::PRO };
    EXPECT_EQ(2017112609, employee2.employeeNum);
    EXPECT_EQ("FB",       employee2.name.first);
    EXPECT_EQ("NTAWR",    employee2.name.last);
    EXPECT_EQ(CL::CL4,    employee2.cl);
    EXPECT_EQ(5645,       employee2.phoneNum.mid);
    EXPECT_EQ(6122,       employee2.phoneNum.end);
    EXPECT_EQ(1986,       employee2.birthday.year);
    EXPECT_EQ(11,         employee2.birthday.month);
    EXPECT_EQ(03,         employee2.birthday.day);
    EXPECT_EQ(Grade::PRO, employee2.certi);
}

TEST(UT_Employee, ConstructorVectorString) {
    // 1. 사용자로부터 parameter로 받을 수 있는 형태인
    //    vector<string>을 인자로 받는 생성자를 이용해 Employee 객체를 초기화한다.
    // 2. 객체의 각 변수가 원하는 값으로 초기화 되었는지 확인한다.

    vector<string> params1 = { "15123099", "VXIHTOTH JHOP", "CL3", "010-3112-2609", "19771211", "ADV" };
    Employee employee1(params1);
    EXPECT_EQ(2015123099, employee1.employeeNum);
    EXPECT_EQ("VXIHTOTH", employee1.name.first);
    EXPECT_EQ("JHOP",     employee1.name.last);
    EXPECT_EQ(CL::CL3,    employee1.cl);
    EXPECT_EQ(3112,       employee1.phoneNum.mid);
    EXPECT_EQ(2609,       employee1.phoneNum.end);
    EXPECT_EQ(1977,       employee1.birthday.year);
    EXPECT_EQ(12,         employee1.birthday.month);
    EXPECT_EQ(11,         employee1.birthday.day);
    EXPECT_EQ(Grade::ADV, employee1.certi);

    vector<string> params2 = { "17112609", "FB NTAWR", "CL4", "010-5645-6122", "19861103", "PRO" };
    Employee employee2(params2);
    EXPECT_EQ(2017112609, employee2.employeeNum);
    EXPECT_EQ("FB",       employee2.name.first);
    EXPECT_EQ("NTAWR",    employee2.name.last);
    EXPECT_EQ(CL::CL4,    employee2.cl);
    EXPECT_EQ(5645,       employee2.phoneNum.mid);
    EXPECT_EQ(6122,       employee2.phoneNum.end);
    EXPECT_EQ(1986,       employee2.birthday.year);
    EXPECT_EQ(11,         employee2.birthday.month);
    EXPECT_EQ(03,         employee2.birthday.day);
    EXPECT_EQ(Grade::PRO, employee2.certi);
}
