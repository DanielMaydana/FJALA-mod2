let canvas = document.querySelector('.game-canvas');
let sprites = document.querySelector('.ship');
let scoretag = document.querySelector('.score');

let player_ship = new Xwing(110, 105);
let enemy_meteor = new Meteor();

let image_ship = new Image(); image_ship.src = '/images/game/xwing.png';
let image_meteor = new Image(); image_meteor.src = '/images/game/meteors.png';

let pressed = false;
let game_over = false;
let score = 0;

let ctx = canvas.getContext('2d');

function hideMenu() {
    
    const mainMenu = document.querySelector(".welcome-screen");
    const gameScreen = document.querySelector(".gameplay");
    
    mainMenu.style.display = "none";

    Object.assign(gameScreen.style,{
        display: "block",
    });
}

// Handle keyboard inputs - Based on JavaScript's event listener loop.
document.addEventListener('keydown', function(event) {
    
    if (event.keyCode === 39 && pressed === false) {
        player_ship.setDirection(1);
        // pressed = true;
    }

    if (event.keyCode === 37 && pressed === false) {
        player_ship.setDirection(-1);
        // pressed = true;
    }

    if (event.keyCode === 13) { 
        window.location.reload();
        isPaused = false;
    }
}, false);

document.addEventListener('keyup', function(event) {
    pressed = false;
    player_ship.setDirection(0);

}, false);

// ----------------MAIN_LOOP----------------

function gameLoop() {

    ctx.clearRect(0, 0, canvas.width, canvas.height);
    
    if(game_over == false)
    {
        player_ship.draw();
        player_ship.update();
    
        enemy_meteor.draw();
        enemy_meteor.update();
    
        scoretag.innerHTML = score;
    }

    window.requestAnimationFrame(gameLoop);
}

gameLoop(); 
