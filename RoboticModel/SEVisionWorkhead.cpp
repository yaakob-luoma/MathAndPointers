#include "SEVisionWorkhead.h"

#include <QtDebug>

SEVisionWorkhead::SEVisionWorkhead()
{
    initialize();
}

SEVisionWorkhead::~SEVisionWorkhead()
{

}

double SEVisionWorkhead::minimumSpottingForward()
{
    return 0.000;
}

double SEVisionWorkhead::maximumSpottingForward()
{
    return 12.000;
}

double SEVisionWorkhead::minimumPatternForward()
{
    return 0.000;
}

double SEVisionWorkhead::maximumPatternForward()
{
    return 12.000;
}

double SEVisionWorkhead::minimumSpottingSwing()
{
    return 0.000;
}

double SEVisionWorkhead::maximumSpottingSwing()
{
    return 4.750;
}

double SEVisionWorkhead::minimumPatternSwing()
{
    return 0.000;
}

double SEVisionWorkhead::maximumPatternSwing()
{
    return 9.500;
}

double SEVisionWorkhead::spottingHeight()
{
    return 14.800; // this may need to change, height can decrease by up to 0.5 inches
}

double SEVisionWorkhead::patternHeight()
{
    return 20.100; // this may need to change, height can decrease by up to 0.5 inch
}

void SEVisionWorkhead::update( double mx, double my, double sx, double sy )
{
    Point m;
    Point s;
    m.setX( mx );
    m.setY( my );
    s.setX( sx );
    s.setY( sy );
    update( m, s );
}

double SEVisionWorkhead::getCylinder(unsigned int index)
{
    switch( index )
    {
    case FWD_PAT:
        return cylinders[ FWD_PAT ];
        break;
    case FWD_SPOT:
        return cylinders[ FWD_SPOT ];
        break;
    case SWG_PAT:
        return cylinders[ SWG_PAT ];
        break;
    case SWG_SPOT:
        return cylinders[ SWG_SPOT ];
        break;
    default:
        return 0.000;
    }
}

double SEVisionWorkhead::determineSpottingForward( double my )
{
/*
 * cylinder = 0;
cylinder = y - fwd_bck_Model.link1.length;
if( cylinder >= fwd_bck_Model.link2.MINIMUM_OFFSET && cylinder <= fwd_bck_Model.link2.MAXIMUM_OFFSET )
fwd_bck_Model.link2.offset = cylinder;
else
cylinder = fwd_bck_Model.link2.offset;
*/
    double spottingForwardCylinderPositionInch;

    spottingForwardCylinderPositionInch = my - forwardBackwordModel.at( LINK_1 ).getLength() - HAMMER_CENTER_FROM_CYLINDER_MOUNT_Y;

    qDebug() << "Spotting Forward: " << spottingForwardCylinderPositionInch;

    if ( spottingForwardCylinderPositionInch < minimumSpottingForward() - TOLERANCE || spottingForwardCylinderPositionInch > maximumSpottingForward() + TOLERANCE )
    {
        spottingForwardCylinderPositionInch = forwardBackwordModel.at( LINK_2 ).getOffset();
    }
    else
    {
        forwardBackwordModel[ LINK_2 ].setVariable( spottingForwardCylinderPositionInch );
    }
    return spottingForwardCylinderPositionInch;
}

double SEVisionWorkhead::determinePatternForward( double sy )
{
/*
  cylinder = 0;
  cylinder = y - fwd_bck_Model.link4.length - fwd_bck_Model.link1.length - fwd_bck_Model.link2.offset;
  if( cylinder >= fwd_bck_Model.link5.MINIMUM_OFFSET && cylinder <= fwd_bck_Model.link5.MAXIMUM_OFFSET )
  fwd_bck_Model.link5.offset = cylinder;
else
  cylinder = fwd_bck_Model.link5.offset;
  */
    double patternForwardCylinderPositionInch;
    //patternForwardCylinderPositionInch = sy - forwardBackwordModel.at( LINK_4 ) - forwardBackwordModel.at( LINK_1 ).getLength() - forwardBackwordModel.at( LINK_2 ).getOffset();
    // don't need to add hammer center as taken care of by spotting forward
    patternForwardCylinderPositionInch = sy - forwardBackwordModel.at( LINK_4 ).getLength()
                                       + ( forwardBackwordModel.at( LINK_3 ).getLength() * sin( forwardBackwordModel[ LINK_3 ].getJointAngleRad() ) )
                                       - forwardBackwordModel.at( LINK_1 ).getLength() - forwardBackwordModel.at( LINK_2 ).getOffset();

    qDebug() << "Pattern Forward: " << patternForwardCylinderPositionInch;

    if ( patternForwardCylinderPositionInch < minimumPatternForward()-TOLERANCE || patternForwardCylinderPositionInch > maximumPatternForward()+TOLERANCE )
    {
        patternForwardCylinderPositionInch = forwardBackwordModel.at( LINK_5 ).getOffset();
    }
    else
    {
        forwardBackwordModel[ LINK_5 ].setVariable( patternForwardCylinderPositionInch );
    }
    return patternForwardCylinderPositionInch;
}

