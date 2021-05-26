#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(nullptr));
    ui->setupUi(this);
    //noend = true;
    //first = true;
    flag= 0;
    sum_angle= 0.;
    c= 0;
    //this->setMouseTracking(true);
    //QObject::connect(ui-> centralwidget, SIGNAL(clicked()), this, SLOT(MarkPoint(mp)));
    QObject::connect(ui->Randomise_points, SIGNAL(triggered()), this, SLOT(ran()));
    QObject::connect(ui->Mark_points, SIGNAL(triggered()), this, SLOT(mark()));
    QObject::connect(ui->Randomise_points_4, SIGNAL(triggered()), this, SLOT(ran4()));
    QObject::connect(ui->Randomise_points_5, SIGNAL(triggered()), this, SLOT(ran5()));
    QObject::connect(ui->Randomise_points_6, SIGNAL(triggered()), this, SLOT(ran6()));
    QObject::connect(ui->Randomise_points_7, SIGNAL(triggered()), this, SLOT(ran7()));
    QObject::connect(ui->Randomise_points_8, SIGNAL(triggered()), this, SLOT(ran8()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow:: MarkPoint(QMouseEvent *mp)
//{
//    pp= mp->pos();
//    flag= 1;  update();
//}

void MainWindow:: ran4()
{
//randk= 3 + rand()% 5;
//rp= new QPointF [randk];
//    QList<double>::iterator itx = listx.begin(); // создаем итератор и переводим его в начало списка
//    while (itx != 8 + listx.begin()) {
//         int i= rand()%400; listx << i;
//         int j= rand()%400; listy << j;
//         rp[itx - listx.begin()]= QPointF(i, j);
//         ++itx;

//    }
//    QList<double>::iterator ity = listy.begin(); // создаем итератор и переводим его в начало списка
//    while (ity != k + listx.begin()) {
//         listy << rand()%400;
//         ++ity;
//    }
    flag= 4;  update();
}

void MainWindow:: ran()
{
    flag= 1;  update();
}

void MainWindow:: mark()
{
    flag= 2;  update();
}

void MainWindow:: ran5()
{
    flag= 5;  update();
}

void MainWindow:: ran6()
{
    flag= 6;  update();
}

void MainWindow:: ran7()
{
    flag= 7;  update();
}

void MainWindow:: ran8()
{
    flag= 8;  update();
}

double angle(QPointF a, QPointF b, QPointF c)
{
    double angle;
    angle= acos(((a - b).x() * (c - b).x() + (a - b).y() * (c - b).y())/sqrt(((b - a).x() * (b - a).x() + (b - a).y()*(b - a).y())*((c - b).x() * (c - b).x() + (c - b).y()*(c - b).y())));
    return angle;
}

bool angle_norm(int flag, double sum)
{
    double eps= 0.05*((flag - 2)*M_PI);
    if(fabs(sum - ((flag - 2)*M_PI))< eps)
        return true;
    return false;
}

bool vector_turn(QPointF a, QPointF b, QPointF c)
{
    return ((b-a).x()*(c-b).y() - (b-a).y()*(c-b).x() > 0);
}

QPointF transform(QPointF a)
{
    QPointF b= QPointF(a.rx()+40, 500 - a.ry());
    return b;
}

bool MainWindow:: result_rand(QPointF r[], int flag)
{
    bool turn= true;
    bool C= vector_turn(r[flag-1], r[0], r[1]);
    sum_angle+= angle(r[flag-1], r[0], r[1]);
    for(int i= 1; i < flag; ++i)
    {
        turn*= (C == vector_turn(r[i-1], r[i], r[i+1]));
        sum_angle+= angle(r[i - 1], r[i], r[i + 1]);
    }
    return turn*angle_norm(flag,  sum_angle);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QColor coordLineColor(255, 0, 0, 255);

    QPen apen = QPen(coordLineColor);
    apen.setWidth(5);
    painter.setPen(apen);

    painter.drawLine(QLine(40,0,40,500));
    painter.drawLine(QLine(40,500,540,500));

    painter.drawText(QPoint(5,520), "0,0");
    painter.drawText(QPoint(480,520), "500");
    painter.drawText(QPoint(3,70), "500");
    switch (flag)
    {
//    case 1:{
//        QPointF a[2];
//        a[0]= pp;
//        a[1]= QPointF(rand()%400+50, rand()%400+50);
//        painter.setPen(QPen(Qt::cyan,3,Qt::SolidLine,Qt::RoundCap,Qt::MiterJoin));
//        painter.drawPolyline(a, 2);
//            ui-> label -> setText(QString:: number(sum_angle) + "= Sum of inner angles. And our polygon is convex!)");
//        else
//            ui-> label -> setText(QString:: number(sum_angle) + "= Sum of inner angles. And our polygon is not convex(((");
//        flag= 0;
//        sum_angle= 0.;
//        break;}
    case 1:{
        int n= ui-> lineEdit_Q -> text().toInt();
        QPointF r[n+1];
        for(int i= 0; i < n; ++i)
        {
            r[i]= transform(QPointF(rand()%300+110, rand()%300+110));
        }
        r[n]= r[0];
        painter.setPen(QPen(Qt:: black,3,Qt::SolidLine,Qt::RoundCap,Qt::MiterJoin));
        painter.drawPolyline(r, n+1);
        if(result_rand( r, n))
            ui-> label -> setText(QString:: number(sum_angle) + "= Sum of inner angles. And our polygon is convex!)");
        else
            ui-> label -> setText(QString:: number(sum_angle) + "= Sum of inner angles. And our polygon is not convex(((");
        flag= 0;
        sum_angle= 0.;
        break;}
    case 2:{
        r4[0]= transform(QPointF(ui-> lineEdit_5 -> text().toDouble(), ui-> lineEdit_1 -> text().toDouble()));
        r4[1]= transform(QPointF(ui-> lineEdit_6 -> text().toDouble(), ui-> lineEdit_2 -> text().toDouble()));
        r4[2]= transform(QPointF(ui-> lineEdit_7 -> text().toDouble(), ui-> lineEdit_3 -> text().toDouble()));
        r4[3]= transform(QPointF(ui-> lineEdit_8 -> text().toDouble(), ui-> lineEdit_4 -> text().toDouble()));
        r4[4]= r4[0];
        painter.setPen(QPen(Qt:: black,3,Qt::SolidLine,Qt::RoundCap,Qt::MiterJoin));
        painter.drawPolyline(r4, 5);
        if(result_rand( r4, 2+flag))
            ui-> label -> setText(QString:: number(sum_angle) + "= Sum of inner angles. And our polygon is convex!)");
        else
            ui-> label -> setText(QString:: number(sum_angle) + "= Sum of inner angles. And our polygon is not convex(((");
        flag= 0;
        sum_angle= 0.;
        break;}
    case 4:{
        for(int i= 0; i < 4; ++i)
        {
            r4[i]= transform(QPointF(rand()%300+110, rand()%300+110));
        }
        r4[4]= r4[0];
        painter.setPen(QPen(Qt::red,3,Qt::SolidLine,Qt::RoundCap,Qt::MiterJoin));
        painter.drawPolyline(r4, 5);
        if(result_rand( r4, flag))
            ui-> label -> setText(QString:: number(sum_angle) + "= Sum of inner angles. And our polygon is convex!)");
        else
            ui-> label -> setText(QString:: number(sum_angle) + "= Sum of inner angles. And our polygon is not convex(((");
        flag= 0;
        sum_angle= 0.;
        break;}
    case 5:{
        for(int i= 0; i < 5; ++i)
        {
            r5[i]= transform(QPointF(rand()%300+110, rand()%300+110));
        }
        r5[5]= r5[0];
        painter.setPen(QPen(Qt::green,3,Qt::SolidLine,Qt::RoundCap,Qt::MiterJoin));
        painter.drawPolyline(r5, 6);
        if(result_rand( r5, flag))
            ui-> label -> setText(QString:: number(sum_angle) + "= Sum of inner angles. And our polygon is convex!)");
        else
            ui-> label -> setText(QString:: number(sum_angle) + "= Sum of inner angles. And our polygon is not convex(((");
        flag= 0;
        sum_angle= 0.;
        break;}
    case 6:{
        for(int i= 0; i < 6; ++i)
        {
            r6[i]= transform(QPointF(rand()%300+110, rand()%300+110));
        }
        r6[6]= r6[0];
        painter.setPen(QPen(Qt::blue,3,Qt::SolidLine,Qt::RoundCap,Qt::MiterJoin));
        painter.drawPolyline(r6, 7);
        if(result_rand( r6, flag))
            ui-> label -> setText(QString:: number(sum_angle) + "= Sum of inner angles. And our polygon is convex!)");
        else
            ui-> label -> setText(QString:: number(sum_angle) + "= Sum of inner angles. And our polygon is not convex(((");
        flag= 0;
        sum_angle= 0.;
        break;}
    case 7:{
        for(int i= 0; i < 7; ++i)
        {
            r7[i]= transform(QPointF(rand()%300+110, rand()%300+110));
        }
        r7[7]= r7[0];
        painter.setPen(QPen(Qt::cyan,3,Qt::SolidLine,Qt::RoundCap,Qt::MiterJoin));
        painter.drawPolyline(r7, 8);
        if(result_rand( r7, flag))
            ui-> label -> setText(QString:: number(sum_angle) + "= Sum of inner angles. And our polygon is convex!)");
        else
            ui-> label -> setText(QString:: number(sum_angle) + "= Sum of inner angles. And our polygon is not convex(((");
        flag= 0;
        sum_angle= 0.;
        break;}
    case 8:{
        for(int i= 0; i < 8; ++i)
        {
            r8[i]= transform(QPointF(rand()%300+110, rand()%300+110));
        }
        r8[8]= r8[0];
        painter.setPen(QPen(Qt::yellow,3,Qt::SolidLine,Qt::RoundCap,Qt::MiterJoin));
        painter.drawPolyline(r8, 9);
        if(result_rand( r8, flag))
            ui-> label -> setText(QString:: number(sum_angle) + "= Sum of inner angles. And our polygon is convex!)");
        else
            ui-> label -> setText(QString:: number(sum_angle) + "= Sum of inner angles. And our polygon is not convex(((");
        flag= 0;
        sum_angle= 0.;
        break;}


    }
}
