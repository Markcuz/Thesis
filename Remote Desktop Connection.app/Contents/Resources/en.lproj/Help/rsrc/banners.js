var baseClass;

function bannerHilite(obj, objId) {
    baseClass = obj.getAttribute('class');
    obj.setAttribute('class', 'hilited');

    var ttlobj = document.getElementById(objId);
    ttlobj.style.textDecoration = 'underline';

}

function bannerUnhilite(obj, objId) {
    var ttlobj = document.getElementById(objId);
    ttlobj.style.textDecoration = 'none';

    obj.setAttribute('class', baseClass);
}

function loadBannerLink(loc) {
    location = loc;
}