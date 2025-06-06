#ifndef FRUIT_H
#define FRUIT_H

#include <QMainWindow>
#include<QWidget>
#include<QPainter>
#include<QTimer>
#include<QKeyEvent>
#include<QPaintEvent>
#include <QMediaPlayer>
#include <QSoundEffect>

QT_BEGIN_NAMESPACE
namespace Ui {
class Fruit;
}
QT_END_NAMESPACE

class Fruit : public QMainWindow
{
    Q_OBJECT

public:
    explicit Fruit(QWidget *parent = nullptr);
    ~Fruit();
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void initiative();
    void judge();
private slots:
    void supdate();
    void subdate();


private:
    Ui::Fruit *ui;
    QMediaPlayer *player;
    QSoundEffect *music = new QSoundEffect();
    int fx;//果篮方向
    QVector<QRect> fruit;//天上的水果
    QVector<int> kind;//水果的种类
    QRect x;//果篮
    QTimer *timer,*t;//定时器
    bool blsRun;//是否开始
    bool blsOver;//是否结束
    QString display;
    int score;//得分
    int speed;//速度
};
#endif // FRUIT_H
