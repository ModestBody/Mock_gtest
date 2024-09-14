#include "DBConnection.h"
#include <string>

class ClassThatUsesDb {
public:
    ClassThatUsesDb(DBConnection* dbConn) : dbConn_(dbConn) {}

    void openConnection() {
        dbConn_->open();
    }

    void useConnection(const std::string& query) {
        dbConn_->execQuery(query);
    }

    void closeConnection() {
        dbConn_->close();
    }

private:
    DBConnection* dbConn_;
};