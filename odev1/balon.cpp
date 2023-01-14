#include "balon.h"

balon::balon(QWidget *parrent):QPushButton(parrent)
{
    tiklandimi=false;
    connect(this,&QPushButton::clicked,this,&balon::tikla);
}

void balon::tikla()
{
    tiklandimi=!tiklandimi;
    QTimer *patlamaTimer = new QTimer(this);
    connect(patlamaTimer,SIGNAL(timeout()),this,SLOT(patlama()));
    patlamaTimer->start(500);
}

void balon::patlama()
{
    this->hide();
}
