#include "mainwindow.hpp"
#include "iostream"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _splitter = new QSplitter(Qt::Horizontal, this);


    QFrame *topleft = new QFrame(this);
    topleft->setFrameShape(QFrame::StyledPanel);

    QFrame *topright = new QFrame(this);
    topright->setFrameShape(QFrame::StyledPanel);
    topright->setWindowTitle("Workspace");
    topright->setVisible(true);


    CoralEditor *editor = new CoralEditor();

    _splitter->addWidget(editor); //topleft);
    _splitter->addWidget(topright);
    setWindowTitle("Projet Platforme");
    setCentralWidget(_splitter);

    //QList liste();
    // liste().insert();

    //  _splitter->setSizes(liste());
    this->setMinimumSize(400,600);
    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
    delete _splitter;
}


QSplitter *MainWindow::getSpliter()
{
    return _splitter;
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(actionOpen);
    fileMenu->addAction(actionSave);
    fileMenu->addSeparator();
    fileMenu->addAction(actionExit);

    optionMenu = menuBar()->addMenu(tr("&Option"));
    optionMenu->addAction(actionSkin);
    optionMenu->addAction(actionLangage);
    optionMenu->addAction(actionDualScreen);
}

void MainWindow::createActions()
{
    actionOpen = new QAction(QIcon(":/images/open.png"), tr("Open"), this);
    actionOpen->setShortcuts(QKeySequence::Open);
    //actionOpen->setStatusTip(tr("Open an existing file"));

    actionSave = new QAction(QIcon(":/images/save.png"), tr("Save"), this);
    actionSave->setShortcuts(QKeySequence::Save);
    //actionSave->setStatusTip(tr("Open an existing file"));

    actionExit = new QAction(QIcon(":/images/exit.png"), tr("Exit"), this);
    actionExit->setShortcuts(QKeySequence::Quit);
    //actionExit->setStatusTip(tr("Exit the application"));
    connect(actionExit, SIGNAL(triggered()), this, SLOT(close()));

    actionSkin = new QAction(QIcon(":/images/skins.png"), tr("Skin"), this);
   // actionSkin->setShortcuts(QKeySequence(Qt::CTRL + Qt::Key_J));
    //actionSkin->setStatusTip(tr("Exit the application"));
    //connect(actionSkin, SIGNAL(triggered()), this, SLOT(close()));

    actionLangage = new QAction(QIcon(":/images/langage.png"), tr("Langage"), this);
   // actionLangage->setShortcuts(QKeySequence(tr("Ctrl+L")));
    //actionLangage->setStatusTip(tr("Exit the application"));
    //connect(actionLangage, SIGNAL(triggered()), this, SLOT(close()));

    actionDualScreen = new QAction(QIcon(":/images/dualscreen.png"), tr("Dual Screen"), this);
  //  actionDualScreen->setShortcuts(QKeySequence(tr("Ctrl+D")));
    //actionDualScreen->setStatusTip(tr("Exit the application"));
    //connect(actionDualScreen, SIGNAL(triggered()), this, SLOT(close()));
}
