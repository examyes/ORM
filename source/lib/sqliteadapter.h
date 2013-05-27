#ifndef SQLITEADAPTER_H
#define SQLITEADAPTER_H

#include "sqladapter.h"

class SqliteAdapter : public SqlAdapter
{
public:
    SqliteAdapter();
    bool createTable(const QString &tableName, const QHash<QString, QString> &info);
    bool createTableRelations(const QString &parent, Relation rel, const QString &child);
    int addRecord(const QString &tableName, const QHash<QString, QVariant> &info);
};

#endif // SQLITEADAPTER_H