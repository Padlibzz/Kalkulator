#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>

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
    void inputnum(const QString &num);
    void getnum();
    void aritmatika();

private slots:
    void on_Display_textChanged(const QString &arg1);
    void on_BT0_clicked();
    void on_BT1_clicked();
    void on_BT2_clicked();
    void on_BT3_clicked();
    void on_BT4_clicked();
    void on_BT5_clicked();
    void on_BT6_clicked();
    void on_BT7_clicked();
    void on_BT8_clicked();
    void on_BT9_clicked();
    void on_BTsum_clicked();
    void on_BTsub_clicked();
    void on_BTmul_clicked();
    void on_BTdiv_clicked();
    void on_BTpoint_clicked();

    void on_BTbackspace_clicked();

    void on_BTequal_clicked();

    void on_BTclear_clicked();

    void on_BTclearentry_clicked();

    void on_BTpower_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<double> angka;
    std::vector<QString> op;

};
#endif // MAINWINDOW_H
