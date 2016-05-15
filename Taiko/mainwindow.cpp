#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include <QMediaPlayer>

extern Game *game;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Start it !");
    bgsound = new QMediaPlayer();
    bgsound->setMedia(QUrl("qrc:/sounds/maple.mp3"));
    bgsound->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //QObject::connect(ui->pushButton, SIGNAL(clicked()), qApp , SLOT(quit()));
    close();
    delete ui;
    delete game;
}

void MainWindow::on_pushButton_2_clicked()
{

    //Game game = new Game();
    bgsound -> stop();
    delete bgsound;
    game = new Game();
    game->show();
    this->hide();
    game->time->countdown ->start();
    delete this;
}
