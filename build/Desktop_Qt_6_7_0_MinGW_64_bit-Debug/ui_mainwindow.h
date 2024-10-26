/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QPushButton *haltButton_3;
    QPushButton *loadDataButton_3;
    QPushButton *singleStepButton_3;
    QPushButton *runButton_3;
    QPushButton *clearMemoryButton_3;
    QPushButton *helpButton_3;
    QTextEdit *dataInputWindow_3;
    QGroupBox *cpuGroupBox_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *r0Label_3;
    QLineEdit *r0LineEdit_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *pcLabel_3;
    QLineEdit *pcLineEdit_3;
    QTableWidget *mainMemoryTable_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1044, 692);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        centralWidget = new QWidget(centralwidget);
        centralWidget->setObjectName("centralWidget");
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        haltButton_3 = new QPushButton(centralWidget);
        haltButton_3->setObjectName("haltButton_3");

        gridLayout_2->addWidget(haltButton_3, 2, 5, 1, 1);

        loadDataButton_3 = new QPushButton(centralWidget);
        loadDataButton_3->setObjectName("loadDataButton_3");

        gridLayout_2->addWidget(loadDataButton_3, 2, 1, 1, 2);

        singleStepButton_3 = new QPushButton(centralWidget);
        singleStepButton_3->setObjectName("singleStepButton_3");

        gridLayout_2->addWidget(singleStepButton_3, 2, 4, 1, 1);

        runButton_3 = new QPushButton(centralWidget);
        runButton_3->setObjectName("runButton_3");

        gridLayout_2->addWidget(runButton_3, 2, 3, 1, 1);

        clearMemoryButton_3 = new QPushButton(centralWidget);
        clearMemoryButton_3->setObjectName("clearMemoryButton_3");

        gridLayout_2->addWidget(clearMemoryButton_3, 2, 0, 1, 1);

        helpButton_3 = new QPushButton(centralWidget);
        helpButton_3->setObjectName("helpButton_3");

        gridLayout_2->addWidget(helpButton_3, 2, 6, 1, 1);

        dataInputWindow_3 = new QTextEdit(centralWidget);
        dataInputWindow_3->setObjectName("dataInputWindow_3");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dataInputWindow_3->sizePolicy().hasHeightForWidth());
        dataInputWindow_3->setSizePolicy(sizePolicy);
        dataInputWindow_3->setMaximumSize(QSize(16777215, 50));

        gridLayout_2->addWidget(dataInputWindow_3, 0, 0, 1, 7);

        cpuGroupBox_3 = new QGroupBox(centralWidget);
        cpuGroupBox_3->setObjectName("cpuGroupBox_3");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cpuGroupBox_3->sizePolicy().hasHeightForWidth());
        cpuGroupBox_3->setSizePolicy(sizePolicy1);
        cpuGroupBox_3->setMaximumSize(QSize(16777215, 16777215));
        widget = new QWidget(cpuGroupBox_3);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 30, 261, 471));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(widget);
        listWidget->setObjectName("listWidget");

        horizontalLayout_3->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        r0Label_3 = new QLabel(widget);
        r0Label_3->setObjectName("r0Label_3");

        horizontalLayout->addWidget(r0Label_3);

        r0LineEdit_3 = new QLineEdit(widget);
        r0LineEdit_3->setObjectName("r0LineEdit_3");

        horizontalLayout->addWidget(r0LineEdit_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pcLabel_3 = new QLabel(widget);
        pcLabel_3->setObjectName("pcLabel_3");

        horizontalLayout_2->addWidget(pcLabel_3);

        pcLineEdit_3 = new QLineEdit(widget);
        pcLineEdit_3->setObjectName("pcLineEdit_3");

        horizontalLayout_2->addWidget(pcLineEdit_3);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);


        gridLayout_2->addWidget(cpuGroupBox_3, 1, 0, 1, 2);

        mainMemoryTable_3 = new QTableWidget(centralWidget);
        if (mainMemoryTable_3->columnCount() < 16)
            mainMemoryTable_3->setColumnCount(16);
        if (mainMemoryTable_3->rowCount() < 16)
            mainMemoryTable_3->setRowCount(16);
        mainMemoryTable_3->setObjectName("mainMemoryTable_3");
        mainMemoryTable_3->setRowCount(16);
        mainMemoryTable_3->setColumnCount(16);

        gridLayout_2->addWidget(mainMemoryTable_3, 1, 2, 1, 5);


        gridLayout->addWidget(centralWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1044, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        haltButton_3->setText(QCoreApplication::translate("MainWindow", "Halt", nullptr));
        loadDataButton_3->setText(QCoreApplication::translate("MainWindow", "Load Data", nullptr));
        singleStepButton_3->setText(QCoreApplication::translate("MainWindow", "Single Step", nullptr));
        runButton_3->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        clearMemoryButton_3->setText(QCoreApplication::translate("MainWindow", "Clear Memory", nullptr));
        helpButton_3->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        cpuGroupBox_3->setTitle(QCoreApplication::translate("MainWindow", "CPU", nullptr));
        r0Label_3->setText(QCoreApplication::translate("MainWindow", "R0:", nullptr));
        pcLabel_3->setText(QCoreApplication::translate("MainWindow", "PC:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
