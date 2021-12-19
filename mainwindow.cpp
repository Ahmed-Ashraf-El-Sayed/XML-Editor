#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{

    currentfile.clear();
    ui->plainTextEdit->setPlainText(QString());
}



void MainWindow::on_actionOpen_triggered()
{
    QString filter = "All Files (*.*) ;; XML Files (*.xml)";
    QString filename = QFileDialog :: getOpenFileName(this,"Open File","C://",filter);
    QFile file(filename);
    currentfile =filename;
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this,"Warning" , "Cannot Open File : " + file.errorString());
        }
    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);

    file.close();
}


void MainWindow::on_actionSave_As_triggered()
{
    QString filename = QFileDialog ::getSaveFileName(this,"save as");
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(this,"Warning" , "Cannot Save File : " + file.errorString());
            return;
        }
        currentfile = filename;
        setWindowTitle(filename);
        QTextStream out(&file);
        QString text = ui->plainTextEdit->toPlainText();
        out << text;
        file.close();
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}



void MainWindow::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}


void MainWindow::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->plainTextEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->plainTextEdit->redo();
}


void MainWindow::on_pushButton_clicked()
{
    QString file = QFileInfo(currentfile).absoluteFilePath();
    string input =file.toStdString();
    minify(input,"Demo.xml");
    QFile x("Demo.xml");
           if(!x.open(QIODevice::ReadOnly | QFile::Text))
           {
               QMessageBox::warning(this,"Warning" , "Cannot Open File : " + x.errorString());
           }
           QTextStream inx(&x);
           QString textx = inx.readAll();
           ui->plainTextEdit->setPlainText(textx);
           x.close();
}


void MainWindow::on_pushButton_3_clicked()
{
    QString file = QFileInfo(currentfile).absoluteFilePath();
    string input =file.toStdString();
    format(input,"Demo.xml");
    QFile x("Demo.xml");
           if(!x.open(QIODevice::ReadOnly | QFile::Text))
           {
               QMessageBox::warning(this,"Warning" , "Cannot Open File : " + x.errorString());
           }
           QTextStream inx(&x);
           QString textx = inx.readAll();

           ui->plainTextEdit->setPlainText(textx);
           x.close();


}


void MainWindow::on_pushButton_2_clicked()
{
    int size_original = 0;
    int size_compressed =0;
    QFile fileing(currentfile);
    size_original = fileing.size();
    QString file = QFileInfo(currentfile).absoluteFilePath();
    string input =file.toStdString();
    compress(input);
    QString compfile = currentfile;
    compfile.append(".huf");
    QFile comp(compfile);
    size_compressed = comp.size();
    QMessageBox::information(this, "Compression Info" ,"Original File Size: "+QString::number(size_original)+" Byte\n"+
                                 "Compressed File Size: "+QString::number(size_compressed)+" Byte\n"+
                                 "Compressed File Name: "+compfile);


}


void MainWindow::on_pushButton_6_clicked()
{
    QString filter = "All Files (*.*) ;; HUF Files (*.huf)";
    QString filename = QFileDialog :: getOpenFileName(this,"Open File","C://",filter);
    QFile file(filename);
    currentfile =filename;
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this,"Warning" , "Cannot Open File : " + file.errorString());
        }
    QString fileing = QFileInfo(currentfile).absoluteFilePath();
    string input =fileing.toStdString();
    decompress(input);
    file.close();
    currentfile.remove(".huf");
    QFile filede(currentfile);
    if(!filede.open(QIODevice::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this,"Warning" , "Cannot Open File : " + filede.errorString());
        }
    setWindowTitle(currentfile);
    QTextStream in(&filede);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);

    filede.close();



}

