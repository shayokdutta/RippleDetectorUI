
/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.5
import QtQuick.Controls 6.5
import RippleDetectorUI
import QtCharts 2.6
import QtQuick.Layouts

//import QtCharts 2.3
Rectangle {
    id: rectangle
    width: Constants.width
    height: 800
    anchors.fill: parent
    color: "#ffffff"
    border.color: "#616161"
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#00ac00"
        }

        GradientStop {
            position: 0.78995
            color: "#ed000000"
        }
        orientation: Gradient.Vertical
    }

    Frame {
        id: frame
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        padding: 0

        ColumnLayout {
            id: columnLayout2
            anchors.fill: parent
            spacing: 0

            Frame {
                id: frame1
                width: 200
                height: 200
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                Layout.fillWidth: true
                padding: 0

                Text {
                    id: text_title
                    x: -12
                    width: 465
                    color: "#ffffff"
                    text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:1; text-indent:0px;\"><span style=\" font-family:'Universalis ADF Std'; font-size:20pt;\">Sh'RippleDetector --- Postdoc Edition</span></p></body></html>"
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    font.pixelSize: 12
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.horizontalCenterOffset: 1
                    anchors.topMargin: 2
                    anchors.bottomMargin: 0
                    anchors.horizontalCenter: parent.horizontalCenter
                    transformOrigin: Item.TopLeft
                    textFormat: Text.RichText
                    styleColor: "#eaeaea"
                }
            }

            Frame {
                id: frame2
                width: 200
                height: 200
                anchors.left: parent.left
                anchors.right: parent.right
                Layout.fillHeight: true
                Layout.fillWidth: true
                padding: 0

                ColumnLayout {
                    id: columnLayout3
                    anchors.fill: parent
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    transformOrigin: Item.Bottom
                    spacing: 0
                    Layout.fillWidth: true

                    Frame {
                        id: frame3
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.top: parent.top
                        padding: 1
                        Layout.fillHeight: true
                        Layout.fillWidth: true

                        RowLayout {
                            id: rowLayout
                            anchors.fill: parent
                            spacing: 0

                            Frame {
                                id: frame_ChannelSelection
                                width: 200
                                height: 200
                                anchors.left: parent.left
                                anchors.top: parent.top
                                anchors.bottom: parent.bottom
                                Layout.fillHeight: false
                                padding: 0
                                rightPadding: 0
                                leftPadding: 0
                                bottomPadding: 0
                                topPadding: 0
                                Layout.fillWidth: false

                                ColumnLayout {
                                    id: columnLayout4
                                    anchors.fill: parent

                                    Frame {
                                        id: frame7
                                        anchors.fill: parent
                                        Layout.fillHeight: false
                                        Layout.fillWidth: true
                                        bottomPadding: 0
                                        padding: 5

                                        Text {
                                            id: text_channelSelection
                                            x: 62
                                            y: -12
                                            width: 190
                                            height: 29
                                            color: "#ffffff"
                                            text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Universalis ADF Std'; font-size:15pt;\">Channel Selection</span></p></body></html>"
                                            anchors.verticalCenter: parent.verticalCenter
                                            anchors.left: parent.left
                                            anchors.right: parent.right
                                            anchors.top: parent.top
                                            font.pixelSize: 12
                                            horizontalAlignment: Text.AlignHCenter
                                            textFormat: Text.RichText
                                        }
                                    }

                                    Frame {
                                        id: frame8
                                        width: 200
                                        height: 200
                                        padding: 0
                                        Layout.fillWidth: true
                                        Layout.fillHeight: false
                                    }
                                }
                            }

                            Frame {
                                id: frame_RDInterface
                                width: 200
                                height: 200
                                anchors.right: parent.right
                                anchors.top: parent.top
                                anchors.bottom: parent.bottom
                                Layout.fillHeight: false
                                padding: 0
                                rightPadding: 0
                                leftPadding: 0
                                bottomPadding: 0
                                topPadding: 0
                                Layout.fillWidth: true

                                ColumnLayout {
                                    id: columnLayout
                                    anchors.fill: parent

                                    Frame {
                                        id: frame_rd
                                        anchors.left: parent.left
                                        anchors.right: parent.right
                                        anchors.top: parent.top
                                        Layout.fillHeight: false
                                        Layout.fillWidth: true
                                        padding: 0
                                        rightPadding: 0
                                        leftPadding: 0
                                        bottomPadding: 0
                                        topPadding: 0

                                        ColumnLayout {
                                            id: columnLayout1
                                            x: 0
                                            y: 0
                                            width: 100
                                            height: 100
                                            anchors.left: parent.left
                                            anchors.right: parent.right
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            anchors.rightMargin: 0
                                            anchors.bottomMargin: 0
                                            anchors.leftMargin: 0
                                            anchors.topMargin: 0
                                            spacing: 0

                                            Frame {
                                                id: frame6
                                                width: 200
                                                height: 200
                                                bottomPadding: 0
                                                padding: 5
                                                Layout.fillWidth: true

                                                Text {
                                                    id: text_RDParams
                                                    color: "#ffffff"
                                                    text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Universalis ADF Std'; font-size:15pt;\">Ripple Detection Parameters</span></p></body></html>"
                                                    anchors.fill: parent
                                                    font.pixelSize: 12
                                                    horizontalAlignment: Text.AlignHCenter
                                                    verticalAlignment: Text.AlignTop
                                                    transformOrigin: Item.TopLeft
                                                    Layout.alignment: Qt.AlignHCenter
                                                                      | Qt.AlignVCenter
                                                    textFormat: Text.RichText
                                                }
                                            }

                                            Frame {
                                                id: frame9
                                                width: 200
                                                height: 200
                                                Layout.fillHeight: false
                                                padding: 2
                                                Layout.fillWidth: true

                                                RowLayout {
                                                    id: rowLayout2
                                                    anchors.fill: parent
                                                    spacing: 5

                                                    Text {
                                                        id: text_detectionThreshold
                                                        color: "#ffffff"
                                                        text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Universalis ADF Std'; font-size:12pt;\">Detection Threshold</span></p></body></html>"
                                                        anchors.left: parent.left
                                                        font.pixelSize: 8
                                                        horizontalAlignment: Text.AlignLeft
                                                        Layout.fillWidth: false
                                                        textFormat: Text.RichText
                                                    }

                                                    SpinBox {
                                                        id: spinBox_detectionThreshold
                                                        width: 100
                                                        height: 15
                                                        opacity: 0.5
                                                        transformOrigin: Item.TopLeft
                                                        font.pointSize: 10
                                                        font.bold: true
                                                        value: 3
                                                        rightPadding: 0
                                                        leftPadding: 0
                                                        rightInset: 10000
                                                        leftInset: 10000
                                                        topInset: 0
                                                        Layout.margins: 5
                                                        Layout.fillHeight: false
                                                        to: 20
                                                        stepSize: 0
                                                        Layout.fillWidth: true
                                                        contentItem: Text {
                                                            text: spinBox_detectionThreshold.value
                                                            color: "white"
                                                            horizontalAlignment: Text.AlignHCenter
                                                            verticalAlignment: Text.AlignVCenter
                                                            anchors.fill: parent
                                                            font: spinBox_detectionThreshold.font
                                                        }
                                                    }

                                                    Text {
                                                        id: text_numChans
                                                        color: "#ffffff"
                                                        text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Universalis ADF Std'; font-size:12pt;\">Number of channels</span></p></body></html>"
                                                        font.pixelSize: 10
                                                        Layout.fillWidth: false
                                                        Layout.alignment: Qt.AlignHCenter
                                                                          | Qt.AlignVCenter
                                                        Layout.fillHeight: false
                                                        textFormat: Text.RichText
                                                    }

                                                    SpinBox {
                                                        id: spinBox_numChans
                                                        width: 100
                                                        height: 15
                                                        opacity: 0.5
                                                        value: 1
                                                        clip: false
                                                        topInset: 50
                                                        font.bold: true
                                                        rightInset: 1000
                                                        leftInset: 10000
                                                        stepSize: 1
                                                        Layout.margins: 5
                                                        Layout.fillWidth: true
                                                        Layout.fillHeight: false
                                                        to: 10
                                                        contentItem: Text {
                                                            text: spinBox_numChans.value
                                                            color: "white" // Set the font color to white
                                                            font: spinBox_numChans.font
                                                            horizontalAlignment: Text.AlignHCenter
                                                            verticalAlignment: Text.AlignVCenter
                                                        }
                                                    }
                                                }
                                            }

                                            Frame {
                                                id: frame11
                                                width: 200
                                                height: 200
                                                padding: 0
                                                Layout.fillWidth: true
                                                Layout.fillHeight: false

                                                RowLayout {
                                                    id: rowLayout4
                                                    anchors.fill: parent
                                                    anchors.topMargin: 0
                                                    spacing: 0

                                                    Text {
                                                        id: text_postStimBlock
                                                        color: "#ffffff"
                                                        text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Universalis ADF Std'; font-size:12pt;\">Post Stim Block (ms)</span></p></body></html>"
                                                        anchors.left: parent.left
                                                        font.pixelSize: 10
                                                        textFormat: Text.RichText
                                                    }

                                                    SpinBox {
                                                        id: spinBox_postStimBlock
                                                        width: 100
                                                        height: 15
                                                        opacity: 0.5
                                                        scale: 1
                                                        value: 200
                                                        editable: false
                                                        topInset: 50
                                                        font.bold: true
                                                        stepSize: 1
                                                        rightInset: 1000
                                                        leftInset: 10000
                                                        clip: false
                                                        Layout.margins: 5
                                                        Layout.fillWidth: true
                                                        Layout.fillHeight: false
                                                        to: 1000
                                                        from: 200
                                                        contentItem: Text {
                                                            text: spinBox_postStimBlock.value
                                                            color: "white"
                                                            horizontalAlignment: Text.AlignHCenter
                                                            verticalAlignment: Text.AlignVCenter
                                                            anchors.fill: parent
                                                            font: spinBox_postStimBlock.font
                                                        }
                                                    }

                                                    Text {
                                                        id: text_maxStimRate
                                                        color: "#ffffff"
                                                        text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Max Stim Rate (Hz)</span></p></body></html>"
                                                        font.pixelSize: 10
                                                        textFormat: Text.RichText
                                                    }

                                                    SpinBox {
                                                        id: spinBox_maxStimRate
                                                        width: 100
                                                        height: 15
                                                        opacity: 0.5
                                                        topInset: 50
                                                        stepSize: 1
                                                        font.bold: true
                                                        rightInset: 1000
                                                        leftInset: 10000
                                                        clip: false
                                                        Layout.margins: 5
                                                        Layout.fillWidth: true
                                                        Layout.fillHeight: false
                                                        to: 10
                                                        contentItem: Text {
                                                            text: spinBox_maxStimRate.value
                                                            color: "white"
                                                            horizontalAlignment: Text.AlignHCenter
                                                            verticalAlignment: Text.AlignVCenter
                                                            anchors.fill: parent
                                                            font: spinBox_maxStimRate.font
                                                        }
                                                    }
                                                }
                                            }

                                            Frame {
                                                id: frame13
                                                width: 200
                                                height: 200
                                                padding: 0
                                                Layout.fillWidth: true
                                                Layout.fillHeight: false

                                                RowLayout {
                                                    id: rowLayout_UpdateParams
                                                    x: -12
                                                    y: -313
                                                    width: 100
                                                    height: 16
                                                    anchors.left: parent.left
                                                    anchors.right: parent.right
                                                    anchors.top: parent.top
                                                    anchors.bottom: parent.bottom
                                                    Layout.alignment: Qt.AlignHCenter
                                                                      | Qt.AlignVCenter
                                                    Layout.fillWidth: false
                                                    spacing: 0

                                                    Button {
                                                        id: button_updateParams
                                                        height: 15
                                                        opacity: 0.79
                                                        visible: true
                                                        text: "Update Parameters"
                                                        clip: false
                                                        Layout.fillHeight: false
                                                        icon.width: 10
                                                        padding: 5
                                                        rightPadding: 5
                                                        leftPadding: 5
                                                        bottomPadding: 5
                                                        topPadding: 5
                                                        font.pointSize: 8
                                                        icon.height: 10
                                                        highlighted: true
                                                        flat: true
                                                        display: AbstractButton.TextBesideIcon
                                                        transformOrigin: Item.TopLeft
                                                        Layout.alignment: Qt.AlignHCenter
                                                                          | Qt.AlignVCenter
                                                        Layout.fillWidth: true
                                                    }
                                                }
                                            }

                                            Frame {
                                                id: frame14
                                                width: 200
                                                height: 200
                                                topPadding: 3
                                                padding: 0
                                                Layout.fillWidth: true
                                                Layout.fillHeight: false

                                                RowLayout {
                                                    id: rowLayout_SpecialStimParams
                                                    x: -12
                                                    y: -305
                                                    width: 100
                                                    height: 100
                                                    anchors.left: parent.left
                                                    anchors.right: parent.right
                                                    anchors.top: parent.top
                                                    anchors.bottom: parent.bottom
                                                    Layout.fillWidth: true
                                                    spacing: 0

                                                    Text {
                                                        id: text_specialStim
                                                        color: "#ffffff"
                                                        text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Universalis ADF Std'; font-size:15pt;\">Special Stim Params</span></p></body></html>"
                                                        font.pixelSize: 10
                                                        Layout.alignment: Qt.AlignHCenter
                                                                          | Qt.AlignVCenter
                                                        textFormat: Text.RichText
                                                    }
                                                }
                                            }

                                            Frame {
                                                id: frame15
                                                width: 200
                                                height: 200
                                                padding: 0
                                                Layout.fillWidth: true
                                                Layout.fillHeight: false

                                                RowLayout {
                                                    id: rowLayout_ControlStim
                                                    anchors.fill: parent
                                                    spacing: 0

                                                    CheckBox {
                                                        id: checkBox
                                                        height: 15
                                                        opacity: 0.5
                                                        text: qsTr("")
                                                        padding: 1
                                                        display: AbstractButton.IconOnly
                                                    }

                                                    Text {
                                                        id: text_numChans5
                                                        color: "#ffffff"
                                                        text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Universalis ADF Std'; font-size:12pt;\">Control Stim Delay (ms)</span></p></body></html>"
                                                        font.pixelSize: 10
                                                        rightPadding: 50
                                                        textFormat: Text.RichText
                                                    }

                                                    SpinBox {
                                                        id: spinBox_controlStim
                                                        width: 100
                                                        height: 15
                                                        font.bold: true
                                                        opacity: 0.5
                                                        topInset: 50
                                                        value: 200
                                                        stepSize: 10
                                                        rightInset: 1000
                                                        leftInset: 10000
                                                        clip: false
                                                        Layout.margins: 5
                                                        Layout.fillWidth: true
                                                        Layout.fillHeight: false
                                                        to: 1000
                                                        contentItem: Text {
                                                            text: spinBox_controlStim.value
                                                            color: "white"
                                                            horizontalAlignment: Text.AlignHCenter
                                                            verticalAlignment: Text.AlignVCenter
                                                            anchors.fill: parent
                                                            font: spinBox_controlStim.font
                                                        }
                                                    }
                                                }
                                            }

                                            Frame {
                                                id: frame16
                                                width: 200
                                                height: 200
                                                padding: 0
                                                Layout.fillWidth: true
                                                Layout.fillHeight: false

                                                RowLayout {
                                                    id: rowLayout_LRD
                                                    anchors.fill: parent
                                                    spacing: 0

                                                    CheckBox {
                                                        id: checkBox_LRD
                                                        height: 15
                                                        opacity: 0.5
                                                        padding: 1
                                                        display: AbstractButton.IconOnly
                                                    }

                                                    Text {
                                                        id: text_numChans6
                                                        color: "#ffffff"
                                                        text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Universalis ADF Std'; font-size:12pt;\">Enable Long Ripple Detection</span></p></body></html>"
                                                        font.pixelSize: 10
                                                        rightPadding: 50
                                                        textFormat: Text.RichText
                                                    }

                                                    Text {
                                                        id: text_numChans7
                                                        color: "#ffffff"
                                                        text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Universalis ADF Std'; font-size:12pt;\">Long Ripple Time </span></p>\n<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Universalis ADF Std'; font-size:12pt;\">Thresh (ms)</span></p></body></html>"
                                                        font.pixelSize: 10
                                                        textFormat: Text.RichText
                                                    }

                                                    SpinBox {
                                                        id: spinBox_LRD
                                                        width: 100
                                                        height: 15
                                                        opacity: 0.5
                                                        value: 10
                                                        topInset: 50
                                                        stepSize: 1
                                                        rightInset: 1000
                                                        leftInset: 10000
                                                        font.bold: true
                                                        clip: false
                                                        Layout.margins: 5
                                                        Layout.fillWidth: true
                                                        Layout.fillHeight: false
                                                        to: 30
                                                        from: 5
                                                        contentItem: Text {
                                                            text: spinBox_LRD.value
                                                            color: "white"
                                                            horizontalAlignment: Text.AlignHCenter
                                                            verticalAlignment: Text.AlignVCenter
                                                            anchors.fill: parent
                                                            font: spinBox_LRD.font
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    Frame {
                                        id: frame_ttl
                                        Layout.fillHeight: true
                                        Layout.fillWidth: true
                                        padding: 0
                                        rightPadding: 0
                                        leftPadding: 0
                                        bottomPadding: 0
                                        topPadding: 0

                                        ColumnLayout {
                                            id: columnLayout5
                                            anchors.fill: parent
                                            spacing: 0

                                            Frame {
                                                id: frame_ttlInterfaceText
                                                width: 200
                                                height: 200
                                                anchors.top: parent.top
                                                Layout.fillHeight: false
                                                topPadding: 5
                                                padding: 0
                                                Layout.fillWidth: true

                                                Text {
                                                    id: text_TTLInterface
                                                    color: "#ffffff"
                                                    text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Universalis ADF Std'; font-size:15pt;\">TTL Interface</span></p></body></html>"
                                                    anchors.bottom: parent.bottom
                                                    anchors.fill: parent
                                                    font.pixelSize: 12
                                                    horizontalAlignment: Text.AlignHCenter
                                                    textFormat: Text.RichText
                                                }
                                            }

                                            Frame {
                                                id: frame_connection
                                                width: 200
                                                //                                                height: 200
                                                Layout.fillWidth: true
                                                padding: 0

                                                RowLayout {
                                                    id: rowLayout3
                                                    width: 100
                                                    height: 100
                                                    anchors.left: parent.left
                                                    anchors.right: parent.right
                                                    anchors.top: parent.top
                                                    anchors.bottom: parent.bottom

                                                    TextField {
                                                        id: textField_address
                                                        text: "udp://192.168.x.x:xxxx"
                                                        Layout.fillWidth: true
                                                        placeholderText: qsTr("udp://192.168.x.x:xxxx")
                                                        color: "white" // This sets the text color to white
                                                        opacity: 0.65

                                                        // Define the background color and opacity
                                                        background: Rectangle {
                                                            color: "red" // Background color
                                                            opacity: 0.4 // Opacity of the background
                                                            anchors.fill: parent // This ensures the background fills the TextField
                                                        }
                                                    }
                                                    Text {
                                                        id: text_connectionStatus
                                                        text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Universalis ADF Std'; font-size:18pt; color:#cc0000;\">Not Connected!</span></p></body></html>"
                                                        font.pixelSize: 12
                                                        Layout.fillWidth: true
                                                        textFormat: Text.RichText
                                                    }
                                                }
                                            }

                                            Frame {
                                                id: frame_testStim
                                                width: 200
                                                anchors.bottom: parent.bottom
                                                Layout.fillWidth: true

                                                RowLayout {
                                                    id: rowLayout1
                                                    width: 100
                                                    height: 100
                                                    anchors.left: parent.left
                                                    anchors.right: parent.right
                                                    anchors.top: parent.top
                                                    anchors.bottom: parent.bottom

                                                    Text {
                                                        id: text_StimDuration
                                                        text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Universalis ADF Std'; font-size:12pt; color:#ffffff;\">Stim Duration Per Phase (</span><span style=\" font-family:'Universalis ADF Std'; font-size:12pt; font-weight:500; color:#ffffff;\">μ</span><span style=\" font-family:'Universalis ADF Std'; font-size:12pt; color:#ffffff;\">s)</span></p></body></html>"
                                                        font.pixelSize: 12
                                                        textFormat: Text.RichText
                                                        Layout.fillWidth: false
                                                    }

                                                    SpinBox {
                                                        id: spinBox_stimPulse
                                                        width: 100
                                                        height: 15
                                                        opacity: 0.5
                                                        font.bold: true
                                                        value: 60
                                                        topInset: 50
                                                        stepSize: 5
                                                        rightInset: 1000
                                                        leftInset: 10000
                                                        clip: false
                                                        Layout.margins: 5
                                                        Layout.fillWidth: true
                                                        Layout.fillHeight: false
                                                        to: 125
                                                        from: 5
                                                        contentItem: Text {
                                                            text: spinBox_stimPulse.value
                                                            color: "white" // Set the font color to white
                                                            font: spinBox_stimPulse.font
                                                            horizontalAlignment: Text.AlignHCenter
                                                            verticalAlignment: Text.AlignVCenter
                                                        }
                                                    }

                                                    Button {
                                                        id: button_stim
                                                        height: 15
                                                        opacity: 0.79
                                                        visible: true
                                                        text: "Test Stim"
                                                        transformOrigin: Item.TopLeft
                                                        topPadding: 5
                                                        rightPadding: 5
                                                        padding: 5
                                                        leftPadding: 5
                                                        icon.width: 10
                                                        icon.height: 10
                                                        highlighted: true
                                                        font.pointSize: 8
                                                        flat: true
                                                        display: AbstractButton.TextBesideIcon
                                                        clip: false
                                                        bottomPadding: 5
                                                        Layout.fillWidth: true
                                                        Layout.fillHeight: false
                                                        Layout.alignment: Qt.AlignHCenter
                                                                          | Qt.AlignVCenter
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    Frame {
                        id: frame_rbf
                        Layout.minimumHeight: 100
                        padding: 5
                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        ChartView {
                            id: line_rbf
                            x: -12
                            y: -236
                            width: 300
                            height: 300
                            anchors.left: parent.left
                            anchors.right: parent.right
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            backgroundColor: "#00000000"
                            legend.visible: false

                            // Custom title using Text item
                            Text {
                                text: "Ripple band filtered"
                                color: "white" // Set the color of the title
                                anchors.top: parent.top
                                anchors.left: parent.left
                                anchors.margins: 10 // Adjust the margin as needed
                                font.pixelSize: 18 // Adjust font size as needed
                            }
                            ValuesAxis {
                                id: axisX
                                gridVisible: false
                                visible: false
                            }
                            ValuesAxis {
                                id: axisY
                                gridVisible: false
                                visible: false
                            }
                            LineSeries {
                                axisX: axisX
                                axisY: axisY
                                XYPoint {
                                    x: 0
                                    y: 2
                                }

                                XYPoint {
                                    x: 1
                                    y: 1.2
                                }

                                XYPoint {
                                    x: 2
                                    y: 3.3
                                }

                                XYPoint {
                                    x: 5
                                    y: 2.1
                                }
                            }
                        }
                    }

                    Frame {
                        id: frame_envelope
                        anchors.bottom: parent.bottom
                        padding: 5
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.minimumHeight: 100

                        ChartView {
                            id: line_envelope
                            x: -12
                            y: -160
                            visible: true
                            anchors.fill: parent
                            title: ""
                            backgroundColor: "#00000000"
                            legend.visible: false

                            // Custom title using Text item
                            Text {
                                text: "Estimated envelope"
                                color: "white" // Set the color of the title
                                anchors.top: parent.top
                                anchors.left: parent.left
                                anchors.margins: 10 // Adjust the margin as needed
                                font.pixelSize: 18 // Adjust font size as needed
                            }
                            ValuesAxis {
                                id: axisXX
                                gridVisible: false
                                visible: false
                            }
                            ValuesAxis {
                                id: axisYY
                                gridVisible: false
                                visible: false
                            }
                            LineSeries {
                                axisX: axisXX
                                axisY: axisYY
                                XYPoint {
                                    x: 0
                                    y: 2
                                }

                                XYPoint {
                                    x: 1
                                    y: 1.2
                                }

                                XYPoint {
                                    x: 2
                                    y: 3.3
                                }

                                XYPoint {
                                    x: 5
                                    y: 2.1
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    states: [
        State {
            name: "clicked"
        }
    ]
}
