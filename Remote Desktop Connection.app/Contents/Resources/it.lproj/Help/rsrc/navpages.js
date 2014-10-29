/*  
Revised: 100616.1300
*/

var minHeight = 480;
var minWidth = 515;
var olUrlBase = "http://mac2.microsoft.com/help/";

function init() {
    var x = window.innerWidth;
    var y = window.innerHeight;
    var resize = false;

    if (x < minWidth) {
        x = minWidth;
        resize = true;
    }
    if (y < minHeight) {
        y = minHeight;
        resize = true;
    }
    if (resize) {
        window.resizeTo(x, y);
    }

    setOnlineHelpLink();
}

function setOnlineHelpLink() {
    var olHome = document.getElementById('olHome');
    olHome = olHome.getAttribute('content');
    olHome = olUrlBase + olHome;
    document.getElementById('goOnlineBtn').setAttribute('href', olHome);
}