#include "mainwindow.h"

#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QRegularExpression>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    setFixedSize(300,150);

    mainWidget = new QWidget(this);
    mainWidget->setFixedSize(300,150);

    vBox = new QVBoxLayout(mainWidget);

    inputLine = new QLineEdit(this);
    inputLine->setPlaceholderText("+00000000000");

    statusLabel = new QLabel(this);
    statusLabel->setAlignment(Qt::AlignCenter);

    vBox->addWidget(inputLine);
    vBox->addWidget(statusLabel);

    connect(inputLine,&QLineEdit::textEdited,[this](QString currentText){
        QRegularExpression exp ("^\\+([0-9]{11})$");
        if(currentText.isEmpty())
        {
            waitIput();
        }
        else if(exp.match(currentText).hasMatch())
        {
            correctNum();
        }
        else
        {
            incorrectNum();
        }
    });

    waitIput();    
}

void MainWindow::correctNum()
{
    statusLabel->setText("Correct number");
    statusLabel->setStyleSheet("QLabel {background-color: green;}");
}

void MainWindow::incorrectNum()
{
    statusLabel->setText("Incorrect number");
    statusLabel->setStyleSheet("QLabel {background-color: red;}");
}

void MainWindow::waitIput()
{
    statusLabel->setText("Waiting input");
    statusLabel->setStyleSheet("QLabel {background-color: grey;}");
}
