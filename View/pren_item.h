#ifndef PREN_ITEM_H
#define PREN_ITEM_H

#include <QWidget>
#include <QObject>
#include <QTableWidget>

class pren_item : public QWidget{
    Q_OBJECT
public:
    pren_item();
    QTableWidget* table;

};

#endif // PREN_ITEM_H
