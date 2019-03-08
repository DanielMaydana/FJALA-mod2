export default class Clock{
    constructor(){

        this.days = 0;
        this.hours = 0;
        this.minutes = 0;
        this.seconds = 0;
    }

    calculateTime(deadLine){
        
        const timesTamp = new Date(deadLine) - new Date();

        this.days = this.calculateDays(timesTamp);
        this.hours = this.calculateHours(timesTamp);
        this.minutes = this.calculateMinutes(timesTamp);
        this.seconds = this.calculateSeconds(timesTamp);
    }

    calculateDays(time){
        return Math.floor(time/(1000 * 60 * 60 *24));
    }

    calculateHours(time){
        return Math.floor((time/1000 * 60 * 60) % 24);
    }

    calculateMinutes(time){
        return Math.floor((time/(1000 * 60)) % 60);
    }

    calculateSeconds(time){
        return Math.floor((time/1000) % 60);
    }
}