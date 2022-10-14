//---------------------------------------------------------->
//  MainWindow.h file.
//  Author     : Jayakrishnan P.
//  Last Edited: 14/10/2022
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


private:
    Ui::MainWindow *ui;

    QColor m_txtBox1Color, m_txtBox2Color;
    QColor GetColor(QString);

private slots:
    void OnClickBtnCompare();
    void ShowHighlighterDlg();

    void ClearAll();

public slots:


};
#endif // MAINWINDOW_H