double SEVisionWorkhead::determineSpottingSwing( double mx )
{
/*
  cylinder = 0;
  cylinder = sqrt( SpottingHoleX * SpottingHoleX + SpottingHeight * SpottingHeight ) - spotting_swing_model.link2.length;
  if( cylinder >= spotting_swing_model.link3.MINIMUM_OFFSET && cylinder <= spotting_swing_model.link3.MAXIMUM_OFFSET )
  spotting_swing_model.link3.offset = cylinder;
else
  cylinder = spotting_swing_model.link3.offset;
  */
    double spottingSwingCylinderPositionInch;
    spottingSwingCylinderPositionInch = sqrt( mx * mx + spottingHeight() * spottingHeight() ) - spottingSwingModel.at( LINK_2 ).getLength();

    qDebug() << "Spotting Swing: " << spottingSwingCylinderPositionInch;

    if ( spottingSwingCylinderPositionInch < minimumSpottingSwing()-TOLERANCE || spottingSwingCylinderPositionInch > maximumSpottingSwing()+TOLERANCE )
    {
        spottingSwingCylinderPositionInch = spottingSwingModel.at( LINK_3 ).getOffset();
    }
    else
    {
        spottingSwingModel[ LINK_3 ].setVariable( spottingSwingCylinderPositionInch );
    }
    return spottingSwingCylinderPositionInch;
}

double SEVisionWorkhead::determinePatternSwing( double sx )
{
/*
  cylinder = 0;
  cylinder = sqrt( PatternHoleX * PatternHoleX + PatternHeight * PatternHeight ) - pattern_swing_model.link2.length;
  if( cylinder >= pattern_swing_model.link3.MINIMUM_OFFSET && cylinder <= pattern_swing_model.link3.MAXIMUM_OFFSET )
  pattern_swing_model.link3.offset = cylinder;
else
  cylinder = pattern_swing_model.link3.offset;
  */
    double patternSwingCylinderPositionInch;
    patternSwingCylinderPositionInch = sqrt( sx * sx + patternHeight() * patternHeight() ) - patternSwingModel.at( LINK_2 ).getLength();

    qDebug() << "Pattern Swing: " << patternSwingCylinderPositionInch;

    if ( patternSwingCylinderPositionInch < minimumPatternSwing()-TOLERANCE || patternSwingCylinderPositionInch > maximumPatternSwing()+TOLERANCE )
    {
        patternSwingCylinderPositionInch = patternSwingModel.at( LINK_3 ).getOffset();
    }
    else
    {
        patternSwingModel[ LINK_3 ].setVariable( patternSwingCylinderPositionInch );
    }
    return patternSwingCylinderPositionInch;
}

void SEVisionWorkhead::applySpottingSwingToPatternModel()
{
    // pattern link 1 to spotting link 1
    // this is the offset of the origin for spottingSwingModel
    qDebug() << "applySpottingSwing2PatternModel";
    // x-offset
    double xOffset2GuidewheelPivot = patternSwing2SpottingSwingModel.at(0).getLength() * sin( patternSwing2SpottingSwingModel.at(0).getJointAngleRad() );
    // y-offset
    double yOffset2GuidewheelPivot = patternSwing2SpottingSwingModel.at(0).getLength() * cos( patternSwing2SpottingSwingModel.at(0).getJointAngleRad() );


    // pattern link 1 to spotting link 3
    // this is the offset of the End Effect of spottingSwingModel
    // x-offset
    double xOffset2SpottingCylinder = patternSwing2SpottingSwingModel.at(1).getLength() * sin( patternSwing2SpottingSwingModel.at(1).getJointAngleRad() );
    // y-offset
    double yOffset2SpottingCylinder = patternSwing2SpottingSwingModel.at(1).getLength() * cos( patternSwing2SpottingSwingModel.at(1).getJointAngleRad() );
    spottingSwingModel[ LINK_3 ].setVariable( spottingSwingModel[ LINK_3 ].getOffset() + xOffset2SpottingCylinder );
}

