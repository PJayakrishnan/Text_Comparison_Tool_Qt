//---------------------------------------------------------->
//  highlightcolor.h file.
//  Author     : Jayakrishnan P.
//  Last Edited: 15/08/2022
//---------------------------------------------------------->
#ifndef HIGHLIGHTCOLOR_H
#define HIGHLIGHTCOLOR_H

#include <QDialog>
#include "mainwindow.h"

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
    void ColorChanged1(QString);
    void ColorChanged2(QString);

};

#endif // HIGHLIGHTCOLOR_H
