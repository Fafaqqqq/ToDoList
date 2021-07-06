#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtUiTools>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_addButton = findChild<QPushButton*>("Add");
    ui_deleteButton = findChild<QPushButton*>("Delete");
    ui_moveButton = findChild<QPushButton*>("Move");
    ui_inputNum = findChild<QLineEdit*>("InputNum");
    ui_inputIndex = findChild<QLineEdit*>("InputIndex");
    ui_inputFrom = findChild<QLineEdit*>("InputFrom");
    ui_inputTo = findChild<QLineEdit*>("InputTo");
    ui_numbers = findChild<QListView*>("Numbers");
}

MainWindow::~MainWindow()
{
    delete ui;
}

