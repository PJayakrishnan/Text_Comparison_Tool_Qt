//---------------------------------------------------------->
//  MainWindow.h file.
//  Author     : Jayakrishnan P.
//  Last Edited: 26/06/2022
//---------------------------------------------------------->
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetHighlighterColor1(QString);
    void SetHighlighterColor2(QString);

private:
    Ui::MainWindow *ui;
    int GetLargerString(int,int);
    bool m_oneBig = false;
    bool m_twoBig = false;
    bool m_sameSize = false;
    QColor m_txtBox1Color, m_txtBox2Color;

private slots:
    void OnClickBtnCompare();
    void ShowHighlighterDlg();


};
#endif // MAINWINDOW_H
