#include "coraleditor.hpp"
//#include "ui_coraleditor.h"

CoralEditor::CoralEditor(QWidget *parent) :
    QWidget(parent)
    //,ui(new Ui::CoralEditor)
{
    //ui->setupUi(this);
    // A modifier par les autres groupes
    histoWidget = new QWidget;
    contrasteWidget = new QWidget;
    algoWidget = new QWidget;
    editorWidget = new QWidget;
    manipWidget = new QWidget;
    // /////////////////////////////////
    layout = new QVBoxLayout();
    scrollLayout = new QVBoxLayout();
    tab = new QTabWidget();
    scrollArea = new QScrollArea();

    tab->addTab(histoWidget,     tr("Histogramme"));
    tab->addTab(contrasteWidget, tr("Constraste"));
    tab->addTab(algoWidget,      tr("Algorithmes"));
    layout->addWidget(tab);

    scrollLayout->addWidget(editorWidget);
    scrollLayout->addWidget(manipWidget);
    scrollArea->setLayout(scrollLayout);
    layout->addWidget(scrollArea);
    setLayout(layout);
    setMaxMinSize();
    setOpaque(false);
    // //////////////////////////////////
}

void CoralEditor::enterEvent( QEvent * event){
    setOpaque(true);
}
void CoralEditor::leaveEvent( QEvent * event){
    setOpaque(false);
}

void CoralEditor::setMaxMinSize(){
    QSizePolicy *expandPolicy = new QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    setMinimumSize(300, 800);
    setMaximumSize(500, 800);
    scrollArea->setSizePolicy(*expandPolicy);
    tab->setSizePolicy(*expandPolicy);
}

void CoralEditor::setOpaque(bool opaque){
    QGraphicsOpacityEffect * effect = new QGraphicsOpacityEffect(this);
    if (!opaque){
        effect->setOpacity(0.5);
    }else{
        effect->setOpacity(1);
    }
    tab->setGraphicsEffect(effect);
    scrollArea->setGraphicsEffect(effect);
    setGraphicsEffect(effect);
}

CoralEditor::~CoralEditor()
{
    //delete ui;
}
