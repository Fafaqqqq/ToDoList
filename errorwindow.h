#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

#include <QWidget>
#include "ui_error.h"

class ErrorWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ErrorWindow(QWidget *parent = nullptr);

signals:

};

#endif // ERRORWINDOW_H
