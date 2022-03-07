#include "gtest/gtest.h"
#include "../FineCode/cmd.cpp"
#include "../FineCode/cmd.h"
#include "../FineCode/IDataBase.h"
#include "../FineCode/Result.h"

namespace {
    class CmdTest : public testing::Test {
    protected:
        void SetUp() override {
            db = make_shared<DataBase>();
        }
        // helper
        bool isSame(Result a, Result b) {
            //return a == b;
            return false;
        }
        // common data
        shared_ptr<IDataBase> db;
        Result result;
    };


    // ADD
    TEST_F(CmdTest, CmdAddSuccess) {
        shared_ptr<ICmd> add = ICmd::getCmd("ADD");
        Employee employee = { 2015123099, { "VXIHXOTH", "JHOP" }, CL::CL3, { 3112,2609 }, { 1977,12,11 }, Grade::ADV };

        EXPECT_TRUE(add->execute(db));
    }

    TEST_F(CmdTest, CmdAddFail) {
        shared_ptr<ICmd> icmd = ICmd::getCmd("ADD");
        Employee employee = { 99, { "VXIHXOTH", "JHOP" }, CL::CL3, { 3112,2609 }, { 1977,12,11 }, Grade::ADV };
        icmd->setEmployee(make_shared<Employee>(employee));
        EXPECT_TRUE(!icmd->execute(db));
    }

    // Modify
    TEST_F(CmdTest, CmdModifySuccess) {
        shared_ptr<ICmd> add = ICmd::getCmd("ADD");
        Employee employee = { 2015123099, { "VXIHXOTH", "JHOP" }, CL::CL3, { 3112,2609 }, { 1977,12,11 }, Grade::ADV };
        EXPECT_TRUE(add->execute(db));
        shared_ptr<ICmd> mod = ICmd::getCmd("MOD");
        Employee employee1 = { 2015123099, { "VXIHXOTH", "JHOP" }, CL::CL2, { 3112,2609 }, { 1977,12,11 }, Grade::ADV };
        // TODO : Get right Condition instance
        shared_ptr<Condition> cond;
        mod->setCondition(cond);
        EXPECT_TRUE(mod->execute(db));
    }
    TEST_F(CmdTest, CmdModifyFail) {
        shared_ptr<ICmd> mod = ICmd::getCmd("MOD");
        Employee employee = { 2015123099, { "VXIHXOTH", "JHOP" }, CL::CL3, { 3112,2609 }, { 1977,12,11 }, Grade::ADV };
        shared_ptr<Condition> cond;
        mod->setCondition(cond);
        EXPECT_TRUE(!mod->execute(db));
    }

    // Search
    TEST_F(CmdTest, CmdSearchSuccess) {
        shared_ptr<ICmd> add = ICmd::getCmd("ADD");
        Employee employee = { 2015123099, { "VXIHXOTH", "JHOP" }, CL::CL3, { 3112,2609 }, { 1977,12,11 }, Grade::ADV };
        EXPECT_TRUE(add->execute(db));
        shared_ptr<ICmd> sch = ICmd::getCmd("SCH");
        Employee employee1 = { 2015123099, { "VXIHXOTH", "JHOP" }, CL::CL3, { 3112,2609 }, { 1977,12,11 }, Grade::ADV };
        shared_ptr<Condition> cond;
        sch->setCondition(cond);
        EXPECT_TRUE(sch->execute(db));
    }
    TEST_F(CmdTest, CmdSearchFail) {
        shared_ptr<ICmd> sch = ICmd::getCmd("SCH");
        Employee employee = { 2015123099, { "VXIHXOTH", "JHOP" }, CL::CL3, { 3112,2609 }, { 1977,12,11 }, Grade::ADV };
        shared_ptr<Condition> cond;
        sch->setCondition(cond);
        EXPECT_TRUE(!sch->execute(db));
    }

    // Erase
    TEST_F(CmdTest, CmdEraseSuccess) {
        shared_ptr<ICmd> add = ICmd::getCmd("ADD");
        Employee employee = { 2015123099, { "VXIHXOTH", "JHOP" }, CL::CL3, { 3112,2609 }, { 1977,12,11 }, Grade::ADV };
        EXPECT_TRUE(add->execute(db));
        shared_ptr<ICmd> del = ICmd::getCmd("DEL");
        Employee employee1 = { 2015123099, { "VXIHXOTH", "JHOP" }, CL::CL3, { 3112,2609 }, { 1977,12,11 }, Grade::ADV };
        shared_ptr<Condition> cond;
        del->setCondition(cond);
        EXPECT_TRUE(del->execute(db));
    }
    TEST_F(CmdTest, CmdEraseFail) {
        shared_ptr<ICmd> del = ICmd::getCmd("DEL");
        Employee employee = { 2015123099, { "VXIHXOTH", "JHOP" }, CL::CL3, { 3112,2609 }, { 1977,12,11 }, Grade::ADV };
        shared_ptr<Condition> cond;
        del->setCondition(cond);
        EXPECT_TRUE(!del->execute(db));
    }
}
