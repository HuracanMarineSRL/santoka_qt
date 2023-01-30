#ifndef BATTERY_FILTER_H
#define BATTERY_FILTER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <memory>

#include "dataproducer.h"

class battery_filter : public QObject
{
    Q_OBJECT
public:
    explicit battery_filter(std::shared_ptr<canbus_thread> canbus_producer = nullptr, QObject *parent = nullptr);

signals:
    void new_bat_Instance(int);
    void new_bat_TotalVoltage(float);
    void new_bat_TotalCurrent(float);
    void new_bat_BatteryTemperature(uint8_t);
    void new_bat_BMSTemperature(uint8_t);
    void new_bat_Power(float);
    void new_bat_TimeToEmpty(uint16_t);
    void new_bat_SOC(uint8_t);
    void new_bat_auxBatteryVoltage(float);
    void new_bat_status(uint8_t);
    void new_bat_warnings(uint8_t);
    void new_bat_faults(uint8_t);


public slots:
    void receivednewframe(can_frame newframe);

private:
    int bat_Instance                = 0;
    float bat_TotalVoltage          = 0;
    float bat_TotalCurrent          = 0;
    uint8_t bat_BatteryTemperature  = 0;
    uint8_t bat_BMSTemperature      = 0;
    float bat_Power                 = 0;
    uint16_t bat_TimeToEmpty        = 0;
    uint8_t bat_SOC                 = 0;
    float bat_auxBatteryVoltage     = 0;
    uint8_t bat_status              = 0;
    uint8_t bat_warnings            = 0;
    uint8_t bat_faults              = 0;
};

#endif // BATTERY_FILTER_H
