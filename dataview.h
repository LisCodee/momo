#ifndef DATAVIEW_H
#define DATAVIEW_H

#include <QWidget>
#include <QObjectUserData>
#include <QSortFilterProxyModel>
#include <QStandardItemModel>
#include "datadelegate.h"
#include "dataDef.h"
namespace Ui {
class DataView;
}

class DataView : public QWidget
{
    Q_OBJECT

public:
    explicit DataView(Data d, QWidget *parent = nullptr);
    ~DataView();

private slots:
    void on_pushButton_clicked();
public slots:
    void itemClicked(DataDetail& d);
private:
    Ui::DataView *ui;
    DataDelegate *m_dataDelegate;
    QSortFilterProxyModel* m_proxyModel;
    QStandardItemModel *m_model;
    Data data;

private:
    void updateData();
};

#endif // DATAVIEW_H
