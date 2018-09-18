#include "home.h"
#include "ui_home.h"
#include <QPushButton>
#include <QVector>
#include <QSize>
#include <QSizePolicy>
#include <QDebug>

class ButtonTile : public QPushButton{

public:
    ButtonTile(QString fontAwesomeCode, QString text) : QPushButton(fontAwesomeCode + "\n" + text){

        QFont font;
        font.setFamily("FontAwesome");
        setFont(font);

        QSizePolicy policy;
        policy.setHorizontalStretch(QSizePolicy::ExpandFlag);
        this->setSizePolicy(policy);

        setStyleSheet("QPushButton{ \
                        background-color: #565656; \
                        color: white; \
                        border-radius:10px;\
                     } \
                     QPushButton:hover {\
                        background-color: #343434;\
                     }");
    }

    // http://doc.qt.io/qt-5/qwidget.html#
    // When implementing a new widget, it is almost always useful
    // to reimplement sizeHint() to provide a reasonable default
    // size for the widget and to set the correct size policy with setSizePolicy().
    QSize sizeHint() const override{
        return QSize(120, 60);
    }

};

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);


    QVector<ButtonTile*> buttons;

    buttons.append(new ButtonTile("\uf083", "Cocoa"));
    buttons.append(new ButtonTile("\uf019", "Soy milk"));
    buttons.append(new ButtonTile("\uf2c2", "Banana"));

    buttons.append(new ButtonTile("\uf0e7", "Apple"));
    buttons.append(new ButtonTile("\uf500", "Ginger"));
    buttons.append(new ButtonTile("\uf5d1", "Lemonade"));

    buttons.append(new ButtonTile("\uf1fd", "Coconut"));
    buttons.append(new ButtonTile("\uf019", "Carrot"));
    buttons.append(new ButtonTile("\uf1c6", "Almond"));


    for(int i=0; i<buttons.size(); i++){
        QPushButton* current = buttons.at(i);
    }


    for(int i=0; i<buttons.size(); i+=3){
        ui->gridLayout->addWidget(buttons.at(i), i, 0, 3, 1);
        ui->gridLayout->addWidget(buttons.at(i+1), i, 1, 3, 1);
        ui->gridLayout->addWidget(buttons.at(i+2), i, 2, 3, 1);
    }


}

Home::~Home()
{
    delete ui;
}
