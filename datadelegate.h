#ifndef DATADELEGATE_H
#define DATADELEGATE_H

#include <QStyledItemDelegate>

class DataDelegate : public QStyledItemDelegate
{
    Q_OBJECT
signals:

public:
    explicit DataDelegate(QObject *parent = 0);
    ~DataDelegate();
    //重写重画函数
    void paint(QPainter * painter,const QStyleOptionViewItem & option,const QModelIndex & index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // DATADELEGATE_H
