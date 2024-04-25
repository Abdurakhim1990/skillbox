#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <QString>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void bt_0();
    void bt_1();
    void bt_2();
    void bt_3();
    void bt_4();
    void bt_5();
    void bt_6();
    void bt_7();
    void bt_8();
    void bt_9();
    void btChUp();
    void btChDw();
    void btVolUp();
    void btVolDw();

private:
    void displayChannel();
    void displayDelayChannel();
    void selectChannel(int ch);

    Ui::MainWindow *ui;
    int channel = 0;
    int volume = 0;
    bool delay = true;
};
#endif // MAINWINDOW_H
