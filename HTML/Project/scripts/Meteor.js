function Meteor() {
    this.kind = Math.round(Math.random() * (2 - 1) + 1);
    this.posX = Math.round(Math.random() * (230 - 30) + 30);
    this.posY = 0;
}

Meteor.prototype.draw = function() {
    
    ctx.imageSmoothingEnabled = false;

    ctx.drawImage(image_meteor,
        0, (80 * this.kind),
        80, 80,
        this.posX, this.posY,
        25, 25
    );
}

Meteor.prototype.update = function() {
    
    if(this.posY > 150)
    {
        this.posY = -25;
        this.posX = Math.random() * (230 - 30) + 30;
        this.kind = Math.round(Math.random() * (2 - 1) + 1);    

        score += 1;
        console.log(score);
    } else
    {
        this.posY += 1;
    }
}