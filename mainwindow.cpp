#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "error.h"
#include <QtUiTools>
#include <QAbstractItemView>
#include <QStringList>
#include <QStringListModel>
#include <sstream>

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


    connect(ui_addButton, &QPushButton::clicked, this, &MainWindow::ReadNum);
    connect(ui_addButton, &QPushButton::clicked, this, &MainWindow::SetListView);

    connect(ui_deleteButton, &QPushButton::clicked, this, &MainWindow::DeleteNum);
    connect(ui_deleteButton, &QPushButton::clicked, this, &MainWindow::SetListView);

    connect(ui_moveButton, &QPushButton::clicked, this, &MainWindow::MoveNum);
    connect(ui_moveButton, &QPushButton::clicked, this, &MainWindow::SetListView);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ReadNum()
{
    QString strNum = ui_inputNum->text();
    bool flag;

    int intNum = strNum.toInt(&flag);

    if (flag)
    {
        numbers.append(intNum);
    }
    else
    {
         ShowErrorWindow("Input data isn`t a number!");
    }
    ui_inputNum->setText("NUMBER");
}

//Доделать обработку неправильного индекса
void MainWindow::DeleteNum()
{
    QString strIndex = ui_inputIndex->text();
    bool flag;

    int intIndex = strIndex.toInt(&flag);

    if (flag)
    {
        if (0 <= intIndex && intIndex < numbers.size())
        {
            auto it = numbers.begin();
            for (int i = 0; i < intIndex; i++, it++);

            numbers.erase(it);
        }
        else
        {
            ShowErrorWindow("Going outside the list!");
        }
    }
    else
    {
         ShowErrorWindow("Input data isn`t a number!");
    }

    ui_inputIndex->setText("INDEX");
}

void MainWindow::MoveNum()
{
    QString strFrom = ui_inputFrom->text();
    QString strTo = ui_inputTo->text();

    bool flagFrom, flagTo;

    int intFrom = strFrom.toInt(&flagFrom);
    int intTo = strTo.toInt(&flagTo);

    if (flagFrom && flagTo)
    {
        if (0 <= intFrom && 0 <= intTo && intFrom < numbers.size() && intTo < numbers.size())
        {
            if (intFrom > intTo)
            {
                auto itFrom = numbers.begin();
                auto itTo = numbers.begin();

                for (int i = 0; i < intFrom; i++, itFrom++);
                for (int i = 0; i < intTo; i++, itTo++);

                numbers.insert(itTo, *itFrom);

                itFrom = numbers.begin();
                for (int i = 0; i <= intFrom; i++, itFrom++);

                numbers.erase(itFrom);
            }
            else
            {
                auto itFrom = numbers.begin();
                auto itTo = numbers.begin();

                for (int i = 0; i < intFrom; i++, itFrom++);
                for (int i = 0; i < intTo; i++, itTo++);

                numbers.insert(++itTo, *itFrom);
                numbers.erase(itFrom);
            }

        }
        else
        {
            ShowErrorWindow("Going outside the list!");
        }
    }
    else
    {
        ShowErrorWindow("Input data isn`t a number!");
    }
    ui_inputFrom->setText("FROM");
    ui_inputTo->setText("TO");

}

void MainWindow::SetListView()
{
    QStringListModel *model = new QStringListModel(this);

    QStringList list;

    foreach (int item, numbers)
    {
        std::ostringstream os;
        os << item;
        list << os.str().c_str();
    }

    model->setStringList(list);
    ui_numbers->setModel(model);
}

void MainWindow::ShowErrorWindow(QString str)
{
    Error *err = new Error(str);
    err->setWindowTitle("Error!");
    err->exec();
}

