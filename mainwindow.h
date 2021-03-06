#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QListView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void ReadNum();
    void DeleteNum();
    void MoveNum();
    void SetListView();
    void ShowErrorWindow(QString str);

    Ui::MainWindow *ui;
    QPushButton *ui_addButton;
    QPushButton *ui_deleteButton;
    QPushButton *ui_moveButton;
    QListView *ui_numbers;
    QLineEdit *ui_inputNum;
    QLineEdit *ui_inputIndex;
    QLineEdit *ui_inputFrom;
    QLineEdit *ui_inputTo;
    QList<int> numbers;
};
#endif // MAINWINDOW_H
