

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.5
import QtQuick.Controls 6.5
import RippleDetectorUI
import QtCharts
import QtQuick.Layouts

Rectangle {
    id: rectangle
    width: Constants.width
    height: Constants.height
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

    ColumnLayout {
        id: columnLayout2
        anchors.fill: parent

        RowLayout {
            id: rowLayout12
            width: 100
            height: 100
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top

            Text {
                id: text_title
                width: 599
                height: 34
                color: "#ffffff"
                text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:1; text-indent:0px;\"><span style=\" font-family:'Impact'; font-size:20pt;\">Sh'RippleDetector --- Postdoc Edition</span></p></body></html>"
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 0
                transformOrigin: Item.Top
                textFormat: Text.RichText
                styleColor: "#eaeaea"
            }
        }

        RowLayout {
            id: rowLayout13
            width: 100
            height: 100
            Layout.fillWidth: true

            ColumnLayout {
                width: 800
                height: 554
                layoutDirection: Qt.LeftToRight
                spacing: 0
                Layout.bottomMargin: 0
                Layout.topMargin: 10
                transformOrigin: Item.TopLeft
                Frame {
                    id: frame
                    width: 800
                    padding: 0
                    rightPadding: 0
                    leftPadding: 0
                    bottomPadding: 0
                    topPadding: 0
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                    Layout.fillWidth: true
                    transformOrigin: Item.TopLeft
                    Layout.preferredWidth: 200
                    Layout.preferredHeight: 200

                    RowLayout {
                        id: rowLayout
                        x: 0
                        y: 0
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        spacing: 0

                        Frame {
                            id: frame_ChannelSelection
                            width: 200
                            height: 200
                            anchors.top: parent.top
                            padding: 0
                            rightPadding: 0
                            leftPadding: 0
                            bottomPadding: 0
                            topPadding: 0
                            Layout.fillWidth: true

                            Text {
                                id: text_channelSelection
                                width: 239
                                height: 29
                                color: "#ffffff"
                                text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Impact'; font-size:12pt;\">Channel Selection</span></p></body></html>"
                                anchors.verticalCenter: parent.verticalCenter
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                anchors.horizontalCenter: parent.horizontalCenter
                                textFormat: Text.RichText
                            }
                        }

                        Frame {
                            id: frame_RDInterface
                            width: 200
                            height: 200
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            padding: 0
                            rightPadding: 0
                            leftPadding: 0
                            bottomPadding: 0
                            topPadding: 0
                            Layout.fillWidth: true

                            ColumnLayout {
                                id: columnLayout
                                width: 100
                                height: 100
                                anchors.left: parent.left
                                anchors.right: parent.right
                                anchors.top: parent.top
                                anchors.bottom: parent.bottom
                                spacing: 0

                                Row {
                                    id: row_rd
                                    width: 200
                                    height: 400
                                    anchors.left: parent.left
                                    anchors.right: parent.right
                                    anchors.top: parent.top

                                    Frame {
                                        id: frame_rd
                                        anchors.fill: parent
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
                                            spacing: 0

                                            RowLayout {
                                                id: rowLayout1
                                                width: 100
                                                height: 100
                                                anchors.left: parent.horizontalCenter
                                                anchors.right: parent.right
                                                spacing: 0
                                                anchors.leftMargin: -198
                                                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                                                Text {
                                                    id: text_RDParams
                                                    color: "#ffffff"
                                                    text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Impact'; font-size:12pt;\">Ripple Detection Parameters</span></p></body></html>"
                                                    anchors.fill: parent
                                                    font.pixelSize: 12
                                                    horizontalAlignment: Text.AlignHCenter
                                                    verticalAlignment: Text.AlignTop
                                                    Layout.alignment: Qt.AlignHCenter
                                                                      | Qt.AlignVCenter
                                                    textFormat: Text.RichText
                                                }
                                            }

                                            RowLayout {
                                                id: rowLayout2
                                                width: 100
                                                height: 100
                                                spacing: 0

                                                Text {
                                                    id: text_detectionThreshold
                                                    color: "#ffffff"
                                                    text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Impact'; font-size:10pt;\">Detection Threshold</span></p></body></html>"
                                                    font.pixelSize: 12
                                                    horizontalAlignment: Text.AlignLeft
                                                    textFormat: Text.RichText
                                                }
                                            }

                                            RowLayout {
                                                id: rowLayout3
                                                width: 100
                                                height: 100
                                                spacing: 0

                                                Text {
                                                    id: text_numChans
                                                    color: "#ffffff"
                                                    text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Impact'; font-size:10pt;\">Number of channels</span></p></body></html>"
                                                    font.pixelSize: 10
                                                    textFormat: Text.RichText
                                                }
                                            }

                                            RowLayout {
                                                id: rowLayout4
                                                width: 100
                                                height: 100
                                                spacing: 0

                                                Text {
                                                    id: text_postStimBlock
                                                    color: "#ffffff"
                                                    text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Impact'; font-size:10pt;\">Post stim block</span></p></body></html>"
                                                    font.pixelSize: 10
                                                    textFormat: Text.RichText
                                                }
                                            }

                                            RowLayout {
                                                id: rowLayout5
                                                width: 100
                                                height: 100
                                                spacing: 0

                                                Text {
                                                    id: text_maxStimRate
                                                    color: "#ffffff"
                                                    text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Impact'; font-size:10pt;\">Max Stim Rate (Hz)</span></p></body></html>"
                                                    font.pixelSize: 10
                                                    textFormat: Text.RichText
                                                }
                                            }

                                            RowLayout {
                                                id: rowLayout_UpdateParams
                                                width: 100
                                                height: 16
                                                anchors.left: parent.left
                                                anchors.right: parent.right
                                                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
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
                                                    Layout.fillWidth: false
                                                }
                                            }

                                            RowLayout {
                                                id: rowLayout_SpecialStimParams
                                                width: 100
                                                height: 100
                                                anchors.left: parent.left
                                                anchors.right: parent.right
                                                Layout.fillWidth: true
                                                spacing: 0

                                                Text {
                                                    id: text_specialStim
                                                    color: "#ffffff"
                                                    text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Impact'; font-size:12pt;\">Special Stim Params</span></p></body></html>"
                                                    font.pixelSize: 10
                                                    Layout.alignment: Qt.AlignHCenter
                                                                      | Qt.AlignVCenter
                                                    textFormat: Text.RichText
                                                }
                                            }

                                            RowLayout {
                                                id: rowLayout8
                                                width: 100
                                                height: 100
                                                spacing: 0

                                                Text {
                                                    id: text_numChans5
                                                    color: "#ffffff"
                                                    text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Impact'; font-size:10pt;\">Number of channels</span></p></body></html>"
                                                    font.pixelSize: 10
                                                    textFormat: Text.RichText
                                                }
                                            }

                                            RowLayout {
                                                id: rowLayout9
                                                width: 100
                                                height: 100
                                                spacing: 0

                                                Text {
                                                    id: text_numChans6
                                                    color: "#ffffff"
                                                    text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Impact'; font-size:10pt;\">Number of channels</span></p></body></html>"
                                                    font.pixelSize: 10
                                                    textFormat: Text.RichText
                                                }
                                            }

                                            RowLayout {
                                                id: rowLayout10
                                                width: 100
                                                height: 100
                                                spacing: 0

                                                Text {
                                                    id: text_numChans7
                                                    color: "#ffffff"
                                                    text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Impact'; font-size:10pt;\">Number of channels</span></p></body></html>"
                                                    font.pixelSize: 10
                                                    textFormat: Text.RichText
                                                }
                                            }
                                        }
                                    }
                                }

                                RowLayout {
                                    id: rowLayout_ttl
                                    width: 100
                                    height: 100
                                    anchors.left: parent.left
                                    anchors.right: parent.right
                                    spacing: 0

                                    Frame {
                                        id: frame_ttl
                                        anchors.fill: parent
                                        padding: 0
                                        rightPadding: 0
                                        leftPadding: 0
                                        bottomPadding: 0
                                        topPadding: 0

                                        Text {
                                            id: text_TTLInterface
                                            x: 135
                                            y: 87
                                            width: 372
                                            height: 172
                                            color: "#ffffff"
                                            text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Impact'; font-size:18pt;\">TTL Interface</span></p></body></html>"
                                            anchors.verticalCenter: parent.verticalCenter
                                            anchors.left: parent.left
                                            anchors.top: parent.top
                                            font.pixelSize: 12
                                            horizontalAlignment: Text.AlignHCenter
                                            textFormat: Text.RichText
                                            anchors.horizontalCenter: parent.horizontalCenter
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                Frame {
                    id: frame_signals
                    width: 800
                    visible: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
                    Layout.bottomMargin: 0
                    Layout.topMargin: 0
                    Layout.fillWidth: true
                    transformOrigin: Item.TopLeft
                    padding: 0
                    topPadding: 0
                    leftPadding: 0
                    rightPadding: 0
                    bottomPadding: 0
                    Layout.preferredWidth: 200
                    Layout.preferredHeight: 200

                    ColumnLayout {
                        id: columnLayout_signals
                        anchors.fill: parent
                        spacing: 0
                        Frame {
                            id: frame_rbf
                            anchors.left: parent.left
                            anchors.right: parent.right
                            anchors.top: parent.top
                            padding: 0
                            rightPadding: 0
                            leftPadding: 0
                            bottomPadding: 0
                            topPadding: 0
                            Layout.preferredHeight: 100
                            Layout.rowSpan: 2
                            Layout.preferredWidth: 800
                            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                            Layout.fillHeight: false
                            Layout.fillWidth: true
                            transformOrigin: Item.TopLeft

                            ChartView {
                                id: line_rbf
                                width: 300
                                height: 300
                                anchors.left: parent.left
                                anchors.right: parent.right
                                anchors.top: parent.top
                                anchors.bottom: parent.bottom
                                backgroundColor: "#00000000"
                                LineSeries {
                                    name: "LineSeries"
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
                            anchors.left: parent.left
                            anchors.right: parent.right
                            anchors.bottom: parent.bottom
                            padding: 0
                            rightPadding: 0
                            leftPadding: 0
                            bottomPadding: 0
                            topPadding: 0
                            Layout.preferredHeight: 10
                            Layout.rowSpan: 2
                            Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
                            Layout.preferredWidth: 800
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            transformOrigin: Item.TopLeft

                            ChartView {
                                id: line_envelope
                                width: frame_envelope.contentWidth
                                height: frame_envelope.implicitBackgroundHeight
                                anchors.left: parent.left
                                anchors.right: parent.right
                                anchors.top: parent.top
                                anchors.bottom: parent.bottom
                                title: ""
                                backgroundColor: "#00000000"
                                anchors.topMargin: 0
                                LineSeries {
                                    name: "LineSeries"
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
    }

    states: [
        State {
            name: "clicked"
        }
    ]
}
