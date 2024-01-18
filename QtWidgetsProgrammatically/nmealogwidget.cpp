#include "nmealogwidget.h"

#include <QLayout>
#include <QPlainTextEdit>

NmeaLogWidget::NmeaLogWidget()
{
    log = new QPlainTextEdit;
    log->setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(log);

    setLayout(layout);
    setTitle(tr("Received NMEA Sentences Log"));
}
