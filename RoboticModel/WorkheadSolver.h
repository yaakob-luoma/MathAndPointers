#ifndef WORKHEADSOLVER_H
#define WORKHEADSOLVER_H

#include <QObject>

#include "SEVisionWorkhead.h"

class WorkheadSolver : public QObject
{
    Q_OBJECT
    Q_PROPERTY( double masterX READ masterX WRITE setMasterX NOTIFY masterXChanged)
    Q_PROPERTY( double masterY READ masterY WRITE setMasterY NOTIFY masterYChanged)
    Q_PROPERTY( double slaveX READ slaveX WRITE setSlaveX NOTIFY slaveXChanged)
    Q_PROPERTY( double slaveY READ slaveY WRITE setSlaveY NOTIFY slaveYChanged)

    Q_PROPERTY( double spottingFBCylinder READ spottingFBCylinder WRITE setSpottingFBCylinder NOTIFY spottingFBCylinderChanged )
    Q_PROPERTY( double spottingSWCylinder READ spottingSWCylinder WRITE setSpottingSWCylinder NOTIFY spottingSWCylinderChanged )
    Q_PROPERTY( double patternFBCylinder READ patternFBCylinder WRITE setPatternFBCylinder NOTIFY patternFBCylinderChanged )
    Q_PROPERTY( double patternSWCylinder READ patternSWCylinder WRITE setPatternSWCylinder NOTIFY patternSWCylinderChanged )

public:
    WorkheadSolver( QObject* parent = nullptr);
    ~WorkheadSolver();

    Q_INVOKABLE solve();

    double masterX() const;
    void setMasterX( double x );

    double masterY() const;
    void setMasterY( double y );

    double slaveX() const;
    void setSlaveX( double x );

    double slaveY() const;
    void setSlaveY( double y );

    double spottingFBCylinder() const;
    void setSpottingFBCylinder( double cylinder );

    double spottingSWCylinder() const;
    void setSpottingSWCylinder( double cylinder );

    double patternFBCylinder() const;
    void setPatternFBCylinder( double cylinder );

    double patternSWCylinder() const;
    void setPatternSWCylinder( double cylinder );

signals:
    void masterXChanged();
    void masterYChanged();
    void slaveXChanged();
    void slaveYChanged();

    void spottingFBCylinderChanged();
    void spottingSWCylinderChanged();
    void patternFBCylinderChanged();
    void patternSWCylinderChanged();

private:
    double _masterX;
    double _masterY;
    double _slaveX;
    double _slaveY;

    double _spottingFBCylinder;
    double _spottingSWCylinder;
    double _patternFBCylinder;
    double _patternSWCylinder;

    SEVisionWorkhead workhead;
};

#endif // WORKHEADSOLVER_H
