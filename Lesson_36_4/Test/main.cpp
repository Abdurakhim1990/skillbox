#include "main.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//    MainWindow w;
//    w.show();
    QTimer myTimer;
    Printer myPrinter;
    QObject::connect(&myTimer, &QTimer::timeout, &myPrinter, &Printer::printFinished);
    myTimer.start(1000);
    return app.exec();
}

Printer::Printer(QWidget *parent)
{}

void Printer::printFinished()
{
    std::cout << "finished" << std::endl;
}
