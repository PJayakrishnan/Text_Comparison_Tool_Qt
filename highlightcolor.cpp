//---------------------------------------------------------->
//  highlightcolor.cpp file.
//  Author     : Jayakrishnan P.
//  Last Edited: 13/10/2022
//---------------------------------------------------------->
#include "highlightcolor.h"
#include "ui_highlightcolor.h"
#include <QMessageBox>


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

    connect(ui->cmbText1Color,SIGNAL(currentTextChanged(QString)),this,SLOT(TextBox1ColorChanged(QString)));
    connect(ui->cmbText2Color,SIGNAL(currentTextChanged(QString)),this,SLOT(TextBox2ColorChanged(QString)));
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
//  Function Name: HighlightColor::TextBox1ColorChanged.
//  Return Type  : void.
//  Parameters   : None.
//  Remarks      : Set color to registry.
//---------------------------------------------------------->
void HighlightColor::TextBox1ColorChanged(QString color)
{
}

//---------------------------------------------------------->
//  Function Name: HighlightColor::TextBox2ColorChanged.
//  Return Type  : void.
//  Parameters   : None.
//  Remarks      : Set color to registry.
//---------------------------------------------------------->
void HighlightColor::TextBox2ColorChanged(QString color)
{
}

