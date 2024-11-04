/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_4;
    QLabel *screenLabel;
    QGridLayout *gridLayout;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QPushButton *clearMemoryButton_3;
    QPushButton *runButton_3;
    QPushButton *haltButton_3;
    QTableWidget *mainMemoryTable_3;
    QPushButton *loadDataButton_3;
    QPushButton *helpButton_3;
    QPushButton *singleStepButton_3;
    QGroupBox *cpuGroupBox_3;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *r0Label_3;
    QLineEdit *r0LineEdit_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *pcLabel_3;
    QLineEdit *pcLineEdit_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1111, 672);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        screenLabel = new QLabel(centralwidget);
        screenLabel->setObjectName("screenLabel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(screenLabel->sizePolicy().hasHeightForWidth());
        screenLabel->setSizePolicy(sizePolicy);
        screenLabel->setMinimumSize(QSize(500, 150));
        screenLabel->setStyleSheet(QString::fromUtf8("border: 2px solid black;"));

        gridLayout_4->addWidget(screenLabel, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        centralWidget = new QWidget(centralwidget);
        centralWidget->setObjectName("centralWidget");
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        clearMemoryButton_3 = new QPushButton(centralWidget);
        clearMemoryButton_3->setObjectName("clearMemoryButton_3");

        gridLayout_2->addWidget(clearMemoryButton_3, 1, 0, 1, 1);

        runButton_3 = new QPushButton(centralWidget);
        runButton_3->setObjectName("runButton_3");

        gridLayout_2->addWidget(runButton_3, 1, 3, 1, 1);

        haltButton_3 = new QPushButton(centralWidget);
        haltButton_3->setObjectName("haltButton_3");

        gridLayout_2->addWidget(haltButton_3, 1, 5, 1, 1);

        mainMemoryTable_3 = new QTableWidget(centralWidget);
        if (mainMemoryTable_3->columnCount() < 16)
            mainMemoryTable_3->setColumnCount(16);
        if (mainMemoryTable_3->rowCount() < 16)
            mainMemoryTable_3->setRowCount(16);
        mainMemoryTable_3->setObjectName("mainMemoryTable_3");
        mainMemoryTable_3->setAlternatingRowColors(true);
        mainMemoryTable_3->setShowGrid(true);
        mainMemoryTable_3->setRowCount(16);
        mainMemoryTable_3->setColumnCount(16);

        gridLayout_2->addWidget(mainMemoryTable_3, 0, 2, 1, 5);

        loadDataButton_3 = new QPushButton(centralWidget);
        loadDataButton_3->setObjectName("loadDataButton_3");

        gridLayout_2->addWidget(loadDataButton_3, 1, 1, 1, 2);

        helpButton_3 = new QPushButton(centralWidget);
        helpButton_3->setObjectName("helpButton_3");

        gridLayout_2->addWidget(helpButton_3, 1, 6, 1, 1);

        singleStepButton_3 = new QPushButton(centralWidget);
        singleStepButton_3->setObjectName("singleStepButton_3");

        gridLayout_2->addWidget(singleStepButton_3, 1, 4, 1, 1);

        cpuGroupBox_3 = new QGroupBox(centralWidget);
        cpuGroupBox_3->setObjectName("cpuGroupBox_3");
        layoutWidget_2 = new QWidget(cpuGroupBox_3);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(10, 30, 261, 471));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(layoutWidget_2);
        listWidget->setObjectName("listWidget");

        horizontalLayout_3->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        r0Label_3 = new QLabel(layoutWidget_2);
        r0Label_3->setObjectName("r0Label_3");

        horizontalLayout->addWidget(r0Label_3);

        r0LineEdit_3 = new QLineEdit(layoutWidget_2);
        r0LineEdit_3->setObjectName("r0LineEdit_3");

        horizontalLayout->addWidget(r0LineEdit_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pcLabel_3 = new QLabel(layoutWidget_2);
        pcLabel_3->setObjectName("pcLabel_3");

        horizontalLayout_2->addWidget(pcLabel_3);

        pcLineEdit_3 = new QLineEdit(layoutWidget_2);
        pcLineEdit_3->setObjectName("pcLineEdit_3");

        horizontalLayout_2->addWidget(pcLineEdit_3);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);


        gridLayout_2->addWidget(cpuGroupBox_3, 0, 0, 1, 2);


        gridLayout->addWidget(centralWidget, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1111, 25));
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
        screenLabel->setText(QCoreApplication::translate("MainWindow", "Screen Window Content", nullptr));
        clearMemoryButton_3->setText(QCoreApplication::translate("MainWindow", "Clear Memory", nullptr));
        runButton_3->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        haltButton_3->setText(QCoreApplication::translate("MainWindow", "Halt", nullptr));
        loadDataButton_3->setText(QCoreApplication::translate("MainWindow", "Load Data", nullptr));
        helpButton_3->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        singleStepButton_3->setText(QCoreApplication::translate("MainWindow", "Single Step", nullptr));
        cpuGroupBox_3->setTitle(QCoreApplication::translate("MainWindow", "CPU", nullptr));
        r0Label_3->setText(QCoreApplication::translate("MainWindow", "IR:", nullptr));
        pcLabel_3->setText(QCoreApplication::translate("MainWindow", "PC:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
