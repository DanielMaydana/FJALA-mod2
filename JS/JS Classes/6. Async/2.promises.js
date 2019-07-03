function fakeRequest() {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve({id: 'a00012', name: 'Juan'});
      //if error onError will Called;
      // reject('unspected error');
    }, 4000);
  })
}

function getUser() {
  fakeRequest()
  .then(response => {
    console.log(response, '1');
    return fakeRequest();
  })
  .then(response => {
    console.log(response, '2');
    return fakeRequest();
  })
  .then(response => {
    console.log(response, '3');
    return fakeRequest();
  })
  .then(response => {
    console.log(response, '4');
    return fakeRequest();
  })
  .catch(error => {
    console.log(error);
  });
}

//getUser();




//promiseAll call promises at the same time and wait for the response of all
function getUserSmart() {
  const promises = [];
  promises.push(fakeRequest());
  promises.push(fakeRequest());
  promises.push(fakeRequest());
  promises.push(fakeRequest());

  Promise.all(promises)
  .then(response => {
    const [res1, res2, res3, res4] = response;
    console.log(res1, '1');
    console.log(res2, '2');
    console.log(res3, '3');
    console.log(res4, '4');
    
  })
  .catch(error => {
    console.log(error);
  });
}

//getUserSmart();


