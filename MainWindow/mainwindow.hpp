#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QSplitter>
#include <QFrame>
#include <QMenuBar>
#include <QKeySequence>

#include "coraleditor.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QSplitter *getSpliter();

private:
    void createMenus();
    void createActions();

    QMenu *fileMenu;
    QMenu *optionMenu;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionSkin;
    QAction *actionLangage;
    QAction *actionDualScreen;


    QSplitter *_splitter;
};

#endif // MAINWINDOW_HPP
