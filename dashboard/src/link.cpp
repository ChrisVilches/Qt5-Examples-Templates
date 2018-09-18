#include "link.h"
#include <QString>
#include <QLabel>
#include <QWidget>

Link::Link(QWidget *parent, QString text, QString link) :
    QLabel(parent)
{
    this->setText("<a href=\"" + link + "\">" + text + "</a>");
}

Link::~Link()
{

}
