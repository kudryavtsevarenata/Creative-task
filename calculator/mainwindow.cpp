#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox> // для всплывающих окон

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // появление всплывающих надписей
    ui->pushButton_44->setToolTip("Вычислить");
    ui->lineEdit->setToolTip("Введите число");
    ui->lineEdit_2->setToolTip("Введите основание логарифма");
    ui->pushButton_45->setToolTip("Вычислить");
    ui->lineEdit_3->setToolTip("Введите число");
    ui->lineEdit_4->setToolTip("Введите основание логарифма");
    ui->lineEdit_5->setToolTip("Введите знак");
    // hide() скрывает ненужные элементы от пользователя
    ui->pushButton_45->hide();
    ui->strange->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->log_2->hide();
    this->ui->info->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// вычисление значения одного логарифма
void MainWindow::on_pushButton_44_clicked()
{
    ui->pushButton_44->setStyleSheet("background-color: rgb(255, 169, 108); border-style: outset; border-radius: 10px; border-width: 2px; border-color: black;");
    double a, b;
    ui->log_3->setAlignment(Qt::AlignLeft | Qt::AlignLeft); // положение текста в лейбле
    QString s1 = ui->lineEdit->text();
    QString s2 = ui->lineEdit_2->text(); // считывание данных из полей
    if (s1.length()!= 0 && s2.length()!= 0) // проверки условий
    {
        if (s1 == "e" || s2 == "e")
        {
            if (s1 == "e" && s2 != "e")
            {
                a = 2.72;
                b = s2.toDouble();
            }
            if (s2 == "e" && s1 != "e")
            {
                b = 2.72;
                a = s1.toDouble();
            }
            if (s1 == "e" && s2 == "e")
            {
                a = b = 2.72;
            }
        }
        else
        {
            a = s1.toDouble(); b = s2.toDouble(); // преобразование из типа string в double
        }
        if (a > 0 && b > 0 && b != 1)
        {
            double res = log(a)/log(b); // вычисление результата
            QString str = QString::number(res); // преобразование типов
            ui->log_3->setText(str); // вывод результата
        }
        else
            QMessageBox::warning(this->ui->strange, "Warning", "Невозможно выполнить операцию"); // предупреждение
    }
    else
        QMessageBox::warning(this->ui->strange, "Warning", "Введены не все данные"); // предупреждение
}

// скрывает и показывает нужные поля при выборе режима работы с двумя логарифмами
void MainWindow::on_radioButton_2_clicked()
{
    ui->pushButton_44->hide();
    // show() показывает нужные поля пользователю
    ui->pushButton_45->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->lineEdit_5->show();
    ui->log_2->show();
    // setText() - установка определенного текста в лейбл log_3
    ui->log_3->setText("");
}

// скрывает и показывает нужные поля при выборе режима работы с одним логарифмом
void MainWindow::on_radioButton_clicked()
{
    ui->pushButton_44->show();
    ui->pushButton_45->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->log_2->hide();
    ui->log_3->setText("");
}

