//---------------------------------------------------------->
//  highlightcolor.h file.
//  Author     : Jayakrishnan P.
//  Last Edited: 13/10/2022
//---------------------------------------------------------->
#ifndef HIGHLIGHTCOLOR_H
#define HIGHLIGHTCOLOR_H

#include <QDialog>
#include "mainwindow.h"
#include <QSettings>

namespace Ui {

    class HighlightColor;
}

class HighlightColor : public QDialog
{
    Q_OBJECT

public:
    explicit HighlightColor(MainWindow* wnd, QWidget *parent = nullptr);
    ~HighlightColor();



private:
    Ui::HighlightColor *ui;
    MainWindow* m_pMnWindow;

private slots:
    void HighlighterDlgBtnClose();
    void TextBox1ColorChanged(QString);
    void TextBox2ColorChanged(QString);
};

#endif // HIGHLIGHTCOLOR_H
