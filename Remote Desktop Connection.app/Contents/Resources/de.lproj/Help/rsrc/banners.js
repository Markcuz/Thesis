var baseClass;
function bannerHilite(obj) {
    baseClass = obj.getAttribute('class');

    obj.setAttribute('class', 'hilited');
}

function bannerUnhilite(obj) {
    obj.setAttribute('class', baseClass);
}