#ifndef SEVISIONWORKHEAD_H
#define SEVISIONWORKHEAD_H

#include <QPoint>
#include <QVector>

#include "LinkageArm.h"
#include "Matrix.h"
#include "Point.h"

class SEVisionWorkhead
{
public:
    enum CylinderNum
    {
        FWD_SPOT,
        FWD_PAT,
        SWG_SPOT,
        SWG_PAT
    };

    SEVisionWorkhead();
    ~SEVisionWorkhead();

    /*!
     * \brief initialize
     */
    void initialize();

    double minimumSpottingForward();
    double maximumSpottingForward();

    double minimumPatternForward();
    double maximumPatternForward();

    double minimumSpottingSwing();
    double maximumSpottingSwing();

    double minimumPatternSwing();
    double maximumPatternSwing();

    double spottingHeight();
    double patternHeight();

    void update( Point spottingGunTarget, Point patternGunTarget );
    void update( double mx, double my, double sx, double sy );

    double getCylinder( unsigned int index );

private:
    enum LinkNum
    {
        LINK_1,
        LINK_2,
        LINK_3,
        LINK_4,
        LINK_5
    };

    double cylinders[4] = { 0.0 };
    QVector< LinkageArm > forwardBackwordModel;
    QVector< LinkageArm > patternSwingModel;
    QVector< LinkageArm > spottingSwingModel;
    QVector< LinkageArm > patternSwing2SpottingSwingModel;
    const double TOLERANCE = 0.0001;
    const double HAMMER_CENTER_FROM_CYLINDER_MOUNT_Y = 8.517;
    /*!
     * \brief createForwardModel
     * model starts in the following form, global frame is y-axis is line, x-axis is column
     *  |
     *  |
     *  |
     *  -
     *  -
     *   \
     *    \
     *     \
     *      |
     *      |
     *      |
     *      -
     *      -
     *
     * legend: the pipe |, and backslash \ represent a fixed length bar
     *         the dash - represents the amount the cylinder can move, when fully closed/retracted its length is account for in the fixed bar
     */
    void createForwardModel();

    /*!
     * \brief createPatternSwingModel
     * model starts in the following form, global frame is z-axis is line, x-axis is column
     *  |
     *  |
     *  |
     *   ---[]
     *
     * legend: the pipe |, and the dash - represent a fixed length bar
     *         the bracket [] represents the amount the cylinder can move, when fully closed/retracted its length is account for in the fixed bar
     */
    void createPatternSwingModel();

    /*!
     * \brief createSpottingSwingModel
     * model starts in the following form, global frame is z-axis is line, x-axis is column
     *  |     |
     *  |     |
     *  |     |
     *   ---[]
     *
     * legend: the pipe |, and dash - represent a fixed length bar
     *         the bracket [] represents the amount the cylinder can move, when fully closed/retracted its length is account for in the fixed bar
     */
    void createSpottingSwingModel();

    /*!
     * \brief createPatternSwing2SpottingSwingModel
     * model starts in the following form, global frame is z-axis is line, x-axis is column
     *  |\
     *  | \
     *  |  \
     *
     * legend: the pipe |, and backslash \ represent a fixed length bar
     */
    void createPatternSwing2SpottingSwingModel();

    /*!
     * \brief determineSpottingForward
     * \param my
     * \return
     */
    double determineSpottingForward( double my );

    /*!
     * \brief determinePatternForward
     * \param sy
     * \return
     */
    double determinePatternForward( double sy );

    /*!
     * \brief determineSpottingSwing
     * \param mx
     * \return
     */
    double determineSpottingSwing( double mx );

    /*!
     * \brief determinePatternSwing
     * \param sx
     * \return
     */
    double determinePatternSwing( double sx );

    /*!
     * \brief applySpottingSwingToPatternModel
     */
    void applySpottingSwingToPatternModel();

    /*!
     * \brief inch2mA
     * \param inch
     * \param max
     * \return
     */
    double inch2mA( double inch, double max );
};

#endif // SEVISIONWORKHEAD_H
