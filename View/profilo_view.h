#ifndef PROFILO_VIEW_H
#define PROFILO_VIEW_H

#include "view.h"
#include <QObject>
#include <QTableWidget>

class profilo_view : public View {
    Q_OBJECT
private:
    //inserire tutti gli oggetti di QT
    QTableWidget* table;
protected:
    explicit profilo_view();

public:
    explicit profilo_view(const QSize& s, View *parent = nullptr);
    void closeEvent(QCloseEvent *event) override;
};

#endif // PROFILO_VIEW_H
