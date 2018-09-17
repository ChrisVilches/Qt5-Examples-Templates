#include "tree.h"
#include "ui_tree.h"
#include "treeitem.h"
#include <QList>
#include <QVariant>

Tree::Tree(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Tree)
{
    ui->setupUi(this);


    QList<QVariant> rootData;
    rootData << "Title" << "Summary";
    rootItem = new TreeItem(rootData);
    ui->
    //setupModelData(data.split(QString("\n")), rootItem);

}

Tree::~Tree()
{
    delete ui;
}
