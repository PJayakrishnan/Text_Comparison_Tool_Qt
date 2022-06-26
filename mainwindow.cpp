//---------------------------------------------------------->
//  MainWindow.cpp file.
//  Author     : Jayakrishnan P.
//  Last Edited: 26/06/2022
//---------------------------------------------------------->
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "highlightcolor.h"

#include <QMessageBox>
#include  <QList>
#include  <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Text Comparison Tool");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//---------------------------------------------------------->
//  Function Name: MainWindow::OnClickBtnCompare.
//  Return Type  : void.
//  Parameters   : No parameters.
//  Remarks      : Event handler for compare button click.
//---------------------------------------------------------->
void MainWindow::OnClickBtnCompare()
{
    //Taking strings from text boxes.
    QByteArray text1 = (ui->textEdit1->toPlainText()).toUtf8();
    QByteArray text2 = (ui->textEdit2->toPlainText()).toUtf8();

    if(text1 == "" || text2 == "")
    {
        QMessageBox::information(this," "," Enter two strings");
        return;
    }
    QList<int> differenceList;


    int larger = GetLargerString(text1.length(),text2.length());


    //Filling rest of smaller array with '\0'.
    if(m_oneBig == true)
    {
        for(int i = text2.length(); i < text1.length();i++)
        {
            text2.append(' ');
        }
    }
    if(m_twoBig == true)
    {
        for(int i = text1.length(); i < text2.length();i++)
        {
            text1.append(' ');
        }
    }

    ui->textEdit1->setText(text1);
    ui->textEdit2->setText(text2);

    //Finding position indeces of difference between strings.
    for(int i = 0; i < larger; i++)
    {
        if(text1[i] != text2[i])
        {
            differenceList.append(i);
        }
    }

    QTextCursor cursorText1(ui->textEdit1->document());
    QTextCursor cursorText2(ui->textEdit2->document());

    QTextCharFormat backgroundClear, background1, background2;
    backgroundClear.clearBackground();
    background1.setBackground(Qt::yellow);
    background2.setBackground(Qt::green);



    //Text Edit reset.
    cursorText1.setPosition(QTextCursor::Start,QTextCursor::MoveAnchor);
    cursorText1.setPosition(QTextCursor::End,QTextCursor::KeepAnchor);
    cursorText1.setCharFormat(backgroundClear);
    cursorText2.setPosition(QTextCursor::Start,QTextCursor::MoveAnchor);
    cursorText2.setPosition(QTextCursor::End,QTextCursor::KeepAnchor);
    cursorText2.setCharFormat(backgroundClear);


    //If strings are equal.
    if(text1 == text2)
    {
        QMessageBox::information(this,""," Both  strings are exactly the same!!");
        return;
    }



    //Highlighting the difference.
    for(int i = 0;i < differenceList.size();i++)
    {
        cursorText1.setPosition(differenceList[i],QTextCursor::MoveAnchor);
        cursorText1.setPosition(differenceList[i] + 1,QTextCursor::KeepAnchor);
        cursorText1.setCharFormat(background1);

        cursorText2.setPosition(differenceList[i],QTextCursor::MoveAnchor);
        cursorText2.setPosition(differenceList[i] + 1,QTextCursor::KeepAnchor);
        cursorText2.setCharFormat(background2);
    }
}

//---------------------------------------------------------->
//  Function Name: MainWindow::ShowHighlighterDlg.
//  Return Type  : void.
//  Parameters   : None.
//  Remarks      : Creates dialog for highlighting color settings.
//---------------------------------------------------------->
void MainWindow::ShowHighlighterDlg()
{
    HighlightColor* highlighter = new HighlightColor();
    highlighter->show();
}

//---------------------------------------------------------->
//  Function Name: MainWindow::GetLargerString.
//  Return Type  : integer.
//  Parameters   : (2) inetegers. Size of text one and size of text two.
//  Remarks      : This function returns largest among two string sizes.
//---------------------------------------------------------->
int MainWindow::GetLargerString(int text1Size, int text2Size)
{
    if(text1Size > text2Size)
    {
        m_twoBig = false;
        m_oneBig = true;
        m_sameSize = false;
        return text1Size;
    }

    if(text1Size < text2Size)
    {
        m_twoBig = true;
        m_oneBig = false;
        m_sameSize = false;
        return text2Size;
    }

    if(text1Size == text2Size)
    {
        m_twoBig = false;
        m_oneBig = false;
        m_sameSize = true;
        return text1Size;
    }
}
