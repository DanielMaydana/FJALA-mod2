function primarySum (a) {
  return function secondarySum (b) {
    return a + b + c
  }
}

var c = 15
var sumOf10 = primarySum(10);
sumOf10 //its the secondary sum;
var result = sumOf10(20);
console.log(result); //15? 10? 20?  45?



/* function getCallbacks () {
  var callbacks = []
  for(let i = 0; i < 6; i++) {
    callbacks.push(function () {
      console.log('value of i:', i)
    })
  }

  return callbacks
}
getCallbacks().forEach(callback => callback()) */