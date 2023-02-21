#include <QPainter>
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>
#include <QObject>
#include <QString>
#include "datadelegate.h"
#include "dataview.h"


DataDelegate::DataDelegate(QObject *parent):
    QStyledItemDelegate(parent)
{

}

DataDelegate::~DataDelegate()
{

}

void DataDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.isValid())
    {
        painter->save();
        QVariant variant = index.data(Qt::UserRole);
        DataDetail dataDetail = variant.value<DataDetail>();

        QStyleOptionViewItem viewOption(option);//用来在视图中画一个item

        QRectF rect;
        //        qDebug() << option.rect;
        rect.setX(option.rect.x());
        rect.setY(option.rect.y());
        rect.setWidth( option.rect.width()-1);
        rect.setHeight(option.rect.height()-1);

        //QPainterPath画圆角矩形
        const qreal radius = 7;
        QPainterPath path;
        path.moveTo(rect.topRight() - QPointF(radius, 0));
        path.lineTo(rect.topLeft() + QPointF(radius, 0));
        path.quadTo(rect.topLeft(), rect.topLeft() + QPointF(0, radius));
        path.lineTo(rect.bottomLeft() + QPointF(0, -radius));
        path.quadTo(rect.bottomLeft(), rect.bottomLeft() + QPointF(radius, 0));
        path.lineTo(rect.bottomRight() - QPointF(radius, 0));
        path.quadTo(rect.bottomRight(), rect.bottomRight() + QPointF(0, -radius));
        path.lineTo(rect.topRight() + QPointF(0, radius));
        path.quadTo(rect.topRight(), rect.topRight() + QPointF(-radius, -0));

        //        if(option.state.testFlag(QStyle::State_Selected))
        //        {
        //            painter->setPen(QPen(Qt::blue));
        //            painter->setBrush(QColor(229, 241, 255));
        //            painter->drawPath(path);
        //        }
        if(option.state.testFlag(QStyle::State_MouseOver))
        {
            painter->setPen(QPen(Qt::green));
            painter->setBrush(Qt::NoBrush);
            painter->drawPath(path);
            painter->fillRect(option.rect, option.palette.highlight());
        }
        else{
            painter->setPen(QPen(Qt::gray));
            painter->setBrush(Qt::NoBrush);
            painter->drawPath(path);
        }

        //绘制数据位置
        QRect contentRect = QRect(rect.left() +10, rect.top()+10, rect.width()-30, rect.height()-20);
        QRect circle = QRect(contentRect.right(), rect.top()+10, 10, 10);
        //        QRect telRect = QRect(rect.left() +10, rect.bottom()-25, rect.width()-10, 20);


        switch (dataDetail.status) {
        case PROCESSING:
            painter->setBrush(Qt::red);
            painter->setPen(QPen(Qt::red));
            break;
        case FINISH:
            painter->setBrush(Qt::green);
            painter->setPen(QPen(Qt::green));
            break;
        }

        painter->drawEllipse(circle);     //画圆圈

        painter->setPen(QPen(Qt::black));
        painter->setFont(QFont("Times", 10));
        painter->drawText(contentRect,Qt::AlignLeft,dataDetail.itemName); //绘制内容


        painter->restore();
    }

}

QSize DataDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(160, 60);
}

bool DataDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonRelease) {
        QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent *>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            // 执行自定义操作
            QVariant variant = index.data(Qt::UserRole);
            DataDetail dataDetail = variant.value<DataDetail>();

            emit itemClicked(dataDetail);                       //触发点击事件信号，改变事件状态
            qDebug() << "Item clicked:" << dataDetail.itemName;
        }
    }

    return QStyledItemDelegate::editorEvent(event, model, option, index);
}

