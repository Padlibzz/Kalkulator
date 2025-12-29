#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTextStream>

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

void MainWindow::inputnum(const QString &num){
    if(ui->Display->text().isEmpty()){
        ui->Display->setText(num);
    }else{
        ui->Display->setText(ui->Display->text() + num);
    }
}

void MainWindow::getnum(){
    QString num = ui->Display->text();
    QTextStream in(&num);
    double angkatemp;
    QString optemp;

    while (!in.atEnd()) {
        in >> angkatemp;
        angka.push_back(angkatemp);
        if(in.atEnd()){break;}
        in >> optemp;
        op.push_back(optemp);
    }
}
void MainWindow::aritmatika(){

    for (int var = 0; var < op.size(); ++var) {
        if(op.at(var) == "*" || op.at((var)) == "/"){
            double a = angka.at(var);
            double b = angka.at(var + 1);

            if(op.at(var) == "/" && b == 0){
                ui->Display->setText("ERROR zero division");
            }

            double hasil = (op.at(var) == "*") ? a * b : a / b;

            angka.at(var) = hasil;
            angka.erase(angka.begin() + (var+1));
            op.erase(op.begin() + var);
        }
    }

    while (!op.empty()) {
        double a = angka.at(0);
        double b = angka.at(1);
        double hasil = (op.at(0) == "+") ? a + b : a - b;
        angka.at(0) = hasil;
        angka.erase(angka.begin() + 1);
        op.erase(op.begin());
    }
    ui->Display->setText(QString::number(angka.at(0)));
    angka.clear();
    op.clear();
}

void MainWindow::on_Display_textChanged(const QString &arg1)
{

}


void MainWindow::on_BT0_clicked(){inputnum("0");}
void MainWindow::on_BT1_clicked(){inputnum("1");}
void MainWindow::on_BT2_clicked(){inputnum("2");}
void MainWindow::on_BT3_clicked(){inputnum("3");}
void MainWindow::on_BT4_clicked(){inputnum("4");}
void MainWindow::on_BT5_clicked(){inputnum("5");}
void MainWindow::on_BT6_clicked(){inputnum("6");}
void MainWindow::on_BT7_clicked(){inputnum("7");}
void MainWindow::on_BT8_clicked(){inputnum("8");}
void MainWindow::on_BT9_clicked(){inputnum("9");}
void MainWindow::on_BTsum_clicked(){inputnum(" + ");}
void MainWindow::on_BTsub_clicked(){inputnum(" - ");}
void MainWindow::on_BTmul_clicked(){inputnum(" * ");}
void MainWindow::on_BTdiv_clicked(){inputnum(" / ");}
void MainWindow::on_BTpoint_clicked(){inputnum(".");}

void MainWindow::on_BTbackspace_clicked()
{
    QString text = ui->Display->text();
    if(text.endsWith(" ")){
        text.chop(3);
    }else{
        text.chop(1);
    }
    ui->Display->setText(text);
}


void MainWindow::on_BTequal_clicked()
{
    getnum();
    aritmatika();
}


void MainWindow::on_BTclear_clicked()
{
    ui->Display->clear();
    op.clear();
    angka.clear();
}


void MainWindow::on_BTclearentry_clicked()
{
    getnum();
    ui->Display->clear();
}


void MainWindow::on_BTpower_clicked()
{
    QString text = ui->Display->text().trimmed();
    int pos = text.lastIndexOf(" ");

    QString kiri, kanan;

    if(pos == -1){
        kanan = text;
        kiri = "";
    } else {
        kiri  = text.left(pos + 1);
        kanan = text.mid(pos + 1);
    }

    double num = kanan.toDouble();

    num = -num;
    ui->Display->setText(kiri + QString::number(num));

}
