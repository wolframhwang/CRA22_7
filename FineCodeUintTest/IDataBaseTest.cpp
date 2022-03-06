#include "pch.h"
#include "gtest/gtest.h"
#include "../FineCode/IDataBase.h"
#include "../FineCode/Condition.cpp"

TEST(IDataBaseTC, IDBAdd) {
    IDataBase *db = new DataBase();
    
    db->add({ 20045583, {"Wolfram", "Hwang"}, CL::CL2, {5678,4321}, {2000, 2, 14}, Grade::PRO });
    db->add({ 12345678, {"ABC", "DEF"}, CL::CL2, {1234, 5678}, {2120, 2, 14}, Grade::EX});
	db->add({ 2015123099, {"POPO","JHON"},CL::CL3,{3112,2609},{1977,12,11},Grade::ADV });
	db->add({ 2017112609, {"FB","ANANTA"},CL::CL4,{5645,6122},{1986,12,03},Grade::PRO });
	db->add({ 2018115040, {"TWITTER","NETFLIX"},CL::CL3,{4581,2050},{2008,7,18},Grade::ADV });
	db->add({ 2088114052, {"JHON","WICK"},CL::CL4,{4528,3059},{1991,10,21},Grade::PRO });
	db->add({ 2019129568, {"SELFISH","HERMAN"},CL::CL2,{3091,9521},{1964,9,10},Grade::PRO });
	db->add({ 2017111236, {"VIVID","TV"},CL::CL1,{3669,1077},{2012,7,18},Grade::PRO });
	db->add({ 2018117906, {"TMU","OCELOTE"},CL::CL4,{6672,7186},{2003,4,13},Grade::PRO });
	db->add({ 1908123556, {"WV","XYZ"},CL::CL1,{7986,5047},{2010,6,14},Grade::PRO });
	db->add({ 1902117175, {"SNOW","BOARD"},CL::CL4,{2814,1699},{1995,07,04},Grade::ADV });
	db->add({ 1903113260, {"SKATE","BOARD"},CL::CL2,{5798,5383},{1979,10,18},Grade::PRO });

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


TEST(IDataBase, IDBSearch) {
    IDataBase *db = new DataBase();
    
    db->add({ 20045583, {"Wolfram", "Hwang"}, CL::CL2, {5678,4321}, {2000, 2, 14}, Grade::PRO });
    db->add({ 20045584, {"Wolfram", "Hwang"}, CL::CL2, {5678,4321}, {2000, 2, 14}, Grade::PRO });
    db->add({ 20045585, {"Wolfram", "Hwang"}, CL::CL2, {5678,4321}, {2000, 2, 14}, Grade::PRO });
    db->add({ 20045586, {"Wolfram", "Hwang"}, CL::CL2, {5678,4321}, {2000, 2, 14}, Grade::PRO });
    db->add({ 12345678, {"ABC", "DEF"}, CL::CL2, {1234, 5678}, {2120, 2, 14}, Grade::EX});
	db->add({ 2015123099, {"POPO","JHON"},CL::CL3,{3112,2609},{1977,12,11},Grade::ADV });
	db->add({ 2017112609, {"FB","ANANTA"},CL::CL4,{5645,6122},{1986,12,03},Grade::PRO });
	db->add({ 2018115040, {"TWITTER","NETFLIX"},CL::CL3,{4581,2050},{2008,7,18},Grade::ADV });
	db->add({ 2088114052, {"JHON","WICK"},CL::CL4,{4528,3059},{1991,10,21},Grade::PRO });
	db->add({ 2019129568, {"SELFISH","HERMAN"},CL::CL2,{3091,9521},{1964,9,10},Grade::PRO });
	db->add({ 2017111236, {"VIVID","TV"},CL::CL1,{3669,1077},{2012,7,18},Grade::PRO });
	db->add({ 2018117906, {"TMU","OCELOTE"},CL::CL4,{6672,7186},{2003,4,13},Grade::PRO });
	db->add({ 1908123556, {"WV","XYZ"},CL::CL1,{7986,5047},{2010,6,14},Grade::PRO });
	db->add({ 1902117175, {"SNOW","BOARD"},CL::CL4,{2814,1699},{1995,07,04},Grade::ADV });
	db->add({ 1903113260, {"SKATE","BOARD"},CL::CL2,{5798,5383},{1979,10,18},Grade::PRO });
    
    Condition *cond = new ConditionNameFirst("Wolfram");
    vector<unsigned long> ret = db->search(*cond);
    EXPECT_EQ(20045583, ret[0]);
    EXPECT_EQ(20045584, ret[1]);
    EXPECT_EQ(20045585, ret[2]);
    EXPECT_EQ(20045586, ret[3]);
}

TEST(IDataBaseTC, IDBMod) {
    IDataBase *db = new DataBase();
    
    db->add({ 20045583, {"Wolfram", "Hwang"}, CL::CL2, {5678,4321}, {2000, 2, 14}, Grade::PRO });
    db->add({ 12345678, {"ABC", "DEF"}, CL::CL2, {1234, 5678}, {2120, 2, 14}, Grade::EX});
	db->add({ 2015123099, {"POPO","JHON"},CL::CL3,{3112,2609},{1977,12,11},Grade::ADV });
	db->add({ 2017112609, {"FB","ANANTA"},CL::CL4,{5645,6122},{1986,12,03},Grade::PRO });
	db->add({ 2018115040, {"TWITTER","NETFLIX"},CL::CL3,{4581,2050},{2008,7,18},Grade::ADV });
	db->add({ 2088114052, {"JHON","WICK"},CL::CL4,{4528,3059},{1991,10,21},Grade::PRO });
	db->add({ 2019129568, {"SELFISH","HERMAN"},CL::CL2,{3091,9521},{1964,9,10},Grade::PRO });
	db->add({ 2017111236, {"VIVID","TV"},CL::CL1,{3669,1077},{2012,7,18},Grade::PRO });
	db->add({ 2018117906, {"TMU","OCELOTE"},CL::CL4,{6672,7186},{2003,4,13},Grade::PRO });
	db->add({ 1908123556, {"WV","XYZ"},CL::CL1,{7986,5047},{2010,6,14},Grade::PRO });
	db->add({ 1902117175, {"SNOW","BOARD"},CL::CL4,{2814,1699},{1995,07,04},Grade::ADV });
	db->add({ 1903113260, {"SKATE","BOARD"},CL::CL2,{5798,5383},{1979,10,18},Grade::PRO });
    
    EXPECT_EQ(db->getEmployeeInfo(20045583)->birthday.year, 2000);    
    Condition *findCond = new ConditionNameFirst("Wolfram");
    Condition *modifyCond = new ConditionBirthdayYear(2012);
    vector<unsigned long> ret = db->search(*cond);
    db->modify(ret[0], *modifyCond);
    EXPECT_EQ(db->getEmployeeInfo(20045583)->birthday.year, 2012);    
}


TEST(IDataBaseTC, IDBErase) {
    IDataBase *db = new DataBase();
    
    db->add({ 20045583, {"Wolfram", "Hwang"}, CL::CL2, {5678,4321}, {2000, 2, 14}, Grade::PRO });
    db->add({ 12345678, {"ABC", "DEF"}, CL::CL2, {1234, 5678}, {2120, 2, 14}, Grade::EX});
	db->add({ 2015123099, {"POPO","JHON"},CL::CL3,{3112,2609},{1977,12,11},Grade::ADV });
	db->add({ 2017112609, {"FB","ANANTA"},CL::CL4,{5645,6122},{1986,12,03},Grade::PRO });
	db->add({ 2018115040, {"TWITTER","NETFLIX"},CL::CL3,{4581,2050},{2008,7,18},Grade::ADV });
	db->add({ 2088114052, {"JHON","WICK"},CL::CL4,{4528,3059},{1991,10,21},Grade::PRO });
	db->add({ 2019129568, {"SELFISH","HERMAN"},CL::CL2,{3091,9521},{1964,9,10},Grade::PRO });
	db->add({ 2017111236, {"VIVID","TV"},CL::CL1,{3669,1077},{2012,7,18},Grade::PRO });
	db->add({ 2018117906, {"TMU","OCELOTE"},CL::CL4,{6672,7186},{2003,4,13},Grade::PRO });
	db->add({ 1908123556, {"WV","XYZ"},CL::CL1,{7986,5047},{2010,6,14},Grade::PRO });
	db->add({ 1902117175, {"SNOW","BOARD"},CL::CL4,{2814,1699},{1995,07,04},Grade::ADV });
	db->add({ 1903113260, {"SKATE","BOARD"},CL::CL2,{5798,5383},{1979,10,18},Grade::PRO });
    
    //EXPECT_EQ(db->erase(12345678), true);
    //EXPECT_EQ(db->getEmployeeInfo(12345678), NULL);
}