#ifndef CORALEDITOR_H
#define CORALEDITOR_H

#include <QWidget>
#include <QtGui>
#include <QString>

namespace Ui {
class CoralEditor;
}

class CoralEditor : public QWidget
{
    Q_OBJECT

public:
    explicit CoralEditor(QWidget *parent = 0);
    ~CoralEditor();

private:
    Ui::CoralEditor *ui;

    QTabWidget      *tab;
    QScrollArea     *scrollArea ;
    QWidget         *histoWidget ;
    QWidget         *contrasteWidget ;
    QWidget         *algoWidget ;
    QWidget         *editorWidget;
    QWidget         *manipWidget;
    QVBoxLayout     *scrollLayout;
    QVBoxLayout     *layout;

    void enterEvent(QEvent* evt);
    void leaveEvent(QEvent* evt);
    void setMaxMinSize();
    void setOpaque(bool opaque);
};

#endif // CORALEDITOR_H
