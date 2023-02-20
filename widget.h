#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QVector>
#include <QLabel>
#include <QScrollArea>
#include "datadelegate.h"
#include "dataDef.h"
#include "dataview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private:
    Ui::Widget *ui;
//    QWidget *mainWidget;
//    QVBoxLayout *mainLayout;
    QVector<DataView*> notes;
    QVector<Data> datas;

    void initData();
};
#endif // WIDGET_H
