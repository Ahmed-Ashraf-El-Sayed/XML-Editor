#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include<QFile>
#include<QFileDialog>
#include<QTextStream>
#include<QMessageBox>
#include<QPrinter>
#include<QPrintDialog>
#include<format.h>
#include<minify.h>
#include"compress.h"
#include"decompress.h"
#include"xml2json.h"
#include"checkConsistency.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    QString currentfile ="";
};
#endif // MAINWINDOW_H
