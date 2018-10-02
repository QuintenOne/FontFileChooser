#ifndef FILELIST_H
#define FILELIST_H

#include <QtWidgets>

namespace Ui {
class FileList;
}

class FileList : public QWidget
{
    Q_OBJECT

public:
    explicit FileList(QWidget *parent = 0);
    ~FileList();

private:
    Ui::FileList *ui;
    QHBoxLayout *layout;
    QTableWidget *table;

public slots:
    void addFile(QString filename);
    void changeDirectory(QString filename);
};

#endif // FILELIST_H
