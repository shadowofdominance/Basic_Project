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
        UpdateTaskCount();
    }
}

void MainWindow::DeleteTask(){
    QListWidgetItem* item = ui->listWidget->currentItem();
    if(item){
        delete item;
        UpdateTaskCount();
    }
}

void MainWindow::UpdateTaskCount(){
    int taskCount = ui->listWidget->count();
    ui->CounterLabel->setText(QString::number(taskCount) + " tasks");
}

void MainWindow::on_ButtonDelete_clicked()
{
    DeleteTask();
}


void MainWindow::on_LineEditField_returnPressed()
{
    AddTask();
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

}

void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();
    UpdateTaskCount();
}

