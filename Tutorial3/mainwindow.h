#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <KXmlGuiWindow>

class KTextEdit;

class MainWindow : public KXmlGuiWindow
{
public:
    MainWindow(QWidget *parent=0);

private:
    KTextEdit* textArea;
    void setupActions();
};

#endif
