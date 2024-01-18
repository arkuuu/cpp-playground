#ifndef NAVIGATIONDATAWIDGET_H
#define NAVIGATIONDATAWIDGET_H

#include <QGroupBox>
#include <QLabel>

class NavigationDataWidget : public QGroupBox
{
    Q_OBJECT
public:
    NavigationDataWidget();

private:
    QLabel *position;
    QLabel *cog;
    QLabel *sog;
    QLabel *depth;
};

#endif // NAVIGATIONDATAWIDGET_H
