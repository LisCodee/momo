#include "widget.h"
#include "ui_widget.h"
#include <QRect>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("备忘录");
    // 禁止缩放和最小化
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setWindowFlags(windowFlags()& ~Qt::WindowMinimizeButtonHint);
    setFixedSize(this->width(), this->height());


    initData();
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    QWidget *widget = new QWidget(scrollArea);
    QVBoxLayout *layout = new QVBoxLayout(widget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(widget);

    //初始化每条备忘录
    for(int i = 0; i < datas.size(); ++i)
    {
        DataView* temp = new DataView(datas[i], this);
        temp->setMaximumSize(700, 90);
        temp->setMinimumSize(700, 90);
        layout->addWidget(temp);
        notes.append(temp);
    }

    setLayout(new QHBoxLayout());
    this->layout()->addWidget(scrollArea);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initData()
{
    for(int i = 0; i < 5; ++i)
    {
        Data d;
        d.content =QString("abcdefg哈哈哈 %1").arg(i);
        DataDetail dd = {"要看一本书", PROCESSING};
        d.details.append(dd);
        datas.append(d);
    }
}




