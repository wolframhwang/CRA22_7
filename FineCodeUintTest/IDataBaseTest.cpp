#include "gtest/gtest.h"
#include "../FineCode/IDataBase.h"

TEST(IDataBaseTC, IDBAdd) {
    IDataBase *db = new DataBase();

    db->add({ 20045583, {"Wolfram", "Hwang"}, CL::CL2, {5678,4321}, {2000, 2, 14}, Grade::PRO });
    db->add({ 12345678, {"ABC", "DEF"}, CL::CL2, {1234, 5678}, {2120, 2, 14}, Grade::EX});

    EXPECT_EQ(db->getEmployeeInfo(20045583)->name.first, "Wolfram");
    EXPECT_EQ(db->getEmployeeInfo(20045583)->name.last, "Hwang");
    EXPECT_EQ(db->getEmployeeInfo(20045583)->cl, CL::CL2);
    EXPECT_EQ(db->getEmployeeInfo(20045583)->phoneNum.mid, 5678);
    EXPECT_EQ(db->getEmployeeInfo(20045583)->phoneNum.end, 4321);
    EXPECT_EQ(db->getEmployeeInfo(20045583)->birthday.year, 2000);
    EXPECT_EQ(db->getEmployeeInfo(20045583)->birthday.month, 2);
    EXPECT_EQ(db->getEmployeeInfo(20045583)->birthday.day, 14);
    EXPECT_EQ(db->getEmployeeInfo(20045583)->certi, Grade::PRO);
    
    EXPECT_EQ(db->getEmployeeInfo(12345678)->name.first, "ABC");
    EXPECT_EQ(db->getEmployeeInfo(12345678)->name.last, "DEF");
    EXPECT_EQ(db->getEmployeeInfo(12345678)->cl, CL::CL2);
    EXPECT_EQ(db->getEmployeeInfo(12345678)->phoneNum.mid, 1234);
    EXPECT_EQ(db->getEmployeeInfo(12345678)->phoneNum.end, 5678);
    EXPECT_EQ(db->getEmployeeInfo(12345678)->birthday.year, 2120);
    EXPECT_EQ(db->getEmployeeInfo(12345678)->birthday.month, 2);
    EXPECT_EQ(db->getEmployeeInfo(12345678)->birthday.day, 14);
    EXPECT_EQ(db->getEmployeeInfo(12345678)->certi, Grade::EX);
}

TEST(IDataBaseTC, IDBMod) {
    
    //EXPECT_EQ(db->modify(EmployeeNumber, EmployeeInfo()), true);
}


TEST(IDataBaseTC, IDBErase) {

    //EXPECT_EQ(db->erase(12345678), true);
    //EXPECT_EQ(db->getEmployeeInfo(12345678), NULL);
}