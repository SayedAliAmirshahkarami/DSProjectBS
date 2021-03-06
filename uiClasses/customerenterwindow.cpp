#include "customerenterwindow.h"
#include "ui_customerenterwindow.h"

int type;
QString nameStr;

CustomerEnterWindow::CustomerEnterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerEnterWindow)
{
    ui->setupUi(this);
    ui->enter_btn->setIcon(QIcon("../pro1/pics/entrance.png"));
    ui->back_btn->setIcon(QIcon("../pro1/pics/back.png"));
}

CustomerEnterWindow::~CustomerEnterWindow()
{
    delete ui;
}

void CustomerEnterWindow::on_enter_btn_clicked()
{
     nameStr = ui->name_lineEdit->text();

     if(ui->male_radioButton->isChecked()){
         type = 1;
     }
     else if(ui->female_radioButton->isChecked()){
         type = 0;
     }
     else{
         ui->reply_label->setText("لطفا جنسیت خود را مشخص کنید!");
         return;
     }


    int i;
    for(i = 0;i < nameStr.size() && nameStr.at(i) == ' ';i++);
    nameStr.remove(0,i);

    if(nameStr.isEmpty()){
        ui->reply_label->setText("نام و نام خانوادگی وارد نشده \n لطفا نام و نام خانوادگی خود را وارد کنید");
        return;
    }

    QDir enteredCustomersDir;
    enteredCustomersDir.mkdir("enteredCustomers");
    QFile enteredCustomersFile("enteredCustomers/enteredCustomers.txt");
    if(enteredCustomersFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&enteredCustomersFile);
        in.setCodec("UTF-8");
        QString customerName;
        while(!in.atEnd()){
           QChar character;
           in >> character;
           if(character != '\n'){
              customerName.append(character);
           }
           else{
               if(customerName == nameStr){
                   enteredCustomersFile.close();
                   this->close();
                   CustomerWindow *cstWindow = new CustomerWindow;
                   cstWindow->showNormal();

                   return;
               }
               customerName.clear();
           }

        }
        enteredCustomersFile.close();
    }
    if(enteredCustomersFile.open(QIODevice::Append  | QIODevice::Text)){
        QTextStream out(&enteredCustomersFile);
        out.setCodec("UTF-8");
        out<<nameStr<<'\n';

        this->close();
        CustomerWindow *cstWindow = new CustomerWindow;
        cstWindow->showNormal();
        enteredCustomersFile.close();



    }
}

void CustomerEnterWindow::on_back_btn_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow;
    mainWindow->showNormal();
}
