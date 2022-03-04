#include "gtest/gtest.h"
#include "../FineCode/cmd.h"
#include "../FineCode/IDataBase.h"

namespace {
    class CmdTest : public testing::Test {
    protected:
        void SetUp() override {
            db = make_shared<DataBase>();
        }
        // helper
        bool isSame(Result a, Result b) {
            return a == b;
        }

        void factory(string str) {
            if (str == "CmdAdd") {
                icmd = make_shared <CmdAdd>();
            }
            else if (str == "CmdModify") {
                icmd = make_shared<CmdModify>();
            }
            else if (str == "CmdSearch") {
                icmd = make_shared<CmdSearch>();
            }
            else if (str == "CmdErase") {
                icmd = make_shared<CmdErase>();
            }
            else {
                cout << "invalid Cmd\n";
            }
        }
        // common data
        shared_ptr<ICmd> icmd;
        shared_ptr<IDataBase> db;
        Result result;
    };


    // ADD
    TEST_F(CmdTest, CmdAddSuccess) {
        factory("CmdAdd");
        Result expected{ "NOK" };
        result = icmd->execute(db);

        EXPECT_TRUE(isSame(expected, result));
    }

    TEST_F(CmdTest, CmdAddFail) {
        factory("CmdAdd");
        Result expected{"OK"};
        result = icmd->execute(db);

        EXPECT_TRUE(!isSame(expected, result));
    }

    // Modify
    TEST_F(CmdTest, CmdModifySuccess) {
        factory("CmdModify");
        Result expected{ "NOK" };
        result = icmd->execute(db);

        EXPECT_TRUE(isSame(expected, result));
    }
    TEST_F(CmdTest, CmdModifyFail) {
        factory("CmdModify");
        Result expected{ "OK" };
        result = icmd->execute(db);

        EXPECT_TRUE(!isSame(expected, result));
    }

    // Search
    TEST_F(CmdTest, CmdSearchSuccess) {
        factory("CmdSearch");
        Result expected{ "NOK" };
        result = icmd->execute(db);

        EXPECT_TRUE(isSame(expected, result));
    }
    TEST_F(CmdTest, CmdSearchFail) {
        factory("CmdSearch");
        Result expected{ "OK" };
        result = icmd->execute(db);

        EXPECT_TRUE(!isSame(expected, result));
    }

    // Erase
    TEST_F(CmdTest, CmdEraseSuccess) {
        factory("CmdErase");
        Result expected{ "NOK" };
        result = icmd->execute(db);

        EXPECT_TRUE(isSame(expected, result));
    }
    TEST_F(CmdTest, CmdEraseFail) {
        factory("CmdErase");
        Result expected{ "OK" };
        result = icmd->execute(db);

        EXPECT_TRUE(!isSame(expected, result));
    }
}
