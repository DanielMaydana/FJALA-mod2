

function fakeRequest(onSuccess, onError) {
  setTimeout(() => {
    onSuccess({id: 'a00012', name: 'Juan'});

    //if error onError will Called;
    // onError('unspected error');
  }, 4000);
}


function getUser() {
  fakeRequest(response => {
    console.log(response, 'first call');
  }, error => {
    console.log(error, 'error');
  }); 
}





/* function getUser() {
  fakeRequest(response => {
    console.log(response, 'firstCall');;
    fakeRequest(response => {
      console.log(response, 'secondCall');
      fakeRequest(response => {
        console.log(response, 'third call');
        fakeRequest(response => {
          console.log(response, 'third call');
          fakeRequest(response => {
            console.log(response, 'third call');
          }, error => {
            console.log(error, 'error');
          }); 
        }, error => {
          console.log(error, 'error');
        }); 
      }, error => {
        console.log(error, 'error');
      }); 
    }, error => {
      console.log(error, 'error');
    }); 
  }, error => {
    console.log(error)
  })
} */

getUser();