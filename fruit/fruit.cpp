#include "fruit.h"
#include "ui_fruit.h"
#include<QPainter>
#include<QTimer>
#include<QKeyEvent>
#include<QPaintEvent>

Fruit::Fruit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Fruit),blsRun(true),blsOver(false)
{
    ui->setupUi(this);
    this->setGeometry(QRect(200,300,650,650));
}

void Fruit::paintEvent(QPaintEvent *event){
    kind.resize(5);
    if(blsRun) initiative();
    QPainter painter(this);
    //外墙
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::gray);
    painter.drawRect(15,15,620,620);
    //内墙
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::black);
    painter.drawRect(25,25,600,600);
    painter.drawPixmap(25,25,600,600,QPixmap(":/image/1/2.png"));
    QFont font1("Courier",20);
    painter.setFont(font1);
    painter.setPen(Qt::white);
    painter.setBrush(Qt::white);
    painter.drawText(480,50,display);
    painter.drawPixmap(x,QPixmap(":/image/1/3.png"));
    if(blsOver) timer->stop();
}

void Fruit:: initiative(){
    display="丰收的季节";
    blsRun=false;
    QRect rect(300,570,50,50);
    x=rect;
    timer=new QTimer(this);
    timer->start(1500);
    connect(timer,SIGNAL(timeout()),SLOT(supdate()));

}

void Fruit::supdate(){

    update();
}

void Fruit::keyPressEvent(QKeyEvent *event){
    QKeyEvent *key=(QKeyEvent*) event;
    switch(key->key()){
    case Qt::Key_Left: fx=1;
        break;
    case Qt::Key_Right: fx=2;
        break;
    default:;
    }
    switch(fx){
    case 1:
        x.setLeft(x.left()-50);
        x.setRight(x.right()-50);
        break;
    case 2:
        x.setLeft(x.left()+50);
        x.setRight(x.right()+50);
        break;
    default:;
    }
    update();
}

Fruit::~Fruit()
{
    delete ui;
}
