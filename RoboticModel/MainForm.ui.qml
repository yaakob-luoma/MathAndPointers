import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

import Workhead 1.0

Item {
    width: 640
    height: 480

    property alias button3: button3
    property alias button2: button2
    property alias button1: button1

    RowLayout {
        anchors.centerIn: parent
//        Row
//        {
//            Column
//            {
//                Label
//                {
//                    id: mxLabel
//                    text: qsTr( "Master X")
//                }
//                TextField
//                {
//                    id: mx
//                    onTextChanged: workheadSolver.mx = text
//                }
//            }
//            Column
//            {
//                Label
//                {
//                    id: fwdSpotLabel
//                    text: qsTr( "Fwd Spotting Cylinder" )
//                }
//                Label
//                {
//                    id: fwdSpot
//                    text: workheadSolver.spottingFBCylinder
//                }
//            }
//        }
//        Row
//        {
//            Column
//            {
//                Label
//                {
//                    id: myLabel
//                    text: qsTr( "Master Y")
//                }
//                TextField
//                {
//                    id: my
//                    onTextChanged: workheadSolver.my = text
//                }
//            }
//            Column
//            {
//                Label
//                {
//                    id: fwdPatLabel
//                    text: qsTr( "Fwd Pattern Cylinder" )
//                }
//                Label
//                {
//                    id: fwdPat
//                    text: workheadSolver.patternFBCylinder
//                }
//            }
//        }
//        Row
//        {
//            Column
//            {
//                Label
//                {
//                    id: sxLabel
//                    text: qsTr( "Slave X")
//                }
//                TextField
//                {
//                    id: sx
//                    onTextChanged: workheadSolver.sx = text
//                }
//            }
//            Column
//            {
//                Label
//                {
//                    id: swgSpotLabel
//                    text: qsTr( "Swg Spotting Cylinder" )
//                }
//                Label
//                {
//                    id: swgSpot
//                    text: WorkheadSolver.spottingSWCylinder
//                }
//            }
//        }
//        Row
//        {
//            Column
//            {
//                Label
//                {
//                    id: syLabel
//                    text: qsTr( "Slave Y")
//                }
//                TextField
//                {
//                    id: sy
//                    onTextChanged: workheadSolver.sy = text
//                }
//            }
//            Column
//            {
//                Label
//                {
//                    id: swgPatLabel
//                    text: qsTr( "Swg Pattern Cylinder" )
//                }
//                Label
//                {
//                    id: swgPat
//                    text: WorkheadSolver.patternSWCylinder
//                }
//            }
//        }
        Row
        {
            Button {
                id: button1
                text: qsTr("Press Me 1")
            }

            Button {
                id: button2
                text: qsTr("Press Me 2")
            }

            Button {
                id: button3
                text: qsTr("Press Me 3")
            }
        }
    }
}
