#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QDebug>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QPushButton *button = new QPushButton("Click me!", this);
    button -> resize(100, 50);
    button -> setGeometry(50, 50, 200, 100);
    connect(button, &QPushButton::clicked, this, &MainWindow::printHelloWorld);

    QVBoxLayout *layout = new QVBoxLayout;
    layout -> addWidget(button);
    layout -> setAlignment(button, Qt::AlignCenter);

    QWidget *mainVWidget = new QWidget(this);
    mainVWidget -> setLayout(layout);
    setCentralWidget(mainVWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printHelloWorld() {
    qDebug() << "Hello, world";
}
