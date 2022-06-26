//---------------------------------------------------------->
//  highlightcolor.h file.
//  Author     : Jayakrishnan P.
//  Last Edited: 26/06/2022
//---------------------------------------------------------->
#ifndef HIGHLIGHTCOLOR_H
#define HIGHLIGHTCOLOR_H

#include <QDialog>

namespace Ui {
class HighlightColor;
}

class HighlightColor : public QDialog
{
    Q_OBJECT

public:
    explicit HighlightColor(QWidget *parent = nullptr);
    ~HighlightColor();

private:
    Ui::HighlightColor *ui;

private slots:
    void HighlighterDlgBtnClose();

};

#endif // HIGHLIGHTCOLOR_H
