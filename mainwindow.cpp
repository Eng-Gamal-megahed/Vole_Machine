#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Vole_Machine.h"
#include <string>
#include <QMessageBox>
#include <QFileDialog>

using namespace std;

QString file;
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

    for (int i = 0; i < 16; ++i) {
        QString hexValue = QString::number(i, 16).toUpper() + " : 00"; // Convert to hex and make uppercase
        ui->listWidget->addItem(hexValue); // Assuming listWidget is the name of your QListWidget
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loadDataButton_3_clicked()
{
    // Open file dialog and get file path
    file = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Files (*.txt)"));
    if (file.isEmpty()) return; // Return if no file selected

    QFile fileObj(file); // Use a different name for QFile object
    if (!fileObj.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Cannot open file for reading.");
        return;
    }

    QTextStream in(&fileObj);
    QString instruction;
    int instructions = 0;


    // Read line by line
    while (!in.atEnd()) {
        instruction = in.readLine(); // Read a line from the file
        if (!is_valid(instruction.toStdString())) { // Assuming is_valid takes std::string
            QMessageBox::warning(this, "Invalid Program", "Error in line " + QString::number(instructions + 1) + ".");
            file.clear();
            fileObj.close();
            return;
        }
        if (instructions >= 256) { // 16 * 16 = 256, memory limit exceeded
            QMessageBox::warning(this, "Memory Limit", "The program you loaded has exceeded the memory limit.");
            file.clear();
            fileObj.close();
            return;
        }

        // Calculate row and column index
        int row = instructions % 16; // Integer division for row index
        int column = instructions / 16; // Modulus for column index

        ui->mainMemoryTable_3->setItem(row, column, new QTableWidgetItem(instruction.left(2)));
        instructions++;
        row = instructions % 16; // Integer division for row index
        column = instructions / 16; // Modulus for column index
        ui->mainMemoryTable_3->setItem(row, column, new QTableWidgetItem(instruction.mid(2, 2)));
        instructions++;
    }

    fileObj.close(); // Close the file after reading
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
    Memory Storage;
    CPU cpu(&Storage);
    int idx = 0;
    QTableWidget *memory_table = ui->mainMemoryTable_3;
    for (int i = 0; i < memory_table->rowCount(); ++i) {
        for (int j = 0; j < memory_table->columnCount(); ++j) {
            Storage.set_cell(idx , memory_table->item(j , i)->text().toStdString());
            idx++;
        }
    }
    cpu.runNextStep();
    cpu.runNextStep();
    cpu.runNextStep();
    cpu.runNextStep();

    idx = 0;
    for (int i = 0; i < memory_table->rowCount(); ++i) {
        for (int j = 0; j < memory_table->columnCount(); ++j) {
            // Assuming Storage.get_cell(idx) returns a QString
            QString value = QString::fromStdString(Storage.get_cell(idx)); // Get the value from Storage
            memory_table->setItem(i, j, new QTableWidgetItem(value)); // Set the item in the table
            idx++; // Increment the index
        }
    }

    string addition = cpu.get_screen();
    ui->screenLabel->setText(QString::fromStdString(addition));

    Register reg = cpu.get_reg();
    for (int i = 0; i < 16; ++i) {
        QString hexValue = QString::number(i, 16).toUpper() + " : " + QString::fromStdString(reg.get_cell(i)); // Convert to hex and make uppercase
        ui->listWidget->addItem(hexValue); // Assuming listWidget is the name of your QListWidget
    }

}



