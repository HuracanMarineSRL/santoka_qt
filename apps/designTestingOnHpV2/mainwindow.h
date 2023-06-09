#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <memory>

#include "dataproducer.h"
#include "displayer/battery_filter.h"
#include "displayer/command_filter.h"
#include "displayer/generalinfo_filter.h"
#include "displayer/motor_filter.h"
#include "boatinfowindow.h"

namespace Ui {
class MainWindow;
}
Q_DECLARE_METATYPE(struct can_frame)

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void connectBatteryFilterToGraphics();
    void connectMotorFilterToGraphics();

public slots:
    void setSOC(uint8_t newSOC);
    void setPowerTemperature(uint8_t newPowerTemperature);
    void setPower(float newPower);

    void setSpeed(uint16_t newSpeed);
    void setMotorTemperature(uint8_t newMotorTemperature);
    void setMotorSpeed(uint16_t newMotorSpeed);


private slots:
    void on_pushButton_2_clicked();

    void on_pb_faults_clicked();

    void on_pb_boatinfo_clicked();

private:
    Ui::MainWindow *ui;

    // Can bus producer thread
    std::shared_ptr<canbus_thread> canbus_producer;

    // Displayer
    std::shared_ptr<filter> logger;
    std::shared_ptr<battery_filter> battery;
    std::shared_ptr<command_filter> command;
    std::shared_ptr<generalinfo_filter> generalinfo;
    std::shared_ptr<motor_filter> motor;

    // Pages:
    std::shared_ptr<BoatInfoWindow> boatinfo_page;

};

#endif // MAINWINDOW_H
