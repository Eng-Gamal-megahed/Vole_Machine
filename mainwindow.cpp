#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
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
    QTableWidget *table = ui->mainMemoryTable_3;

    // Set row headers (0 to F)
    for (int i = 0; i < table->rowCount(); ++i) {
        table->setVerticalHeaderItem(i, new QTableWidgetItem(QString::number(i, 16).toUpper()));
    }

    // Set column headers (0 to F)
    for (int j = 0; j < table->columnCount(); ++j) {
        table->setHorizontalHeaderItem(j, new QTableWidgetItem(QString::number(j, 16).toUpper()));
    }

    for (int i = 0; i < 16; ++i) {
        ui->listWidget->addItem(QString::fromStdString(std::to_string(col) + std::to_string(row)) + " : ");
        row++;
        if(row == 10)
        {
            row = 0;
            col++;
        }
    }
    row = col = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loadDataButton_3_clicked()
{
    string instruction = ui->input->text().toStdString();
    ui->mainMemoryTable_3->setItem(row , col , new QTableWidgetItem(QString::fromStdString(instruction.substr(0, 2))));
    next_item();
    ui->mainMemoryTable_3->setItem(row , col , new QTableWidgetItem(QString::fromStdString(instruction.substr(2, 2))));
    next_item();
}


void MainWindow::on_clearMemoryButton_3_clicked()
{
    for (int i = 0; i < ui->mainMemoryTable_3->rowCount(); ++i) {
        for (int j = 0; j < ui->mainMemoryTable_3->columnCount(); ++j) {
            QTableWidgetItem *item = ui->mainMemoryTable_3->item(i, j);
            if (item) {
                item->setText("");  // Clear the text of each cell
            }
        }
    }
    row = col = 0;
}

