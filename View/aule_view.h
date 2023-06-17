#ifndef AULE_VIEW_H
#define AULE_VIEW_H

#include "view.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class aule_view : public View {
    Q_OBJECT
private:
    QPushButton* indietroButton;
public:
    explicit aule_view(const QSize& s, View* parent);
    void closeEvent(QCloseEvent *event) override;
signals:
    void indietro_signal() const;
    void visualizzaPren_signal() const; //come parametro forse serve il numero dell'aula
};

#endif // AULE_VIEW_H
