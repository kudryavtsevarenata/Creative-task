#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_44_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_clicked();

    void on_pushButton_pressed();

    void on_pushButton_44_pressed();

    void on_pushButton_45_pressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
