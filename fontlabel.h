#ifndef FONTLIST_H
#define FONTLIST_H

#include <QtWidgets>

namespace Ui {
class FontList;
}

class FontLabel : public QWidget
{
    Q_OBJECT

public:
    explicit FontLabel(QWidget *parent = 0);
    ~FontLabel();

private:
    Ui::FontList *ui;
    QLabel *label;

public slots:
    void newFont(QFont font);
};

#endif // FONTLIST_H
