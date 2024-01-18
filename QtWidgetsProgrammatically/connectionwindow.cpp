#include "connectionwindow.h"

#include <QDialog>
#include <QDialogButtonBox>
#include <QLayout>

ConnectionWindow::ConnectionWindow(QDialog *parent)
    : QDialog{parent}
{
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                                           | QDialogButtonBox::Cancel,
                                                       Qt::Horizontal);
    setWindowTitle(tr("Connect..."));
}
