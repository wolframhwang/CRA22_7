#include "gtest/gtest.h"

TEST(IDataBaseTC, IDBAdd) {
    db->add({EmployeeNumber1, EmployeeInfo()});
    db->add({EmployeeNumber2, EmployeeInfo()});

    EXPECT_EQ(db->getEmployeeInfo(20045583)->name.first, "Hwang");
    EXPECT_EQ(db->getEmployeeInfo(20045583)->name.last, "Jiwoong");
    EXPECT_EQ(db->getEmployeeInfo(20045583)->cl, "CL2");
    EXPECT_EQ(db->getEmployeeInfo(20045583)->phoneNum.head, "010");
    EXPECT_EQ(db->getEmployeeInfo(20045583)->phoneNum.body, "1234");
    EXPECT_EQ(db->getEmployeeInfo(20045583)->phoneNum.last, "5678");
    EXPECT_EQ(db->getEmployeeInfo(20045583)->birth.year, "2000");
    EXPECT_EQ(db->getEmployeeInfo(20045583)->birth.month, "2");
    EXPECT_EQ(db->getEmployeeInfo(20045583)->birth.day, "14");
    EXPECT_EQ(db->getEmployeeInfo(20045583)->certi, "professional");

    EXPECT_EQ(db->getEmployeeInfo(12345678)->name.first, "ABC");
    EXPECT_EQ(db->getEmployeeInfo(12345678)->name.last, "DEF");
    EXPECT_EQ(db->getEmployeeInfo(12345678)->cl, "CL2");
    EXPECT_EQ(db->getEmployeeInfo(12345678)->phoneNum.head, "010");
    EXPECT_EQ(db->getEmployeeInfo(12345678)->phoneNum.body, "1234");
    EXPECT_EQ(db->getEmployeeInfo(12345678)->phoneNum.last, "5678");
    EXPECT_EQ(db->getEmployeeInfo(12345678)->birth.year, "2120");
    EXPECT_EQ(db->getEmployeeInfo(12345678)->birth.month, "2");
    EXPECT_EQ(db->getEmployeeInfo(12345678)->birth.day, "14");
    EXPECT_EQ(db->getEmployeeInfo(12345678)->certi, "Expert");
}

TEST(IDataBaseTC, IDBMod) {
    
    EXPECT_EQ(db->modify(EmployeeNumber, EmployeeInfo()), true);
}


TEST(IDataBaseTC, IDBErase) {

    EXPECT_EQ(db->erase(12345678), true);
    EXPECT_EQ(db->getEmployeeInfo(12345678), NULL);
}