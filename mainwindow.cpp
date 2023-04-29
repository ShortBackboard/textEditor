#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::bridge)
{
    ui->setupUi(this);

    //设置文本框QTextEdit布满整个setCentralWidget
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//新建文件,清空当前文件以及文本框
void MainWindow::on_action_New_triggered()
{
    qDebug() << "New File";
    currentFile.clear();//清空
    ui->textEdit->setText("");
    setWindowTitle("New File");

}

//打开文件
void MainWindow::on_action_Open_triggered()
{
    //选择要打开的文件并获得打开文件的名字
    QString fileName = QFileDialog::getOpenFileName(this,"Open File");

    //打开文件
    QFile file(fileName);

    //如果只读,弹出报错信息
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"warning","can not open file:"+file.errorString());
        return;
    }

    currentFile = fileName;

    //设置窗口名称
    setWindowTitle(currentFile);

    //读取文件
    QTextStream in(&file);
    QString text= in.readAll();
    ui->textEdit->setText(text);

    //关闭文件
    file.close();

}

//保存文件
void MainWindow::on_action_Save_triggered()
{
    QString fileName;

    if(currentFile.isEmpty()){
        fileName = QFileDialog::getSaveFileName(this,"Save File");
        currentFile = fileName;
    }else{
        fileName = currentFile;
    }

    //打开文件
    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"warning","can not save file:"+file.errorString());
        return;
    }

    //设置窗口名称
    setWindowTitle(fileName);

    //读取文本框内容
    QTextStream out(&file);

    //保存的格式
    QString text= ui->textEdit->toPlainText();//toHtml();

    out<<text;

    //关闭文件
    file.close();
}

//另存为
void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save As File");
    currentFile = fileName;


    //打开文件
    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"warning","can not save file:"+file.errorString());
        return;
    }

    //设置窗口名称
    setWindowTitle(fileName);

    //读取文本框内容
    QTextStream out(&file);

    //保存的格式
    QString text= ui->textEdit->toPlainText();//toHtml();

    out<<text;

    //关闭文件
    file.close();
}


void MainWindow::on_action_Exit_triggered()
{
    exit(0);
}

//粘贴
void MainWindow::on_action_Paste_triggered()
{
    ui->textEdit->paste();
}

//剪切
void MainWindow::on_action_Cut_triggered()
{
    ui->textEdit->cut();
}

//复制
void MainWindow::on_action_Copy_triggered()
{
    ui->textEdit->copy();
}


//字体设置
void MainWindow::on_action_Typeface_triggered()
{
    bool fontSelect;
    QFont font = QFontDialog::getFont(&fontSelect,this);

    if(fontSelect){
        ui->textEdit->setFont(font);
    }
}


void MainWindow::on_action_About_triggered()
{
    QMessageBox::about(this,"TextEditor","liChengYang");
}

//撤销
void MainWindow::on_action_Undo_triggered()
{
    ui->textEdit->undo();
}

//取消撤销
void MainWindow::on_action_Redo_triggered()
{
    ui->textEdit->redo();
}

//加粗
void MainWindow::on_action_Bold_triggered(bool checked)
{
    ui->textEdit->setFontWeight(checked ? QFont::Bold : QFont::Normal);
}

//斜体
void MainWindow::on_action_Italic_triggered(bool checked)
{
    ui->textEdit->setFontItalic(checked);
}

//下划线
void MainWindow::on_action_Underline_triggered(bool checked)
{
    ui->textEdit->setFontUnderline(checked);
}
