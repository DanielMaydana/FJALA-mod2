module.exports = {

  convertDegreeToRadians(degrees) {
    return degrees * Math.PI / 180;
  },

  calcCoordinatesFrom(degree, radio) {

    const radians = this.convertDegreeToRadians(degree);

    return {
      x: Math.cos(radians) * radio,
      y: Math.sin(radians) * radio
    }
  },
}