// вычисление значения выражения, состоящего из двух логарифмов
void MainWindow::on_pushButton_45_clicked()
{
    ui->pushButton_45->setStyleSheet("background-color: rgb(255, 169, 108); border-style: outset; border-radius: 10px; border-width: 2px; border-color: black;");
    double a, b, c, d;
    ui->log_3->setAlignment(Qt::AlignLeft | Qt::AlignCenter);
    QString s1 = ui->lineEdit->text();
    QString s2 = ui->lineEdit_2->text();
    QString s3 = ui->lineEdit_4->text();
    QString s4 = ui->lineEdit_3->text();
    QString sign = ui->lineEdit_5->text(); // считывание данных из полей
    /* проверка  введенных данных на корректность */
    if (sign == "+" || sign == "-" || sign == "*" || sign == "/")
    {
        if (s1.length()!= 0 && s2.length()!= 0  && s3.length()!= 0  && s4.length()!= 0 )
        {
            if (s1 == "e" || s2 == "e" || s3 == "e" || s4 == "e")
            {
                if (s1 == "e" && s2 != "e" && s3 != "e" && s4 != "e")
                {
                    a = 2.72;
                    b = s2.toDouble();
                    c = s3.toDouble();
                    d = s4.toDouble();
                }
                if (s1 != "e" && s2 == "e" && s3 != "e" && s4 != "e")
                {
                    a = s1.toDouble();
                    b = 2.72;
                    c = s3.toDouble();
                    d = s4.toDouble();
                }
                if (s1 != "e" && s2 != "e" && s3 == "e" && s4 != "e")
                {
                    a = s1.toDouble();
                    b = s2.toDouble();
                    c = 2.72;
                    d = s4.toDouble();
                }
                if (s1 != "e" && s2 != "e" && s3 != "e" && s4 == "e")
                {
                    a = s1.toDouble();
                    b = s2.toDouble();
                    c = s3.toDouble();
                    d = 2.72;
                }
                if (s1 == "e" && s2 == "e" && s3 == "e" && s4 == "e")
                {
                    a = 2.72;
                    b = 2.72;
                    c = 2.72;
                    d = 2.72;
                }
            }
            else
            {
                a = s1.toDouble(); b = s2.toDouble(); c = s3.toDouble(); d = s4.toDouble(); // преобразование типов
            }
            if (a > 0 && b > 0 && b != 1 && c > 0 && d > 0 && d != 1)
            {
                if (sign == "+")
                {
                    double res = log(a)/log(b)+log(c)/log(d);
                    QString str = QString::number(res);
                    ui->log_3->setText(str);
                }
                else
                {
                    if (sign == "-")
                    {
                        double res = log(a)/log(b)-log(c)/log(d);
                        QString str = QString::number(res);
                        ui->log_3->setText(str);
                    }
                    else
                        if (sign == "*")
                        {
                            double res = (log(a)/log(b))*(log(c)/log(d));
                            QString str = QString::number(res);
                            ui->log_3->setText(str);
                        }
                    else
                            if (sign == "/")
                            {
                                if (log(c)/log(d) == 0) // если делитель равен 0
                                    QMessageBox::warning(this->ui->strange, "Warning", "Невозможно выполнить операцию, делитель равен 0");
                                else
                                {
                                    double res = (log(a)/log(b))/(log(c)/log(d)); // вычисление результата
                                    QString str = QString::number(res); // преобразование типов
                                    ui->log_3->setText(str); // вывод результата
                                }
                            }
                }
            }
            else{
                QMessageBox::warning(this->ui->strange, "Warning", "Невозможно выполнить операцию");
            }
        }
        else
            QMessageBox::warning(this->ui->strange, "Warning", "Введены не все данные");
    }
    else
        QMessageBox::warning(this->ui->strange, "Warning", "Неверный знак");
}

// для вывода подсказки (кнопки со знаком "?")
int counter = 0;
void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setStyleSheet("background-color: rgb(255, 191, 134); border-style: outset; border-radius: 10px; border-width: 2px; border-color: black;");
    counter++;
    if (counter % 2 == 1)
        ui->info->show();
    else
        this->ui->info->hide();
}

// изменение стиля кнопок при нажатии
void MainWindow::on_pushButton_pressed()
{
    ui->pushButton->setStyleSheet(" color: white; background-color: rgb(255, 55, 55); border-style: outset; border-radius: 10px; border-width: 2px; border-color: rgb(68, 68, 68);");
}

void MainWindow::on_pushButton_44_pressed()
{
    ui->pushButton_44->setStyleSheet(" color: white; background-color: rgb(255, 55, 55); border-style: outset; border-radius: 10px; border-width: 2px; border-color: rgb(68, 68, 68);");
}

void MainWindow::on_pushButton_45_pressed()
{
    ui->pushButton_45->setStyleSheet(" color: white; background-color: rgb(255, 55, 55); border-style: outset; border-radius: 10px; border-width: 2px; border-color: rgb(68, 68, 68);");

}
