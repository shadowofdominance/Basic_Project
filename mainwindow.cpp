#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonAdd_clicked()
{
    AddTask();
}

void MainWindow::AddTask(){
    QString task = ui->LineEditField->text();
    if(!task.isEmpty()){
        ui->listWidget->addItem(task);
        ui->LineEditField->clear();
    }
}

