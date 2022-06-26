//---------------------------------------------------------->
//  MainWindow.h file.
//  Author: Jayakrishnan P.
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

private:
    Ui::MainWindow *ui;
    int GetLargerString(int,int);
    bool m_oneBig = false;
    bool m_twoBig = false;
    bool m_sameSize = false;
private slots:
    void OnClickBtnCompare();

};
#endif // MAINWINDOW_H
