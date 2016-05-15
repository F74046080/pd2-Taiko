#include "end.h"
#include "ui_end.h"
#include "game.h"
#include <QGraphicsTextItem>
#include <QDebug>
#include <QLabel>
#include "mainwindow.h"

extern Game * game;
End::End(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::End)
{
   int a;
   a =  game->score->getScore();
   label = new QLabel(this);
   label->setText("  Score: "+ QString::number(a));
   label->setGeometry(150,50,190,175);
   this->setWindowTitle("Result");

    ui->setupUi(this);
}


End::~End()
{
    delete ui;
}

void End::on_pushButton_clicked()
{
    this->hide();
    QObject::connect(ui->pushButton,SIGNAL(clicked()),qApp,SLOT(quit()));
//    delete this;
//    delete game;

}

void End::on_pushButton_2_clicked()
{
    this->hide();
    MainWindow *a = new MainWindow();
    a->show();

    delete game;
}
