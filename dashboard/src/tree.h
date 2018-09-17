#ifndef TREE_H
#define TREE_H

#include <QFrame>
#include "treeitem.h"

namespace Ui {
class Tree;
}

class Tree : public QFrame
{
    Q_OBJECT

public:
    explicit Tree(QWidget *parent = 0);
    ~Tree();

private:
    Ui::Tree *ui;
    TreeItem *rootItem;
};

#endif // TREE_H
