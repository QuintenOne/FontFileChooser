#include "filelist.h"
#include "ui_filelist.h"

FileList::FileList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileList)
{
    ui->setupUi(this);
    layout = ui->layout;
    table = new QTableWidget();

    layout->addWidget(table);

    table->insertColumn(0);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

FileList::~FileList()
{
    delete ui;
}

void FileList::addFile(QString filename)
{
     qDebug() << "addFile " << filename;
     int rowIndex = table->rowCount();
     table->insertRow(rowIndex);
     table->setItem(rowIndex, 0, new QTableWidgetItem(filename));
}

void FileList::changeDirectory(QString filename)
{
    qDebug() << "changeDirectory " << filename;
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setText(filename);
    table->setHorizontalHeaderItem(0, item);
}
