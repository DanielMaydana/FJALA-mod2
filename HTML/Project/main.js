document.onkeydown = checkKey;
const ship = document.querySelector(".ship");

function hideMenu() {

    const mainMenu = document.querySelector(".welcome-screen");
    const gameScreen = document.querySelector(".gameplay");

    mainMenu.style.display = "none";

    Object.assign(gameScreen.style,{
        display: "block",
    });
}

function checkKey(e) {

    e = e || window.event;
    
    var left = parseInt (ship.style.left, 10);
    console.log(left);

    if (e.keyCode == '37') { // left arrow
        moveShipToTheLeft();

    } else if (e.keyCode == '39') { // right arrow

        moveShipToTheRight();
    }

}

function moveShipToTheLeft() {
//     ship.
}

function moveShipToTheRight() {

}

