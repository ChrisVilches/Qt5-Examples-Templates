#include "loading.h"
#include "ui_loading.h"
#include <QMovie>

Loading::Loading(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Loading)
{
    ui->setupUi(this);

    QMovie *gif = new QMovie(":/loading.gif");

    ui->gifLabel->setMovie(gif);
    gif->start();

}

Loading::~Loading()
{
    delete ui;
}
