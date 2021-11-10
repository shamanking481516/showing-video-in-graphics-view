#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class OutputView;
class QGraphicsScene;
class QMenuBar;
class QMenu;
class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *t_parent = nullptr);
    ~MainWindow() {}

private:
    OutputView *m_output_view;
    QGraphicsScene *m_scene;
    QMenuBar *m_menu_bar;
    QMenu *m_file_menu;
    QAction *m_open_action;

    void setupUi();
    void initializationOfConnection();

private slots:
    void openFile();
};

#endif // MAINWINDOW_H
