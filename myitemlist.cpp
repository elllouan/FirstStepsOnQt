#include "myitemlist.h"

MyItemList::MyItemList(const QPointF &pos, const QSize& size) :
    QGraphicsScene(pos.x(),pos.y(),size.width(),size.height())
{
    rows_ = 5;
    cols_ = rows_;
    total_width_ = size.width();
    total_height_ = size.height();
    drawGrid_();

    addRect(pos.x(),pos.y(),50,50);
    QGraphicsRectItem* rect = static_cast<QGraphicsRectItem*>(items().at(0));
    rect->setBrush(Qt::red);
    rect->setFlag(QGraphicsItem::ItemIsFocusable, true);
    rect->setFocus(Qt::MouseFocusReason);
}

void MyItemList::rearangeGrid(bool reshape)
{
    clear();
    setRows(rows_ > 9 ? 5 : rows_+1);
    drawGrid_();

    update();
}

void MyItemList::drawGrid_()
{
    int col_width = int(total_width_/cols_);
    int row_height = int(total_height_/rows_);


    for (int c = 1; c <= cols_; ++c) {
        addLine(c*col_width, 0, c*col_width, total_height_);
    }
    for (int r = 1; r < rows_; ++r) {
        addLine(0, r*row_height, total_width_, r*row_height);
    }
}
