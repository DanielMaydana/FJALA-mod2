


const person = {
  name: 'Juan',
  getBitacora: function () {
    return {
      hora: new Date().getHours(),
      name: this.name,
    }
  }
}


const personBitacora = person.getBitacora();
console.log(personBitacora, ' :::: this is the bitacora');