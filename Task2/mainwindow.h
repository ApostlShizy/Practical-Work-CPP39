#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class QLineEdit;
class QVBoxLayout;
class QWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
private:
    QWidget * mainWidget;
    QVBoxLayout * vBox;
    QLabel * statusLabel;
    QLineEdit * inputLine;
private slots:
    void correctNum();
    void incorrectNum();
    void waitIput();
};
#endif // MAINWINDOW_H
