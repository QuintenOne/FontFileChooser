#include "fontlabel.h"
#include "ui_fontlabel.h"

FontLabel::FontLabel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FontList)
{
    ui->setupUi(this);
    label = new QLabel();
    ui->layout->addWidget(label);
}

FontLabel::~FontLabel()
{
    delete ui;
}

void FontLabel::newFont(QFont font) {
    qDebug() << "Font " << font;

    label->setText(font.family());
    label->setFont(font);
}
