#include "dataview.h"
#include "ui_dataview.h"
#include <QDebug>
#include <QInputDialog>
#include "datadelegate.h"

DataView::DataView(Data d, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataView)
{
    ui->setupUi(this);
    data = d;
//    initData();
    ui->lbTopic->adjustSize();
    ui->lbTopic->setWordWrap(true);
    ui->lbTopic->setStyleSheet("border:1px solid black;");
    ui->lbTopic->setText(data.content);

    m_dataDelegate = new DataDelegate(this);
    connect(m_dataDelegate, SIGNAL(itemClicked(DataDetail&)), this, SLOT(itemClicked(DataDetail&)));
    m_model = new QStandardItemModel();
    ui->listView->setItemDelegate(m_dataDelegate);
    ui->listView->setSpacing(15);                   //为视图设置控件间距
    m_proxyModel = new QSortFilterProxyModel(ui->listView);
    m_proxyModel->setSourceModel(m_model);
    m_proxyModel->setFilterRole(Qt::UserRole);
    m_proxyModel->setDynamicSortFilter(true);
    ui->listView->setModel(m_proxyModel);                  //为委托设置模型
    ui->listView->setViewMode(QListView::IconMode); //设置Item图标显示
    ui->listView->setDragEnabled(false);            //控件不允许拖动
    ui->listView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listView->setVerticalScrollMode(QListView::ScrollPerPixel);
    updateData();

}

DataView::~DataView()
{
    delete ui;
}

void DataView::on_pushButton_clicked()
{
    qDebug() << "+被点击";
    bool ok;
    QString text = QInputDialog::getText(this, "添加事项", "", QLineEdit::Normal, "", &ok);

    if (ok && !text.isEmpty()) {
        data.details.append({text, PROCESSING});
        updateData();
        qDebug() << "User entered: " << text;
    } else {
        // 用户取消了输入
        qDebug() << "User cancelled the input dialog";
    }
}

void DataView::itemClicked(DataDetail & d)
{
    qDebug() << "signal triggered:" <<  d.itemName;
    for(DataDetail& detail: data.details)
    {
        if(d.itemName == detail.itemName && d.status == detail.status)
        {
            if(detail.status == PROCESSING)
                detail.status = FINISH;
            else
                detail.status = PROCESSING;
        }

    }
    updateData();
}

void DataView::updateData()
{
    m_model->clear();
    for (int i = 0; i < data.details.size(); ++i) {
        QStandardItem *item = new QStandardItem;
        item->setData(QVariant::fromValue(data.details[i]),Qt::UserRole);
        m_model->appendRow(item);      //追加Item
    }
}
