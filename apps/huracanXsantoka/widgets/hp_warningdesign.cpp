#include "hp_warningdesign.h"

hp_warningdesign::hp_warningdesign(QString name, int _canchannel, int bit, QWidget *parent):hp_faultwarning(name, _canchannel, bit, parent)
{
}

void hp_warningdesign::activatecolor(int c, int b, bool active)
{
    if(c == hp_faultwarning::canchannel && b == hp_faultwarning::bit){
       if(active){
            ui->pushButton_2->setStyleSheet("background-color:rgb(204,204,0);");
       }else{
            ui->pushButton_2->setStyleSheet("background-color:rgb(154, 153, 150);");
       }
    }
}
