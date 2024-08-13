#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QStandardItemModel>
#include <QTableView>
#include <QVBoxLayout>
#include <QStandardItem>
#include <QHeaderView>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include "contactslist.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ContactsList List;
    QStandardItemModel *model;
    QTableView *table;
private slots:
    void SlotAddFunction();
    void SlotRmvMessage();
    void SlotSrchFunction();
    void SlotFileSave();
    void SlotFileLoad();
};
#endif // MAINWINDOW_H
