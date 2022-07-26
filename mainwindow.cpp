#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),finding_match(false)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer,SIGNAL(timeout()),this,SLOT(TimerTick()));
    this->SetupGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetupGame()
{
    srand(time(NULL));
    QList<QString>* animalEmoji =
            new QList<QString>(std::initializer_list<QString>
                               {
                                  "🐔", "🐔",
                                   "🐶","🐶",
                                   "👽","👽",
                                   "🐯","🐯",
                                   "👹","👹",
                                   "🤖","🤖",
                                   "🐴","🐴",
                                   "🙉","🙉"
                               });
    for(auto button : this->findChildren<QPushButton*>())
    {
        button->setVisible(true);
        int index = rand() % animalEmoji->count();

    }
}
