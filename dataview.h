#ifndef DATAVIEW_H
#define DATAVIEW_H

#include <QWidget>
#include <QObjectUserData>
#include <QSortFilterProxyModel>
#include <QStandardItemModel>
#include "datadelegate.h"
namespace Ui {
class DataView;
}

class DataView : public QWidget
{
    Q_OBJECT

public:
    explicit DataView(QWidget *parent = nullptr);
    ~DataView();

private:
    Ui::DataView *ui;
    DataDelegate *m_dataDelegate;
    QSortFilterProxyModel* m_proxyModel;
    QStandardItemModel *m_model;
};

#endif // DATAVIEW_H
