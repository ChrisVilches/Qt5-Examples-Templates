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
#include <QFontDatabase>
#include <QDebug>
#include <QSizePolicy>
#include <QObjectList>
#include <QMessageBox>

void MainWindow::okBtnClicked(){
    QMessageLogger q;
    q.debug("Clicked");

    int currValue = ui->progressBar->value();

    int nextValue = currValue + 3;

    if(nextValue >= 100){
        nextValue = 100;        
    }

    ui->progressBar->setValue(nextValue);

    if(nextValue == 100){
        QMessageBox::information(
            this,
            tr("Done"),
            tr("Progress bar is complete.") );
    }
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    if (QFontDatabase::addApplicationFont(":/FontAwesome.otf") < 0)
        qWarning() << "FontAwesome cannot be loaded !";

    createButtonBar();
    createTreeTab();
    createMainMenu();

    settings = new Settings();
    home = new Home();
    loading = new Loading();
    setView(home);

    ui->githubLabel->setOpenExternalLinks(true);

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

    stringList.append(QString::fromUtf8("Home"));
    stringList.append(QString::fromUtf8("Settings"));
    stringList.append(QString::fromUtf8("Configure profile"));
    stringList.append(QString::fromUtf8("Friend list"));
    stringList.append(QString::fromUtf8("Follower list"));
    stringList.append(QString::fromUtf8("Likes"));
    stringList.append(QString::fromUtf8("Purchases"));
    stringList.append(QString::fromUtf8("My data"));
    stringList.append(QString::fromUtf8("Change password"));

    iconList.append(QString::fromUtf8("\uf015"));
    iconList.append(QString::fromUtf8("\uf0ad"));
    iconList.append(QString::fromUtf8("\uf4ff"));
    iconList.append(QString::fromUtf8("\uf4fc"));
    iconList.append(QString::fromUtf8("\uf0c0"));
    iconList.append(QString::fromUtf8("\uf560"));
    iconList.append(QString::fromUtf8("\uf53c"));
    iconList.append(QString::fromUtf8("\uf15c"));
    iconList.append(QString::fromUtf8("\uf21b"));


    list = new QListWidget(this);


    for(int i=0; i<stringList.size() && i<iconList.size(); i++){

        QListWidgetItem *listItem = new QListWidgetItem();
        IconText* iconText = new IconText(list, iconList.at(i), stringList.at(i));
        listItem->setSizeHint(QSize(50, 33));

        list->addItem(listItem);
        menuItems.push_back(listItem);
        list->setItemWidget(listItem, iconText);
    }


    ui->menuContainer->layout()->addWidget(list);

    connect(list, SIGNAL(itemClicked(QListWidgetItem*)),
                this, SLOT(onListItemClicked(QListWidgetItem*)));

}

void MainWindow::setView(QWidget *component){
    ui->upperContainer->takeWidget();
    ui->upperContainer->setWidget(component);
}

void MainWindow::onListItemClicked(QListWidgetItem* item)
{

    QWidget* newView = 0;

    if(item == menuItems.at(0)){
        newView = home;
    } else if(item == menuItems.at(1)){
        newView = settings;
    } else if(item == menuItems.at(2)){
        newView = loading;
    }

    if(newView == 0) return;

    QSize minSize = newView->minimumSize();
    if(minSize.width() == 0 && minSize.height() == 0){
        qWarning() << "The component has a minimum size of (0, 0). This may result in scrollbars not appearing (specially components without a layout that were built using drag & drop).";
    }


    setView(newView);

    /*if(list->item(0) == item){
        qWarning() << "First item";
    }*/
    /*if (ui->listMail->item(0) == item) {
        // This is the first item.
    }*/
}

MainWindow::~MainWindow()
{
    delete ui;
    delete list;
    delete tree1;
    delete tree2;
    delete settings;
    delete model;
    delete home;
}
