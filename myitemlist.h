#ifndef MYITEMLIST_H
#define MYITEMLIST_H

#include <QObject>
#include <QWidget>
#include <QSettings>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

class MyItemList : public QGraphicsScene
{
    Q_OBJECT

    Q_PROPERTY(int rows_property READ getRows WRITE setRows)

public:
    MyItemList(const QPointF& pos, const QSize& size);

    inline int getRows() { return rows_; }
    inline void setRows(int nb) { rows_ = nb; cols_ = nb; }

public slots:

    void rearangeGrid(bool reshape);

private:
    QString name_, description_;
    int rows_, cols_;
    int total_width_, total_height_;

    void drawGrid_();

};

#endif // MYITEMLIST_H
