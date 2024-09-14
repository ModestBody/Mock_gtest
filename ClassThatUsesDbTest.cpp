#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ClassThatUsesDb.h"
#include "MockDBConnection.h"

using ::testing::AtLeast;
using ::testing::Exactly;
using ::testing::Return;

TEST(ClassThatUsesDbTest, OpenConnectionCallsDBConnectionOpen) {
    MockDBConnection mockDbConn;
    ClassThatUsesDb classUnderTest(&mockDbConn);

    EXPECT_CALL(mockDbConn, open()).Times(Exactly(1));

    classUnderTest.openConnection();
}

TEST(ClassThatUsesDbTest, UseConnectionCallsExecQuery) {
    MockDBConnection mockDbConn;
    ClassThatUsesDb classUnderTest(&mockDbConn);

    EXPECT_CALL(mockDbConn, execQuery("SELECT * FROM table")).Times(Exactly(1));

    classUnderTest.useConnection("SELECT * FROM table");
}

TEST(ClassThatUsesDbTest, CloseConnectionCallsDBConnectionClose) {
    MockDBConnection mockDbConn;
    ClassThatUsesDb classUnderTest(&mockDbConn);

    EXPECT_CALL(mockDbConn, close()).Times(Exactly(1));

    classUnderTest.closeConnection();
}