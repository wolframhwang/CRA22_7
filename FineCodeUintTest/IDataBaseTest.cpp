#include "gtest/gtest.h"
#include "../FineCode/IDataBase.h"

TEST(IDataBaseTC, IDBAdd) {
    IDataBase *db = new DataBase();

    db->add(EmployeeInfo(20045583, {"Wolfram", "Hwang"}, CL::CL2, {5678,4321}, {2000, 2, 14}, Grade::PRO));
    db->add({123456789, {"ABC", "DEF"}, CL::CL2, {1234, 5678}, {2120, 2, 14}, Grade::EXP});

    EXPECT_EQ(db->getEmployeeInfo(20045583)->name.first, "Hwang");
    EXPECT_EQ(db->getEmployeeInfo(20045583)->name.last, "Jiwoong");
    EXPECT_EQ(db->getEmployeeInfo(20045583)->cl, CL::CL2);
    EXPECT_EQ(db->getEmployeeInfo(20045583)->phoneNum.body, 5678);
    EXPECT_EQ(db->getEmployeeInfo(20045583)->phoneNum.last, 4321);
    EXPECT_EQ(db->getEmployeeInfo(20045583)->birth.year, 2000);
    EXPECT_EQ(db->getEmployeeInfo(20045583)->birth.month, 2);
    EXPECT_EQ(db->getEmployeeInfo(20045583)->birth.day, 14);
    EXPECT_EQ(db->getEmployeeInfo(20045583)->certi, Grade::PRO);

    EXPECT_EQ(db->getEmployeeInfo(12345678)->name.first, "ABC");
    EXPECT_EQ(db->getEmployeeInfo(12345678)->name.last, "DEF");
    EXPECT_EQ(db->getEmployeeInfo(12345678)->cl, CL::CL2);
    EXPECT_EQ(db->getEmployeeInfo(12345678)->phoneNum.body, 1234);
    EXPECT_EQ(db->getEmployeeInfo(12345678)->phoneNum.last, 5678);
    EXPECT_EQ(db->getEmployeeInfo(12345678)->birth.year, 2120);
    EXPECT_EQ(db->getEmployeeInfo(12345678)->birth.month, 2);
    EXPECT_EQ(db->getEmployeeInfo(12345678)->birth.day, 14);
    EXPECT_EQ(db->getEmployeeInfo(12345678)->certi, Grade::EXP);
}

TEST(IDataBaseTC, IDBMod) {
    
    EXPECT_EQ(db->modify(EmployeeNumber, EmployeeInfo()), true);
}


TEST(IDataBaseTC, IDBErase) {

    EXPECT_EQ(db->erase(12345678), true);
    EXPECT_EQ(db->getEmployeeInfo(12345678), NULL);
}