import React from 'react';
import './App.css';
import CreatePerson from './views/Person/CreatePerson';
import UserList from './views/User/UserList';

function App() {
  return (
    <div className="App">
      <UserList></UserList>
      <CreatePerson></CreatePerson>
    </div>
  );
}

export default App;
