#ifndef ERROR_H
#define ERROR_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class Error;
}

class Error : public QDialog
{
    Q_OBJECT

public:
    explicit Error(QString str, QWidget *parent = nullptr);
    ~Error();

private:
    Ui::Error *ui;
};

#endif // ERROR_H
