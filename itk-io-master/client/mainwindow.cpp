#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(int gui_width, int gui_height, QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);

    client=new Client(this);

    this->setFixedSize(gui_width,gui_height);
    this->statusBar()->setSizeGripEnabled(false);

    connect(client, SIGNAL(data_changed()), this, SLOT(refreshPlayers()));
    createGUI();

}

void MainWindow::joinedSuccessful()
{
    qDebug()<<"successfully connected";
    if(state==MainWindow::GUIState::WAITING_FOR_CONNECTION){
        setGUIState(MainWindow::GUIState::GAME_MENU);
    }
}

void MainWindow::connectNotSuccessful(QString errorMessage)
{
    fatalError(errorMessage,"Connection Error");
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::fatalError(QString errorMessage,QString title)
{
    qDebug()<<"[Fatal error]: "<<errorMessage;

    QMessageBox messageBox(QMessageBox::Critical,title,errorMessage,QMessageBox::Ok,this);
    messageBox.exec();

    QWidget* tmp=centralWidget();
    createGUI();
    delete tmp;
}

void MainWindow::setGUIState(MainWindow::GUIState s)
{
    state=s;
    stackedWidget->setCurrentIndex(s);
}

void MainWindow::createGUI()
{
    stackedWidget=new QStackedWidget(this);

    stackedWidget->addWidget(new LoginScreen(this,stackedWidget));
    stackedWidget->addWidget(new ConnectingToServerScreen(this,stackedWidget));
    stackedWidget->addWidget(new InGameMenu(this,stackedWidget));
    stackedWidget->addWidget(new IngameView(this,stackedWidget));

    state=MainWindow::GUIState::LOGIN;

    this->setCentralWidget(stackedWidget);
}

void MainWindow::setServerInfo(ServerInfo serverInfo)
{

}

void MainWindow::setPlayerInfo(list<CompletePlayerInfo*> completePlayerInfo, int ownID)
{

}

void MainWindow::refreshPlayers()
{

}

void MainWindow::connectToServer()
{
    if(state==MainWindow::GUIState::LOGIN){
        //qDebug()<<"1";

        //qDebug()<<qobject_cast<LoginScreen*>(stackedWidget->currentWidget())->getName();
        client->clickedJoinServerButton(qobject_cast<LoginScreen*>(stackedWidget->currentWidget())->getName(),qobject_cast<LoginScreen*>(stackedWidget->currentWidget())->getIP(),qobject_cast<LoginScreen*>(stackedWidget->currentWidget())->getPort());
        setGUIState(MainWindow::GUIState::WAITING_FOR_CONNECTION);
        //qDebug()<<childAt(width()/2,height()/2);
        //qDebug()<<"3";
        //repaint(0,0,width(),height());                  //TODO

    }
    //QThread::sleep(2);              //TODO
    //joinedSuccessful();             //TODO
    //connectNotSuccessful("asd");

    //client->clickedJoinServerButton(QString name, QString ipAddress, int portNum)
}

void MainWindow::joinGame()
{
    setGUIState(MainWindow::GUIState::INGAME);
}


void MainWindow::networkErrorMessage(QString errorMessage){
     /*TODO*/
    //qDebug()<<"[Network error]: "+errorMessage;
    fatalError(errorMessage,"Network error");
};
