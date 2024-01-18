#ifndef CONNECTIONWIDGET_H
#define CONNECTIONWIDGET_H

#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>

class ConnectionWidget : public QGroupBox
{
    Q_OBJECT
public:
    ConnectionWidget();

private:
    QPushButton *connectBtn;
    QPushButton *disconnectBtn;
    QLineEdit *serverInput;
    QLineEdit *portInput;
};

#endif // CONNECTIONWIDGET_H
