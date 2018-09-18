#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QTreeView>
#include <QListWidget>
#include <QList>
#include <QListWidgetItem>
#include "home.h"
#include "settings.h"
#include "treemodel.h"
#include "loading.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void okBtnClicked();
    void onListItemClicked(QListWidgetItem*);

signals:
    void accepted();
    void itemClicked(QListWidgetItem*);

private:
    Ui::MainWindow *ui;
    void createMainMenu();
    void createTreeTab();
    void createButtonBar();

    Settings* settings;
    QTreeView* tree1;
    QTreeView* tree2;
    TreeModel* model;
    QListWidget *list;
    Home* home;
    Loading* loading;
    QList<QListWidgetItem*> menuItems;
    void setView(QWidget* component);

};

#endif // MAINWINDOW_H
