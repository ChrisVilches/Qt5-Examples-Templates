#ifndef LINK_H
#define LINK_H

#include <QLabel>
#include <QString>

namespace Ui {
class Link;
}

class Link : public QLabel
{
    Q_OBJECT

public:
    explicit Link(QWidget* parent, QString text, QString href);
    ~Link();

};

#endif // LINK_H
