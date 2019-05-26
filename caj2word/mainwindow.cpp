#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//cja2word
{
QString cja = ui->textEdit->toPlainText();
int cja_l= cja.length();
QString word="";
int i=0;int key=0;
qDebug()<<cja<<endl;
qDebug()<<cja_l<<endl;
for(i=0;i<cja_l;i++)
{
    if(cja[i]=='\n'&&key==0)
    {
        key=1;
        qDebug()<<"well"<<endl;
        continue;
    }
    else if(cja[i]=='\n'&&key==1)
    {
        word = word+cja[i];
        key = 0;
         qDebug()<<"1"<<endl;
    }
    else if(cja[i]!='\n'&&key==1)
    {
        key=0;
        word = word+cja[i];
         qDebug()<<"2"<<endl;
    }
    else
    {
        word = word+cja[i];
         qDebug()<<"3"<<endl;
    }
     qDebug()<<"4  "<<cja[i]<<endl;

}
qDebug()<<word<<endl;
word=word+'\0';
ui->textEdit_2->setText(word);
}
