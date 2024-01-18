#include "mainwindow.h"
#include "centralwidget.h"

#include <QLayout>
#include <QMenuBar>
#include <QPushButton>
#include "connectionwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QAction *quitAction = new QAction(tr("Quit"));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    QMenu *fileMenu = menuBar()->addMenu(tr("File"));
    fileMenu->addAction(quitAction);

    QMenu *helpMenu = menuBar()->addMenu(tr("Help"));
    helpMenu->addAction(new QAction(tr("About")));

    CentralWidget *content = new CentralWidget;
    setCentralWidget(content);

    setMinimumSize(640, 480);
    setWindowTitle(tr("Qt NMEA 0138 Listener"));
}

MainWindow::~MainWindow() {}
