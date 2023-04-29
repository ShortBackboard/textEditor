#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class bridge; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_New_triggered();

    void on_action_Open_triggered();

    void on_action_Bold_triggered(bool checked);

    void on_action_Italic_triggered(bool checked);

    void on_action_Underline_triggered(bool checked);

    void on_action_Save_triggered();

    void on_actionSave_as_triggered();

    void on_action_Exit_triggered();

    void on_action_Paste_triggered();

    void on_action_Cut_triggered();

    void on_action_Copy_triggered();

    void on_action_Typeface_triggered();

    void on_action_About_triggered();

    void on_action_Undo_triggered();

    void on_action_Redo_triggered();

private:
    Ui::bridge *ui;
    QString currentFile;//当前文件
};
#endif // MAINWINDOW_H
