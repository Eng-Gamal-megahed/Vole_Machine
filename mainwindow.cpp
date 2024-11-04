#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QMessageBox>
using namespace std;

int row = 0 , col = 0;

void next_item()
{
    row++;
    if(row == 16)
    {
        row = 0;
        col++;
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTableWidget *memory_table = ui->mainMemoryTable_3;

    // Set up the memory table with headers (0 to F for both rows and columns)
    for (int i = 0; i < memory_table->rowCount(); ++i) {
        memory_table->setVerticalHeaderItem(i, new QTableWidgetItem(QString::number(i, 16).toUpper()));
    }
    for (int j = 0; j < memory_table->columnCount(); ++j) {
        memory_table->setHorizontalHeaderItem(j, new QTableWidgetItem(QString::number(j, 16).toUpper()));
    }

    // Initialize the register table

    // Ensure each cell in the memory table is initialized to "00" if empty
    for (int i = 0; i < memory_table->rowCount(); ++i) {
        for (int j = 0; j < memory_table->columnCount(); ++j) {
            if (!memory_table->item(i, j)) {
                memory_table->setItem(i, j, new QTableWidgetItem(QString::fromStdString("00")));
            }
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loadDataButton_3_clicked()
{

}


void MainWindow::on_clearMemoryButton_3_clicked()
{
    for (int i = 0; i < ui->mainMemoryTable_3->rowCount(); ++i) {
        for (int j = 0; j < ui->mainMemoryTable_3->columnCount(); ++j) {
            QTableWidgetItem *item = ui->mainMemoryTable_3->item(i, j);
                item->setText("00");
        }
    }
    row = col = 0;
}


void MainWindow::on_runButton_3_clicked()
{

}



