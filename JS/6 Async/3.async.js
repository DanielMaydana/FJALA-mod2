function fakeRequest() {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve({id: 'a00012', name: 'Juan'});
      //if error onError will Called;
      // reject('unspected error');
    }, 4000);
  })
}


async function getUser() {
  const response1 = await fakeRequest();
  console.log(response1, '1');

  const response2 = await fakeRequest();
  console.log(response2, '2');

  const response3 = await fakeRequest();
  console.log(response3, '3');

  const response4 = await fakeRequest();
  console.log(response4, '4');
}

getUser();