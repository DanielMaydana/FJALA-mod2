import { Component } from 'react';
import httpClient from '../Init';

class UserService extends Component {

  getUsers() {
    return httpClient.get('/users');
  }
}

export default new UserService()