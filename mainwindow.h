#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ButtonAdd_clicked();

    void on_ButtonDelete_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_LineEditField_returnPressed();

    void on_pushButton_clicked();

private:
    void AddTask();
    void DeleteTask();
    void UpdateTaskCount();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
