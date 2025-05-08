/********************************************************************************
** Form generated from reading UI file 'fruit.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRUIT_H
#define UI_FRUIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fruit
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Fruit)
    {
        if (Fruit->objectName().isEmpty())
            Fruit->setObjectName("Fruit");
        Fruit->resize(800, 600);
        centralwidget = new QWidget(Fruit);
        centralwidget->setObjectName("centralwidget");
        Fruit->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Fruit);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        Fruit->setMenuBar(menubar);
        statusbar = new QStatusBar(Fruit);
        statusbar->setObjectName("statusbar");
        Fruit->setStatusBar(statusbar);

        retranslateUi(Fruit);

        QMetaObject::connectSlotsByName(Fruit);
    } // setupUi

    void retranslateUi(QMainWindow *Fruit)
    {
        Fruit->setWindowTitle(QCoreApplication::translate("Fruit", "Fruit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fruit: public Ui_Fruit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRUIT_H
