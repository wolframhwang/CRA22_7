#include "gtest/gtest.h"
#include "../FineCode/Condition.cpp"
#include "../FineCode/cmd.cpp"
#include "../FineCode/IDataBase.h"
#include "../FineCode/Result.h"

namespace {
    class CmdTest : public testing::Test {
    protected:
        void SetUp() override {
            db = make_shared<DataBase>();
            vector<string> cmd = { "ADD","","","", "18050301", "KYUMOK KIM", "CL2", "010-9777-6055", "19980906", "PRO" };
            shared_ptr<ICmd> add = ICmd::getCmd(cmd);
            add->execute(db);
        }
        // common data
        shared_ptr<IDataBase> db;
    };

    // ADD
    TEST_F(CmdTest, CmdAddSuccess) {
        vector<string> cmd = { "ADD","","","", "18050302", "KYUMOK KIM", "CL2", "010-9777-6055", "19980906", "PRO" };
        shared_ptr<ICmd> add = ICmd::getCmd(cmd);
        string res = add->getResult();
        EXPECT_TRUE(add->execute(db));
    }
    TEST_F(CmdTest, CmdAddFail) {
        // duplicate
        vector<string> cmd = { "ADD","","","", "18050301", "KYUMOK KIM", "CL2", "010-9777-6055", "19980906", "PRO" };

        shared_ptr<ICmd> add = ICmd::getCmd(cmd);
        EXPECT_TRUE(!add->execute(db));
    }
    TEST_F(CmdTest, getCmdAssert) {
        // Too long phon number
        vector<string> cmd = { "ADD","","","", "18050301", "KYUMOK KIM", "CL2", "010-9777-60556", "19980906", "PRO" };
        ASSERT_ANY_THROW(ICmd::getCmd(cmd));
    }

    // Modify
    TEST_F(CmdTest, CmdModifySuccess) {
        vector<string> cmd = { "MOD","","","", "name", "KYUMOK KIM", "name", "KYUMOK LEE"};
        shared_ptr<ICmd> mod = ICmd::getCmd(cmd);
        EXPECT_TRUE(mod->execute(db));
        string res = mod->getResult();
        string expected = "MOD,1";
        EXPECT_TRUE(res == expected);

        vector<string> cmd2 = { "MOD","-p","","", "name", "KYUMOK LEE", "name", "KYUMOK KOO" };
        shared_ptr<ICmd> mod2 = ICmd::getCmd(cmd2);
        EXPECT_TRUE(mod2->execute(db));
        string res2 = mod2->getResult();
        string expected2 = "MOD,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO";
        EXPECT_TRUE(res == expected2);

        vector<string> cmd3 = { "MOD","-p","-f","", "name", "KYUMOK", "phoneNum", "010-9777-6057" };
        shared_ptr<ICmd> mod3 = ICmd::getCmd(cmd3);
        EXPECT_TRUE(mod3->execute(db));
        string res3 = mod3->getResult();
        string expected3 = "MOD,18050301,KYUMOK KIM,CL2,010-9777-6057,19980906,PRO";
        EXPECT_TRUE(res3 == expected3);
    }
    TEST_F(CmdTest, CmdModifyNameSuccess) {
        vector<string> cmd = { "MOD","","-f","", "name", "KYUMOK", "phoneNum", "010-9777-6057" };
        shared_ptr<ICmd> mod = ICmd::getCmd(cmd);
        EXPECT_TRUE(mod->execute(db));
        string res = mod->getResult();
        string expected = "MOD,18050301,KYUMOK KIM,CL2,010-9777-6057,19980906,PRO";
        EXPECT_TRUE(res == expected);

        vector<string> cmd3 = { "MOD","","-l","", "name", "KIM", "phoneNum", "010-9777-6057" };
        shared_ptr<ICmd> mod3 = ICmd::getCmd(cmd3);
        EXPECT_TRUE(mod3->execute(db));
        string res3 = mod3->getResult();
        string expected3 = "MOD,18050301,KYUMOK KIM,CL2,010-9777-6057,19980906,PRO";
        EXPECT_TRUE(res3 == expected3);
    }
    TEST_F(CmdTest, CmdModifyCLSuccess) {
        vector<string> cmd3 = { "MOD","-p","","", "cl", "CL2", "phoneNum", "010-9777-6057" };
        shared_ptr<ICmd> mod3 = ICmd::getCmd(cmd3);
        EXPECT_TRUE(mod3->execute(db));
        string res3 = mod3->getResult();
        string expected3 = "MOD,18050301,KYUMOK KIM,CL2,010-9777-6057,19980906,PRO";
        EXPECT_TRUE(res3 == expected3);
    }
    TEST_F(CmdTest, CmdModifyPhoneSuccess) {
        vector<string> cmd = { "MOD","-p","","", "phoneNum", "010-9777-6055", "certi", "ADV" };
        shared_ptr<ICmd> mod = ICmd::getCmd(cmd);
        EXPECT_TRUE(mod->execute(db));
        string res = mod->getResult();
        string expected = "MOD,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,ADV";
        EXPECT_TRUE(res == expected);

        vector<string> cmd2 = { "MOD","-p","-m","", "phoneNum", "9777", "certi", "ADV" };
        shared_ptr<ICmd> mod2 = ICmd::getCmd(cmd2);
        EXPECT_TRUE(mod2->execute(db));
        string res2 = mod2->getResult();
        string expected2 = "MOD,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,ADV";
        EXPECT_TRUE(res2 == expected2);

        vector<string> cmd3 = { "MOD","-p","-l","", "phoneNum", "6055", "certi", "ADV" };
        shared_ptr<ICmd> mod3 = ICmd::getCmd(cmd3);
        EXPECT_TRUE(mod3->execute(db));
        string res3 = mod3->getResult();
        string expected3 = "MOD,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,ADV";
        EXPECT_TRUE(res3 == expected3);
    }
    TEST_F(CmdTest, CmdModifyFail) {
        // Not found
        vector<string> cmd = { "MOD","","","", "name", "KYUMOK YA", "name", "KYUMOK LEE" };
        shared_ptr<ICmd> mod = ICmd::getCmd(cmd);
        EXPECT_TRUE(mod->execute(db));
        string res = mod->getResult();
        string expected = "MOD,NONE";
        EXPECT_TRUE(res == expected);
    }

