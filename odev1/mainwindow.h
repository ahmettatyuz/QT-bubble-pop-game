#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtimer.h>
#include <balon.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void sure();
    void balonOlustur();
    void game();

private:
    Ui::MainWindow *ui;
    QList<balon*> baloons;
    QTimer *timer;
    QTimer *sureTimer;
    QTimer *gameTimer;
};
#endif // MAINWINDOW_H
