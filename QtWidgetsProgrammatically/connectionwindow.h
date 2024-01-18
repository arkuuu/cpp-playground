#ifndef CONNECTIONWINDOW_H
#define CONNECTIONWINDOW_H

#include <QDialog>
#include <QWidget>

class ConnectionWindow : public QDialog
{
    Q_OBJECT
public:
    explicit ConnectionWindow(QDialog *parent = nullptr);

signals:
};

#endif // CONNECTIONWINDOW_H
