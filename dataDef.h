#ifndef DATADEF_H
#define DATADEF_H
#include <QString>
#include <QMetaType>
#include <QVector>
typedef enum{
    PROCESSING,
    FINISH
}DataStatus;

struct DataDetail
{
    QString itemName;         //具体事项
    DataStatus status;      //状态
};

struct Data{
    QString content;                //主题
    QVector<DataDetail> details;    //具体项
};

Q_DECLARE_METATYPE(DataDetail)
#endif // DATADEF_H
