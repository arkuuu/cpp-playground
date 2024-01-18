#include "centralwidget.h"

#include <QGroupBox>
#include <QLayout>
#include <QPushButton>

#include "connectionwidget.h"
#include "navigationdatawidget.h"
#include "nmealogwidget.h"

CentralWidget::CentralWidget(QWidget *parent)
    : QWidget{parent}
{
    QGroupBox *connectionWidget = new ConnectionWidget;
    QGroupBox *navigationDataWidget = new NavigationDataWidget;
    QHBoxLayout *upperLayout = new QHBoxLayout;
    upperLayout->addWidget(connectionWidget);
    upperLayout->addWidget(navigationDataWidget);

    QGroupBox *nmeaLogWidget = new NmeaLogWidget;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(upperLayout);
    layout->addWidget(nmeaLogWidget);

    setLayout(layout);
}
