#include "WorkheadSolver.h"

#include <QDebug>

WorkheadSolver::WorkheadSolver(QObject *parent)
    : QObject( parent )
{
    workhead.initialize();
}

WorkheadSolver::~WorkheadSolver()
{

}

WorkheadSolver::solve()
{
    workhead.update( _masterX, _masterY, _slaveX, _slaveY );
    _spottingFBCylinder = workhead.getCylinder( SEVisionWorkhead::FWD_SPOT );
    _spottingSWCylinder = workhead.getCylinder( SEVisionWorkhead::SWG_SPOT );
    _patternFBCylinder = workhead.getCylinder( SEVisionWorkhead::FWD_PAT );
    _patternSWCylinder = workhead.getCylinder( SEVisionWorkhead::SWG_PAT );

}

double WorkheadSolver::masterX() const
{
    return _masterX;
}

void WorkheadSolver::setMasterX(double x)
{
    _masterX = x;
}

double WorkheadSolver::masterY() const
{
    return _masterY;
}

void WorkheadSolver::setMasterY(double y)
{
    _masterY = y;
}

double WorkheadSolver::slaveX() const
{
    return _slaveX;
}

void WorkheadSolver::setSlaveX(double x)
{
    _slaveX = x;
}

double WorkheadSolver::slaveY() const
{
    return _slaveY;
}

void WorkheadSolver::setSlaveY(double y)
{
    _slaveY = y;
}

double WorkheadSolver::spottingFBCylinder() const
{
    return _spottingFBCylinder;
}

void WorkheadSolver::setSpottingFBCylinder(double cylinder)
{
    _spottingFBCylinder = cylinder;
}

double WorkheadSolver::spottingSWCylinder() const
{
    return _spottingSWCylinder;
}

void WorkheadSolver::setSpottingSWCylinder(double cylinder)
{
    _spottingSWCylinder = cylinder;
}

double WorkheadSolver::patternFBCylinder() const
{
    return _patternFBCylinder;
}

void WorkheadSolver::setPatternFBCylinder(double cylinder)
{
    _patternFBCylinder = cylinder;
}

double WorkheadSolver::patternSWCylinder() const
{
    return _patternSWCylinder;
}

void WorkheadSolver::setPatternSWCylinder(double cylinder)
{
    _patternSWCylinder = cylinder;
}

