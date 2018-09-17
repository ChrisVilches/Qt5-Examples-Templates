#ifndef ICONTEXT_H
#define ICONTEXT_H

#include <QWidget>

namespace Ui {
class IconText;
}

class IconText : public QWidget
{
    Q_OBJECT

public:
    explicit IconText(QWidget *parent, QString fontAwesomeCode = "", QString text = "");
    ~IconText();

private:
    Ui::IconText *ui;
};

#endif // ICONTEXT_H
