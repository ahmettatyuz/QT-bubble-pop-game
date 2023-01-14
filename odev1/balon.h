#ifndef BALON_H
#define BALON_H

#include <QPushButton>
#include <QTimer>

class balon : public QPushButton
{
    Q_OBJECT
public:
    balon(QWidget *parrent=0);
    bool tiklandimi;
public slots:
    void tikla();
    void patlama();
};

#endif // BALON_H
