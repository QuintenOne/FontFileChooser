#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "filelist.h"
#include "fontlabel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QVBoxLayout *mainLayout;
    QHBoxLayout *inputLayout;

    QPushButton *fileButton;
    QPushButton *fontButton;
    QStackedWidget *stackedWidget;

    FontLabel *filelist;
    FontLabel *fontList;

private slots:
    void selectDirectory();
    void selectFont();

signals:
    void addFile(QString filename);
    void changeDirectory(QString filename);
    void newFont(QFont font);
};

#endif // MAINWINDOW_H
