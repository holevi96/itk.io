#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>






MainWindow::MainWindow(int gui_width, int gui_height, QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);

    client=new Client(this);


    this->setFixedSize(gui_width,gui_height);
    this->statusBar()->setSizeGripEnabled(false);

    //connect(client, SIGNAL(setPlayerInfo()), this, SLOT(setPlayerInfo()));
    //connect(client, SIGNAL(setServerInfo()), this, SLOT(setServerInfo()));
    createGUI();

    //connect(this,SIGNAL(refreshPlayers()),stackedWidget->widget(MainWindow::GUIState::INGAME),SLOT(refreshPlayers()));
    //qDebug()<<"asd";
    //test=new TestClass(this);
}

void MainWindow::joinedSuccessful()
{
    qDebug()<<"successfully connected";
    if(state==MainWindow::GUIState::WAITING_FOR_CONNECTION){
        setGUIState(MainWindow::GUIState::GAME_MENU);
    }

    /*qDebug()<<"timer start";
    test->timer->start(3000);
    qDebug()<<"timer started";*/
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

void MainWindow::printCompletePlayerInfo(list<CompletePlayerInfo *> l)
{
    for(CompletePlayerInfo* p:l){
        p->printForDebug();
    }
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

void MainWindow::setServerInfo(ServerInfo* serverInfo)
{
    gameData.serverInfo=*serverInfo;
    refreshServerInfo();
}

void MainWindow::setPlayerInfo(list<CompletePlayerInfo*> completePlayerInfo, int ownID)
{
    this->printCompletePlayerInfo(completePlayerInfo);
    //delete gameData.completePlayerInfo;
    gameData.completePlayerInfo=completePlayerInfo;

    gameData.playerId=ownID;
    qDebug()<<"Data arrived. CompletePlayerInfo size: "<<gameData.completePlayerInfo.size();

    refreshPlayers();
}

/*void MainWindow::refreshPlayers()
{

}*/

void MainWindow::connectToServer()
{
    if(state==MainWindow::GUIState::LOGIN){
        client->clickedJoinServerButton(qobject_cast<LoginScreen*>(stackedWidget->currentWidget())->getName(),qobject_cast<LoginScreen*>(stackedWidget->currentWidget())->getIP(),qobject_cast<LoginScreen*>(stackedWidget->currentWidget())->getPort());
        setGUIState(MainWindow::GUIState::WAITING_FOR_CONNECTION);
    }
}

void MainWindow::disconnectServer()
{
    client->clickedQuitServerButton();
    //setGUIState(MainWindow::GUIState::LOGIN);
    createGUI();
}

void MainWindow::joinGame()
{
    if(state==MainWindow::GUIState::GAME_MENU){
        client->clickedJoinGameButton();
        setGUIState(MainWindow::GUIState::INGAME);
    }
}

void MainWindow::leaveGame()
{
    if(state==MainWindow::GUIState::INGAME){
        client->clickedQuitServerButton();
        setGUIState(MainWindow::GUIState::GAME_MENU);
    }
}


void MainWindow::networkErrorMessage(QString errorMessage){
     /*TODO*/
    //qDebug()<<"[Network error]: "+errorMessage;
    fatalError(errorMessage,"Network error");
};




/*
TestClass::TestClass(MainWindow *w):window(w){
    timer->start(3000);
    ls=new list<CompletePlayerInfo>();
    current=new CompletePlayerInfo(0,10,100,300,0,150,0,0,0,0,fireDirection::NONE,false,false,fireDirection::NONE,50,100,0,"asd",new Design("asd"));
    timer=new QTimer(this);
    ls->insert(ls->end(),*current);

    QObject::connect(timer,SIGNAL(timout()),this,SLOT(sendNewShipData()));
}

TestClass::~TestClass(){}

void TestClass::sendNewShipData(){
    qDebug()<<"timer timeout";
    window->setPlayerInfo(ls,0);
    current->phi+=15;
}
*/
