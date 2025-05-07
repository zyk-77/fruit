#ifndef SNAKE_H
#define SNAKE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Snake;
}
QT_END_NAMESPACE

class Snake : public QMainWindow
{
    Q_OBJECT

public:
    explicit Snake(QWidget *parent = nullptr);
    ~Snake();
    void paintEvent(QPaintEvent *event);
    void InitSnake();
    void keyPressEvent(QKeyEvent *event);
    QRect CreateFood();
    void eat();
private slots:
    void supdate();
    void s();
private:
    Ui::Snake *ui;
    QTimer *timer,*t;//定时器
    int fx;//移动方向
    bool blsRun;//是否开始
    bool blsOver;//是否结束
    QVector<QRect> vSnakeRect;//蛇
    QRect SnakeHead;//蛇头
    QString display;
    QRect Food;
    int score;//得分
    int speed;//速度

};
#endif // SNAKE_H
