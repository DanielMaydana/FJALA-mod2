export default class Clock {

  constructor() {
    this.days = 0;
    this.hours = 0;
    this.mins = 0;
    this.seconds = 0;
  }

  calculateTime(deadLine) {
    const timestamp = new Date(deadLine) - new Date()
    this.days = this.calculateDays(timestamp)
    this.hours = this.calculateHours(timestamp)
    this.mins = this.calculateMins(timestamp)
    this.seconds = this.calculateSeconds(timestamp)
    console.log(this);
  }

  calculateDays(timestamp) {
    const days = timestamp/(1000*60*60*24);
    return Math.floor(days)
  }

  calculateHours(timestamp) {
    const hours = (timestamp/(1000*60*60)) % 24;
    return Math.floor(hours);
  }

  calculateMins(timestamp) {
    const mins = (timestamp/(1000*60)) % 60;
    return Math.floor(mins);
  }

  calculateSeconds(timestamp) {
    const seconds = (timestamp/1000) % 60;
    return Math.floor(seconds);
  }
};