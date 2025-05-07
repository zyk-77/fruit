#include "snake.h"
#include "ui_snake.h"
#include<QPainter>
#include<QTimer>
#include<QKeyEvent>
#include<QPaintEvent>
#include<QVector>

Snake::Snake(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Snake),blsRun(false),blsOver(false),speed(500)
{
    ui->setupUi(this);
    this->setGeometry(QRect(200,300,290,310));
}

Snake::~Snake()
{
    delete ui;
}
void Snake::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    if(blsRun==0) InitSnake();
    //画游戏背景
    //外墙
    painter.setPen(Qt::blue);//画笔颜色
    painter.setBrush(Qt::gray);//填充颜色
    painter.drawRect(15,15,260,260);
    //内墙
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::black);
    painter.drawRect(20,20,250,250);
    painter.drawPixmap(20,20,250,250,QPixmap(":/images/s/1.jpg"));

    //画格子
    /*.setPen(Qt::gray);
    for(int i=2;i<=27;++i){
        painter.drawLine(20,i*10,270,i*10);//画横线
        painter.drawLine(i*10,20,i*10,270);//画竖线
    }*/
    //显示游戏开始和结束
    QFont font1("Courier",24);
    painter.setFont(font1);
    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);
    painter.drawText(40,150,display);
    //显示分数
    QFont font2("Courier",24);
    painter.setFont(font2);
    painter.setPen(Qt::green);
    painter.setBrush(Qt::green);
    painter.drawText(150,300,"得分:");
    painter.drawText(230,300,QString::number(score));
    //显示食物
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::green);
    //painter.drawRect(Food);
    painter.drawPixmap(Food,QPixmap(":/images/s/2.png"));
    painter.drawRects(&vSnakeRect[0],vSnakeRect.size());
    if(blsOver) timer->stop();
}

void Snake::InitSnake(){
    score=0;
    blsRun=true;
    fx=2;
    display="游戏开始";
    Food=CreateFood();

    vSnakeRect.resize(9);//蛇的长度
    for(int i=0;i<vSnakeRect.size();++i){
        QRect rect(100,70+10*i,10,10);
        vSnakeRect[vSnakeRect.size()-1-i]=rect;
    }

    timer=new QTimer(this);
    t=new QTimer(this);
    timer->start(500);
    t->start(1000);
    connect(t,SIGNAL(timeout()),SLOT(s()));
    connect(timer,SIGNAL(timeout()),SLOT(supdate()));
}

void Snake::s(){
    display="";
    t->stop();
}

void Snake::supdate(){
    SnakeHead=vSnakeRect.first();//获取蛇头
    eat();
    for(int j=0;j<vSnakeRect.size()-1;++j){
        vSnakeRect[vSnakeRect.size()-1-j]=vSnakeRect[vSnakeRect.size()-2-j];
    }
    switch(fx){
    case 1:
        SnakeHead.setTop(SnakeHead.top()-10);
        SnakeHead.setBottom(SnakeHead.bottom()-10);
        break;
    case 2:
        SnakeHead.setTop(SnakeHead.top()+10);
        SnakeHead.setBottom(SnakeHead.bottom()+10);
        break;
    case 3:
        SnakeHead.setLeft(SnakeHead.left()-10);
        SnakeHead.setRight(SnakeHead.right()-10);
        break;
    case 4:
        SnakeHead.setLeft(SnakeHead.left()+10);
        SnakeHead.setRight(SnakeHead.right()+10);
        break;
    default:;
    }
    for(int j=0;j<vSnakeRect.size();++j){
        if(SnakeHead==vSnakeRect[j]) blsOver=true,display="gameover!!";
    }
    vSnakeRect[0]=SnakeHead;
    if(SnakeHead.left()<20 || SnakeHead.right()>270 || SnakeHead.top()<20||SnakeHead.bottom()>270)
        blsOver=true,display="gameover!!";
    update();//更新
}

void Snake::keyPressEvent(QKeyEvent *event){
    QKeyEvent *key=(QKeyEvent*) event;
    switch(key->key()){
    case Qt::Key_Up: fx=1;
        break;
    case Qt::Key_Down: fx=2;
        break;
    case Qt::Key_Left: fx=3;
        break;
    case Qt::Key_Right: fx=4;
        break;
    default:;
    }
}

QRect Snake::CreateFood(){
    int x,y;
    x=rand()%25;
    y=rand()%25;
    QRect rect(20+x*10,20+y*10,10,10);
    return rect;
}

void Snake::eat(){
    if(SnakeHead==Food){
        SnakeHead=Food;
        vSnakeRect.push_back(vSnakeRect.last());
        Food=CreateFood();
        score++;
        speed-=10;
        timer->stop();
        timer->start(speed);
    }
}
