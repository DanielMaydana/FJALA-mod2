//so what is hoisting
/*
   Function declarations are always
   moved (hoisted) to the top of their JavaScript scope
   but Assignment Expressions don’t
*/


//in this case hoisting only applies to function declarations
/* function petFactory() {
  function getDog() {
    return 'brian';
  }

  return getDog();

  function getDog() {
    return 'ayudanteDeSanta';
  }
}
console.log('PET::: => ', petFactory()); */


/* function petFactory() {
  var getDog = function () {
      return 'brian';
  };
  return getDog();

  var getDog = function () {
      return 'ayudanteDeSanta';
  };
}

console.log(petFactory()); */

function petFactory() {
  return getDog();

  var getDog = function () {
      return 'brian';
  };

  var getDog = function () {
    return 'ayudanteDeSanta';
  };
} 

console.log('PET:::: =>', petFactory());



function petFactory() {
  function getDog() {
    console.log(issue, '::: Oh oh a issue');
    return 'brian';
  }
  const issue = 'the dog is sick';

  return getDog();

}

console.log('PET:::: =>', petFactory());
