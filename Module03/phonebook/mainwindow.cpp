#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("PhoneBook Module03");

    // search tab
    model=new QStandardItemModel(0,3);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PhoneNumber"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));


    table=new QTableView(ui->searchtab);
    table->setModel(model);
    table->resize(500,300);
    table->resizeColumnsToContents();

    // slot generate
    connect(ui->addbtn,&QPushButton::clicked,this,&MainWindow::SlotAddFunction);
    connect(ui->rmvbtn,&QPushButton::clicked,this,&MainWindow::SlotRmvMessage);
    connect(ui->searchbtn,&QPushButton::clicked,this,&MainWindow::SlotSrchFunction);
    connect(ui->actionSave,&QAction::triggered,this,&MainWindow::SlotFileSave);
    connect(ui->actionLoad,&QAction::triggered,this,&MainWindow::SlotFileLoad);
}

void MainWindow::SlotSrchFunction(){
    QString index=ui->searchidx->text();
    QMessageBox::StandardButton reply;
    std::vector<QString> contact=List.SearchContacts(index.toInt(),false);
    QMessageBox::information(this,"information",QString("Contacts from %1: name: %2, phonenumber : %3, email : %4").arg(index.toInt()).arg(contact[0]).arg(contact[1]).arg(contact[2]));
    reply=QMessageBox::question(this,"bookmark","Do you want to bookmark this contact?",QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes){
        std::vector<QString> contact=List.SearchContacts(index.toInt(),true);
        QMessageBox::information(this,"information","Bookmark func completed");
        model->verticalHeaderItem(index.toInt())->setBackground(QBrush(Qt::cyan));
    }
    ui->searchidx->clear();
}

void MainWindow::SlotAddFunction(){
    QString str1=ui->lineEdit->text();
    QString str2=ui->lineEdit_2->text();
    QString str3=ui->lineEdit_3->text();
    model->setVerticalHeaderItem(List.getIndex(), new QStandardItem(QString("Contacts %1").arg(List.getIndex())));
    model->setData(model->index(List.getIndex(), 0), str1);
    model->setData(model->index(List.getIndex(), 1), str2);
    model->setData(model->index(List.getIndex(), 2), str3);
    List.AddNewContact(str1,str2,str3);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    List.show();
}


void MainWindow::SlotRmvMessage(){
    QString index = ui->lineEdit_4->text();
    QString phonenumber = ui->lineEdit_5->text();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"REMOVE","Do you want to remove it",QMessageBox::No|QMessageBox::Yes );
    int idx;
    if(reply==QMessageBox::Yes){
        idx=List.Remove(index,phonenumber);
        QMessageBox::information(this, "Information", "Successfully removed");
    }
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    List.show();

    // remove func using index
    if(index!="")
    {
        model->removeRow(index.toInt());
        for(int i=index.toInt();i<=List.getIndex();i++){
            model->setVerticalHeaderItem(i, new QStandardItem(QString("Contacts %1").arg(i)));

        }
    }
    // remove func using phonenumber
    else{
        model->removeRow(idx);
        for(int i=idx;i<=List.getIndex();i++)
        {
            model->setVerticalHeaderItem(i, new QStandardItem(QString("Contacts %1").arg(i)));
        }

        }
}

void MainWindow::SlotFileSave(){
    QFile file("contact.txt");

    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream out(&file);

        for(int i=0;i<List.getIndex();i++){
            if(i<List.getIndex()-1){
            out<<List.getContacts(i).getName()<<" "<<List.getContacts(i).getPhoneNumber()<<" "<<List.getContacts(i).getEmailAddress()<<"\n";
            }else{
                out<<List.getContacts(i).getName()<<" "<<List.getContacts(i).getPhoneNumber()<<" "<<List.getContacts(i).getEmailAddress();
            }
        }
        qDebug()<<"successfully saved";
        file.close();
    }else{
        QMessageBox::information(this,"warning","failed to write file");
    }
}


void MainWindow::SlotFileLoad(){
    QString fileName=QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QTextStream in(&file);

        while(!in.atEnd()){
            QString name;
            QString phone;
            QString email;
            in>>name>>phone>>email;
            model->setVerticalHeaderItem(List.getIndex(), new QStandardItem(QString("Contacts %1").arg(List.getIndex())));
            model->setData(model->index(List.getIndex(), 0), name);
            model->setData(model->index(List.getIndex(), 1), phone);
            model->setData(model->index(List.getIndex(), 2), email);
            List.AddNewContact(name,phone,email);
        }
        file.close();
    }else{
        QMessageBox::information(this,"Failed","failed to load file");
    }

}

// if want more sophiscated module, add function that when we load file, existing contacts on searchtab and contactlist automatically are removed

// currently, if we load file on existing contacts, just added after existing contacts.
MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete table;
}
