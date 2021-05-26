#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QGraphicsScene>
#include <QPoint>
#include <QMouseEvent>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousepoint(QMouseEvent *mp);
    void paintEvent(QPaintEvent *event);

private slots:
    //void listin();

    bool result_rand(QPointF [], int);
    void ran4();//flag = 4
    void ran5();//flag = 5
    void ran6();//flag = 6
    void ran7();//flag = 7
    void ran8();//flag = 8
    void mark();//flag = 2
    void ran(); //flag = 1
    //void MarkPoint(QMouseEvent *mp);

private:
    Ui::MainWindow *ui;
    QList<double> listx;
    QList<double> listy;
    QPointF r4[5];
    QPointF r5[6];
    QPointF r6[7];
    QPointF r7[8];
    QPointF r8[9];
    double sum_angle; //сумма внутренних углов
    QPointF pp;
    int flag; // какой режим рисования
    int c;// счетчик точек при вводе
};
#endif // MAINWINDOW_H
