#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
//    QLineEdit* lineEdit = nullptr;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void add0();
    void add1();
    void add2();
    void add3();
    void add4();
    void add5();
    void add6();
    void add7();
    void add8();
    void add9();
    void makeCall();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
