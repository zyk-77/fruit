#include "fruit.h"
#include "ui_fruit.h"
#include<QPainter>
#include<QTimer>
#include<QKeyEvent>
#include<QPaintEvent>
#include <QMediaPlayer>
#include <QSoundEffect>

Fruit::Fruit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Fruit),blsRun(true),blsOver(false),score(0),speed(800)
{
    ui->setupUi(this);
    this->setGeometry(QRect(200,300,650,650));
}

void Fruit::paintEvent(QPaintEvent *event){
    if(blsRun) initiative();
    judge();
    QPainter painter(this);
    //外墙
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::gray);
    painter.drawRect(15,15,620,620);
    //内墙
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::black);
    painter.drawRect(25,25,600,600);

    painter.drawPixmap(25,25,600,600,QPixmap(":/image/1/2.png"));//背景
    QFont font1("Courier",20);
    painter.setFont(font1);
    painter.setPen(Qt::white);
    painter.setBrush(Qt::white);
    painter.drawText(40,600,"←向左 →向右");
    painter.drawText(40,50,"得分:");
    painter.drawText(120,50,QString::number(score));//显示分数
    painter.drawText(480,50,display);
    painter.drawPixmap(x,QPixmap(":/image/1/3.png"));//果篮插图
    for(int i=0;i<fruit.size();++i){
        switch(kind[i]){
        case 0:
            painter.drawPixmap(fruit[i],QPixmap(":/image/1/4.png"));
            break;
        case 1:
            painter.drawPixmap(fruit[i],QPixmap(":/image/1/5.png"));
            break;
        case 2:
            painter.drawPixmap(fruit[i],QPixmap(":/image/1/6.png"));
            break;
        case 3:
            painter.drawPixmap(fruit[i],QPixmap(":/image/1/7.png"));
            break;
        default:;
        }
    }
    if(blsOver==true){
        t->stop();
        timer->stop();
    }
    //是否结束
}

void Fruit:: initiative(){
    display="丰收的季节";
    blsRun=false;
    QRect rect(325,575,50,50);
    x=rect;
    timer=new QTimer(this);
    t=new QTimer(this);
    timer->start(3200);
    t->start(800);
    connect(t,SIGNAL(timeout()),SLOT(subdate()));//更新位置
    connect(timer,SIGNAL(timeout()),SLOT(supdate()));//每隔一段时间产生新水果*/

}

void Fruit::subdate(){
    for(int i=0;i<fruit.size();++i){
        fruit[i].setTop(fruit[i].top()+50);
        fruit[i].setBottom(fruit[i].bottom()+50);
    }
    update();
}

void Fruit::supdate(){
    int p;//随机生成水果
    int q;//水果初始位置
    p=rand()%4;
    q=rand()%12*50+25;
    kind.push_back(p);
    QRect a(q,25,50,50);
    fruit.push_back(a);
}

void Fruit::keyPressEvent(QKeyEvent *event){
    QKeyEvent *key=(QKeyEvent*) event;//按键感应
    switch(key->key()){
    case Qt::Key_Left: fx=1;
        break;
    case Qt::Key_Right: fx=2;
        break;
    default:;
    }
    if(fx==1&&x.left()>=75){
        x.setLeft(x.left()-50);
        x.setRight(x.right()-50);
    }
    if(fx==2&&x.right()<=575){
        x.setLeft(x.left()+50);
        x.setRight(x.right()+50);
    }
    update();
}

void Fruit:: judge(){//判断是否收集到水果或者炸弹
    if(fruit.size()<=0) return ;
    if(fruit[0].bottom()>=600){
        if(fruit[0]==x){
            if(kind[0]==3){
                blsOver=true;
                display="gameover!";
            }
            else{
                score=score+1+kind[0];
                t->stop();
                if(speed>500) speed-=10;
                t->start(speed);
                timer->stop();
                timer->start(speed*4);
            }
        }
        for(int i=1;i<fruit.size();++i){
            fruit[i-1]=fruit[i];
            kind[i-1]=kind[i];
        }
        fruit.pop_back();
        kind.pop_back();
    }
}

Fruit::~Fruit()
{
    delete ui;
}
