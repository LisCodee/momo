#include "dataview.h"
#include "ui_dataview.h"

DataView::DataView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataView)
{
    ui->setupUi(this);


//    m_dataDelegate = new DataDelegate(this);
//    ui->listView->setItemDelegate(m_dataDelegate);
//    ui->listView->setSpacing(15);                   //为视图设置控件间距
//    m_proxyModel = new QSortFilterProxyModel(ui->listView);
//    m_proxyModel->setSourceModel(m_model);
//    m_proxyModel->setFilterRole(Qt::UserRole);
//    m_proxyModel->setDynamicSortFilter(true);
//    ui->listView->setModel(m_proxyModel);                  //为委托设置模型
//    ui->listView->setViewMode(QListView::IconMode); //设置Item图标显示
//    ui->listView->setDragEnabled(false);            //控件不允许拖动
//    ui->listView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    ui->listView->setVerticalScrollMode(QListView::ScrollPerPixel);
//    ui->pushButton->setText("点我");
}

DataView::~DataView()
{
    delete ui;
}