// assume encoder is 4,000 to 20,000 mA
double SEVisionWorkhead::inch2mA( double inch, double max )
{
    double b = 4000;
    double maxCurrent = 20000;
    double m;
    m = ( maxCurrent - b ) / ( max - 0 );
    return m * inch + b;
}

void SEVisionWorkhead::update( Point spottingGunTarget, Point patternGunTarget )
{
    // if guidewheel is down
    //move forward/backword model first
    //spotting before pattern
    cylinders[ FWD_SPOT ] = determineSpottingForward( spottingGunTarget.getY() );
    cylinders[ FWD_PAT ] = determinePatternForward( patternGunTarget.getY() );

    // move swing spotting model
    cylinders[ SWG_SPOT ] = determineSpottingSwing( spottingGunTarget.getX() );

    // apply offset between spotting and pattern swing model
    //applySpottingSwingToPatternModel();

    // move swing pattern model
    cylinders[ SWG_PAT ] = determinePatternSwing( patternGunTarget.getX() );
}

void SEVisionWorkhead::createForwardModel()
{
    forwardBackwordModel.clear();
    LinkageArm spottingForwardFixed( true, 22.75, 0, 0, deg2rad( 90 ) );
    LinkageArm spottingForwardCylinder( false, 0, 0, 0, 0 ); //minimum offset = 0, maximum offset = 12
    LinkageArm spottingToPatternFixed( true, 27.29, 0, 0, deg2rad( 39.486 ) );
    LinkageArm patternForwardFixed( true, 22.75, 0, 0, deg2rad( 90 ) );
    LinkageArm patternForwardCylinder( false, 0, 0, 0, 0 ); //minimum offset = 0, maximum offset = 12
    forwardBackwordModel.append( spottingForwardFixed );
    forwardBackwordModel.append( spottingForwardCylinder );
    forwardBackwordModel.append( spottingToPatternFixed );
    forwardBackwordModel.append( patternForwardFixed );
    forwardBackwordModel.append( patternForwardCylinder );
}

void SEVisionWorkhead::createPatternSwingModel()
{
    patternSwingModel.clear();
    LinkageArm carriageRodToPatternCylinderFix( true, 32.75, 0, 0, deg2rad( 90 ) );
    LinkageArm patternSwingFixed( true, 20.25, 0, 0, deg2rad( 0 ) );
    LinkageArm patternSwingCylinder( false, 0, 0, 0, 0 ); //minimum offset = 0, maximum offset = 9.5
    patternSwingModel.append( carriageRodToPatternCylinderFix );
    patternSwingModel.append( patternSwingFixed );
    patternSwingModel.append( patternSwingCylinder );
    patternSwingModel.append( carriageRodToPatternCylinderFix ); //add again to include both guns
}

void SEVisionWorkhead::createPatternSwing2SpottingSwingModel()
{
    patternSwing2SpottingSwingModel.clear();
    LinkageArm patternSwingCarriageRod2SpottingGuidewheelCylinderFix( true, 6.96, 0, 0, deg2rad( 21 ) );
    LinkageArm patternSwingCarriageRod2SpottingSwingCylinder( true, 29.507, 0, 0, deg2rad( 88.66 ) );
    patternSwing2SpottingSwingModel.append( patternSwingCarriageRod2SpottingGuidewheelCylinderFix );
    patternSwing2SpottingSwingModel.append( patternSwingCarriageRod2SpottingSwingCylinder );
}

void SEVisionWorkhead::createSpottingSwingModel()
{
    spottingSwingModel.clear();
    LinkageArm guidewheelToCylinderFix( true, 17.917, 0, 0, deg2rad( 74.311 ) );
    LinkageArm spottingSwingFixed( true, 13.75, 0, 0, deg2rad( 0 ) );
    LinkageArm spottingSwingCylinder( false, 0, 0, 0, 0 ); //minimum offset = 0, maximum offset = 4.75
    spottingSwingModel.append( guidewheelToCylinderFix );
    spottingSwingModel.append( spottingSwingFixed );
    spottingSwingModel.append( spottingSwingCylinder );

}

void SEVisionWorkhead::initialize()
{
    createForwardModel();
    createPatternSwingModel();
    createSpottingSwingModel();
    createPatternSwing2SpottingSwingModel();
}


