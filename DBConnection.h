class DBConnection {
public:
    virtual ~DBConnection() = default;

    virtual void open() = 0;
    virtual void close() = 0;
    virtual void execQuery(const std::string& query) = 0;
};