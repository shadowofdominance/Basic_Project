#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QListWidget>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    LoadTasks();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonAdd_clicked()
{
    AddTask();
}

// Adds an item or a task in the listWidget
void MainWindow::AddTask(){
    QString task = ui->LineEditField->text(); // Accesses the text present in the line-edit
    if(!task.isEmpty()){
        ui->listWidget->addItem(task); // Adds the task string to the list as item
        ui->LineEditField->clear();
        UpdateTaskCount();
    }
}

// Deletes an item or a task in the listWidget
void MainWindow::DeleteTask(){
    QListWidgetItem* item = ui->listWidget->currentItem(); // Access the selected list item
    if(item){
        delete item;
        UpdateTaskCount();
    }
}

// Saves the items in a text file called tasks.txt
void MainWindow::SaveTasks(){
    QFile file("tasks.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);

        for(int i=0; i < ui->listWidget->count(); i++){
            QListWidgetItem *item = ui->listWidget->item(i);
            out << item->text() << "\n";
        }

        file.close();
    }
}

// Loads the items from the tasks.txt file! Called when the app starts
void MainWindow::LoadTasks(){
    QFile file("tasks.txt");

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);

        while(!in.atEnd()){
            QString task = in.readLine();
            ui->listWidget->addItem(task);
        }

        file.close();
    }
}

// Updates the count of tasks everytime its called
void MainWindow::UpdateTaskCount(){
    int taskCount = ui->listWidget->count(); // Counts the elements in the list with built-in function count()
    ui->CounterLabel->setText(QString::number(taskCount) + " tasks"); // Changes the text of the label
}

void MainWindow::on_ButtonDelete_clicked()
{
    DeleteTask();
}

//When enter is clicked the task is added to the list
void MainWindow::on_LineEditField_returnPressed()
{
    AddTask();
}

// Double click to complete the task
void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QFont font = item->font(); // fetches the font from the selected item
    bool isCompleted = font.strikeOut();

    font.setStrikeOut(!isCompleted);
    item->setFont(font);

    if(isCompleted)
        item->setForeground(Qt::white);
    else
        item->setForeground(Qt::gray);
}

// Clears everything
void MainWindow::on_ButtonClearAll_clicked()
{
    ui->listWidget->clear(); // Clears the whole list widget items with built-in function clear()
    UpdateTaskCount();
}

void MainWindow::closeEvent(QCloseEvent *event){
    SaveTasks(); // Saves the tasks before closing!
    event->accept();
}
