#ifndef DATADEF_H
#define DATADEF_H
#include <QString>
#include <QMetaType>
#include <QVector>
typedef enum{
    PROCESSING,
    FINISH
}DataStatus;

struct Data{
    QString content;
};

Q_DECLARE_METATYPE(Data)
#endif // DATADEF_H
