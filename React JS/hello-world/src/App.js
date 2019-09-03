import React from 'react';
import logo from './logo.svg';
import './App.css';
import Greet from './Components/Greet';

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          <h1>Hello from reactJS!!!</h1>
        </p>
      </header>
      <Greet />
    </div>
  );
}

export default App;
