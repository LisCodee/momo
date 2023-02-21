#ifndef DATADELEGATE_H
#define DATADELEGATE_H

#include <QStyledItemDelegate>

#include "dataDef.h"
class DataDelegate : public QStyledItemDelegate
{
    Q_OBJECT
signals:
    void itemClicked(DataDetail& d);
public:
    explicit DataDelegate(QObject *parent = 0);
    ~DataDelegate();
    //重写重画函数
    void paint(QPainter * painter,const QStyleOptionViewItem & option,const QModelIndex & index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override;
};

#endif // DATADELEGATE_H
