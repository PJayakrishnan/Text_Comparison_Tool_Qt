//---------------------------------------------------------->
//  highlightcolor.cpp file.
//  Author     : Jayakrishnan P.
//  Last Edited: 15/08/2022
//---------------------------------------------------------->
#include "highlightcolor.h"
#include "ui_highlightcolor.h"


HighlightColor::HighlightColor(MainWindow* wnd, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HighlightColor)
{
    ui->setupUi(this);
    setWindowTitle("Highlight color");
    m_pMnWindow = wnd;

    //Initializing combo box.
    ui->cmbText1Color->addItem("Red");
    ui->cmbText1Color->addItem("Green");
    ui->cmbText1Color->addItem("Yellow");
    ui->cmbText1Color->addItem("Blue");

    ui->cmbText2Color->addItem("Red");
    ui->cmbText2Color->addItem("Green");
    ui->cmbText2Color->addItem("Yellow");
    ui->cmbText2Color->addItem("Blue");

    connect(ui->cmbText1Color,SIGNAL(currentTextChanged(QString)),this,SLOT(ColorChanged1(QString)));
    connect(ui->cmbText2Color,SIGNAL(currentTextChanged(QString)),this,SLOT(ColorChanged2(QString)));
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

//---------------------------------------------------------->
//  Function Name: HighlightColor::ColorChanged1.
//  Return Type  : void.
//  Parameters   : QString - color name.
//  Remarks      : Set color 1.
//---------------------------------------------------------->
void HighlightColor::ColorChanged1(QString color)
{
    m_pMnWindow->SetHighlighterColor1(color);
}

//---------------------------------------------------------->
//  Function Name: HighlightColor::ColorChanged2.
//  Return Type  : void.
//  Parameters   : QString - color name.
//  Remarks      : Set color 2.
//---------------------------------------------------------->
void HighlightColor::ColorChanged2(QString color)
{
    m_pMnWindow->SetHighlighterColor2(color);
}

