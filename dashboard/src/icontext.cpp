#include "icontext.h"
#include "ui_icontext.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QString>
#include <QFont>
#include <QDebug>
#include <QLabel>


IconText::IconText(QWidget *parent, QString fontAwesomeCode, QString text) :
    QWidget(parent),
    ui(new Ui::IconText)
{

    ui->setupUi(this);

    QFont font;
    font.setFamily("FontAwesome");

    ui->icon->setFont(font);

    ui->icon->setText(fontAwesomeCode);
    ui->text->setText(text);

}

IconText::~IconText()
{
    delete ui;
}
