#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mainLayout = ui->layout;

    fileButton = new QPushButton("Select file");
    fontButton = new QPushButton("Select font");
    stackedWidget = new QStackedWidget();

    filelist = new FileList();
    fontLabel = new FontLabel();

    mainLayout->addWidget(fileButton);
    mainLayout->addWidget(fontButton);
    mainLayout->addWidget(stackedWidget);

    stackedWidget->addWidget(filelist);
    stackedWidget->addWidget(fontLabel);

    stackedWidget->setVisible(false);

    connect(fileButton, SIGNAL(clicked()), SLOT(selectDirectory()));
    connect(fontButton, SIGNAL(clicked()), SLOT(selectFont()));

    connect(this, SIGNAL(newFont(QFont)),
            fontLabel, SLOT(newFont(QFont)));

    connect(this, SIGNAL(addFile(QString)),
            filelist, SLOT(addFile(QString)));
    connect(this, SIGNAL(changeDirectory(QString)),
            filelist, SLOT(changeDirectory(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectDirectory() {
    stackedWidget->setCurrentIndex(0);
    stackedWidget->setVisible(false);

    QDir directory = QDir(
        QFileDialog::getExistingDirectory(this, tr("Directory"), QDir::currentPath())
    );

    if (directory.exists()) {
        stackedWidget->setVisible(true);

        foreach (QString filename, directory.entryList(QDir::Files)) {
            emit addFile(filename);
        }

        emit changeDirectory(directory.absolutePath());
    }
}

void MainWindow::selectFont() {
    stackedWidget->setCurrentIndex(1);
    stackedWidget->setVisible(true);

    bool ok = false;
    emit newFont(QFontDialog::getFont(&ok));
}

