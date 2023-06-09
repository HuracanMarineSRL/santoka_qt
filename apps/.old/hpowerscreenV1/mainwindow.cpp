#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    can_thread{std::make_shared<canbus_thread>(nullptr)}
{
    // need this to avoid errors for metatype data passing
    qRegisterMetaType<struct can_frame>();

    ui->setupUi(this);

    // connect can thread to data consumers
    //ex_listen = std::make_shared<examplelisten>(nullptr, can_thread);
    battery = std::make_shared<battery_listener>(nullptr, can_thread);
    generalinfo = std::make_shared<generalinfo_listener>(nullptr, can_thread);

    connect_generalinfo();
    // system log feature
    //connect(can_thread.get(), SIGNAL(signalnewdata(struct can_frame)), this, SLOT(canbusdatalog(struct can_frame)));

    // start background thread
    can_thread->start();
}

MainWindow::~MainWindow()
{
    can_thread->stop();
    delete ui;
}
void MainWindow::connect_generalinfo(){
    connect(generalinfo.get(), SIGNAL(info_BoatType_signal(uint8_t)), this, SLOT(updateBoatType(uint8_t)));
}

void MainWindow::updateBoatType(uint8_t newvalue){
    QString boattype = "Boat type: " + QString::number(newvalue);

    ui->pb_generalinfo->setText(boattype);
}

// log
void MainWindow::canbusdatalog(struct can_frame frame){
    // reset
    numlogs++;
    if (numlogs % MAXLOGS == 0){
        logstrign = "";
    }else{
        logstrign += QString::number(frame.can_id) + ":";
        for(int i = 0; i < frame.can_dlc; i++){
            logstrign += " " + QString::number(frame.data[i]);
        }
        logstrign += "\n";
    }

    ui->tb_cablog->setText(logstrign);
}
