import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

import Workhead 1.0

ApplicationWindow {
    title: qsTr("SEVision Workhead Model")
    width: 640
    height: 480
    visible: true

    //var localFormat = Qt.local() //used for converting number to string

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    function myFunction()
    {
        console.debug( "mx: ", workheadSolver.masterX, " my: ", workheadSolver.masterY, " sx: ", workheadSolver.slaveX, " sy: ", workheadSolver.slaveY, "\n\nSolving..." )
        workheadSolver.solve()
        console.debug( "completed\n" )
        fwdSpot.text = workheadSolver.spottingFBCylinder.toLocaleString()
        fwdPat.text = workheadSolver.patternFBCylinder.toLocaleString()
        swgSpot.text = workheadSolver.spottingSWCylinder.toLocaleString()
        swgPat.text = workheadSolver.patternSWCylinder.toLocaleString()
    }

//    MainForm {
//        anchors.fill: parent
//        button1.onClicked: messageDialog.show(qsTr("Button 1 pressed"))
//        button2.onClicked: messageDialog.show(qsTr("Button 2 pressed"))
//        button3.onClicked: messageDialog.show(qsTr("Button 3 pressed"))
//    }
    Rectangle
    {
        anchors.fill: parent
        anchors.leftMargin: 10
        anchors.topMargin: 10
        ColumnLayout
        {
            RowLayout
            {

                ColumnLayout
                {
                    Label
                    {
                        id: mxLabel
                        text: qsTr( "Master X (3-11)")
                        width: 100
                        height: 50
                    }
                    TextField
                    {
                        id: mx
                        onTextChanged: workheadSolver.masterX = text
                        height: 50
                    }
                }
                ColumnLayout
                {
                    Label
                    {
                        id: fwdSpotLabel
                        text: qsTr( "Fwd Spotting Cylinder" )
                        width: 100
                        height: 50
                    }
                    Label
                    {
                        id: fwdSpot
//                        text: workheadSolver.spottingFBCylinder.toLocaleString(Qt.local())
                        height: 50
                    }
                }
            }
            RowLayout
            {
                ColumnLayout
                {
                    Label
                    {
                        id: myLabel
                        text: qsTr( "Master Y (32-43)")
                        width: 100
                        height: 50
                    }
                    TextField
                    {
                        id: my
                        onTextChanged: workheadSolver.masterY = text
                        height: 50
                    }
                }
                ColumnLayout
                {
                    Label
                    {
                        id: fwdPatLabel
                        text: qsTr( "Fwd Pattern Cylinder" )
                        width: 100
                        height: 50
                    }
                    Label
                    {
                        id: fwdPat
//                        text: workheadSolver.patternFBCylinder.toLocaleString(Qt.local())
                        height: 50
                    }
                }
            }
            RowLayout
            {
                ColumnLayout
                {
                    Label
                    {
                        id: sxLabel
                        text: qsTr( "Slave X (16-21)")
                        width: 100
                        height: 50
                    }
                    TextField
                    {
                        id: sx
                        onTextChanged: workheadSolver.slaveX = text
                        height: 50
                    }
                }
                ColumnLayout
                {
                    Label
                    {
                        id: swgSpotLabel
                        text: qsTr( "Swg Spotting Cylinder" )
                        width: 100
                        height: 50
                    }
                    Label
                    {
                        id: swgSpot
//                        text: workheadSolver.spottingSWCylinder.toLocaleString(Qt.local())
                        height: 50
                    }
                }
            }
            RowLayout
            {
                ColumnLayout
                {
                    Label
                    {
                        id: syLabel
                        text: qsTr( "Slave Y (27-49)")
                        width: 100
                        height: 50
                    }
                    TextField
                    {
                        id: sy
                        onTextChanged: workheadSolver.slaveY = text
                        height: 50
                    }
                }
                ColumnLayout
                {
                    Label
                    {
                        id: swgPatLabel
                        text: qsTr( "Swg Pattern Cylinder" )
                        width: 100
                        height: 50
                    }
                    Label
                    {
                        id: swgPat
//                        text: workheadSolver.patternSWCylinder.toLocaleString(Qt.local())
                        height: 50
                    }
                }
            }
            RowLayout
            {
                Button
                {
                    id: solveButton
                    height: 50
                    text: qsTr( "Determine Cylinder Positions" )
                    onClicked: myFunction()
                }
            }
        }
    }

    MessageDialog {
        id: messageDialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }
    WorkheadSolver
    {
        id: workheadSolver
    }
}
