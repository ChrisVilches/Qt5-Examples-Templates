#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollArea>
#include <QLabel>
#include <QLayoutItem>
#include <QStringList>
#include <QVBoxLayout>
#include <QMessageLogger>
#include <QTreeView>
#include <QFile>
#include <QListWidget>
#include <QPushButton>
#include <QSize>
#include "icontext.h"
#include "treemodel.h"
#include "tree.h"
#include "settings.h"

void MainWindow::okBtnClicked(){
    QMessageLogger q;
    q.debug("Clicked");

    int currValue = ui->progressBar->value();

    int nextValue = currValue + 3;

    if(nextValue >= 100){
        nextValue = 100;
    }

    ui->progressBar->setValue(nextValue);
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    createButtonBar();
    createTreeTab();
    createMainMenu();

    settings = new Settings();

    ui->upperContainer->setWidget(settings);

}


void MainWindow::createButtonBar(){
    ui->btnBar->clear();
    ui->btnBar->addButton(tr("OK"), QDialogButtonBox::AcceptRole);
    ui->btnBar->addButton(tr("Cancel"), QDialogButtonBox::RejectRole);
    ui->btnBar->addButton(tr("Apply"), QDialogButtonBox::ApplyRole);
    ui->btnBar->addButton(tr("Reset"), QDialogButtonBox::ResetRole);
    ui->btnBar->addButton(tr("Help"), QDialogButtonBox::HelpRole);
    connect(ui->btnBar, SIGNAL(accepted()), this, SLOT(okBtnClicked()));
}

void MainWindow::createTreeTab(){
    QFile file(":/treeContent.txt");
    file.open(QIODevice::ReadOnly);

    model = new TreeModel(file.readAll());
    file.close();

    tree1 = new QTreeView();
    tree2 = new QTreeView();
    tree1->setModel(model);
    tree2->setModel(model);


    tree1->setHeaderHidden(true);
    tree2->setHeaderHidden(true);

    ui->tabs->clear();
    ui->tabs->addTab(tree1, tr("IT"));
    ui->tabs->addTab(tree2, tr("Others"));

}



void MainWindow::createMainMenu(){

    QStringList stringList, iconList;

    stringList.append(QString::fromUtf8("Main"));
    stringList.append(QString::fromUtf8("Settings"));
    stringList.append(QString::fromUtf8("Configure profile"));
    stringList.append(QString::fromUtf8("Friend list"));
    stringList.append(QString::fromUtf8("Follower list"));
    stringList.append(QString::fromUtf8("Likes"));
    stringList.append(QString::fromUtf8("Purchases"));
    stringList.append(QString::fromUtf8("My data"));
    stringList.append(QString::fromUtf8("Billing"));
    stringList.append(QString::fromUtf8("Change password"));

    iconList.append(QString::fromUtf8("\uf083"));
    iconList.append(QString::fromUtf8("\uf019"));
    iconList.append(QString::fromUtf8("\uf2c2"));
    iconList.append(QString::fromUtf8("\uf0e7"));
    iconList.append(QString::fromUtf8("\uf500"));
    iconList.append(QString::fromUtf8("\uf5d1"));
    iconList.append(QString::fromUtf8("\uf1fd"));
    iconList.append(QString::fromUtf8("\uf019"));
    iconList.append(QString::fromUtf8("\uf1c6"));
    iconList.append(QString::fromUtf8("\uf58d"));


    list = new QListWidget(this);


    for(int i=0; i<stringList.size(); i++){

        QListWidgetItem *listItem=new QListWidgetItem();
        IconText* iconText = new IconText(list, iconList.at(i), stringList.at(i));
        listItem->setSizeHint(QSize(50, 33));

        list->addItem(listItem);
        list->setItemWidget(listItem, iconText);
    }

    /*QVBoxLayout *layout = new QVBoxLayout;

    ui->menuContainer->setLayout(layout);*/
    ui->menuContainer->layout()->addWidget(list);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete list;
    delete tree1;
    delete tree2;
    delete settings;
    delete model;
}
