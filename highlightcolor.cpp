//---------------------------------------------------------->
//  highlightcolor.cpp file.
//  Author     : Jayakrishnan P.
//  Last Edited: 14/10/2022
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
    ui->cmbText1Color->addItem("");
    ui->cmbText1Color->addItem("red");
    ui->cmbText1Color->addItem("green");
    ui->cmbText1Color->addItem("yellow");
    ui->cmbText1Color->addItem("blue");

    ui->cmbText2Color->addItem("");
    ui->cmbText2Color->addItem("red");
    ui->cmbText2Color->addItem("green");
    ui->cmbText2Color->addItem("yellow");
    ui->cmbText2Color->addItem("blue");

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
    QSettings settings("JK", "Text Comparison Tool");
    settings.beginGroup("Highlight Color");
    settings.setValue("color_one", color);
    settings.endGroup();
}

//---------------------------------------------------------->
//  Function Name: HighlightColor::TextBox2ColorChanged.
//  Return Type  : void.
//  Parameters   : None.
//  Remarks      : Set color to registry.
//---------------------------------------------------------->
void HighlightColor::TextBox2ColorChanged(QString color)
{
    QSettings settings("JK", "Text Comparison Tool");
    settings.beginGroup("Highlight Color");
    settings.setValue("color_two", color);
    settings.endGroup();
}

