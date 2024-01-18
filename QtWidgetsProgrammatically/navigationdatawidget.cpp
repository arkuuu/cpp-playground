#include "navigationdatawidget.h"

#include <QLabel>
#include <QLayout>

NavigationDataWidget::NavigationDataWidget()
{
    position = new QLabel(tr("n.a."));
    cog = new QLabel(tr("n.a."));
    sog = new QLabel(tr("n.a."));
    depth = new QLabel(tr("n.a."));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QLabel(tr("Position:")), 0, 0);
    layout->addWidget(position, 0, 1);
    layout->addWidget(new QLabel(tr("COG:")), 2, 0);
    layout->addWidget(cog, 2, 1);
    layout->addWidget(new QLabel(tr("SOG:")), 1, 0);
    layout->addWidget(sog, 1, 1);
    layout->addWidget(new QLabel(tr("Depth:")), 3, 0);
    layout->addWidget(depth, 3, 1);

    setLayout(layout);
    setTitle(tr("Received Navigation Data"));
}
