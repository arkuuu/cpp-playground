#include "connectionwidget.h"

#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>

ConnectionWidget::ConnectionWidget()
{
    connectBtn = new QPushButton(tr("Connect"));
    disconnectBtn = new QPushButton(tr("Disconnect"));
    disconnectBtn->setDisabled(true);

    serverInput = new QLineEdit;
    portInput = new QLineEdit;

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QLabel(tr("Server:")), 0, 0);
    layout->addWidget(serverInput, 0, 1, 1, 2);
    layout->addWidget(new QLabel(tr("Port:")), 1, 0);
    layout->addWidget(portInput, 1, 1, 1, 2);
    layout->addWidget(connectBtn, 2, 1);
    layout->addWidget(disconnectBtn, 2, 2);

    setLayout(layout);
    setTitle(tr("Connection"));
}