    // Search
    TEST_F(CmdTest, CmdSearchSuccess) {
        vector<string> cmd = { "SCH","","","", "name", "KYUMOK KIM" };
        shared_ptr<ICmd> sch = ICmd::getCmd(cmd);
        EXPECT_TRUE(sch->execute(db));
        string res = sch->getResult();
        string expected = "SCH,1";
        EXPECT_TRUE(res == expected);

        vector<string> cmd2 = { "SCH","-p","","", "name", "KYUMOK KIM" };
        shared_ptr<ICmd> sch2 = ICmd::getCmd(cmd2);
        EXPECT_TRUE(sch2->execute(db));
        string res2 = sch2->getResult();
        string expected2 = "SCH,1";
        EXPECT_TRUE(res2 == expected2);
    }
    TEST_F(CmdTest, CmdSearchFail) {
        vector<string> cmd = { "SCH","","","", "name", "UU K" };
        shared_ptr<ICmd> sch = ICmd::getCmd(cmd);
        EXPECT_TRUE(sch->execute(db));
        string res = sch->getResult();
        string expected = "SCH,NONE";
        EXPECT_TRUE(res == expected);
    }

    // Erase
    TEST_F(CmdTest, CmdEraseSuccess) {
        vector<string> cmd = { "DEL","","","", "name", "KYUMOK KIM" };
        shared_ptr<ICmd> del = ICmd::getCmd(cmd);
        EXPECT_TRUE(del->execute(db));
        string res = del->getResult();
        string expected = "DEL,1";
        EXPECT_TRUE(res == expected);
    }
    TEST_F(CmdTest, CmdEraseFail) {
        vector<string> cmd = { "DEL","","","", "name", "KYUMOK LEE" };
        shared_ptr<ICmd> del = ICmd::getCmd(cmd);
        EXPECT_TRUE(del->execute(db));
        string res = del->getResult();
        string expected = "DEL,NONE";
        EXPECT_TRUE(res == expected);
    }
}
