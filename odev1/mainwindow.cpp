#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(balonOlustur()));
    timer->start(1000);

    sureTimer=new QTimer(this);
    connect(sureTimer,SIGNAL(timeout()),this,SLOT(sure()));
    sureTimer->start(1000);

    gameTimer = new QTimer(this);
    connect(gameTimer,SIGNAL(timeout()),this,SLOT(game()));
    gameTimer->start(9);
}
int sure_=0;
int kacanBalon=0;
int vurulanBalon=0;
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sure()
{
    sure_=sure_+1;
    ui->sure->setText(QString::number(sure_));
}

void MainWindow::balonOlustur()
{
    int genislik=this->width();
    int randomKonum=rand()%(genislik);
    QString randomImage= QString::number(rand()%(7));
    balon *yeni_balon = new balon(this);
    yeni_balon->setStyleSheet("QPushButton { border-image: url(:/images/images/"+randomImage+".jpg) }");
    yeni_balon->setGeometry(randomKonum,ui->arkaplan->y(),50,50);
    yeni_balon->show();
    baloons.append(yeni_balon);
}

void MainWindow::game()
{
    foreach(balon *eleman,baloons){
        if(!eleman->tiklandimi){
            eleman->setGeometry(eleman->x(),eleman->y()+1,50,50);
        }
        if(eleman->y() > this->geometry().height()){
            kacanBalon++;
            ui->kacanBalon->setText(QString::number(kacanBalon));
            eleman->hide();
            baloons.removeOne(eleman);
        }

        if(eleman->tiklandimi){
            vurulanBalon++;
            ui->vurulanBalon->setText(QString::number(vurulanBalon));
            eleman->setStyleSheet("QPushButton { border-image: url(:/images/images/patlama.jpg)}");
            baloons.removeOne(eleman);
        }
    }

    ui->arkaplan->setGeometry(0,70,this->width(),this->height());
    ui->vurulanBalon->setGeometry(this->width()-100,1,ui->vurulanBalon->width(),ui->vurulanBalon->height());
    ui->kacanBalon->setGeometry(this->width()-100,39,ui->kacanBalon->width(),ui->kacanBalon->height());
    ui->label1->setGeometry(this->width()-280,1,ui->label1->width(),ui->label1->height());
    ui->label2->setGeometry(this->width()-280,39,ui->label2->width(),ui->label2->height());
}
