#include "include/QT/mainwindow.h"
#include <QApplication>
// #include <QtGui>
#include <QMessageBox>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();

    return app.exec();

    QTextStream cout(stdout);

    // Declarations of variables
    int answer = 0;

    do
    {
        // local variables to the loop:
        int factArg = 0;
        int fact(1);
        factArg = QInputDialog::getInt(0, "Factorial Calculator",
                                       "Factorial of:", 1);
        factArg = QInputDialog::getInt(0, "Factorial Calculator",
                                       "Factorial of:", 1);
        cout << "User entered: " << factArg << endl;
        int i = 2;
        while (i <= factArg)
        {
            fact = fact * i;
            ++i;
        }
        QString response = QString("The factorial of %1 is %2.\n%3")
                               .arg(factArg)
                               .arg(fact)
                               .arg("Compute another factorial?");
        answer = QMessageBox::question(0, "Play again?", response,
                                       QMessageBox::Yes | QMessageBox::No);
    } while (answer == QMessageBox::Yes);
    return EXIT_SUCCESS;
}
