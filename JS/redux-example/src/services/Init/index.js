import axios from 'axios';

const apiURL = `https://jsonplaceholder.typicode.com/`;
console.log(apiURL);

const httpClient = axios.create({
  baseURL: apiURL,
  headers: { 'Content-Type': 'application/json' }
});

export default httpClient;