function Xwing(posX, posY) {
    
    this.posX = posX;
    this.posY = posY;

    this.direction = 0;
    this.speed = 1;
    this.score = 0;
    this.frame = 0;
}

Xwing.prototype.draw = function() {
    
    ctx.imageSmoothingEnabled = false;

    ctx.drawImage(image_ship,
        75, 0,
        50, 80,
        this.posX, this.posY,
        50, 75);
}

Xwing.prototype.update = function() {
    
    if(this.posX > (-15) && this.posX < 260)
    {
        this.posX += (this.direction * this.speed);
    } else
    {
        this.posX -= (this.direction * 2 * this.speed);
    }
    
    // console.log("")
    
    
    if(enemy_meteor.posY > 85)
    {
        if(enemy_meteor.posX > this.posX && (enemy_meteor.posX + 25) < (this.posX + 50))
        {
            game_over = true;
        }
    }
    
    Xwing.prototype.setDirection = function(newDirection) {
        this.direction = newDirection;
        // console.log("E " + enemy_meteor.posX);
        // console.log("P " + this.posX);
    }
}