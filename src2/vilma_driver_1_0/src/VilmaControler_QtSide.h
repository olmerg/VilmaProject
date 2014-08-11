/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the documentation of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
#ifndef VILMACONTROLER_QTSIDE
#define VILMACONTROLER_QTSIDE
#include "VilmaControler_RosSide.h"
#include <QtDeclarative/QDeclarativeItem>
#include <QColor>
#include <QTimer>
#include<QKeyEvent>
#include <QDateTime>


//![0]
class VilmaControler_QtSide : public QDeclarativeItem
{
//![0]
    Q_OBJECT
    Q_PROPERTY(QString gas_joint READ gas_joint WRITE setGas_joint) // Each one is a property exposed to the qml interface
    Q_PROPERTY(QString brake_joint READ brake_joint WRITE setBrake_joint) //Each has a name, a fuction to return
    Q_PROPERTY(QString hand_brake_joint READ hand_brake_joint WRITE setHand_brake_joint) //it's value and one to set it.
    Q_PROPERTY(QString steering_joint READ steering_joint WRITE setSteering_joint)
    Q_PROPERTY(QString bl_wheel_speed READ bl_wheel_speed WRITE setBl_wheel_speed)
    Q_PROPERTY(QString br_wheel_speed READ br_wheel_speed WRITE setBr_wheel_speed)
    Q_PROPERTY(QString fl_wheel_speed READ fl_wheel_speed WRITE setFl_wheel_speed)
    Q_PROPERTY(QString fr_wheel_speed READ fr_wheel_speed WRITE setFr_wheel_speed)
    Q_PROPERTY(QString gears READ gears WRITE setgears)
    Q_PROPERTY(QString xposition READ xposition)
    Q_PROPERTY(QString yposition READ yposition)
    Q_PROPERTY(QString zposition READ zposition)
    Q_PROPERTY(QString xtwist READ readXtwist WRITE setXtwist)
    Q_PROPERTY(QString ytwist READ readYtwist WRITE setYtwist)
    Q_PROPERTY(QString ztwist READ readZtwist WRITE setZtwist)
    Q_PROPERTY(QString xorientation READ readXorientation WRITE setXorientation)
    Q_PROPERTY(QString yorientation READ readYorientation WRITE setYorientation)
    Q_PROPERTY(QString zorientation READ readZorientation WRITE setZorientation)
    Q_PROPERTY(QString worientation READ readWorientation WRITE setWorientation)





//![1]
//!


public:
//![1]    

    VilmaControler_ROS VilmaControler_ROS_Object; //Object of the class VilmaControler_ROS, which handles ROS-QT interface.

    VilmaControler_QtSide(QDeclarativeItem *parent = 0); //constructor

    QString readXtwist() const;

    QString readYtwist() const;

    QString readZtwist() const;

    QString readXorientation() const;

    QString readYorientation() const;

    QString readZorientation() const;

    QString readWorientation() const;

    QString gas_joint() const;  // Functions to read the properties declared above.

    QString brake_joint() const;

    QString hand_brake_joint() const;

    QString steering_joint() const;

    QString bl_wheel_speed() const;

    QString br_wheel_speed() const;

    QString fl_wheel_speed() const;

    QString fr_wheel_speed() const;

    QString gears() const;

    QString xposition() const;

    QString yposition() const;

    QString zposition() const;



//![2]
    void setXposition(const QString &value);
    void setYposition(const QString &value);
    void setZposition(const QString &value);

    void setXtwist(const QString &value);
    void setYtwist(const QString &value);
    void setZtwist(const QString &value);

    void setXorientation(const QString &value);
    void setYorientation(const QString &value);
    void setZorientation(const QString &value);
    void setWorientation(const QString &value);

    void setGas_joint(const QString &name); //functions which can be invoked from the qml code.
    void setBrake_joint(const QString &name);
    void setHand_brake_joint(const QString &name);
    void setSteering_joint(const QString &name);
    void setBl_wheel_speed(const QString &name);
    void setBr_wheel_speed(const QString &name);
    void setFl_wheel_speed(const QString &name);
    void setFr_wheel_speed(const QString &name);
    void setgears(const QString &name);
    Q_INVOKABLE void change_gears();
    Q_INVOKABLE void accelerate();
    Q_INVOKABLE void deaccelerate();
    Q_INVOKABLE void use_hand_brake();
    Q_INVOKABLE void use_Steering(float value); //using float instead of Qstring because of the slider, it outputs using float.
    Q_INVOKABLE void use_brake_push();
    Q_INVOKABLE void use_brake_release();
    Q_INVOKABLE void reset_state(); //Function to reset all properties and car to default state.



public slots:
    void update_vilma_info(); //function to update the qml values using the ros values
  Q_INVOKABLE  void maintain_speed();
signals:
    void gas_jointChanged();
    void brake_jointChanged();
    void hand_brake_jointChanged();
    void steering_jointChanged();
    void bl_wheel_speedChanged();
    void br_wheel_speedChanged();
    void fl_wheel_speedChanged();
    void fr_wheel_speedChanged();
    void gearsChanged();
    void updated_info();
    void timeout();
    void x_positionChanged();
    void y_positionChanged();
    void z_positionChanged();
    void xtwistChanged();
    void ytwistChanged();
    void ztwistChanged();
    void xorientationChanged();
    void yorientationChanged();
    void zorientationChanged();
    void worientationChanged();


//![2]

private:
    QString gas_joint_value; // variables in which the properties used by the qml (gui) are stored.
    QString brake_joint_value;
    QString hand_brake_joint_value;
    QString steering_joint_value;
    QString bl_wheel_speed_value;
    QString br_wheel_speed_value;
    QString fl_wheel_speed_value;
    QString fr_wheel_speed_value;
    QString gears_value;
    QString xposition_value;
    QString yposition_value;
    QString zposition_value;
    QString xtwist_value;
    QString ytwist_value;
    QString ztwist_value;
    QString xorientation_value;
    QString yorientation_value;
    QString zorientation_value;
    QString worientation_value;

//![3]
};
//![3]

#endif

