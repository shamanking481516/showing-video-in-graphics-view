#include "mainwindow.h"
#include "output_view.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QDir>
#include <QImage>
#include <QPixmap>
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *t_parent) :
    QMainWindow(t_parent),
    m_output_view(new OutputView(this)),
    m_scene(new QGraphicsScene(this)),
    m_menu_bar(new QMenuBar(this)),
    m_file_menu(new QMenu(tr("&File"), this)),
    m_open_action(new QAction(tr("&Open"), this))
{
    setupUi();
    initializationOfConnection();
}

void MainWindow::setupUi()
{
    m_file_menu->addAction(m_open_action);
    m_menu_bar->addMenu(m_file_menu);
    setMenuBar(m_menu_bar);
    m_output_view->setScene(m_scene);
    setCentralWidget(m_output_view);
}

void MainWindow::initializationOfConnection()
{
    connect(m_open_action, &QAction::triggered, this, &MainWindow::openFile);
}

void MainWindow::openFile()
{
    const QString caption { tr("Open File") };
    const QString filter { tr("Images ") + "(*.jpg *.png)" };
    QString filename = QFileDialog::getOpenFileName(this, caption, QDir::homePath(), filter);
    if (QFile::exists(filename))
    {
        m_scene->addPixmap(QPixmap::fromImage(QImage(filename)));
        m_output_view->fitIntoView();
    }
}
