export default function Validator() {
  const messageEmpty = ' ';
  return {
    validateName: (name) => {
      const regex = /^([A-ZÁÉÍÓÚ]{1}[a-zñáéíóú]+[\s]*)+$/;
      if (name === '') {
        return messageEmpty;
      }
      return regex.test(name) ? '' : 'The name must start with a capital letter and not contains numbers';
    },
    validateLastName: (lastName) => {
      const regex = /^([A-ZÁÉÍÓÚ]{1}[a-zñáéíóú]+[\s]*)+/;
      if (lastName === '') {
        return messageEmpty;
      }
      return regex.test(lastName) ? '' : 'Must start with capital letters and not contains numbers';
    },
    validateTelf: (telf) => {
      const regex = /^[7|6|4]{1}[0-9]{6,7}$/;
      if (telf === '') {
        return messageEmpty;
      }
      return regex.test(telf) ? '' : 'The number must start with 7, 6 or 4 and have between 7 to 8 digits';
    },
    validateEmail: (email) => {
      const regex = /^([a-z0-9A-Z_.-]+)@([\da-z.-]+)\.([a-z.]{2,6})$/;
      if (email === '') {
        return messageEmpty;
      }
      return regex.test(email) ? '' : 'The email has not a valid format';
    },
    validateCi: (ci) => {
      const regex = /^[1-9]{1}[0-9]{6,7}$/;
      if (ci === '') {
        return messageEmpty;
      }
      return regex.test(ci) ? '' : 'The number should have between 7 to 8 digits';
    },
    validateListUsers: (users) => {
      return (users.length === 0) ? 'There are not registered users' : '';
    },
    validateModuleName: (moduleName) => {

      if (moduleName === '') {
        return messageEmpty;
      }
      return (moduleName >= 1 && moduleName <= 1000) ? '' : 'The module name should be between 1 to 1000';
    }
  };
}