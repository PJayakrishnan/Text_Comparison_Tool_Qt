//---------------------------------------------------------->
//  highlightcolor.cpp file.
//  Author     : Jayakrishnan P.
//  Last Edited: 26/06/2022
//---------------------------------------------------------->
#include "highlightcolor.h"
#include "ui_highlightcolor.h"


HighlightColor::HighlightColor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HighlightColor)
{
    ui->setupUi(this);
    setWindowTitle("Highlight color");

    //Initializing combo box.
    ui->cmbText1Color->addItem("Red");
    ui->cmbText1Color->addItem("Green");
    ui->cmbText1Color->addItem("Yellow");
    ui->cmbText1Color->addItem("Blue");

    ui->cmbText2Color->addItem("Red");
    ui->cmbText2Color->addItem("Green");
    ui->cmbText2Color->addItem("Yellow");
    ui->cmbText2Color->addItem("Blue");
}

HighlightColor::~HighlightColor()
{
    delete ui;
}

//---------------------------------------------------------->
//  Function Name: HighlightColor::HighlighterDlgBtnClose.
//  Return Type  : void.
//  Parameters   : None.
//  Remarks      : Closes dialog for highlighting color settings.
//---------------------------------------------------------->
void HighlightColor::HighlighterDlgBtnClose()
{
    this->close();
}


void HighlightColor::ColorChanged1(QString color)
{
    m_pMnWindow->SetHighlighterColor1(color);
}


void HighlightColor::ColorChanged2(QString color)
{
    m_pMnWindow->SetHighlighterColor2(color);
}

