#include <QString>
#include <QtTest>
#include "ormdatabase.cpp"
#include "mysqladapter.cpp"
#include "ormabstractadapter.cpp"

class Test_ORMDatabase : public QObject
{
    Q_OBJECT
    
public:
    Test_ORMDatabase();
    
private Q_SLOTS:
    void constructor();
    void test_addDatabase();
    void test_createDatabase();
    void test_lastQuery();
};

Test_ORMDatabase::Test_ORMDatabase()
{
}

void Test_ORMDatabase::constructor()
{
    {
        ORMDatabase db("QMYSQL");
        QCOMPARE(db.driverName(), QString("QMYSQL"));
    }
    ORMDatabase::removeDatabase("qt_sql_default_connection");
}

void Test_ORMDatabase::test_addDatabase()
{
    {
        ORMDatabase db;
        QCOMPARE(db.driverName(), QString(""));
        db = ORMDatabase::addORMDatabase("QMYSQL");
        QCOMPARE(db.driverName(), QString("QMYSQL"));
    }
    ORMDatabase::removeDatabase("qt_sql_default_connection");
}

void Test_ORMDatabase::test_createDatabase()
{
    {
        ORMDatabase db("QMYSQL");
        QCOMPARE(db.createDatabase("test_ORMDatabase"), true);
        db.exec("DROP DATABASE test_ORMDatabase;");
        QCOMPARE(db.createDatabase("test"), false);
    }
    ORMDatabase::removeDatabase("qt_sql_default_connection");
}

void Test_ORMDatabase::test_lastQuery()
{
    {
        ORMDatabase db("QMYSQL");
        QCOMPARE(db.lastQuery().isEmpty(), true);
        db.createDatabase("test_ORMDatabase");
        QCOMPARE(db.lastQuery().isEmpty(), false);
        db.exec("DROP DATABASE test_ORMDatabase;");
    }
    ORMDatabase::removeDatabase("qt_sql_default_connection");
}

QTEST_APPLESS_MAIN(Test_ORMDatabase)

#include "tst_test_ormdatabase.moc"