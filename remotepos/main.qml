import QtQuick 2.9
import QtQuick.Window 2.3
import QtLocation 5.9
import QtPositioning 5.8
//import QtMultimedia 5.9

Window {
    id:mainWnd
    visible: true
    width: 1024
    height: 768

    Map {
       id: map
       anchors.fill: parent
       anchors.margins: 50

       plugin: Plugin {
           name:"osm";
       }
       center: QtPositioning.coordinate(47.14, -1.6)
       zoomLevel: 12

       MapItemView{
           id:mapItemView
           model: playerModel

           delegate: MapQuickItem {
              //anchorPoint:
              id: delegateMQI
              rotation: model.Azimuth

              sourceItem: Rectangle {
                  id: defaultDelegate
                  width:32
                  height:32
                  radius:16
                  opacity: 0.6
                  rotation:Azimuth
                  color:"blue"

                  Text{
                      text: PlayerID
                      anchors.centerIn : parent
                  }

              }
              coordinate: QtPositioning.coordinate(Latitude, Longitude)
          }

       }
    }

    Connections{
        target:mapItemView.model
        onDataChanged: {
                //console.log("dataChanged signal Azim:" + playerModel.data( topLeft, 0x0101) );
        }
    }

    Rectangle{
        anchors.top : parent.top
        anchors.left : parent.left
        width : 400
        height : 200
        radius: 10
        color:"grey"
        ListView{
            id:lstView
            model:mapItemView.model
            anchors.fill:parent
            delegate: Text{
                width:parent.width
                height:50
                verticalAlignment: TextInput.AlignVCenter
                fontSizeMode : Text.Fit
                font.pixelSize: 42
                minimumPixelSize: 5
                text: "Latitude : " + Latitude.toFixed(2) + " - Longitude :" + Longitude.toFixed(2) + " - Azimuth : " + Azimuth
            }
        }
    }
/*
    Rectangle{
        anchors.bottom : parent.bottom
        anchors.left : parent.left
        width : 400
        height : 200
        radius: 10
        color:"grey"


        Item {
            MediaPlayer {
                id: mediaplayer
                source: "groovy_video.mp4"
            }

            VideoOutput {
                anchors.fill: parent
                source: mediaplayer
            }

            MouseArea {
                id: playArea
                anchors.fill: parent
                onPressed: mediaplayer.play();
            }
        }
    }
*/

}
