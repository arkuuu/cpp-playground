#ifndef NMEALOGWIDGET_H
#define NMEALOGWIDGET_H

#include <QGroupBox>
#include <QPlainTextEdit>

class NmeaLogWidget : public QGroupBox
{
    Q_OBJECT
public:
    NmeaLogWidget();

private:
    QPlainTextEdit *log;
};

#endif // NMEALOGWIDGET_H
